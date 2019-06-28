[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Paginator\/Adapter\/AdapterInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Paginator\\Adapter",
        "file": "\/app\/phalcon\/Paginator\/Adapter\/AdapterInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Paginator\\RepositoryInterface",
                "file": "\/app\/phalcon\/Paginator\/Adapter\/AdapterInterface.zep",
                "line": 13,
                "char": 42
            }
        ],
        "file": "\/app\/phalcon\/Paginator\/Adapter\/AdapterInterface.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Paginator\\AdapterInterface\n *\n * Interface for Phalcon\\Paginator adapters\n *",
        "file": "\/app\/phalcon\/Paginator\/Adapter\/AdapterInterface.zep",
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
                    "name": "getLimit",
                    "docblock": "**\n     * Get current rows limit\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/AdapterInterface.zep",
                                "line": 25,
                                "char": 38
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AdapterInterface.zep",
                        "line": 25,
                        "char": 38
                    },
                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AdapterInterface.zep",
                    "line": 25,
                    "last-line": 29,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "paginate",
                    "docblock": "**\n     * Returns a slice of the resultset to show in the pagination\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RepositoryInterface",
                                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AdapterInterface.zep",
                                    "line": 30,
                                    "char": 56
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Paginator\/Adapter\/AdapterInterface.zep",
                                "line": 30,
                                "char": 56
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Paginator\/Adapter\/AdapterInterface.zep",
                        "line": 30,
                        "char": 56
                    },
                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AdapterInterface.zep",
                    "line": 30,
                    "last-line": 34,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setCurrentPage",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "page",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/AdapterInterface.zep",
                            "line": 35,
                            "char": 44
                        }
                    ],
                    "docblock": "**\n     * Set the current page number\n     *",
                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AdapterInterface.zep",
                    "line": 35,
                    "last-line": 39,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setLimit",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "limit",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Paginator\/Adapter\/AdapterInterface.zep",
                            "line": 40,
                            "char": 39
                        }
                    ],
                    "docblock": "**\n     * Set current rows limit\n     *",
                    "file": "\/app\/phalcon\/Paginator\/Adapter\/AdapterInterface.zep",
                    "line": 40,
                    "last-line": 41,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Paginator\/Adapter\/AdapterInterface.zep",
            "line": 41,
            "char": 1
        },
        "file": "\/app\/phalcon\/Paginator\/Adapter\/AdapterInterface.zep",
        "line": 0,
        "char": 0
    }
]