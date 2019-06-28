[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Lang.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model\\Query",
        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Lang.zep",
        "line": 31,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\Query\\Lang\n *\n * PHQL is implemented as a parser (written in C) that translates syntax in\n * that of the target RDBMS. It allows Phalcon to offer a unified SQL language to\n * the developer, while internally doing all the work of translating PHQL\n * instructions to the most optimal SQL instructions depending on the\n * RDBMS type associated with a model.\n *\n * To achieve the highest performance possible, we wrote a parser that uses\n * the same technology as SQLite. This technology provides a small in-memory\n * parser with a very low memory footprint that is also thread-safe.\n *\n * ```php\n * $intermediate = Phalcon\\Mvc\\Model\\Query\\Lang::parsePHQL(\n *     \"SELECT r.* FROM Robots r LIMIT 10\"\n * );\n * ```\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Lang.zep",
        "line": 32,
        "char": 8
    },
    {
        "type": "class",
        "name": "Lang",
        "abstract": 1,
        "final": 0,
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "parsePHQL",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "phql",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Lang.zep",
                            "line": 37,
                            "char": 50
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "phql_parse_phql",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "phql",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Lang.zep",
                                            "line": 39,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Lang.zep",
                                        "line": 39,
                                        "char": 36
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Lang.zep",
                                "line": 39,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Lang.zep",
                            "line": 40,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Parses a PHQL statement returning an intermediate representation (IR)\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Lang.zep",
                                "line": 38,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Lang.zep",
                        "line": 38,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Lang.zep",
                    "line": 37,
                    "last-line": 41,
                    "char": 26
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Lang.zep",
            "line": 32,
            "char": 14
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/Query\/Lang.zep",
        "line": 32,
        "char": 14
    }
]