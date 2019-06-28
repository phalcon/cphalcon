[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Annotations\\Adapter",
        "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Annotations\\Reflection",
                "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                "line": 13,
                "char": 35
            }
        ],
        "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Annotations\\Collection",
                "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                "line": 14,
                "char": 35
            }
        ],
        "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Annotations\\ReaderInterface",
                "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                "line": 15,
                "char": 40
            }
        ],
        "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * This interface must be implemented by adapters in Phalcon\\Annotations\n *",
        "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
        "line": 20,
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
                    "name": "get",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "className",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                            "line": 25,
                            "char": 41
                        }
                    ],
                    "docblock": "**\n     * Parses or retrieves all the annotations found in a class\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Reflection",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                                    "line": 25,
                                    "char": 58
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                                "line": 25,
                                "char": 58
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                        "line": 25,
                        "char": 58
                    },
                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                    "line": 25,
                    "last-line": 29,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMethod",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "className",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                            "line": 30,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "methodName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                            "line": 30,
                            "char": 66
                        }
                    ],
                    "docblock": "**\n     * Returns the annotations found in a specific method\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                                    "line": 30,
                                    "char": 83
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                                "line": 30,
                                "char": 83
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                        "line": 30,
                        "char": 83
                    },
                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                    "line": 30,
                    "last-line": 34,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMethods",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "className",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                            "line": 35,
                            "char": 48
                        }
                    ],
                    "docblock": "**\n     * Returns the annotations found in all the class' methods\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                                "line": 35,
                                "char": 58
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                        "line": 35,
                        "char": 58
                    },
                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                    "line": 35,
                    "last-line": 39,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getProperty",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "className",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                            "line": 40,
                            "char": 49
                        },
                        {
                            "type": "parameter",
                            "name": "propertyName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                            "line": 40,
                            "char": 70
                        }
                    ],
                    "docblock": "**\n     * Returns the annotations found in a specific property\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                                    "line": 40,
                                    "char": 87
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                                "line": 40,
                                "char": 87
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                        "line": 40,
                        "char": 87
                    },
                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                    "line": 40,
                    "last-line": 44,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getProperties",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "className",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                            "line": 45,
                            "char": 51
                        }
                    ],
                    "docblock": "**\n     * Returns the annotations found in all the class' methods\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                                "line": 45,
                                "char": 61
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                        "line": 45,
                        "char": 61
                    },
                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                    "line": 45,
                    "last-line": 49,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getReader",
                    "docblock": "**\n     * Returns the annotation reader\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ReaderInterface",
                                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                                    "line": 50,
                                    "char": 53
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                                "line": 50,
                                "char": 53
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                        "line": 50,
                        "char": 53
                    },
                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                    "line": 50,
                    "last-line": 54,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setReader",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "reader",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ReaderInterface",
                                "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                                "line": 55,
                                "char": 54
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                            "line": 55,
                            "char": 55
                        }
                    ],
                    "docblock": "**\n     * Sets the annotations parser\n     *",
                    "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
                    "line": 55,
                    "last-line": 56,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
            "line": 56,
            "char": 1
        },
        "file": "\/app\/phalcon\/Annotations\/Adapter\/AdapterInterface.zep",
        "line": 0,
        "char": 0
    }
]