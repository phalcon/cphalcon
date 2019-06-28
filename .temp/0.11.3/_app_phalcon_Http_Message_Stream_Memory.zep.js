[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *\n * Implementation of this file has been influenced by Zend Diactoros\n * @link    https:\/\/github.com\/zendframework\/zend-diactoros\n * @license https:\/\/github.com\/zendframework\/zend-diactoros\/blob\/master\/LICENSE.md\n *",
        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Memory.zep",
        "line": 15,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Http\\Message\\Stream",
        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Memory.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Message\\Stream",
                "file": "\/app\/phalcon\/Http\/Message\/Stream\/Memory.zep",
                "line": 17,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Memory.zep",
        "line": 25,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Describes a data stream from \"php:\/\/memory\"\n *\n * Typically, an instance will wrap a PHP stream; this interface provides\n * a wrapper around the most common operations, including serialization of\n * the entire stream to a string.\n *",
        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Memory.zep",
        "line": 26,
        "char": 5
    },
    {
        "type": "class",
        "name": "Memory",
        "abstract": 0,
        "final": 0,
        "extends": "Stream",
        "definition": {
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
                            "name": "mode",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "string",
                                "value": "rb",
                                "file": "\/app\/phalcon\/Http\/Message\/Stream\/Memory.zep",
                                "line": 31,
                                "char": 46
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Memory.zep",
                            "line": 31,
                            "char": 46
                        }
                    ],
                    "statements": [
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "__construct",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "php:\/\/memory",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Memory.zep",
                                            "line": 33,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Memory.zep",
                                        "line": 33,
                                        "char": 41
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "mode",
                                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Memory.zep",
                                            "line": 33,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Memory.zep",
                                        "line": 33,
                                        "char": 47
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/Stream\/Memory.zep",
                                "line": 33,
                                "char": 48
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Memory.zep",
                            "line": 34,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Memory.zep",
                        "line": 32,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/Stream\/Memory.zep",
                    "line": 31,
                    "last-line": 35,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Http\/Message\/Stream\/Memory.zep",
            "line": 26,
            "char": 5
        },
        "file": "\/app\/phalcon\/Http\/Message\/Stream\/Memory.zep",
        "line": 26,
        "char": 5
    }
]