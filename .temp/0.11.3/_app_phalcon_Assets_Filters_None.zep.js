[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Assets\/Filters\/None.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Assets\\Filters",
        "file": "\/app\/phalcon\/Assets\/Filters\/None.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Assets\\FilterInterface",
                "file": "\/app\/phalcon\/Assets\/Filters\/None.zep",
                "line": 13,
                "char": 35
            }
        ],
        "file": "\/app\/phalcon\/Assets\/Filters\/None.zep",
        "line": 17,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Returns the content without make any modification to the original source\n *",
        "file": "\/app\/phalcon\/Assets\/Filters\/None.zep",
        "line": 18,
        "char": 5
    },
    {
        "type": "class",
        "name": "None",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "FilterInterface",
                "file": "\/app\/phalcon\/Assets\/Filters\/None.zep",
                "line": 19,
                "char": 1
            }
        ],
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "filter",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "content",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Assets\/Filters\/None.zep",
                            "line": 23,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "content",
                                "file": "\/app\/phalcon\/Assets\/Filters\/None.zep",
                                "line": 25,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Assets\/Filters\/None.zep",
                            "line": 26,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the content as is\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Assets\/Filters\/None.zep",
                                "line": 24,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Filters\/None.zep",
                        "line": 24,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Filters\/None.zep",
                    "line": 23,
                    "last-line": 27,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Assets\/Filters\/None.zep",
            "line": 18,
            "char": 5
        },
        "file": "\/app\/phalcon\/Assets\/Filters\/None.zep",
        "line": 18,
        "char": 5
    }
]