[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon.\n *\n * (c) Phalcon Team <team@phalcon.com>\n *\n * For the full copyright and license information, please view the LICENSE\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Session",
        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "InvalidArgumentException",
                "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                "line": 13,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "RuntimeException",
                "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                "line": 14,
                "char": 21
            }
        ],
        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "SessionHandlerInterface",
                "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                "line": 15,
                "char": 28
            }
        ],
        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
        "line": 21,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Session\n *\n * Interface for the Phalcon\\Session\\Manager\n *",
        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
        "line": 22,
        "char": 9
    },
    {
        "type": "interface",
        "name": "ManagerInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__get",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                            "line": 31,
                            "char": 37
                        }
                    ],
                    "docblock": "**\n     * Alias: Gets a session variable from an application context\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                        "line": 31,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                    "line": 31,
                    "last-line": 35,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__isset",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                            "line": 36,
                            "char": 39
                        }
                    ],
                    "docblock": "**\n     * Alias: Check whether a session variable is set in an application context\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                                "line": 36,
                                "char": 48
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                        "line": 36,
                        "char": 48
                    },
                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                    "line": 36,
                    "last-line": 40,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__set",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                            "line": 41,
                            "char": 37
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                            "line": 41,
                            "char": 48
                        }
                    ],
                    "docblock": "**\n     * Alias: Sets a session variable in an application context\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                        "line": 41,
                        "char": 57
                    },
                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                    "line": 41,
                    "last-line": 45,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__unset",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                            "line": 46,
                            "char": 39
                        }
                    ],
                    "docblock": "**\n     * Alias: Removes a session variable from an application context\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                        "line": 46,
                        "char": 48
                    },
                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                    "line": 46,
                    "last-line": 50,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "exists",
                    "docblock": "**\n     * Check whether the session has been started\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                                "line": 51,
                                "char": 37
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                        "line": 51,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                    "line": 51,
                    "last-line": 55,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "destroy",
                    "docblock": "**\n     * Destroy\/end a session\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                        "line": 56,
                        "char": 38
                    },
                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                    "line": 56,
                    "last-line": 60,
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
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                            "line": 61,
                            "char": 35
                        },
                        {
                            "type": "parameter",
                            "name": "defaultValue",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                                "line": 61,
                                "char": 60
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                            "line": 61,
                            "char": 60
                        },
                        {
                            "type": "parameter",
                            "name": "remove",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                                "line": 61,
                                "char": 81
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                            "line": 61,
                            "char": 81
                        }
                    ],
                    "docblock": "**\n     * Gets a session variable from an application context\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                                "line": 61,
                                "char": 89
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                        "line": 61,
                        "char": 89
                    },
                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                    "line": 61,
                    "last-line": 65,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getId",
                    "docblock": "**\n     * Returns the session id\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                                "line": 66,
                                "char": 38
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                        "line": 66,
                        "char": 38
                    },
                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                    "line": 66,
                    "last-line": 70,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHandler",
                    "docblock": "**\n     * Returns the stored session handler\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "SessionHandlerInterface",
                                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                                    "line": 71,
                                    "char": 62
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                                "line": 71,
                                "char": 62
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                        "line": 71,
                        "char": 62
                    },
                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                    "line": 71,
                    "last-line": 75,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getName",
                    "docblock": "**\n     * Returns the name of the session\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                                "line": 76,
                                "char": 40
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                        "line": 76,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                    "line": 76,
                    "last-line": 80,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getOptions",
                    "docblock": "**\n     * Get internal options\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                                "line": 81,
                                "char": 42
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                        "line": 81,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                    "line": 81,
                    "last-line": 85,
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
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                            "line": 86,
                            "char": 35
                        }
                    ],
                    "docblock": "**\n     * Check whether a session variable is set in an application context\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                                "line": 86,
                                "char": 44
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                        "line": 86,
                        "char": 44
                    },
                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                    "line": 86,
                    "last-line": 90,
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
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                            "line": 91,
                            "char": 38
                        }
                    ],
                    "docblock": "**\n     * Removes a session variable from an application context\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                        "line": 91,
                        "char": 47
                    },
                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                    "line": 91,
                    "last-line": 95,
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
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                            "line": 96,
                            "char": 35
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                            "line": 96,
                            "char": 46
                        }
                    ],
                    "docblock": "**\n     * Sets a session variable in an application context\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                        "line": 96,
                        "char": 55
                    },
                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                    "line": 96,
                    "last-line": 100,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setHandler",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "SessionHandlerInterface",
                                "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                                "line": 101,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                            "line": 101,
                            "char": 65
                        }
                    ],
                    "docblock": "**\n     * Set the handler for the session\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ManagerInterface",
                                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                                    "line": 101,
                                    "char": 88
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                                "line": 101,
                                "char": 88
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                        "line": 101,
                        "char": 88
                    },
                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                    "line": 101,
                    "last-line": 105,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setId",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "id",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                            "line": 106,
                            "char": 36
                        }
                    ],
                    "docblock": "**\n     * Set session Id\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ManagerInterface",
                                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                                    "line": 106,
                                    "char": 59
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                                "line": 106,
                                "char": 59
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                        "line": 106,
                        "char": 59
                    },
                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                    "line": 106,
                    "last-line": 113,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setName",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                            "line": 114,
                            "char": 40
                        }
                    ],
                    "docblock": "**\n     * Set the session name. Throw exception if the session has started\n     * and do not allow poop names\n     *\n     * @throws InvalidArgumentException\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ManagerInterface",
                                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                                    "line": 114,
                                    "char": 63
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                                "line": 114,
                                "char": 63
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                        "line": 114,
                        "char": 63
                    },
                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                    "line": 114,
                    "last-line": 118,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setOptions",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                            "line": 119,
                            "char": 45
                        }
                    ],
                    "docblock": "**\n     * Sets session's options\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                        "line": 119,
                        "char": 54
                    },
                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                    "line": 119,
                    "last-line": 123,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "status",
                    "docblock": "**\n     * Returns the status of the current session.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                                "line": 124,
                                "char": 36
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                        "line": 124,
                        "char": 36
                    },
                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                    "line": 124,
                    "last-line": 129,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "start",
                    "docblock": "**\n     * Starts the session (if headers are already sent the session will not be\n     * started)\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                                "line": 130,
                                "char": 36
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                        "line": 130,
                        "char": 36
                    },
                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                    "line": 130,
                    "last-line": 134,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "regenerateId",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "deleteOldSession",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                                "line": 135,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                            "line": 135,
                            "char": 57
                        }
                    ],
                    "docblock": "**\n     * Regenerates the session id using the handler.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ManagerInterface",
                                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                                    "line": 135,
                                    "char": 80
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                                "line": 135,
                                "char": 80
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                        "line": 135,
                        "char": 80
                    },
                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                    "line": 135,
                    "last-line": 139,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "registerHandler",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "SessionHandlerInterface",
                                "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                                "line": 140,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                            "line": 140,
                            "char": 70
                        }
                    ],
                    "docblock": "**\n     * Registers a handler with the session\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                                "line": 140,
                                "char": 79
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                        "line": 140,
                        "char": 79
                    },
                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                    "line": 140,
                    "last-line": 141,
                    "char": 19
                }
            ],
            "constants": [
                {
                    "type": "const",
                    "name": "SESSION_ACTIVE",
                    "default": {
                        "type": "int",
                        "value": "2",
                        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                        "line": 24,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                    "line": 25,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "SESSION_DISABLED",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                        "line": 25,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                    "line": 26,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "SESSION_NONE",
                    "default": {
                        "type": "int",
                        "value": "1",
                        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                        "line": 26,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
                    "line": 30,
                    "char": 6
                }
            ],
            "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
            "line": 141,
            "char": 1
        },
        "file": "\/app\/phalcon\/Session\/ManagerInterface.zep",
        "line": 0,
        "char": 0
    }
]