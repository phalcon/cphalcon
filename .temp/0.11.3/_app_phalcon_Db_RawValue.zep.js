[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Db\/RawValue.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Db",
        "file": "\/app\/phalcon\/Db\/RawValue.zep",
        "line": 26,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * This class allows to insert\/update raw data without quoting or formatting.\n *\n * The next example shows how to use the MySQL now() function as a field value.\n *\n *```php\n * $subscriber = new Subscribers();\n *\n * $subscriber->email     = \"andres@phalconphp.com\";\n * $subscriber->createdAt = new \\Phalcon\\Db\\RawValue(\"now()\");\n *\n * $subscriber->save();\n *```\n *",
        "file": "\/app\/phalcon\/Db\/RawValue.zep",
        "line": 27,
        "char": 5
    },
    {
        "type": "class",
        "name": "RawValue",
        "abstract": 0,
        "final": 0,
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "value",
                    "docblock": "**\n     * Raw value without quoting or formatting\n     *\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Db\/RawValue.zep",
                            "line": 34,
                            "char": 26
                        },
                        {
                            "type": "shortcut",
                            "name": "__toString",
                            "file": "\/app\/phalcon\/Db\/RawValue.zep",
                            "line": 34,
                            "char": 39
                        }
                    ],
                    "file": "\/app\/phalcon\/Db\/RawValue.zep",
                    "line": 38,
                    "char": 6
                }
            ],
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
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/RawValue.zep",
                            "line": 39,
                            "char": 42
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "value",
                                    "file": "\/app\/phalcon\/Db\/RawValue.zep",
                                    "line": 41,
                                    "char": 20
                                },
                                "right": {
                                    "type": "string",
                                    "value": "",
                                    "file": "\/app\/phalcon\/Db\/RawValue.zep",
                                    "line": 41,
                                    "char": 23
                                },
                                "file": "\/app\/phalcon\/Db\/RawValue.zep",
                                "line": 41,
                                "char": 23
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "value",
                                            "expr": {
                                                "type": "string",
                                                "value": "''",
                                                "file": "\/app\/phalcon\/Db\/RawValue.zep",
                                                "line": 42,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Db\/RawValue.zep",
                                            "line": 42,
                                            "char": 33
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/RawValue.zep",
                                    "line": 43,
                                    "char": 9
                                }
                            ],
                            "elseif_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Db\/RawValue.zep",
                                            "line": 43,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Db\/RawValue.zep",
                                            "line": 43,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Db\/RawValue.zep",
                                        "line": 43,
                                        "char": 33
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "value",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "NULL",
                                                        "file": "\/app\/phalcon\/Db\/RawValue.zep",
                                                        "line": 44,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/RawValue.zep",
                                                    "line": 44,
                                                    "char": 35
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/RawValue.zep",
                                            "line": 45,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/RawValue.zep",
                                    "line": 45,
                                    "char": 14
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "value",
                                            "expr": {
                                                "type": "cast",
                                                "left": "string",
                                                "right": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Db\/RawValue.zep",
                                                    "line": 46,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Db\/RawValue.zep",
                                                "line": 46,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Db\/RawValue.zep",
                                            "line": 46,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/RawValue.zep",
                                    "line": 47,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/RawValue.zep",
                            "line": 48,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Db\\RawValue constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Db\/RawValue.zep",
                        "line": 40,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/RawValue.zep",
                    "line": 39,
                    "last-line": 49,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Db\/RawValue.zep",
            "line": 27,
            "char": 5
        },
        "file": "\/app\/phalcon\/Db\/RawValue.zep",
        "line": 27,
        "char": 5
    }
]