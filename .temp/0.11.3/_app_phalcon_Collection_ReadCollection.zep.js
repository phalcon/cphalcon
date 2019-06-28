[
    {
        "type": "comment",
        "value": "**\n* This file is part of the Phalcon Framework.\n*\n* (c) Phalcon Team <team@phalconphp.com>\n*\n* For the full copyright and license information, please view the LICENSE.txt\n* file that was distributed with this source code.\n*",
        "file": "\/app\/phalcon\/Collection\/ReadCollection.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Collection",
        "file": "\/app\/phalcon\/Collection\/ReadCollection.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Collection\\Collection",
                "file": "\/app\/phalcon\/Collection\/ReadCollection.zep",
                "line": 13,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Collection\/ReadCollection.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Collection\\Exception",
                "file": "\/app\/phalcon\/Collection\/ReadCollection.zep",
                "line": 14,
                "char": 33
            }
        ],
        "file": "\/app\/phalcon\/Collection\/ReadCollection.zep",
        "line": 18,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Collection\\ReadCollection is a read only Collection object\n *",
        "file": "\/app\/phalcon\/Collection\/ReadCollection.zep",
        "line": 19,
        "char": 5
    },
    {
        "type": "class",
        "name": "ReadCollection",
        "abstract": 0,
        "final": 0,
        "extends": "Collection",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "remove",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "element",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Collection\/ReadCollection.zep",
                            "line": 24,
                            "char": 42
                        }
                    ],
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
                                            "value": "The object is read only",
                                            "file": "\/app\/phalcon\/Collection\/ReadCollection.zep",
                                            "line": 26,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Collection\/ReadCollection.zep",
                                        "line": 26,
                                        "char": 52
                                    }
                                ],
                                "file": "\/app\/phalcon\/Collection\/ReadCollection.zep",
                                "line": 26,
                                "char": 53
                            },
                            "file": "\/app\/phalcon\/Collection\/ReadCollection.zep",
                            "line": 27,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Delete the element from the collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Collection\/ReadCollection.zep",
                        "line": 25,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Collection\/ReadCollection.zep",
                    "line": 24,
                    "last-line": 31,
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
                            "name": "element",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Collection\/ReadCollection.zep",
                            "line": 32,
                            "char": 39
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Collection\/ReadCollection.zep",
                            "line": 32,
                            "char": 50
                        }
                    ],
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
                                            "value": "The object is read only",
                                            "file": "\/app\/phalcon\/Collection\/ReadCollection.zep",
                                            "line": 34,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Collection\/ReadCollection.zep",
                                        "line": 34,
                                        "char": 52
                                    }
                                ],
                                "file": "\/app\/phalcon\/Collection\/ReadCollection.zep",
                                "line": 34,
                                "char": 53
                            },
                            "file": "\/app\/phalcon\/Collection\/ReadCollection.zep",
                            "line": 35,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set an element in the collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Collection\/ReadCollection.zep",
                        "line": 33,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Collection\/ReadCollection.zep",
                    "line": 32,
                    "last-line": 36,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Collection\/ReadCollection.zep",
            "line": 19,
            "char": 5
        },
        "file": "\/app\/phalcon\/Collection\/ReadCollection.zep",
        "line": 19,
        "char": 5
    }
]