[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Paginator",
        "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
        "line": 18,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Paginator\\RepositoryInterface\n *\n * Interface for the repository of current state\n * Phalcon\\Paginator\\AdapterInterface::paginate()\n *",
        "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
        "line": 19,
        "char": 9
    },
    {
        "type": "interface",
        "name": "RepositoryInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAliases",
                    "docblock": "**\n     * Gets the aliases for properties repository\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                                "line": 33,
                                "char": 42
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                        "line": 33,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                    "line": 33,
                    "last-line": 37,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getCurrent",
                    "docblock": "**\n     * Gets number of the current page\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                                "line": 38,
                                "char": 40
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                        "line": 38,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                    "line": 38,
                    "last-line": 42,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getFirst",
                    "docblock": "**\n     * Gets number of the first page\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                                "line": 43,
                                "char": 38
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                        "line": 43,
                        "char": 38
                    },
                    "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                    "line": 43,
                    "last-line": 47,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getItems",
                    "docblock": "**\n     * Gets the items on the current page\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                                "line": 48,
                                "char": 38
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                        "line": 48,
                        "char": 38
                    },
                    "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                    "line": 48,
                    "last-line": 52,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getLast",
                    "docblock": "**\n     * Gets number of the last page\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                                "line": 53,
                                "char": 37
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                        "line": 53,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                    "line": 53,
                    "last-line": 57,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getLimit",
                    "docblock": "**\n     * Gets current rows limit\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                                "line": 58,
                                "char": 38
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                        "line": 58,
                        "char": 38
                    },
                    "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                    "line": 58,
                    "last-line": 62,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getNext",
                    "docblock": "**\n     * Gets number of the next page\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                                "line": 63,
                                "char": 37
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                        "line": 63,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                    "line": 63,
                    "last-line": 67,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getPrevious",
                    "docblock": "**\n     * Gets number of the previous page\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                                "line": 68,
                                "char": 41
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                        "line": 68,
                        "char": 41
                    },
                    "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                    "line": 68,
                    "last-line": 72,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getTotalItems",
                    "docblock": "**\n     * Gets the total number of items\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                                "line": 73,
                                "char": 43
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                        "line": 73,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                    "line": 73,
                    "last-line": 77,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setAliases",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "aliases",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                            "line": 78,
                            "char": 45
                        }
                    ],
                    "docblock": "**\n     * Sets the aliases for properties repository\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RepositoryInterface",
                                    "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                                    "line": 78,
                                    "char": 71
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                                "line": 78,
                                "char": 71
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                        "line": 78,
                        "char": 71
                    },
                    "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                    "line": 78,
                    "last-line": 82,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setProperties",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "properties",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                            "line": 83,
                            "char": 51
                        }
                    ],
                    "docblock": "**\n     * Sets values for properties of the repository\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RepositoryInterface",
                                    "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                                    "line": 83,
                                    "char": 77
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                                "line": 83,
                                "char": 77
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                        "line": 83,
                        "char": 77
                    },
                    "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                    "line": 83,
                    "last-line": 84,
                    "char": 19
                }
            ],
            "constants": [
                {
                    "type": "const",
                    "name": "PROPERTY_CURRENT_PAGE",
                    "default": {
                        "type": "string",
                        "value": "current",
                        "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                        "line": 21,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                    "line": 22,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "PROPERTY_FIRST_PAGE",
                    "default": {
                        "type": "string",
                        "value": "first",
                        "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                        "line": 22,
                        "char": 41
                    },
                    "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                    "line": 23,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "PROPERTY_ITEMS",
                    "default": {
                        "type": "string",
                        "value": "items",
                        "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                        "line": 23,
                        "char": 41
                    },
                    "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                    "line": 24,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "PROPERTY_LAST_PAGE",
                    "default": {
                        "type": "string",
                        "value": "last",
                        "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                        "line": 24,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                    "line": 25,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "PROPERTY_LIMIT",
                    "default": {
                        "type": "string",
                        "value": "limit",
                        "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                        "line": 25,
                        "char": 41
                    },
                    "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                    "line": 26,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "PROPERTY_NEXT_PAGE",
                    "default": {
                        "type": "string",
                        "value": "next",
                        "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                        "line": 26,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                    "line": 27,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "PROPERTY_PREVIOUS_PAGE",
                    "default": {
                        "type": "string",
                        "value": "previous",
                        "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                        "line": 27,
                        "char": 44
                    },
                    "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                    "line": 28,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "PROPERTY_TOTAL_ITEMS",
                    "default": {
                        "type": "string",
                        "value": "total_items",
                        "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                        "line": 28,
                        "char": 47
                    },
                    "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
                    "line": 32,
                    "char": 6
                }
            ],
            "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
            "line": 84,
            "char": 1
        },
        "file": "\/app\/phalcon\/Paginator\/RepositoryInterface.zep",
        "line": 0,
        "char": 0
    }
]