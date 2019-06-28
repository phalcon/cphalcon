[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Logger\/Adapter\/Noop.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Logger\\Adapter",
        "file": "\/app\/phalcon\/Logger\/Adapter\/Noop.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Logger\\Item",
                "file": "\/app\/phalcon\/Logger\/Adapter\/Noop.zep",
                "line": 13,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Logger\/Adapter\/Noop.zep",
        "line": 28,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Logger\\Adapter\\Noop\n *\n * Adapter to store logs in plain text files\n *\n *```php\n * $logger = new \\Phalcon\\Logger\\Adapter\\Noop();\n *\n * $logger->log(\\Phalcon\\Logger::ERROR, \"This is an error\");\n * $logger->error(\"This is another error\");\n *\n * $logger->close();\n *```\n *",
        "file": "\/app\/phalcon\/Logger\/Adapter\/Noop.zep",
        "line": 29,
        "char": 5
    },
    {
        "type": "class",
        "name": "Noop",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractAdapter",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "close",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Logger\/Adapter\/Noop.zep",
                                "line": 36,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Noop.zep",
                            "line": 37,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Closes the stream\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Logger\/Adapter\/Noop.zep",
                                "line": 35,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Logger\/Adapter\/Noop.zep",
                        "line": 35,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Adapter\/Noop.zep",
                    "line": 34,
                    "last-line": 41,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "process",
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
                                "file": "\/app\/phalcon\/Logger\/Adapter\/Noop.zep",
                                "line": 42,
                                "char": 39
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Logger\/Adapter\/Noop.zep",
                            "line": 42,
                            "char": 40
                        }
                    ],
                    "docblock": "**\n     * Processes the message i.e. writes it to the file\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Logger\/Adapter\/Noop.zep",
                        "line": 43,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Logger\/Adapter\/Noop.zep",
                    "line": 42,
                    "last-line": 46,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Logger\/Adapter\/Noop.zep",
            "line": 29,
            "char": 5
        },
        "file": "\/app\/phalcon\/Logger\/Adapter\/Noop.zep",
        "line": 29,
        "char": 5
    }
]