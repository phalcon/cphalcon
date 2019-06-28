[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Assets\/Filters\/JsMin.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Assets\\Filters",
        "file": "\/app\/phalcon\/Assets\/Filters\/JsMin.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Assets\\FilterInterface",
                "file": "\/app\/phalcon\/Assets\/Filters\/JsMin.zep",
                "line": 13,
                "char": 35
            }
        ],
        "file": "\/app\/phalcon\/Assets\/Filters\/JsMin.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Deletes the characters which are insignificant to JavaScript. Comments will\n * be removed. Tabs will be replaced with spaces. Carriage returns will be\n * replaced with linefeeds. Most spaces and linefeeds will be removed.\n *",
        "file": "\/app\/phalcon\/Assets\/Filters\/JsMin.zep",
        "line": 20,
        "char": 5
    },
    {
        "type": "class",
        "name": "Jsmin",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "FilterInterface",
                "file": "\/app\/phalcon\/Assets\/Filters\/JsMin.zep",
                "line": 21,
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
                            "file": "\/app\/phalcon\/Assets\/Filters\/JsMin.zep",
                            "line": 26,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "content",
                                "file": "\/app\/phalcon\/Assets\/Filters\/JsMin.zep",
                                "line": 28,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Assets\/Filters\/JsMin.zep",
                            "line": 29,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Filters the content using JSMIN\n     * NOTE: This functionality is not currently available\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Assets\/Filters\/JsMin.zep",
                                "line": 27,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Assets\/Filters\/JsMin.zep",
                        "line": 27,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Assets\/Filters\/JsMin.zep",
                    "line": 26,
                    "last-line": 30,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Assets\/Filters\/JsMin.zep",
            "line": 20,
            "char": 5
        },
        "file": "\/app\/phalcon\/Assets\/Filters\/JsMin.zep",
        "line": 20,
        "char": 5
    }
]