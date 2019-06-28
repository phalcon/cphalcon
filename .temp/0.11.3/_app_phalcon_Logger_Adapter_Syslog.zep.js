[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Logger\\Adapter",
        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "LogicException",
                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                "line": 13,
                "char": 19
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\Logger",
                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                "line": 14,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\Adapter",
                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                "line": 15,
                "char": 27
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\Exception",
                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                "line": 16,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\Formatter\\FormatterInterface",
                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                "line": 17,
                "char": 48
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\Item",
                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                "line": 18,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
        "line": 42,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Logger\\Adapter\\Syslog\n *\n * Sends logs to the system logger\n *\n * ```php\n * use Phalcon\\Logger;\n * use Phalcon\\Logger\\Adapter\\Syslog;\n *\n * \/\/ LOG_USER is the only valid log type under Windows operating systems\n * $logger = new Syslog(\n *     \"ident\",\n *     [\n *         \"option\"   => LOG_CONS | LOG_NDELAY | LOG_PID,\n *         \"facility\" => LOG_USER,\n *     ]\n * );\n *\n * $logger->log(\"This is a message\");\n * $logger->log(Logger::ERROR, \"This is an error\");\n * $logger->error(\"This is another error\");\n *```\n *",
        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
        "line": 43,
        "char": 5
    },
    {
        "type": "class",
        "name": "Syslog",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractAdapter",
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "defaultFormatter",
                    "default": {
                        "type": "string",
                        "value": "Syslog",
                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                        "line": 50,
                        "char": 40
                    },
                    "docblock": "**\n     * Name of the default formatter class\n     *\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                    "line": 54,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "facility",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                        "line": 55,
                        "char": 27
                    },
                    "docblock": "**\n     * @var int\n     *",
                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                    "line": 59,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "name",
                    "default": {
                        "type": "string",
                        "value": "",
                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                        "line": 60,
                        "char": 22
                    },
                    "docblock": "**\n     * @var string\n     *",
                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                    "line": 64,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "opened",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                        "line": 65,
                        "char": 29
                    },
                    "docblock": "**\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                    "line": 69,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "option",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                        "line": 70,
                        "char": 25
                    },
                    "docblock": "**\n     * @var int\n     *",
                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                    "line": 74,
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
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                            "line": 75,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                "line": 75,
                                "char": 65
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                            "line": 75,
                            "char": 65
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "option",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 77,
                                    "char": 19
                                },
                                {
                                    "variable": "facility",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 77,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                            "line": 79,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "option",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 79,
                                    "char": 42
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                        "line": 79,
                                        "char": 33
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "option",
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                        "line": 79,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 79,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                "line": 79,
                                "char": 42
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "option",
                                            "expr": {
                                                "type": "constant",
                                                "value": "LOG_ODELAY",
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                "line": 80,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                            "line": 80,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 81,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                            "line": 83,
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
                                        "value": "facility",
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                        "line": 83,
                                        "char": 47
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                            "line": 83,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "facility",
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                            "line": 83,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                        "line": 83,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 83,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                "line": 83,
                                "char": 47
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "facility",
                                            "expr": {
                                                "type": "constant",
                                                "value": "LOG_USER",
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                "line": 84,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                            "line": 84,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 85,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                            "line": 87,
                            "char": 11
                        },
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
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                        "line": 87,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 87,
                                    "char": 34
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "facility",
                                    "expr": {
                                        "type": "variable",
                                        "value": "facility",
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                        "line": 88,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 88,
                                    "char": 38
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "option",
                                    "expr": {
                                        "type": "variable",
                                        "value": "option",
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                        "line": 89,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 89,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                            "line": 90,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Logger\\Adapter\\Syslog constructor\n     *",
                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                    "line": 75,
                    "last-line": 94,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "close",
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
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                        "line": 97,
                                        "char": 18
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "opened",
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                        "line": 97,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 97,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                "line": 97,
                                "char": 26
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                        "line": 98,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 99,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                            "line": 101,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "closelog",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                "line": 101,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                            "line": 102,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n      * Closes the logger\n      *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                "line": 96,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                        "line": 96,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                    "line": 95,
                    "last-line": 106,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "process",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "item",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Item",
                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                "line": 107,
                                "char": 39
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                            "line": 107,
                            "char": 40
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 109,
                                    "char": 17
                                },
                                {
                                    "variable": "facility",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 109,
                                    "char": 27
                                },
                                {
                                    "variable": "formatter",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 109,
                                    "char": 38
                                },
                                {
                                    "variable": "level",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 109,
                                    "char": 45
                                },
                                {
                                    "variable": "message",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 109,
                                    "char": 54
                                },
                                {
                                    "variable": "option",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 109,
                                    "char": 62
                                },
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 109,
                                    "char": 70
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                            "line": 110,
                            "char": 12
                        },
                        {
                            "type": "declare",
                            "data-type": "bool",
                            "variables": [
                                {
                                    "variable": "opened",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 110,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                            "line": 112,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "formatter",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                            "line": 112,
                                            "char": 30
                                        },
                                        "name": "getFormatter",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                        "line": 112,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 112,
                                    "char": 45
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "message",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "formatter",
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                            "line": 113,
                                            "char": 35
                                        },
                                        "name": "format",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "item",
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                    "line": 113,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                "line": 113,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                        "line": 113,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 113,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                            "line": 115,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "message",
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                        "line": 115,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 115,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 115,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                "line": 115,
                                "char": 37
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
                                                    "value": "The formatted message is not valid",
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                    "line": 116,
                                                    "char": 67
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                "line": 116,
                                                "char": 67
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                        "line": 116,
                                        "char": 68
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 117,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                            "line": 119,
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
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                            "line": 119,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                            "line": 119,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                        "line": 119,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 119,
                                    "char": 34
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "facility",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                            "line": 120,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "facility",
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                            "line": 120,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                        "line": 120,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 120,
                                    "char": 38
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "option",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                            "line": 121,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "option",
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                            "line": 121,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                        "line": 121,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 121,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                            "line": 123,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "result",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "openlog",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                    "line": 123,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                "line": 123,
                                                "char": 34
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "option",
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                    "line": 123,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                "line": 123,
                                                "char": 42
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "facility",
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                    "line": 123,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                "line": 123,
                                                "char": 52
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                        "line": 123,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 123,
                                    "char": 53
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                            "line": 125,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "list",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "variable",
                                        "value": "result",
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                        "line": 125,
                                        "char": 20
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 125,
                                    "char": 20
                                },
                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                "line": 125,
                                "char": 22
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "LogicException",
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
                                                                "value": "Cannot open syslog for name [%s] and facility [%s]",
                                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                                "line": 128,
                                                                "char": 71
                                                            },
                                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                            "line": 128,
                                                            "char": 71
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "name",
                                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                                "line": 129,
                                                                "char": 25
                                                            },
                                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                            "line": 129,
                                                            "char": 25
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "facility",
                                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                                "line": 131,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                            "line": 131,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                    "line": 132,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                "line": 132,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                        "line": 132,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 133,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                            "line": 135,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "opened",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                        "line": 135,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 135,
                                    "char": 32
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "opened",
                                    "expr": {
                                        "type": "variable",
                                        "value": "opened",
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                        "line": 136,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 136,
                                    "char": 34
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "level",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                            "line": 137,
                                            "char": 33
                                        },
                                        "name": "logLevelToSyslog",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "message",
                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                        "line": 137,
                                                        "char": 58
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "1",
                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                        "line": 137,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                    "line": 137,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                "line": 137,
                                                "char": 61
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                        "line": 137,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 137,
                                    "char": 62
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                            "line": 139,
                            "char": 14
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "syslog",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "level",
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                            "line": 139,
                                            "char": 21
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                        "line": 139,
                                        "char": 21
                                    },
                                    {
                                        "parameter": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "message",
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                "line": 139,
                                                "char": 30
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "1",
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                "line": 139,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                            "line": 139,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                        "line": 139,
                                        "char": 33
                                    }
                                ],
                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                "line": 139,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                            "line": 140,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Processes the message i.e. writes it to the syslog\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                        "line": 108,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                    "line": 107,
                    "last-line": 144,
                    "char": 19
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "logLevelToSyslog",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "level",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                            "line": 145,
                            "char": 51
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 147,
                                    "char": 19
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                            "line": 148,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "levels",
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 148,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                            "line": 150,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "levels",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "key": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "Logger",
                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                        "line": 151,
                                                        "char": 31
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "ALERT",
                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                        "line": 151,
                                                        "char": 31
                                                    },
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                    "line": 151,
                                                    "char": 31
                                                },
                                                "value": {
                                                    "type": "constant",
                                                    "value": "LOG_ALERT",
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                    "line": 151,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                "line": 151,
                                                "char": 42
                                            },
                                            {
                                                "key": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "Logger",
                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                        "line": 152,
                                                        "char": 31
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "CRITICAL",
                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                        "line": 152,
                                                        "char": 31
                                                    },
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                    "line": 152,
                                                    "char": 31
                                                },
                                                "value": {
                                                    "type": "constant",
                                                    "value": "LOG_CRIT",
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                    "line": 152,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                "line": 152,
                                                "char": 41
                                            },
                                            {
                                                "key": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "Logger",
                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                        "line": 153,
                                                        "char": 31
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "CUSTOM",
                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                        "line": 153,
                                                        "char": 31
                                                    },
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                    "line": 153,
                                                    "char": 31
                                                },
                                                "value": {
                                                    "type": "constant",
                                                    "value": "LOG_ERR",
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                    "line": 153,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                "line": 153,
                                                "char": 40
                                            },
                                            {
                                                "key": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "Logger",
                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                        "line": 154,
                                                        "char": 31
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "DEBUG",
                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                        "line": 154,
                                                        "char": 31
                                                    },
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                    "line": 154,
                                                    "char": 31
                                                },
                                                "value": {
                                                    "type": "constant",
                                                    "value": "LOG_DEBUG",
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                    "line": 154,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                "line": 154,
                                                "char": 42
                                            },
                                            {
                                                "key": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "Logger",
                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                        "line": 155,
                                                        "char": 31
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "EMERGENCY",
                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                        "line": 155,
                                                        "char": 31
                                                    },
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                    "line": 155,
                                                    "char": 31
                                                },
                                                "value": {
                                                    "type": "constant",
                                                    "value": "LOG_EMERG",
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                    "line": 155,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                "line": 155,
                                                "char": 42
                                            },
                                            {
                                                "key": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "Logger",
                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                        "line": 156,
                                                        "char": 31
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "ERROR",
                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                        "line": 156,
                                                        "char": 31
                                                    },
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                    "line": 156,
                                                    "char": 31
                                                },
                                                "value": {
                                                    "type": "constant",
                                                    "value": "LOG_ERR",
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                    "line": 156,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                "line": 156,
                                                "char": 40
                                            },
                                            {
                                                "key": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "Logger",
                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                        "line": 157,
                                                        "char": 31
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "INFO",
                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                        "line": 157,
                                                        "char": 31
                                                    },
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                    "line": 157,
                                                    "char": 31
                                                },
                                                "value": {
                                                    "type": "constant",
                                                    "value": "LOG_INFO",
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                    "line": 157,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                "line": 157,
                                                "char": 41
                                            },
                                            {
                                                "key": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "Logger",
                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                        "line": 158,
                                                        "char": 31
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "NOTICE",
                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                        "line": 158,
                                                        "char": 31
                                                    },
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                    "line": 158,
                                                    "char": 31
                                                },
                                                "value": {
                                                    "type": "constant",
                                                    "value": "LOG_NOTICE",
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                    "line": 158,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                "line": 158,
                                                "char": 43
                                            },
                                            {
                                                "key": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "Logger",
                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                        "line": 159,
                                                        "char": 31
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "WARNING",
                                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                        "line": 159,
                                                        "char": 31
                                                    },
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                    "line": 159,
                                                    "char": 31
                                                },
                                                "value": {
                                                    "type": "constant",
                                                    "value": "LOG_WARNING",
                                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                    "line": 160,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                "line": 160,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                        "line": 160,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 160,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                            "line": 162,
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
                                        "value": "result",
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                        "line": 162,
                                        "char": 41
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "levels",
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                            "line": 162,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "level",
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                            "line": 162,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                        "line": 162,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 162,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                "line": 162,
                                "char": 41
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "result",
                                            "expr": {
                                                "type": "constant",
                                                "value": "LOG_ERR",
                                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                                "line": 163,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                            "line": 163,
                                            "char": 33
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                    "line": 164,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                            "line": 166,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "result",
                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                "line": 166,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                            "line": 167,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Translates a Logger level to a Syslog level\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                                "line": 146,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                        "line": 146,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
                    "line": 145,
                    "last-line": 168,
                    "char": 20
                }
            ],
            "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
            "line": 43,
            "char": 5
        },
        "file": "\/app\/phalcon\/Logger\/Adapter\/Syslog.zep",
        "line": 43,
        "char": 5
    }
]