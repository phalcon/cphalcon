[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Logger\/Formatter\/FormatterInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Logger\\Formatter",
        "file": "\/app\/phalcon\/Logger\/Formatter\/FormatterInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\Item",
                "file": "\/app\/phalcon\/Logger\/Formatter\/FormatterInterface.zep",
                "line": 13,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Formatter\/FormatterInterface.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Logger\\FormatterInterface\n *\n * This interface must be implemented by formatters in Phalcon\\Logger\n *",
        "file": "\/app\/phalcon\/Logger\/Formatter\/FormatterInterface.zep",
        "line": 20,
        "char": 9
    },
    {
        "type": "interface",
        "name": "FormatterInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "format",
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
                                "file": "\/app\/phalcon\/Logger\/Formatter\/FormatterInterface.zep",
                                "line": 25,
                                "char": 38
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Formatter\/FormatterInterface.zep",
                            "line": 25,
                            "char": 39
                        }
                    ],
                    "docblock": "**\n     * Applies a format to an item\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Logger\/Formatter\/FormatterInterface.zep",
                                "line": 25,
                                "char": 51
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Logger\/Formatter\/FormatterInterface.zep",
                                "line": 25,
                                "char": 58
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Formatter\/FormatterInterface.zep",
                        "line": 25,
                        "char": 58
                    },
                    "file": "\/app\/phalcon\/Logger\/Formatter\/FormatterInterface.zep",
                    "line": 25,
                    "last-line": 26,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Logger\/Formatter\/FormatterInterface.zep",
            "line": 26,
            "char": 1
        },
        "file": "\/app\/phalcon\/Logger\/Formatter\/FormatterInterface.zep",
        "line": 0,
        "char": 0
    }
]