[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Security.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon",
        "file": "\/app\/phalcon\/Security.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Security.zep",
                "line": 13,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Security.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Security\\Random",
                "file": "\/app\/phalcon\/Security.zep",
                "line": 14,
                "char": 28
            }
        ],
        "file": "\/app\/phalcon\/Security.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Security\\Exception",
                "file": "\/app\/phalcon\/Security.zep",
                "line": 15,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Security.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\InjectionAwareInterface",
                "file": "\/app\/phalcon\/Security.zep",
                "line": 16,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Security.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Session\\ManagerInterface",
                "alias": "SessionInterface",
                "file": "\/app\/phalcon\/Security.zep",
                "line": 17,
                "char": 57
            }
        ],
        "file": "\/app\/phalcon\/Security.zep",
        "line": 35,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * This component provides a set of functions to improve the security in Phalcon\n * applications\n *\n *```php\n * $login    = $this->request->getPost(\"login\");\n * $password = $this->request->getPost(\"password\");\n *\n * $user = Users::findFirstByLogin($login);\n *\n * if ($user) {\n *     if ($this->security->checkHash($password, $user->password)) {\n *         \/\/ The password is valid\n *     }\n * }\n *```\n *",
        "file": "\/app\/phalcon\/Security.zep",
        "line": 36,
        "char": 5
    },
    {
        "type": "class",
        "name": "Security",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "InjectionAwareInterface",
                "file": "\/app\/phalcon\/Security.zep",
                "line": 37,
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
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 50,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "defaultHash",
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 51,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "numberBytes",
                    "default": {
                        "type": "int",
                        "value": "16",
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 51,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 52,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "random",
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 53,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "requestToken",
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 54,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "token",
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 55,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "tokenKey",
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 56,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "tokenKeySessionId",
                    "default": {
                        "type": "string",
                        "value": "$PHALCON\/CSRF\/KEY$",
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 56,
                        "char": 53
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 57,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "tokenValueSessionId",
                    "default": {
                        "type": "string",
                        "value": "$PHALCON\/CSRF$",
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 57,
                        "char": 51
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 58,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "workFactor",
                    "default": {
                        "type": "int",
                        "value": "8",
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 58,
                        "char": 30
                    },
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "set",
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 58,
                            "char": 35
                        },
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 58,
                            "char": 41
                        }
                    ],
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 62,
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
                                    "property": "random",
                                    "expr": {
                                        "type": "new",
                                        "class": "Random",
                                        "dynamic": 0,
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 65,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 65,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 66,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Security constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 64,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 63,
                    "last-line": 71,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "checkHash",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "password",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 72,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "passwordHash",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 72,
                            "char": 67
                        },
                        {
                            "type": "parameter",
                            "name": "maxPassLength",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "0",
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 72,
                                "char": 90
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 72,
                            "char": 90
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "char",
                            "variables": [
                                {
                                    "variable": "ch",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 74,
                                    "char": 16
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 75,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "cryptedHash",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 75,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 76,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "int",
                            "variables": [
                                {
                                    "variable": "i",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 76,
                                    "char": 14
                                },
                                {
                                    "variable": "sum",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 76,
                                    "char": 19
                                },
                                {
                                    "variable": "cryptedLength",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 76,
                                    "char": 34
                                },
                                {
                                    "variable": "passwordLength",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 76,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 78,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "greater",
                                    "left": {
                                        "type": "variable",
                                        "value": "maxPassLength",
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 78,
                                        "char": 26
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 78,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 78,
                                    "char": 31
                                },
                                "right": {
                                    "type": "greater",
                                    "left": {
                                        "type": "fcall",
                                        "name": "strlen",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "password",
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 78,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 78,
                                                "char": 48
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 78,
                                        "char": 50
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "maxPassLength",
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 78,
                                        "char": 66
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 78,
                                    "char": 66
                                },
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 78,
                                "char": 66
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 79,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 80,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 82,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "cryptedHash",
                                    "expr": {
                                        "type": "cast",
                                        "left": "string",
                                        "right": {
                                            "type": "fcall",
                                            "name": "crypt",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "password",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 82,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 82,
                                                    "char": 50
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "passwordHash",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 82,
                                                        "char": 64
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 82,
                                                    "char": 64
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 82,
                                            "char": 65
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 82,
                                        "char": 65
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 82,
                                    "char": 65
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 84,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "cryptedLength",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "strlen",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "cryptedHash",
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 84,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 84,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 84,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 84,
                                    "char": 48
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "passwordLength",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "strlen",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "passwordHash",
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 85,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 85,
                                                "char": 49
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 85,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 85,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 87,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "concat-assign",
                                    "variable": "cryptedHash",
                                    "expr": {
                                        "type": "variable",
                                        "value": "passwordHash",
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 87,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 87,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 89,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "sum",
                                    "expr": {
                                        "type": "sub",
                                        "left": {
                                            "type": "variable",
                                            "value": "cryptedLength",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 89,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "passwordLength",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 89,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 89,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 89,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 91,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "passwordHash",
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 91,
                                "char": 35
                            },
                            "key": "i",
                            "value": "ch",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "sum",
                                            "expr": {
                                                "type": "bitwise_or",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "sum",
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 92,
                                                    "char": 27
                                                },
                                                "right": {
                                                    "type": "list",
                                                    "left": {
                                                        "type": "bitwise_xor",
                                                        "left": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "cryptedHash",
                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                "line": 92,
                                                                "char": 41
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "i",
                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                "line": 92,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 92,
                                                            "char": 45
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "ch",
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 92,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 92,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 92,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 92,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 92,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 93,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 95,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "int",
                                    "value": "0",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 95,
                                    "char": 20
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "sum",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 95,
                                    "char": 25
                                },
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 95,
                                "char": 25
                            },
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 96,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks a plain text password and its hash version to check if the\n     * password matches\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 73,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 73,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 72,
                    "last-line": 101,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "checkToken",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "tokenKey",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 102,
                                "char": 51
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 102,
                            "char": 51
                        },
                        {
                            "type": "parameter",
                            "name": "tokenValue",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 102,
                                "char": 74
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 102,
                            "char": 74
                        },
                        {
                            "type": "parameter",
                            "name": "destroyIfValid",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 102,
                                "char": 102
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 102,
                            "char": 102
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 104,
                                    "char": 22
                                },
                                {
                                    "variable": "session",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 104,
                                    "char": 31
                                },
                                {
                                    "variable": "request",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 104,
                                    "char": 40
                                },
                                {
                                    "variable": "equals",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 104,
                                    "char": 48
                                },
                                {
                                    "variable": "userToken",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 104,
                                    "char": 59
                                },
                                {
                                    "variable": "knownToken",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 104,
                                    "char": 71
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 106,
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
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 106,
                                            "char": 54
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 106,
                                                "char": 44
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "container",
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 106,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 106,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 106,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 106,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 108,
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
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 108,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 108,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 108,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 108,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 108,
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
                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                "line": 110,
                                                                "char": 74
                                                            },
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 110,
                                                            "char": 74
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 111,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 111,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 111,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 112,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 114,
                            "char": 11
                        },
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
                                            "value": "SessionInterface",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 114,
                                            "char": 71
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "container",
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 114,
                                                "char": 52
                                            },
                                            "name": "getShared",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "session",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 114,
                                                        "char": 70
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 114,
                                                    "char": 70
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 114,
                                            "char": 71
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 114,
                                        "char": 71
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 114,
                                    "char": 71
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 116,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "tokenKey",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 116,
                                    "char": 22
                                },
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 116,
                                "char": 22
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "tokenKey",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "session",
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 117,
                                                    "char": 36
                                                },
                                                "name": "get",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                "line": 118,
                                                                "char": 22
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "tokenKeySessionId",
                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                "line": 119,
                                                                "char": 13
                                                            },
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 119,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 119,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 119,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 119,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 120,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 125,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "tokenKey",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 125,
                                    "char": 22
                                },
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 125,
                                "char": 22
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 126,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 127,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 129,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "tokenValue",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 129,
                                    "char": 24
                                },
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 129,
                                "char": 24
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "request",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 130,
                                                    "char": 37
                                                },
                                                "name": "getShared",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "request",
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 130,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 130,
                                                        "char": 55
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 130,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 130,
                                            "char": 56
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 135,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "userToken",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "request",
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 135,
                                                    "char": 37
                                                },
                                                "name": "getPost",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "tokenKey",
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 135,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 135,
                                                        "char": 54
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "string",
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 135,
                                                            "char": 62
                                                        },
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 135,
                                                        "char": 62
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 135,
                                                "char": 63
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 135,
                                            "char": 63
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 136,
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
                                            "variable": "userToken",
                                            "expr": {
                                                "type": "variable",
                                                "value": "tokenValue",
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 137,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 137,
                                            "char": 39
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 138,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 143,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "knownToken",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 143,
                                            "char": 31
                                        },
                                        "name": "getRequestToken",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 143,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 143,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 145,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "equals",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "hash_equals",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "knownToken",
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 145,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 145,
                                                "char": 44
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "userToken",
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 145,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 145,
                                                "char": 55
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 145,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 145,
                                    "char": 56
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 150,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "variable",
                                    "value": "equals",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 150,
                                    "char": 20
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "destroyIfValid",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 150,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 150,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 151,
                                            "char": 18
                                        },
                                        "name": "destroyToken",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 151,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 152,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 154,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "equals",
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 154,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 155,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check if the CSRF token sent in the request is the same that the current\n     * in session\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 103,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 103,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 102,
                    "last-line": 159,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "computeHmac",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 160,
                            "char": 44
                        },
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 160,
                            "char": 56
                        },
                        {
                            "type": "parameter",
                            "name": "algo",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 160,
                            "char": 69
                        },
                        {
                            "type": "parameter",
                            "name": "raw",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 160,
                                "char": 87
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 160,
                            "char": 87
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "hmac",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 162,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 164,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "hmac",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "hash_hmac",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "algo",
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 164,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 164,
                                                "char": 34
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "data",
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 164,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 164,
                                                "char": 40
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 164,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 164,
                                                "char": 45
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "raw",
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 164,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 164,
                                                "char": 50
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 164,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 164,
                                    "char": 51
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 166,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "variable",
                                        "value": "hmac",
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 166,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 166,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 166,
                                "char": 27
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
                                                    "type": "fcall",
                                                    "name": "sprintf",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "Unknown hashing algorithm: %s",
                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                "line": 169,
                                                                "char": 50
                                                            },
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 169,
                                                            "char": 50
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "algo",
                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                "line": 171,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 171,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 172,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 172,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 172,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 173,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 175,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "hmac",
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 175,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 176,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Computes a HMAC\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 161,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 161,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 160,
                    "last-line": 180,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "destroyToken",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 183,
                                    "char": 22
                                },
                                {
                                    "variable": "session",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 183,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 185,
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
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 185,
                                            "char": 54
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 185,
                                                "char": 44
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "container",
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 185,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 185,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 185,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 185,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 187,
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
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 187,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 187,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 187,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 187,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 187,
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
                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                "line": 189,
                                                                "char": 74
                                                            },
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 189,
                                                            "char": 74
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 190,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 190,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 190,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 191,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 193,
                            "char": 11
                        },
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
                                            "value": "SessionInterface",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 193,
                                            "char": 71
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "container",
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 193,
                                                "char": 52
                                            },
                                            "name": "getShared",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "session",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 193,
                                                        "char": 70
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 193,
                                                    "char": 70
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 193,
                                            "char": 71
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 193,
                                        "char": 71
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 193,
                                    "char": 71
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 195,
                            "char": 15
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "session",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 195,
                                    "char": 17
                                },
                                "name": "remove",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 195,
                                                "char": 30
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "tokenKeySessionId",
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 195,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 195,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 195,
                                        "char": 48
                                    }
                                ],
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 195,
                                "char": 49
                            },
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 196,
                            "char": 15
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "session",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 196,
                                    "char": 17
                                },
                                "name": "remove",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 196,
                                                "char": 30
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "tokenValueSessionId",
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 196,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 196,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 196,
                                        "char": 50
                                    }
                                ],
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 196,
                                "char": 51
                            },
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 198,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "token",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 198,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 198,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 199,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "tokenKey",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 199,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 199,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 200,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "requestToken",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 200,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 200,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 202,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 202,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 203,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Removes the value of the CSRF token and key from session\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Security",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 182,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 182,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 182,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 181,
                    "last-line": 207,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDefaultHash",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 210,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "defaultHash",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 210,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 210,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 211,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n      * Returns the default hash\n      *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 208,
                                "char": 45
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 209,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 209,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 208,
                    "last-line": 215,
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
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 218,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "container",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 218,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 218,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 219,
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
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 217,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 217,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 217,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 216,
                    "last-line": 223,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRandom",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 226,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "random",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 226,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 226,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 227,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a secure random number generator instance\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Random",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 225,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 225,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 225,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 224,
                    "last-line": 232,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRandomBytes",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 235,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "numberBytes",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 235,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 235,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 236,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a number of bytes to be generated by the openssl pseudo random\n     * generator\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 234,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 234,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 233,
                    "last-line": 240,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRequestToken",
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "empty",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 243,
                                        "char": 23
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "requestToken",
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 243,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 243,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 243,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 244,
                                            "char": 25
                                        },
                                        "name": "getSessionToken",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 244,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 245,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 247,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 247,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "requestToken",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 247,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 247,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 248,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the value of the CSRF token for the current request.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 242,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 242,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 241,
                    "last-line": 252,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getSessionToken",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 255,
                                    "char": 22
                                },
                                {
                                    "variable": "session",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 255,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 257,
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
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 257,
                                            "char": 54
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 257,
                                                "char": 44
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "container",
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 257,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 257,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 257,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 257,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 259,
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
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 259,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 259,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 259,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 259,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 259,
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
                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                "line": 261,
                                                                "char": 74
                                                            },
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 261,
                                                            "char": 74
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 262,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 262,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 262,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 263,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 265,
                            "char": 11
                        },
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
                                            "value": "SessionInterface",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 265,
                                            "char": 71
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "container",
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 265,
                                                "char": 52
                                            },
                                            "name": "getShared",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "session",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 265,
                                                        "char": 70
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 265,
                                                    "char": 70
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 265,
                                            "char": 71
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 265,
                                        "char": 71
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 265,
                                    "char": 71
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 267,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "session",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 267,
                                    "char": 24
                                },
                                "name": "get",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 267,
                                                "char": 34
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "tokenValueSessionId",
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 267,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 267,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 267,
                                        "char": 54
                                    }
                                ],
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 267,
                                "char": 55
                            },
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 268,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the value of the CSRF token in session\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 254,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 254,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 253,
                    "last-line": 273,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getSaltBytes",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "numberBytes",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "0",
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 274,
                                "char": 53
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 274,
                            "char": 53
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "safeBytes",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 276,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 278,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "numberBytes",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 278,
                                    "char": 25
                                },
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 278,
                                "char": 25
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "numberBytes",
                                            "expr": {
                                                "type": "cast",
                                                "left": "int",
                                                "right": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 279,
                                                        "char": 42
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "numberBytes",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 279,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 279,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 279,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 279,
                                            "char": 54
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 280,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 282,
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
                                            "variable": "safeBytes",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 283,
                                                        "char": 34
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "random",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 283,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 283,
                                                    "char": 42
                                                },
                                                "name": "base64Safe",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "numberBytes",
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 283,
                                                            "char": 65
                                                        },
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 283,
                                                        "char": 65
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 283,
                                                "char": 66
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 283,
                                            "char": 66
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 285,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "variable",
                                            "value": "safeBytes",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 285,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "greater-equal",
                                            "left": {
                                                "type": "fcall",
                                                "name": "strlen",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "safeBytes",
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 285,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 285,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 285,
                                                "char": 47
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "numberBytes",
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 285,
                                                "char": 61
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 285,
                                            "char": 61
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 285,
                                        "char": 61
                                    },
                                    "statements": [
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 287,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 288,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 290,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "safeBytes",
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 290,
                                "char": 25
                            },
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 291,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generate a >22-length pseudo random string to be used as salt for\n     * passwords\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 275,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 275,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 274,
                    "last-line": 296,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getToken",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 299,
                                    "char": 22
                                },
                                {
                                    "variable": "session",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 299,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 301,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 301,
                                    "char": 19
                                },
                                "right": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 301,
                                        "char": 26
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "token",
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 301,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 301,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 301,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "requestToken",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 302,
                                                    "char": 43
                                                },
                                                "name": "getSessionToken",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 302,
                                                "char": 61
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 302,
                                            "char": 61
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 303,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "token",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 303,
                                                        "char": 36
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "random",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 303,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 303,
                                                    "char": 44
                                                },
                                                "name": "base64Safe",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                "line": 303,
                                                                "char": 61
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "numberBytes",
                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                "line": 303,
                                                                "char": 73
                                                            },
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 303,
                                                            "char": 73
                                                        },
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 303,
                                                        "char": 73
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 303,
                                                "char": 74
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 303,
                                            "char": 74
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 305,
                                    "char": 15
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
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 305,
                                                    "char": 58
                                                },
                                                "right": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 305,
                                                        "char": 48
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "container",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 305,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 305,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 305,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 305,
                                            "char": 58
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 307,
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
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 307,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 307,
                                                "char": 43
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 307,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 307,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 307,
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
                                                                        "value": "the 'session' service",
                                                                        "file": "\/app\/phalcon\/Security.zep",
                                                                        "line": 309,
                                                                        "char": 78
                                                                    },
                                                                    "file": "\/app\/phalcon\/Security.zep",
                                                                    "line": 309,
                                                                    "char": 78
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 310,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 310,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 310,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 311,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 313,
                                    "char": 15
                                },
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
                                                    "value": "SessionInterface",
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 313,
                                                    "char": 75
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "container",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 313,
                                                        "char": 56
                                                    },
                                                    "name": "getShared",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "session",
                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                "line": 313,
                                                                "char": 74
                                                            },
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 313,
                                                            "char": 74
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 313,
                                                    "char": 75
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 313,
                                                "char": 75
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 313,
                                            "char": 75
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 315,
                                    "char": 19
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "session",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 315,
                                            "char": 21
                                        },
                                        "name": "set",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 316,
                                                        "char": 22
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "tokenValueSessionId",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 316,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 316,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 316,
                                                "char": 42
                                            },
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 317,
                                                        "char": 22
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "token",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 318,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 318,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 318,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 318,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 319,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 321,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 321,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "token",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 321,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 321,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 322,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates a pseudo random token value to be used as input's value in a\n     * CSRF check\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 298,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 298,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 297,
                    "last-line": 327,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getTokenKey",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 330,
                                    "char": 22
                                },
                                {
                                    "variable": "session",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 330,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 332,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 332,
                                    "char": 19
                                },
                                "right": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 332,
                                        "char": 26
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "tokenKey",
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 332,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 332,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 332,
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
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 333,
                                                    "char": 58
                                                },
                                                "right": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 333,
                                                        "char": 48
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "container",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 333,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 333,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 333,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 333,
                                            "char": 58
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 335,
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
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 335,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 335,
                                                "char": 43
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 335,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 335,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 335,
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
                                                                        "value": "the 'session' service",
                                                                        "file": "\/app\/phalcon\/Security.zep",
                                                                        "line": 337,
                                                                        "char": 78
                                                                    },
                                                                    "file": "\/app\/phalcon\/Security.zep",
                                                                    "line": 337,
                                                                    "char": 78
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 338,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 338,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 338,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 339,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 341,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "tokenKey",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 341,
                                                        "char": 39
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "random",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 341,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 341,
                                                    "char": 47
                                                },
                                                "name": "base64Safe",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                "line": 341,
                                                                "char": 64
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "numberBytes",
                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                "line": 341,
                                                                "char": 76
                                                            },
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 341,
                                                            "char": 76
                                                        },
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 341,
                                                        "char": 76
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 341,
                                                "char": 77
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 341,
                                            "char": 77
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 343,
                                    "char": 15
                                },
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
                                                    "value": "SessionInterface",
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 343,
                                                    "char": 75
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "container",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 343,
                                                        "char": 56
                                                    },
                                                    "name": "getShared",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "session",
                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                "line": 343,
                                                                "char": 74
                                                            },
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 343,
                                                            "char": 74
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 343,
                                                    "char": 75
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 343,
                                                "char": 75
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 343,
                                            "char": 75
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 345,
                                    "char": 19
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "session",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 345,
                                            "char": 21
                                        },
                                        "name": "set",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 346,
                                                        "char": 22
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "tokenKeySessionId",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 346,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 346,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 346,
                                                "char": 40
                                            },
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 347,
                                                        "char": 22
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "tokenKey",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 348,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 348,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 348,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 348,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 349,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 351,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 351,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "tokenKey",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 351,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 351,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 352,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates a pseudo random token key to be used as input's name in a CSRF\n     * check\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 329,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 329,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 328,
                    "last-line": 356,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "hash",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "password",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 357,
                            "char": 41
                        },
                        {
                            "type": "parameter",
                            "name": "workFactor",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "0",
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 357,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 357,
                            "char": 61
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "int",
                            "variables": [
                                {
                                    "variable": "hash",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 359,
                                    "char": 17
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 360,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "variant",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 360,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 361,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "saltBytes",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 361,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 363,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "workFactor",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 363,
                                    "char": 24
                                },
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 363,
                                "char": 24
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "workFactor",
                                            "expr": {
                                                "type": "cast",
                                                "left": "int",
                                                "right": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 364,
                                                        "char": 41
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "workFactor",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 364,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 364,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 364,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 364,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 365,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 367,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "hash",
                                    "expr": {
                                        "type": "cast",
                                        "left": "int",
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 367,
                                                "char": 31
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "defaultHash",
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 367,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 367,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 367,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 367,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 369,
                            "char": 14
                        },
                        {
                            "type": "switch",
                            "expr": {
                                "type": "variable",
                                "value": "hash",
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 369,
                                "char": 21
                            },
                            "clauses": [
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 371,
                                            "char": 40
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "CRYPT_BLOWFISH_A",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 371,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 371,
                                        "char": 40
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "variant",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "a",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 372,
                                                        "char": 32
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 372,
                                                    "char": 32
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 373,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 375,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 375,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 375,
                                            "char": 40
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "CRYPT_BLOWFISH_X",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 375,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 375,
                                        "char": 40
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "variant",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "x",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 376,
                                                        "char": 32
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 376,
                                                    "char": 32
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 377,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 379,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 379,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 379,
                                            "char": 40
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "CRYPT_BLOWFISH_Y",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 379,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 379,
                                        "char": 40
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "variant",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "y",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 380,
                                                        "char": 32
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 380,
                                                    "char": 32
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 381,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 383,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 383,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 383,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "CRYPT_MD5",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 383,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 383,
                                        "char": 33
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "variant",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "1",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 384,
                                                        "char": 32
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 384,
                                                    "char": 32
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 385,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 387,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 387,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 387,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "CRYPT_SHA256",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 387,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 387,
                                        "char": 36
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "variant",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "5",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 388,
                                                        "char": 32
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 388,
                                                    "char": 32
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 389,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 391,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 391,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 391,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "CRYPT_SHA512",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 391,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 391,
                                        "char": 36
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "variant",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "6",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 392,
                                                        "char": 32
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 392,
                                                    "char": 32
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 393,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 395,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 395,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 395,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "CRYPT_DEFAULT",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 395,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 395,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 396,
                                    "char": 19
                                },
                                {
                                    "type": "default",
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "variant",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "y",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 397,
                                                        "char": 32
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 397,
                                                    "char": 32
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 398,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 399,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 399,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 401,
                            "char": 14
                        },
                        {
                            "type": "switch",
                            "expr": {
                                "type": "variable",
                                "value": "hash",
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 401,
                                "char": 21
                            },
                            "clauses": [
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 403,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "CRYPT_STD_DES",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 403,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 403,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 404,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 404,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "CRYPT_EXT_DES",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 404,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 404,
                                        "char": 37
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "hash",
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 411,
                                                    "char": 26
                                                },
                                                "right": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "self",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 411,
                                                        "char": 48
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "CRYPT_EXT_DES",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 411,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 411,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 411,
                                                "char": 48
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "saltBytes",
                                                            "expr": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "string",
                                                                    "value": "_",
                                                                    "file": "\/app\/phalcon\/Security.zep",
                                                                    "line": 412,
                                                                    "char": 39
                                                                },
                                                                "right": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Security.zep",
                                                                        "line": 412,
                                                                        "char": 46
                                                                    },
                                                                    "name": "getSaltBytes",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "int",
                                                                                "value": "8",
                                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                                "line": 412,
                                                                                "char": 61
                                                                            },
                                                                            "file": "\/app\/phalcon\/Security.zep",
                                                                            "line": 412,
                                                                            "char": 61
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Security.zep",
                                                                    "line": 412,
                                                                    "char": 62
                                                                },
                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                "line": 412,
                                                                "char": 62
                                                            },
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 412,
                                                            "char": 62
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 413,
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
                                                            "variable": "saltBytes",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Security.zep",
                                                                    "line": 414,
                                                                    "char": 42
                                                                },
                                                                "name": "getSaltBytes",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "int",
                                                                            "value": "2",
                                                                            "file": "\/app\/phalcon\/Security.zep",
                                                                            "line": 414,
                                                                            "char": 57
                                                                        },
                                                                        "file": "\/app\/phalcon\/Security.zep",
                                                                        "line": 414,
                                                                        "char": 57
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                "line": 414,
                                                                "char": 58
                                                            },
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 414,
                                                            "char": 58
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 415,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 417,
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
                                                            "value": "saltBytes",
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 417,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 417,
                                                        "char": 47
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "string",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 417,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 417,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 417,
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
                                                                    "type": "string",
                                                                    "value": "Unable to get random bytes for the salt",
                                                                    "file": "\/app\/phalcon\/Security.zep",
                                                                    "line": 420,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                "line": 420,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 420,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 421,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 423,
                                            "char": 22
                                        },
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "crypt",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "password",
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 423,
                                                            "char": 38
                                                        },
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 423,
                                                        "char": 38
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "saltBytes",
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 423,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 423,
                                                        "char": 49
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 423,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 425,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 425,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 425,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "CRYPT_MD5",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 425,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 425,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 426,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 426,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "CRYPT_SHA256",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 426,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 426,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 427,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 427,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "CRYPT_SHA512",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 427,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 427,
                                        "char": 36
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "saltBytes",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 434,
                                                            "char": 38
                                                        },
                                                        "name": "getSaltBytes",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "ternary",
                                                                    "left": {
                                                                        "type": "equals",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "hash",
                                                                            "file": "\/app\/phalcon\/Security.zep",
                                                                            "line": 434,
                                                                            "char": 58
                                                                        },
                                                                        "right": {
                                                                            "type": "static-constant-access",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "self",
                                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                                "line": 434,
                                                                                "char": 76
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "CRYPT_MD5",
                                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                                "line": 434,
                                                                                "char": 76
                                                                            },
                                                                            "file": "\/app\/phalcon\/Security.zep",
                                                                            "line": 434,
                                                                            "char": 76
                                                                        },
                                                                        "file": "\/app\/phalcon\/Security.zep",
                                                                        "line": 434,
                                                                        "char": 76
                                                                    },
                                                                    "right": {
                                                                        "type": "int",
                                                                        "value": "12",
                                                                        "file": "\/app\/phalcon\/Security.zep",
                                                                        "line": 434,
                                                                        "char": 81
                                                                    },
                                                                    "extra": {
                                                                        "type": "int",
                                                                        "value": "16",
                                                                        "file": "\/app\/phalcon\/Security.zep",
                                                                        "line": 434,
                                                                        "char": 85
                                                                    },
                                                                    "file": "\/app\/phalcon\/Security.zep",
                                                                    "line": 434,
                                                                    "char": 85
                                                                },
                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                "line": 434,
                                                                "char": 85
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 434,
                                                        "char": 86
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 434,
                                                    "char": 86
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 436,
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
                                                            "value": "saltBytes",
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 436,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 436,
                                                        "char": 47
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "string",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 436,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 436,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 436,
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
                                                                    "type": "string",
                                                                    "value": "Unable to get random bytes for the salt",
                                                                    "file": "\/app\/phalcon\/Security.zep",
                                                                    "line": 439,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                "line": 439,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 439,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 440,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 442,
                                            "char": 22
                                        },
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "crypt",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "password",
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 443,
                                                            "char": 29
                                                        },
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 443,
                                                        "char": 29
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "string",
                                                                            "value": "$",
                                                                            "file": "\/app\/phalcon\/Security.zep",
                                                                            "line": 443,
                                                                            "char": 33
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "variant",
                                                                            "file": "\/app\/phalcon\/Security.zep",
                                                                            "line": 443,
                                                                            "char": 43
                                                                        },
                                                                        "file": "\/app\/phalcon\/Security.zep",
                                                                        "line": 443,
                                                                        "char": 43
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "$",
                                                                        "file": "\/app\/phalcon\/Security.zep",
                                                                        "line": 443,
                                                                        "char": 48
                                                                    },
                                                                    "file": "\/app\/phalcon\/Security.zep",
                                                                    "line": 443,
                                                                    "char": 48
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "saltBytes",
                                                                    "file": "\/app\/phalcon\/Security.zep",
                                                                    "line": 443,
                                                                    "char": 60
                                                                },
                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                "line": 443,
                                                                "char": 60
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "$",
                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                "line": 444,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 444,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 444,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 444,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 446,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 446,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 446,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "CRYPT_DEFAULT",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 446,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 446,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 447,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 447,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "CRYPT_BLOWFISH",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 447,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 447,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 448,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 448,
                                            "char": 40
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "CRYPT_BLOWFISH_X",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 448,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 448,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 449,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 449,
                                            "char": 40
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "CRYPT_BLOWFISH_Y",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 449,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 449,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 450,
                                    "char": 19
                                },
                                {
                                    "type": "default",
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "saltBytes",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 463,
                                                            "char": 38
                                                        },
                                                        "name": "getSaltBytes",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "int",
                                                                    "value": "22",
                                                                    "file": "\/app\/phalcon\/Security.zep",
                                                                    "line": 463,
                                                                    "char": 54
                                                                },
                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                "line": 463,
                                                                "char": 54
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 463,
                                                        "char": 55
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 463,
                                                    "char": 55
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 465,
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
                                                            "value": "saltBytes",
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 465,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 465,
                                                        "char": 47
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "string",
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 465,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 465,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 465,
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
                                                                    "type": "string",
                                                                    "value": "Unable to get random bytes for the salt",
                                                                    "file": "\/app\/phalcon\/Security.zep",
                                                                    "line": 468,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                "line": 468,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 468,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 469,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 471,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "less",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "workFactor",
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 471,
                                                    "char": 31
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "4",
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 471,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 471,
                                                "char": 35
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "workFactor",
                                                            "expr": {
                                                                "type": "int",
                                                                "value": "4",
                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                "line": 472,
                                                                "char": 39
                                                            },
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 472,
                                                            "char": 39
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 473,
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
                                                            "value": "workFactor",
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 473,
                                                            "char": 37
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "31",
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 473,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 473,
                                                        "char": 42
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "workFactor",
                                                                    "expr": {
                                                                        "type": "int",
                                                                        "value": "31",
                                                                        "file": "\/app\/phalcon\/Security.zep",
                                                                        "line": 474,
                                                                        "char": 40
                                                                    },
                                                                    "file": "\/app\/phalcon\/Security.zep",
                                                                    "line": 474,
                                                                    "char": 40
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 475,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Security.zep",
                                                    "line": 477,
                                                    "char": 22
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 477,
                                            "char": 22
                                        },
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "crypt",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "password",
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 478,
                                                            "char": 29
                                                        },
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 478,
                                                        "char": 29
                                                    },
                                                    {
                                                        "parameter": {
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
                                                                                    "value": "$2",
                                                                                    "file": "\/app\/phalcon\/Security.zep",
                                                                                    "line": 479,
                                                                                    "char": 24
                                                                                },
                                                                                "right": {
                                                                                    "type": "variable",
                                                                                    "value": "variant",
                                                                                    "file": "\/app\/phalcon\/Security.zep",
                                                                                    "line": 479,
                                                                                    "char": 34
                                                                                },
                                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                                "line": 479,
                                                                                "char": 34
                                                                            },
                                                                            "right": {
                                                                                "type": "string",
                                                                                "value": "$",
                                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                                "line": 479,
                                                                                "char": 38
                                                                            },
                                                                            "file": "\/app\/phalcon\/Security.zep",
                                                                            "line": 479,
                                                                            "char": 38
                                                                        },
                                                                        "right": {
                                                                            "type": "fcall",
                                                                            "name": "sprintf",
                                                                            "call-type": 1,
                                                                            "parameters": [
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "string",
                                                                                        "value": "%02s",
                                                                                        "file": "\/app\/phalcon\/Security.zep",
                                                                                        "line": 479,
                                                                                        "char": 52
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Security.zep",
                                                                                    "line": 479,
                                                                                    "char": 52
                                                                                },
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "variable",
                                                                                        "value": "workFactor",
                                                                                        "file": "\/app\/phalcon\/Security.zep",
                                                                                        "line": 479,
                                                                                        "char": 64
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Security.zep",
                                                                                    "line": 479,
                                                                                    "char": 64
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Security.zep",
                                                                            "line": 479,
                                                                            "char": 66
                                                                        },
                                                                        "file": "\/app\/phalcon\/Security.zep",
                                                                        "line": 479,
                                                                        "char": 66
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "$",
                                                                        "file": "\/app\/phalcon\/Security.zep",
                                                                        "line": 479,
                                                                        "char": 70
                                                                    },
                                                                    "file": "\/app\/phalcon\/Security.zep",
                                                                    "line": 479,
                                                                    "char": 70
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "saltBytes",
                                                                    "file": "\/app\/phalcon\/Security.zep",
                                                                    "line": 479,
                                                                    "char": 82
                                                                },
                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                "line": 479,
                                                                "char": 82
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "$",
                                                                "file": "\/app\/phalcon\/Security.zep",
                                                                "line": 480,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Security.zep",
                                                            "line": 480,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Security.zep",
                                                        "line": 480,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Security.zep",
                                                "line": 480,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 481,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 481,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 483,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "string",
                                "value": "",
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 483,
                                "char": 16
                            },
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 484,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Creates a password hash using bcrypt with a pseudo random salt\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 358,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 358,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 357,
                    "last-line": 488,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isLegacyHash",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "passwordHash",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 489,
                            "char": 53
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "starts_with",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "passwordHash",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 491,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 491,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "$2a$",
                                            "file": "\/app\/phalcon\/Security.zep",
                                            "line": 491,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 491,
                                        "char": 46
                                    }
                                ],
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 491,
                                "char": 47
                            },
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 492,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks if a password hash is a valid bcrypt's hash\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 490,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 490,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 489,
                    "last-line": 496,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDefaultHash",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "defaultHash",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 497,
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
                                    "property": "defaultHash",
                                    "expr": {
                                        "type": "variable",
                                        "value": "defaultHash",
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 499,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 499,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 501,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 501,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 502,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n      * Sets the default hash\n      *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Security",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 498,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 498,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 498,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 497,
                    "last-line": 506,
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
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 507,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 507,
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
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 509,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 509,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 510,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the dependency injector\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 508,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 507,
                    "last-line": 515,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setRandomBytes",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "randomBytes",
                            "const": 0,
                            "data-type": "long",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 516,
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
                                    "property": "numberBytes",
                                    "expr": {
                                        "type": "variable",
                                        "value": "randomBytes",
                                        "file": "\/app\/phalcon\/Security.zep",
                                        "line": 518,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 518,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 520,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 520,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Security.zep",
                            "line": 521,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a number of bytes to be generated by the openssl pseudo random\n     * generator\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Security",
                                    "file": "\/app\/phalcon\/Security.zep",
                                    "line": 517,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Security.zep",
                                "line": 517,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 517,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 516,
                    "last-line": 522,
                    "char": 19
                }
            ],
            "constants": [
                {
                    "type": "const",
                    "name": "CRYPT_DEFAULT",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 38,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 39,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "CRYPT_BLOWFISH",
                    "default": {
                        "type": "int",
                        "value": "4",
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 39,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 40,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "CRYPT_BLOWFISH_A",
                    "default": {
                        "type": "int",
                        "value": "5",
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 40,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 41,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "CRYPT_BLOWFISH_X",
                    "default": {
                        "type": "int",
                        "value": "6",
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 41,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 42,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "CRYPT_BLOWFISH_Y",
                    "default": {
                        "type": "int",
                        "value": "7",
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 42,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 43,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "CRYPT_EXT_DES",
                    "default": {
                        "type": "int",
                        "value": "2",
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 43,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 44,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "CRYPT_MD5",
                    "default": {
                        "type": "int",
                        "value": "3",
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 44,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 45,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "CRYPT_SHA256",
                    "default": {
                        "type": "int",
                        "value": "8",
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 45,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 46,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "CRYPT_SHA512",
                    "default": {
                        "type": "int",
                        "value": "9",
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 46,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 47,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "CRYPT_STD_DES",
                    "default": {
                        "type": "int",
                        "value": "1",
                        "file": "\/app\/phalcon\/Security.zep",
                        "line": 47,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Security.zep",
                    "line": 49,
                    "char": 13
                }
            ],
            "file": "\/app\/phalcon\/Security.zep",
            "line": 36,
            "char": 5
        },
        "file": "\/app\/phalcon\/Security.zep",
        "line": 36,
        "char": 5
    }
]