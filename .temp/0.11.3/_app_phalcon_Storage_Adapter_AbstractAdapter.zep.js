[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Storage\\Adapter",
        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "DateInterval",
                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                "line": 13,
                "char": 17
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "DateTime",
                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                "line": 14,
                "char": 13
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Arr",
                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                "line": 15,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Adapter\\AdapterInterface",
                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                "line": 16,
                "char": 45
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Exception",
                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                "line": 17,
                "char": 30
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\SerializerFactory",
                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                "line": 18,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Serializer\\SerializerInterface",
                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                "line": 19,
                "char": 51
            }
        ],
        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
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
                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                "line": 22,
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
                    "name": "adapter",
                    "docblock": "**\n     * @var mixed\n     *",
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                    "line": 32,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "defaultSerializer",
                    "default": {
                        "type": "string",
                        "value": "Php",
                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                        "line": 33,
                        "char": 39
                    },
                    "docblock": "**\n     * Name of the default serializer class\n     *\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 33,
                            "char": 44
                        },
                        {
                            "type": "shortcut",
                            "name": "set",
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 33,
                            "char": 50
                        }
                    ],
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                    "line": 39,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "lifetime",
                    "default": {
                        "type": "int",
                        "value": "3600",
                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                        "line": 40,
                        "char": 30
                    },
                    "docblock": "**\n     * Name of the default TTL (time to live)\n     *\n     * @var int\n     *",
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                    "line": 44,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "prefix",
                    "default": {
                        "type": "string",
                        "value": "",
                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                        "line": 45,
                        "char": 25
                    },
                    "docblock": "**\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 45,
                            "char": 31
                        }
                    ],
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                    "line": 51,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "serializer",
                    "docblock": "**\n     * Serializer\n     *\n     * @var <SerializerInterface>\n     *",
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                    "line": 58,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "serializerFactory",
                    "docblock": "**\n     * Serializer Factory\n     *\n     * @var <SerializerFactory>\n     *",
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                    "line": 63,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "__construct",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "factory",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "SerializerFactory",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 64,
                                "char": 62
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 64,
                                "char": 70
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 64,
                            "char": 70
                        },
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 64,
                            "char": 86
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
                                    "property": "defaultSerializer",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "Arr",
                                        "dynamic": 0,
                                        "name": "get",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                    "line": 69,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                "line": 69,
                                                "char": 55
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "defaultSerializer",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                    "line": 69,
                                                    "char": 74
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                "line": 69,
                                                "char": 74
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "Php",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                    "line": 69,
                                                    "char": 79
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                "line": 69,
                                                "char": 79
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                        "line": 69,
                                        "char": 80
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 69,
                                    "char": 80
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "lifetime",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "Arr",
                                        "dynamic": 0,
                                        "name": "get",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                    "line": 70,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                "line": 70,
                                                "char": 55
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "lifetime",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                    "line": 70,
                                                    "char": 65
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                "line": 70,
                                                "char": 65
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "3600",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                    "line": 70,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                "line": 70,
                                                "char": 71
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                        "line": 70,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 70,
                                    "char": 72
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "serializer",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "Arr",
                                        "dynamic": 0,
                                        "name": "get",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                    "line": 71,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                "line": 71,
                                                "char": 55
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "serializer",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                    "line": 71,
                                                    "char": 67
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                "line": 71,
                                                "char": 67
                                            },
                                            {
                                                "parameter": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                    "line": 71,
                                                    "char": 73
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                "line": 71,
                                                "char": 73
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                        "line": 71,
                                        "char": 74
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 71,
                                    "char": 74
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "serializerFactory",
                                    "expr": {
                                        "type": "variable",
                                        "value": "factory",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                        "line": 72,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 72,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 74,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "options",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                        "line": 74,
                                        "char": 25
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "prefix",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                        "line": 74,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 74,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 74,
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
                                            "property": "prefix",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                    "line": 75,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "prefix",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                    "line": 75,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                "line": 75,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                            "line": 75,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 76,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 77,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets parameters based on options\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                        "line": 65,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                    "line": 64,
                    "last-line": 81,
                    "char": 22
                },
                {
                    "visibility": [
                        "abstract",
                        "public"
                    ],
                    "type": "method",
                    "name": "clear",
                    "docblock": "**\n     * Flushes\/clears the cache\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 82,
                                "char": 45
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                        "line": 82,
                        "char": 45
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                    "line": 82,
                    "last-line": 86,
                    "char": 28
                },
                {
                    "visibility": [
                        "abstract",
                        "public"
                    ],
                    "type": "method",
                    "name": "decrement",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 87,
                            "char": 51
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "1",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 87,
                                "char": 66
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 87,
                            "char": 66
                        }
                    ],
                    "docblock": "**\n     * Decrements a stored number\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 87,
                                "char": 75
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 87,
                                "char": 81
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                        "line": 87,
                        "char": 81
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                    "line": 87,
                    "last-line": 91,
                    "char": 28
                },
                {
                    "visibility": [
                        "abstract",
                        "public"
                    ],
                    "type": "method",
                    "name": "delete",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 92,
                            "char": 48
                        }
                    ],
                    "docblock": "**\n     * Deletes data from the adapter\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 92,
                                "char": 57
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                        "line": 92,
                        "char": 57
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                    "line": 92,
                    "last-line": 96,
                    "char": 28
                },
                {
                    "visibility": [
                        "abstract",
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
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 97,
                            "char": 45
                        }
                    ],
                    "docblock": "**\n     * Reads data from the adapter\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 97,
                                "char": 53
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                        "line": 97,
                        "char": 53
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                    "line": 97,
                    "last-line": 101,
                    "char": 28
                },
                {
                    "visibility": [
                        "abstract",
                        "public"
                    ],
                    "type": "method",
                    "name": "getAdapter",
                    "docblock": "**\n     * Returns the adapter - connects to the storage if not connected\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 102,
                                "char": 49
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                        "line": 102,
                        "char": 49
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                    "line": 102,
                    "last-line": 106,
                    "char": 28
                },
                {
                    "visibility": [
                        "abstract",
                        "public"
                    ],
                    "type": "method",
                    "name": "getKeys",
                    "docblock": "**\n     * Returns all the keys stored\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 107,
                                "char": 48
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                        "line": 107,
                        "char": 48
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                    "line": 107,
                    "last-line": 111,
                    "char": 28
                },
                {
                    "visibility": [
                        "abstract",
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
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 112,
                            "char": 45
                        }
                    ],
                    "docblock": "**\n     * Checks if an element exists in the cache\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 112,
                                "char": 54
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                        "line": 112,
                        "char": 54
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                    "line": 112,
                    "last-line": 116,
                    "char": 28
                },
                {
                    "visibility": [
                        "abstract",
                        "public"
                    ],
                    "type": "method",
                    "name": "increment",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 117,
                            "char": 51
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "1",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 117,
                                "char": 66
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 117,
                            "char": 66
                        }
                    ],
                    "docblock": "**\n     * Increments a stored number\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 117,
                                "char": 75
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 117,
                                "char": 81
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                        "line": 117,
                        "char": 81
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                    "line": 117,
                    "last-line": 121,
                    "char": 28
                },
                {
                    "visibility": [
                        "abstract",
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
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 122,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 122,
                            "char": 56
                        },
                        {
                            "type": "parameter",
                            "name": "ttl",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 122,
                                "char": 72
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 122,
                            "char": 72
                        }
                    ],
                    "docblock": "**\n     * Stores data in the adapter\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 122,
                                "char": 81
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                        "line": 122,
                        "char": 81
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                    "line": 122,
                    "last-line": 126,
                    "char": 28
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getPrefixedKey",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 127,
                            "char": 46
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "key",
                                    "expr": {
                                        "type": "cast",
                                        "left": "string",
                                        "right": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                            "line": 129,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                        "line": 129,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 129,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 131,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                        "line": 131,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "prefix",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                        "line": 131,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 131,
                                    "char": 29
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "key",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 131,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 131,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 132,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the key requested, prefixed\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 128,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                        "line": 128,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                    "line": 127,
                    "last-line": 136,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getSerializedData",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "content",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 137,
                            "char": 53
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                        "line": 139,
                                        "char": 17
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "defaultSerializer",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                        "line": 139,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 139,
                                    "char": 38
                                },
                                "right": {
                                    "type": "string",
                                    "value": "",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 139,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 139,
                                "char": 41
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
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                "line": 140,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "serializer",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                "line": 140,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                            "line": 140,
                                            "char": 30
                                        },
                                        "name": "setData",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "content",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                    "line": 140,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                "line": 140,
                                                "char": 46
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                        "line": 140,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 141,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "content",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                        "line": 141,
                                                        "char": 32
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "serializer",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                        "line": 141,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                    "line": 141,
                                                    "char": 44
                                                },
                                                "name": "serialize",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                "line": 141,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                            "line": 141,
                                            "char": 56
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 142,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 144,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "content",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 144,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 145,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns serialized data\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 138,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                        "line": 138,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                    "line": 137,
                    "last-line": 154,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getTtl",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "ttl",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 155,
                            "char": 38
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "dateTime",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 157,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 159,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "ttl",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 159,
                                    "char": 18
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 159,
                                    "char": 25
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 159,
                                "char": 25
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                            "line": 160,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "lifetime",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                            "line": 160,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                        "line": 160,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 161,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 163,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "identical",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "ttl",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                            "line": 163,
                                            "char": 25
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                        "line": 163,
                                        "char": 25
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                        "line": 163,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 163,
                                    "char": 35
                                },
                                "right": {
                                    "type": "instanceof",
                                    "left": {
                                        "type": "variable",
                                        "value": "ttl",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                        "line": 163,
                                        "char": 50
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "DateInterval",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                        "line": 163,
                                        "char": 65
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 163,
                                    "char": 65
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 163,
                                "char": 65
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "dateTime",
                                            "expr": {
                                                "type": "new",
                                                "class": "DateTime",
                                                "dynamic": 0,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "@0",
                                                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                            "line": 164,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                        "line": 164,
                                                        "char": 43
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                "line": 164,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                            "line": 164,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 165,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "dateTime",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                "line": 165,
                                                "char": 29
                                            },
                                            "name": "add",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "ttl",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                        "line": 165,
                                                        "char": 37
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                    "line": 165,
                                                    "char": 37
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                            "line": 165,
                                            "char": 39
                                        },
                                        "name": "getTimestamp",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                        "line": 165,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 166,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 168,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "cast",
                                "left": "int",
                                "right": {
                                    "type": "variable",
                                    "value": "ttl",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 168,
                                    "char": 25
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 168,
                                "char": 25
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 169,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Calculates the TTL for a cache item\n     *\n     * @param DateInterval|int|null $ttl\n     *\n     * @return int\n     * @throws Exception\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 156,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                        "line": 156,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                    "line": 155,
                    "last-line": 173,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getUnserializedData",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "content",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 174,
                            "char": 55
                        },
                        {
                            "type": "parameter",
                            "name": "defaultValue",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 174,
                                "char": 80
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 174,
                            "char": 80
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "content",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 176,
                                    "char": 21
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 176,
                                "char": 21
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "defaultValue",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                        "line": 177,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 178,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 180,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                        "line": 180,
                                        "char": 17
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "defaultSerializer",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                        "line": 180,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 180,
                                    "char": 38
                                },
                                "right": {
                                    "type": "string",
                                    "value": "",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 180,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 180,
                                "char": 41
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
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                "line": 181,
                                                "char": 18
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "serializer",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                "line": 181,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                            "line": 181,
                                            "char": 30
                                        },
                                        "name": "unserialize",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "content",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                    "line": 181,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                "line": 181,
                                                "char": 50
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                        "line": 181,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 182,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "content",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                        "line": 182,
                                                        "char": 32
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "serializer",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                        "line": 182,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                    "line": 182,
                                                    "char": 44
                                                },
                                                "name": "getData",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                "line": 182,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                            "line": 182,
                                            "char": 54
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 183,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 185,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "content",
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 185,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 186,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns unserialized data\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 175,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                        "line": 175,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                    "line": 174,
                    "last-line": 190,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "initSerializer",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "className",
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 193,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 195,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "identical",
                                    "left": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                        "line": 195,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                            "line": 195,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "serializerFactory",
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                            "line": 195,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                        "line": 195,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 195,
                                    "char": 54
                                },
                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                "line": 195,
                                "char": 54
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
                                                    "value": "A valid serializer is required",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                    "line": 196,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                "line": 196,
                                                "char": 63
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                        "line": 196,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 197,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 199,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "className",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "strtolower",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                        "line": 199,
                                                        "char": 48
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "defaultSerializer",
                                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                        "line": 199,
                                                        "char": 66
                                                    },
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                    "line": 199,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                "line": 199,
                                                "char": 66
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                        "line": 199,
                                        "char": 67
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 199,
                                    "char": 67
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "serializer",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                "line": 200,
                                                "char": 37
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "serializerFactory",
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                "line": 200,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                            "line": 200,
                                            "char": 56
                                        },
                                        "name": "newInstance",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "className",
                                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                    "line": 200,
                                                    "char": 78
                                                },
                                                "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                                "line": 200,
                                                "char": 78
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                        "line": 200,
                                        "char": 79
                                    },
                                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                                    "line": 200,
                                    "char": 79
                                }
                            ],
                            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                            "line": 201,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Initializes the serializer\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                        "line": 192,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
                    "line": 191,
                    "last-line": 202,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
            "line": 21,
            "char": 14
        },
        "file": "\/app\/phalcon\/Storage\/Adapter\/AbstractAdapter.zep",
        "line": 21,
        "char": 14
    }
]