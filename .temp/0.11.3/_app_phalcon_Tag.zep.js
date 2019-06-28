[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Tag.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon",
        "file": "\/app\/phalcon\/Tag.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Tag\\Select",
                "file": "\/app\/phalcon\/Tag.zep",
                "line": 13,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Tag.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Tag\\Exception",
                "file": "\/app\/phalcon\/Tag.zep",
                "line": 14,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Tag.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\UrlInterface",
                "file": "\/app\/phalcon\/Tag.zep",
                "line": 15,
                "char": 25
            }
        ],
        "file": "\/app\/phalcon\/Tag.zep",
        "line": 21,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Tag is designed to simplify building of HTML tags.\n * It provides a set of helpers to generate HTML in a dynamic way.\n * This component is an abstract class that you can extend to add more helpers.\n *",
        "file": "\/app\/phalcon\/Tag.zep",
        "line": 22,
        "char": 5
    },
    {
        "type": "class",
        "name": "Tag",
        "abstract": 0,
        "final": 0,
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected",
                        "static"
                    ],
                    "type": "property",
                    "name": "autoEscape",
                    "default": {
                        "type": "bool",
                        "value": "true",
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 36,
                        "char": 39
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 40,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected",
                        "static"
                    ],
                    "type": "property",
                    "name": "container",
                    "docblock": "**\n     * Framework Dispatcher\n     *",
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 45,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected",
                        "static"
                    ],
                    "type": "property",
                    "name": "displayValues",
                    "docblock": "**\n     * Pre-assigned values for components\n     *",
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 48,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected",
                        "static"
                    ],
                    "type": "property",
                    "name": "dispatcherService",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 48,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 50,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected",
                        "static"
                    ],
                    "type": "property",
                    "name": "documentAppendTitle",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 50,
                        "char": 48
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 52,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected",
                        "static"
                    ],
                    "type": "property",
                    "name": "documentPrependTitle",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 52,
                        "char": 49
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 56,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected",
                        "static"
                    ],
                    "type": "property",
                    "name": "documentTitle",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 57,
                        "char": 42
                    },
                    "docblock": "**\n     * HTML document title\n     *",
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 59,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected",
                        "static"
                    ],
                    "type": "property",
                    "name": "documentTitleSeparator",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 59,
                        "char": 51
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 61,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected",
                        "static"
                    ],
                    "type": "property",
                    "name": "documentType",
                    "default": {
                        "type": "int",
                        "value": "11",
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 61,
                        "char": 39
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 63,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected",
                        "static"
                    ],
                    "type": "property",
                    "name": "escaperService",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 63,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 65,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected",
                        "static"
                    ],
                    "type": "property",
                    "name": "urlService",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 65,
                        "char": 39
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 69,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "appendTitle",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "title",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 70,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "static-property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "self",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 72,
                                        "char": 40
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "documentAppendTitle",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 72,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 72,
                                    "char": 40
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 72,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 72,
                                "char": 47
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "static-property",
                                            "operator": "assign",
                                            "variable": "self",
                                            "property": "documentAppendTitle",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 73,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 73,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 74,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 76,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "title",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 76,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 76,
                                    "char": 26
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 76,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 76,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "static-property",
                                            "operator": "assign",
                                            "variable": "self",
                                            "property": "documentAppendTitle",
                                            "expr": {
                                                "type": "variable",
                                                "value": "title",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 77,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 77,
                                            "char": 51
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 78,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "static-property-append",
                                            "operator": "assign",
                                            "variable": "self",
                                            "property": "documentAppendTitle",
                                            "expr": {
                                                "type": "variable",
                                                "value": "title",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 79,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 79,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 80,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 81,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Appends a text to current document title\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 71,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 70,
                    "last-line": 101,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "checkField",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 102,
                            "char": 53
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "self",
                                "dynamic": 0,
                                "name": "inputFieldChecked",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "checkbox",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 104,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 104,
                                        "char": 48
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "parameters",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 104,
                                            "char": 60
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 104,
                                        "char": 60
                                    }
                                ],
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 104,
                                "char": 61
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 105,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds a HTML input[type=\"check\"] tag\n     *\n     *```php\n     * echo Phalcon\\Tag::checkField(\n     *     [\n     *         \"terms\",\n     *         \"value\" => \"Y\",\n     *     ]\n     * );\n     *```\n     *\n     * Volt syntax:\n     *```php\n     * {{ check_field(\"terms\") }}\n     *```\n     *\n     * @param array parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 103,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 103,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 102,
                    "last-line": 111,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "colorField",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 112,
                            "char": 53
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "self",
                                "dynamic": 0,
                                "name": "inputField",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "color",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 114,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 114,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "parameters",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 114,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 114,
                                        "char": 50
                                    }
                                ],
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 114,
                                "char": 51
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 115,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds a HTML input[type=\"color\"] tag\n     *\n     * @param array parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 113,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 113,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 112,
                    "last-line": 130,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "dateField",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 131,
                            "char": 52
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "self",
                                "dynamic": 0,
                                "name": "inputField",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "date",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 133,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 133,
                                        "char": 37
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "parameters",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 133,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 133,
                                        "char": 49
                                    }
                                ],
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 133,
                                "char": 50
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 134,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds a HTML input[type=\"date\"] tag\n     *\n     * ```php\n     * echo Phalcon\\Tag::dateField(\n     *     [\n     *         \"born\",\n     *         \"value\" => \"14-12-1980\",\n     *     ]\n     * );\n     * ```\n     *\n     * @param array parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 132,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 132,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 131,
                    "last-line": 140,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "dateTimeField",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 141,
                            "char": 56
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "self",
                                "dynamic": 0,
                                "name": "inputField",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "datetime",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 143,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 143,
                                        "char": 41
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "parameters",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 143,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 143,
                                        "char": 53
                                    }
                                ],
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 143,
                                "char": 54
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 144,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n    * Builds a HTML input[type=\"datetime\"] tag\n    *\n    * @param array parameters\n    *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 142,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 142,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 141,
                    "last-line": 150,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "dateTimeLocalField",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 151,
                            "char": 61
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "self",
                                "dynamic": 0,
                                "name": "inputField",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "datetime-local",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 153,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 153,
                                        "char": 47
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "parameters",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 153,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 153,
                                        "char": 59
                                    }
                                ],
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 153,
                                "char": 60
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 154,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n    * Builds a HTML input[type=\"datetime-local\"] tag\n    *\n    * @param array parameters\n    *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 152,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 152,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 151,
                    "last-line": 160,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "displayTo",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "id",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 161,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 161,
                            "char": 55
                        }
                    ],
                    "statements": [
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "self",
                                "dynamic": 0,
                                "name": "setDefault",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "id",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 163,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 163,
                                        "char": 28
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 163,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 163,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 163,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 164,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Alias of Phalcon\\Tag::setDefault()\n     *\n     * @param string value\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 162,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 161,
                    "last-line": 174,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "emailField",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 175,
                            "char": 53
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "self",
                                "dynamic": 0,
                                "name": "inputField",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "email",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 177,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 177,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "parameters",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 177,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 177,
                                        "char": 50
                                    }
                                ],
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 177,
                                "char": 51
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 178,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds a HTML input[type=\"email\"] tag\n     *\n     * ```php\n     * echo Phalcon\\Tag::emailField(\"email\");\n     * ```\n     *\n     * @param array parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 176,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 176,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 175,
                    "last-line": 182,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "endForm",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "string",
                                "value": "<\/form>",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 185,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 186,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds a HTML close FORM tag\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 184,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 184,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 183,
                    "last-line": 196,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "fileField",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 197,
                            "char": 52
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "self",
                                "dynamic": 0,
                                "name": "inputField",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "file",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 199,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 199,
                                        "char": 37
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "parameters",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 199,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 199,
                                        "char": 49
                                    }
                                ],
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 199,
                                "char": 50
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 200,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds a HTML input[type=\"file\"] tag\n     *\n     *```php\n     * echo Phalcon\\Tag::fileField(\"file\");\n     *```\n     *\n     * @param array parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 198,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 198,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 197,
                    "last-line": 223,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "form",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 224,
                            "char": 47
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "params",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 226,
                                    "char": 19
                                },
                                {
                                    "variable": "paramsAction",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 226,
                                    "char": 33
                                },
                                {
                                    "variable": "action",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 226,
                                    "char": 41
                                },
                                {
                                    "variable": "code",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 226,
                                    "char": 47
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 228,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "parameters",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 228,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 228,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 228,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 228,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "params",
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "parameters",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 229,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 229,
                                                        "char": 37
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 229,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 229,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 230,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "params",
                                            "expr": {
                                                "type": "variable",
                                                "value": "parameters",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 231,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 231,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 232,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 234,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "paramsAction",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 234,
                                        "char": 43
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 234,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 234,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 234,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 234,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 234,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "fetch",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "paramsAction",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 235,
                                            "char": 47
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "params",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 235,
                                                "char": 39
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "action",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 235,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 235,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 235,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 236,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 241,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 241,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "method",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 241,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 241,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 241,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 241,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "params",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "method",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 242,
                                                    "char": 30
                                                }
                                            ],
                                            "expr": {
                                                "type": "string",
                                                "value": "post",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 242,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 242,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 243,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 245,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "action",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 245,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 245,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 247,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "empty",
                                    "left": {
                                        "type": "variable",
                                        "value": "paramsAction",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 247,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 247,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 247,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "action",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "scall",
                                                    "dynamic-class": 0,
                                                    "class": "self",
                                                    "dynamic": 0,
                                                    "name": "getUrlService",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 248,
                                                    "char": 48
                                                },
                                                "name": "get",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "paramsAction",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 248,
                                                            "char": 65
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 248,
                                                        "char": 65
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 248,
                                                "char": 66
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 248,
                                            "char": 66
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 249,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 254,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "parameters",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 254,
                                    "char": 49
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "params",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 254,
                                        "char": 36
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "parameters",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 254,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 254,
                                    "char": 49
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 254,
                                "char": 49
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "action",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": "?",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 255,
                                                    "char": 28
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "parameters",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 255,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 255,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 255,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 256,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 258,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "empty",
                                    "left": {
                                        "type": "variable",
                                        "value": "action",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 258,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 258,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 258,
                                "char": 26
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "params",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "action",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 259,
                                                    "char": 30
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "action",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 259,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 259,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 260,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 262,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "code",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "self",
                                        "dynamic": 0,
                                        "name": "renderAttributes",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "<form",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 262,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 262,
                                                "char": 48
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 262,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 262,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 262,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 262,
                                    "char": 57
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "concat-assign",
                                    "variable": "code",
                                    "expr": {
                                        "type": "string",
                                        "value": ">",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 263,
                                        "char": 21
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 263,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 265,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "code",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 265,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 266,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds a HTML FORM tag\n     *\n     * ```php\n     * echo Phalcon\\Tag::form(\"posts\/save\");\n     *\n     * echo Phalcon\\Tag::form(\n     *     [\n     *         \"posts\/save\",\n     *         \"method\" => \"post\",\n     *     ]\n     * );\n     * ```\n     *\n     * Volt syntax:\n     * ```php\n     * {{ form(\"posts\/save\") }}\n     * {{ form(\"posts\/save\", \"method\": \"post\") }}\n     * ```\n     *\n     * @param array parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 225,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 225,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 224,
                    "last-line": 274,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "friendlyTitle",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 276,
                            "char": 20
                        },
                        {
                            "type": "parameter",
                            "name": "separator",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "string",
                                "value": "-",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 277,
                                "char": 29
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 277,
                            "char": 29
                        },
                        {
                            "type": "parameter",
                            "name": "lowercase",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 278,
                                "char": 30
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 278,
                            "char": 30
                        },
                        {
                            "type": "parameter",
                            "name": "replace",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 280,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 280,
                            "char": 5
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "friendly",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 282,
                                    "char": 21
                                },
                                {
                                    "variable": "locale",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 282,
                                    "char": 29
                                },
                                {
                                    "variable": "search",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 282,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 284,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "extension_loaded",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "iconv",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 284,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 284,
                                        "char": 34
                                    }
                                ],
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 284,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "locale",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "setlocale",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "constant",
                                                            "value": "LC_ALL",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 288,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 288,
                                                        "char": 42
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "en_US.UTF-8",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 288,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 288,
                                                        "char": 55
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 288,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 288,
                                            "char": 56
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "text",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "iconv",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "UTF-8",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 289,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 289,
                                                        "char": 35
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "ASCII\/\/TRANSLIT",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 289,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 289,
                                                        "char": 52
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "text",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 289,
                                                            "char": 58
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 289,
                                                        "char": 58
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 289,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 289,
                                            "char": 59
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 290,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 292,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "replace",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 292,
                                "char": 20
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "list",
                                            "left": {
                                                "type": "and",
                                                "left": {
                                                    "type": "not-equals",
                                                    "left": {
                                                        "type": "typeof",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "replace",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 293,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 293,
                                                        "char": 42
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "array",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 293,
                                                        "char": 51
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 293,
                                                    "char": 51
                                                },
                                                "right": {
                                                    "type": "not-equals",
                                                    "left": {
                                                        "type": "typeof",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "replace",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 293,
                                                            "char": 69
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 293,
                                                        "char": 69
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "string",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 293,
                                                        "char": 77
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 293,
                                                    "char": 77
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 293,
                                                "char": 77
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 293,
                                            "char": 79
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 293,
                                        "char": 79
                                    },
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
                                                            "value": "Parameter replace must be an array or a string",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 296,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 296,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 296,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 297,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 299,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "replace",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 299,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 299,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 299,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 299,
                                        "char": 40
                                    },
                                    "statements": [
                                        {
                                            "type": "for",
                                            "expr": {
                                                "type": "variable",
                                                "value": "replace",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 300,
                                                "char": 39
                                            },
                                            "value": "search",
                                            "reverse": 0,
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "text",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "str_replace",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "search",
                                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                                            "line": 301,
                                                                            "char": 50
                                                                        },
                                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                                        "line": 301,
                                                                        "char": 50
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": " ",
                                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                                            "line": 301,
                                                                            "char": 53
                                                                        },
                                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                                        "line": 301,
                                                                        "char": 53
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "text",
                                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                                            "line": 301,
                                                                            "char": 59
                                                                        },
                                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                                        "line": 301,
                                                                        "char": 59
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 301,
                                                                "char": 60
                                                            },
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 301,
                                                            "char": 60
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 302,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 303,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "text",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "str_replace",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "replace",
                                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                                    "line": 304,
                                                                    "char": 47
                                                                },
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 304,
                                                                "char": 47
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": " ",
                                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                                    "line": 304,
                                                                    "char": 50
                                                                },
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 304,
                                                                "char": 50
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "text",
                                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                                    "line": 304,
                                                                    "char": 56
                                                                },
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 304,
                                                                "char": 56
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 304,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 304,
                                                    "char": 57
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 305,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 306,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 308,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "friendly",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "preg_replace",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "\/[^a-zA-Z0-9\\\\\/_|+ -]\/",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 309,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 309,
                                                "char": 35
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 310,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 310,
                                                "char": 13
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "text",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 312,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 312,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 312,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 312,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 314,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "lowercase",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 314,
                                "char": 22
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "friendly",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "strtolower",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "friendly",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 315,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 315,
                                                        "char": 47
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 315,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 315,
                                            "char": 48
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 316,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 318,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "friendly",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "preg_replace",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "\/[\\\\\/_|+ -]+\/",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 318,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 318,
                                                "char": 50
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "separator",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 318,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 318,
                                                "char": 61
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "friendly",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 318,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 318,
                                                "char": 71
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 318,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 318,
                                    "char": 72
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "friendly",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "trim",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "friendly",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 319,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 319,
                                                "char": 37
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "separator",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 319,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 319,
                                                "char": 48
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 319,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 319,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 321,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "extension_loaded",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "iconv",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 321,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 321,
                                        "char": 34
                                    }
                                ],
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 321,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "setlocale",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "constant",
                                                    "value": "LC_ALL",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 325,
                                                    "char": 29
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 325,
                                                "char": 29
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "locale",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 325,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 325,
                                                "char": 37
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 325,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 326,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 327,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "friendly",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 327,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 328,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Converts texts into URL-friendly titles\n     *\n     *```php\n     * echo Phalcon\\Tag::friendlyTitle(\"These are big important news\", \"-\")\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 281,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 281,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 275,
                    "last-line": 332,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "getDocType",
                    "statements": [
                        {
                            "type": "switch",
                            "expr": {
                                "type": "static-property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "self",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 336,
                                    "char": 9
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "documentType",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 336,
                                    "char": 9
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 336,
                                "char": 9
                            },
                            "clauses": [
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "int",
                                        "value": "1",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 337,
                                        "char": 19
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": "<!DOCTYPE html PUBLIC \\\"-\/\/W3C\/\/DTD HTML 3.2 Final\/\/EN\\\">",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 337,
                                                    "char": 87
                                                },
                                                "right": {
                                                    "type": "constant",
                                                    "value": "PHP_EOL",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 337,
                                                    "char": 96
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 337,
                                                "char": 96
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 340,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 340,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "int",
                                        "value": "2",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 340,
                                        "char": 19
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "<!DOCTYPE html PUBLIC \\\"-\/\/W3C\/\/DTD HTML 4.01\/\/EN\\\"",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 340,
                                                            "char": 81
                                                        },
                                                        "right": {
                                                            "type": "constant",
                                                            "value": "PHP_EOL",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 340,
                                                            "char": 91
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 340,
                                                        "char": 91
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "\\t\\\"http:\/\/www.w3.org\/TR\/html4\/strict.dtd\\\">",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 340,
                                                        "char": 138
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 340,
                                                    "char": 138
                                                },
                                                "right": {
                                                    "type": "constant",
                                                    "value": "PHP_EOL",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 340,
                                                    "char": 147
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 340,
                                                "char": 147
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 343,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 343,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "int",
                                        "value": "3",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 343,
                                        "char": 19
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "<!DOCTYPE html PUBLIC \\\"-\/\/W3C\/\/DTD HTML 4.01 Transitional\/\/EN\\\"",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 343,
                                                            "char": 94
                                                        },
                                                        "right": {
                                                            "type": "constant",
                                                            "value": "PHP_EOL",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 343,
                                                            "char": 104
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 343,
                                                        "char": 104
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "\\t\\\"http:\/\/www.w3.org\/TR\/html4\/loose.dtd\\\">",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 343,
                                                        "char": 150
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 343,
                                                    "char": 150
                                                },
                                                "right": {
                                                    "type": "constant",
                                                    "value": "PHP_EOL",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 343,
                                                    "char": 159
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 343,
                                                "char": 159
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 346,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 346,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "int",
                                        "value": "4",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 346,
                                        "char": 19
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "<!DOCTYPE html PUBLIC \\\"-\/\/W3C\/\/DTD HTML 4.01 Frameset\/\/EN\\\"",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 346,
                                                            "char": 90
                                                        },
                                                        "right": {
                                                            "type": "constant",
                                                            "value": "PHP_EOL",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 346,
                                                            "char": 100
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 346,
                                                        "char": 100
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "\\t\\\"http:\/\/www.w3.org\/TR\/html4\/frameset.dtd\\\">",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 346,
                                                        "char": 149
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 346,
                                                    "char": 149
                                                },
                                                "right": {
                                                    "type": "constant",
                                                    "value": "PHP_EOL",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 346,
                                                    "char": 158
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 346,
                                                "char": 158
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 349,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 349,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "int",
                                        "value": "6",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 349,
                                        "char": 19
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "<!DOCTYPE html PUBLIC \\\"-\/\/W3C\/\/DTD XHTML 1.0 Strict\/\/EN\\\"",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 349,
                                                            "char": 88
                                                        },
                                                        "right": {
                                                            "type": "constant",
                                                            "value": "PHP_EOL",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 349,
                                                            "char": 98
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 349,
                                                        "char": 98
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "\\t\\\"http:\/\/www.w3.org\/TR\/xhtml1\/DTD\/xhtml1-strict.dtd\\\">",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 349,
                                                        "char": 157
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 349,
                                                    "char": 157
                                                },
                                                "right": {
                                                    "type": "constant",
                                                    "value": "PHP_EOL",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 349,
                                                    "char": 166
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 349,
                                                "char": 166
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 352,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 352,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "int",
                                        "value": "7",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 352,
                                        "char": 19
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "<!DOCTYPE html PUBLIC \\\"-\/\/W3C\/\/DTD XHTML 1.0 Transitional\/\/EN\\\"",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 352,
                                                            "char": 94
                                                        },
                                                        "right": {
                                                            "type": "constant",
                                                            "value": "PHP_EOL",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 352,
                                                            "char": 103
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 352,
                                                        "char": 103
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "\\t\\\"http:\/\/www.w3.org\/TR\/xhtml1\/DTD\/xhtml1-transitional.dtd\\\">",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 352,
                                                        "char": 167
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 352,
                                                    "char": 167
                                                },
                                                "right": {
                                                    "type": "constant",
                                                    "value": "PHP_EOL",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 352,
                                                    "char": 176
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 352,
                                                "char": 176
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 355,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 355,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "int",
                                        "value": "8",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 355,
                                        "char": 19
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "<!DOCTYPE html PUBLIC \\\"-\/\/W3C\/\/DTD XHTML 1.0 Frameset\/\/EN\\\"",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 355,
                                                            "char": 90
                                                        },
                                                        "right": {
                                                            "type": "constant",
                                                            "value": "PHP_EOL",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 355,
                                                            "char": 100
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 355,
                                                        "char": 100
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "\\t\\\"http:\/\/www.w3.org\/TR\/xhtml1\/DTD\/xhtml1-frameset.dtd\\\">",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 355,
                                                        "char": 161
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 355,
                                                    "char": 161
                                                },
                                                "right": {
                                                    "type": "constant",
                                                    "value": "PHP_EOL",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 355,
                                                    "char": 170
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 355,
                                                "char": 170
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 358,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 358,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "int",
                                        "value": "9",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 358,
                                        "char": 19
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "<!DOCTYPE html PUBLIC \\\"-\/\/W3C\/\/DTD XHTML 1.1\/\/EN\\\"",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 358,
                                                            "char": 81
                                                        },
                                                        "right": {
                                                            "type": "constant",
                                                            "value": "PHP_EOL",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 358,
                                                            "char": 91
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 358,
                                                        "char": 91
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "\\t\\\"http:\/\/www.w3.org\/TR\/xhtml11\/DTD\/xhtml11.dtd\\\">",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 358,
                                                        "char": 145
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 358,
                                                    "char": 145
                                                },
                                                "right": {
                                                    "type": "constant",
                                                    "value": "PHP_EOL",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 358,
                                                    "char": 154
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 358,
                                                "char": 154
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 361,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 361,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "int",
                                        "value": "10",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 361,
                                        "char": 20
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "<!DOCTYPE html PUBLIC \\\"-\/\/W3C\/\/DTD XHTML 2.0\/\/EN\\\"",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 361,
                                                            "char": 81
                                                        },
                                                        "right": {
                                                            "type": "constant",
                                                            "value": "PHP_EOL",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 361,
                                                            "char": 91
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 361,
                                                        "char": 91
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "\\t\\\"http:\/\/www.w3.org\/MarkUp\/DTD\/xhtml2.dtd\\\">",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 361,
                                                        "char": 140
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 361,
                                                    "char": 140
                                                },
                                                "right": {
                                                    "type": "constant",
                                                    "value": "PHP_EOL",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 361,
                                                    "char": 149
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 361,
                                                "char": 149
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 364,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 364,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "int",
                                        "value": "5",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 364,
                                        "char": 19
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 365,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "int",
                                        "value": "11",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 365,
                                        "char": 20
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": "<!DOCTYPE html>",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 365,
                                                    "char": 45
                                                },
                                                "right": {
                                                    "type": "constant",
                                                    "value": "PHP_EOL",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 365,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 365,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 367,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 367,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 369,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "string",
                                "value": "",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 369,
                                "char": 16
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 370,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Get the document type declaration of content\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 334,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 334,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 333,
                    "last-line": 374,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "getEscaper",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "params",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 375,
                            "char": 52
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "autoescape",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 377,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 379,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "autoescape",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 379,
                                        "char": 46
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 379,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "escape",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 379,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 379,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 379,
                                    "char": 46
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 379,
                                "char": 46
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "autoescape",
                                            "expr": {
                                                "type": "static-property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 380,
                                                    "char": 46
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "autoEscape",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 380,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 380,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 380,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 381,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 383,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "autoescape",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 383,
                                    "char": 24
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 383,
                                "char": 24
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 384,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 385,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 387,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "self",
                                "dynamic": 0,
                                "name": "getEscaperService",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 387,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 388,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Obtains the 'escaper' service if required\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "EscaperInterface",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 375,
                                    "char": 76
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 375,
                                "char": 76
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 376,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 376,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 375,
                    "last-line": 392,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "getDI",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "di",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 395,
                                    "char": 15
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 397,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "di",
                                    "expr": {
                                        "type": "static-property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 397,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "container",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 397,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 397,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 397,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 399,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "di",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 399,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 399,
                                    "char": 23
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 399,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 399,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "di",
                                            "expr": {
                                                "type": "scall",
                                                "dynamic-class": 0,
                                                "class": "Di",
                                                "dynamic": 0,
                                                "name": "getDefault",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 400,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 400,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 401,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 403,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "di",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 403,
                                "char": 18
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 404,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Internally gets the request dispatcher\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "DiInterface",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 394,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 394,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 394,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 393,
                    "last-line": 408,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "getEscaperService",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "escaper",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 411,
                                    "char": 20
                                },
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 411,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 413,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "escaper",
                                    "expr": {
                                        "type": "static-property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 413,
                                            "char": 43
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "escaperService",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 413,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 413,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 413,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 415,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "escaper",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 415,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 415,
                                    "char": 28
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 415,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 415,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "container",
                                            "expr": {
                                                "type": "scall",
                                                "dynamic-class": 0,
                                                "class": "self",
                                                "dynamic": 0,
                                                "name": "getDI",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 416,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 416,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 418,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "not-equals",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 418,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 418,
                                                "char": 43
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 418,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 418,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 418,
                                        "char": 52
                                    },
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
                                                            "type": "scall",
                                                            "dynamic-class": 0,
                                                            "class": "Exception",
                                                            "dynamic": 0,
                                                            "name": "containerServiceNotFound",
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "the 'escaper' service",
                                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                                        "line": 420,
                                                                        "char": 78
                                                                    },
                                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                                    "line": 420,
                                                                    "char": 78
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 421,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 421,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 421,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 422,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 424,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "escaper",
                                            "expr": {
                                                "type": "type-hint",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "EscaperInterface",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 424,
                                                    "char": 75
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "container",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 424,
                                                        "char": 56
                                                    },
                                                    "name": "getShared",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "escaper",
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 424,
                                                                "char": 74
                                                            },
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 424,
                                                            "char": 74
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 424,
                                                    "char": 75
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 424,
                                                "char": 75
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 424,
                                            "char": 75
                                        },
                                        {
                                            "assign-type": "static-property",
                                            "operator": "assign",
                                            "variable": "self",
                                            "property": "escaperService",
                                            "expr": {
                                                "type": "variable",
                                                "value": "escaper",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 425,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 425,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 426,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 428,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "escaper",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 428,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 429,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns an Escaper service from the default DI\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "EscaperInterface",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 410,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 410,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 410,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 409,
                    "last-line": 449,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "getTitle",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "prepend",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 450,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 450,
                            "char": 56
                        },
                        {
                            "type": "parameter",
                            "name": "append",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 450,
                                "char": 76
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 450,
                            "char": 76
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "items",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 452,
                                    "char": 18
                                },
                                {
                                    "variable": "output",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 452,
                                    "char": 26
                                },
                                {
                                    "variable": "title",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 452,
                                    "char": 33
                                },
                                {
                                    "variable": "documentTitle",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 452,
                                    "char": 48
                                },
                                {
                                    "variable": "documentAppendTitle",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 452,
                                    "char": 69
                                },
                                {
                                    "variable": "documentPrependTitle",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 453,
                                    "char": 33
                                },
                                {
                                    "variable": "documentTitleSeparator",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 453,
                                    "char": 57
                                },
                                {
                                    "variable": "escaper",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 453,
                                    "char": 66
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 455,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "escaper",
                                    "expr": {
                                        "type": "type-hint",
                                        "left": {
                                            "type": "variable",
                                            "value": "EscaperInterface",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 455,
                                            "char": 74
                                        },
                                        "right": {
                                            "type": "scall",
                                            "dynamic-class": 0,
                                            "class": "self",
                                            "dynamic": 0,
                                            "name": "getEscaper",
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "array",
                                                        "left": [
                                                            {
                                                                "key": {
                                                                    "type": "string",
                                                                    "value": "escape",
                                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                                    "line": 455,
                                                                    "char": 66
                                                                },
                                                                "value": {
                                                                    "type": "bool",
                                                                    "value": "true",
                                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                                    "line": 455,
                                                                    "char": 72
                                                                },
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 455,
                                                                "char": 72
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 455,
                                                        "char": 73
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 455,
                                                    "char": 73
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 455,
                                            "char": 74
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 455,
                                        "char": 74
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 455,
                                    "char": 74
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 456,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "items",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 456,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 456,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 457,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "output",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 457,
                                        "char": 22
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 457,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 458,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "documentTitle",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "escaper",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 458,
                                            "char": 37
                                        },
                                        "name": "escapeHtml",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "static-property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "self",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 458,
                                                        "char": 68
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "documentTitle",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 458,
                                                        "char": 68
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 458,
                                                    "char": 68
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 458,
                                                "char": 68
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 458,
                                        "char": 69
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 458,
                                    "char": 69
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 460,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "documentTitleSeparator",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "escaper",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 460,
                                            "char": 46
                                        },
                                        "name": "escapeHtml",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "static-property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "self",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 462,
                                                        "char": 9
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "documentTitleSeparator",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 462,
                                                        "char": 9
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 462,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 462,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 462,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 462,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 464,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "prepend",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 464,
                                "char": 20
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "static-property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 465,
                                                "char": 45
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "documentPrependTitle",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 465,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 465,
                                            "char": 45
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 465,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 465,
                                        "char": 52
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "static-property",
                                                    "operator": "assign",
                                                    "variable": "self",
                                                    "property": "documentPrependTitle",
                                                    "expr": {
                                                        "type": "empty-array",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 466,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 466,
                                                    "char": 52
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 467,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 469,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "documentPrependTitle",
                                            "expr": {
                                                "type": "static-property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 469,
                                                    "char": 66
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "documentPrependTitle",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 469,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 469,
                                                "char": 66
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 469,
                                            "char": 66
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 471,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "empty",
                                            "left": {
                                                "type": "variable",
                                                "value": "documentPrependTitle",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 471,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 471,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 471,
                                        "char": 44
                                    },
                                    "statements": [
                                        {
                                            "type": "declare",
                                            "data-type": "variable",
                                            "variables": [
                                                {
                                                    "variable": "tmp",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "array_reverse",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "documentPrependTitle",
                                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                                    "line": 472,
                                                                    "char": 61
                                                                },
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 472,
                                                                "char": 61
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 472,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 472,
                                                    "char": 62
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 474,
                                            "char": 19
                                        },
                                        {
                                            "type": "for",
                                            "expr": {
                                                "type": "variable",
                                                "value": "tmp",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 474,
                                                "char": 34
                                            },
                                            "value": "title",
                                            "reverse": 0,
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable-append",
                                                            "operator": "assign",
                                                            "variable": "items",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "escaper",
                                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                                    "line": 475,
                                                                    "char": 43
                                                                },
                                                                "name": "escapeHtml",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "title",
                                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                                            "line": 475,
                                                                            "char": 60
                                                                        },
                                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                                        "line": 475,
                                                                        "char": 60
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 475,
                                                                "char": 61
                                                            },
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 475,
                                                            "char": 61
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 476,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 477,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 478,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 480,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "empty",
                                    "left": {
                                        "type": "variable",
                                        "value": "documentTitle",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 480,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 480,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 480,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "items",
                                            "expr": {
                                                "type": "variable",
                                                "value": "documentTitle",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 481,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 481,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 482,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 484,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "append",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 484,
                                "char": 19
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "static-property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 485,
                                                "char": 44
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "documentAppendTitle",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 485,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 485,
                                            "char": 44
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 485,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 485,
                                        "char": 51
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "static-property",
                                                    "operator": "assign",
                                                    "variable": "self",
                                                    "property": "documentAppendTitle",
                                                    "expr": {
                                                        "type": "empty-array",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 486,
                                                        "char": 51
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 486,
                                                    "char": 51
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 487,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 489,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "documentAppendTitle",
                                            "expr": {
                                                "type": "static-property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 489,
                                                    "char": 64
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "documentAppendTitle",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 489,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 489,
                                                "char": 64
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 489,
                                            "char": 64
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 491,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "empty",
                                            "left": {
                                                "type": "variable",
                                                "value": "documentAppendTitle",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 491,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 491,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 491,
                                        "char": 43
                                    },
                                    "statements": [
                                        {
                                            "type": "for",
                                            "expr": {
                                                "type": "variable",
                                                "value": "documentAppendTitle",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 492,
                                                "char": 50
                                            },
                                            "value": "title",
                                            "reverse": 0,
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable-append",
                                                            "operator": "assign",
                                                            "variable": "items",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "escaper",
                                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                                    "line": 493,
                                                                    "char": 43
                                                                },
                                                                "name": "escapeHtml",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "title",
                                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                                            "line": 493,
                                                                            "char": 60
                                                                        },
                                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                                        "line": 493,
                                                                        "char": 60
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 493,
                                                                "char": 61
                                                            },
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 493,
                                                            "char": 61
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 494,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 495,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 496,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 498,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "empty",
                                "left": {
                                    "type": "variable",
                                    "value": "documentTitleSeparator",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 498,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 498,
                                "char": 41
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "documentTitleSeparator",
                                            "expr": {
                                                "type": "string",
                                                "value": "",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 499,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 499,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 500,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 502,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "empty",
                                    "left": {
                                        "type": "variable",
                                        "value": "items",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 502,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 502,
                                    "char": 25
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 502,
                                "char": 25
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "output",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "implode",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "documentTitleSeparator",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 503,
                                                            "char": 56
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 503,
                                                        "char": 56
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "items",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 503,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 503,
                                                        "char": 63
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 503,
                                                "char": 64
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 503,
                                            "char": 64
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 504,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 506,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "output",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 506,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 507,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets the current document title.\n     * The title will be automatically escaped.\n     *\n     * ```php\n     * Tag::prependTitle('Hello');\n     * Tag::setTitle('World');\n     * Tag::appendTitle('from Phalcon');\n     *\n     * echo Tag::getTitle();             \/\/ Hello World from Phalcon\n     * echo Tag::getTitle(false);        \/\/ World from Phalcon\n     * echo Tag::getTitle(true, false);  \/\/ Hello World\n     * echo Tag::getTitle(false, false); \/\/ World\n     * ```\n     *\n     * ```php\n     * {{ get_title() }}\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 451,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 451,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 450,
                    "last-line": 519,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "getTitleSeparator",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "static-property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "self",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 522,
                                    "char": 44
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "documentTitleSeparator",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 522,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 522,
                                "char": 44
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 523,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets the current document title separator\n     *\n     * ```php\n     * echo Phalcon\\Tag::getTitleSeparator();\n     * ```\n     *\n     * ```php\n     * {{ get_title_separator() }}\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 521,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 521,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 520,
                    "last-line": 527,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "getUrlService",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "url",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 530,
                                    "char": 16
                                },
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 530,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 532,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "url",
                                    "expr": {
                                        "type": "static-property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 532,
                                            "char": 35
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "urlService",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 532,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 532,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 532,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 534,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "url",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 534,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 534,
                                    "char": 24
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 534,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 534,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "container",
                                            "expr": {
                                                "type": "scall",
                                                "dynamic-class": 0,
                                                "class": "self",
                                                "dynamic": 0,
                                                "name": "getDI",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 535,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 535,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 537,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "not-equals",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 537,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 537,
                                                "char": 43
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 537,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 537,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 537,
                                        "char": 52
                                    },
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
                                                            "type": "scall",
                                                            "dynamic-class": 0,
                                                            "class": "Exception",
                                                            "dynamic": 0,
                                                            "name": "containerServiceNotFound",
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "the 'url' service",
                                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                                        "line": 539,
                                                                        "char": 74
                                                                    },
                                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                                    "line": 539,
                                                                    "char": 74
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 540,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 540,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 540,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 541,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 543,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "url",
                                            "expr": {
                                                "type": "type-hint",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "UrlInterface",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 543,
                                                    "char": 63
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "container",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 543,
                                                        "char": 48
                                                    },
                                                    "name": "getShared",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "url",
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 543,
                                                                "char": 62
                                                            },
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 543,
                                                            "char": 62
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 543,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 543,
                                                "char": 63
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 543,
                                            "char": 63
                                        },
                                        {
                                            "assign-type": "static-property",
                                            "operator": "assign",
                                            "variable": "self",
                                            "property": "urlService",
                                            "expr": {
                                                "type": "variable",
                                                "value": "url",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 544,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 544,
                                            "char": 39
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 545,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 547,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "url",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 547,
                                "char": 19
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 548,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a URL service from the default DI\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "UrlInterface",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 529,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 529,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 529,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 528,
                    "last-line": 556,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "getValue",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 557,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "params",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 557,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 557,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 559,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 561,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 561,
                                        "char": 40
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 561,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 561,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 561,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 561,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 561,
                                "char": 40
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "fetch",
                                            "left": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 565,
                                                "char": 56
                                            },
                                            "right": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "static-property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "self",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 565,
                                                        "char": 49
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "displayValues",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 565,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 565,
                                                    "char": 49
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 565,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 565,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 565,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 565,
                                        "char": 56
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not",
                                                "left": {
                                                    "type": "fetch",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 569,
                                                        "char": 46
                                                    },
                                                    "right": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "_POST",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 569,
                                                            "char": 39
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 569,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 569,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 569,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 569,
                                                "char": 46
                                            },
                                            "statements": [
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "null",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 570,
                                                        "char": 32
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 571,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 572,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 573,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 575,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "value",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 575,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 576,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Every helper calls this function to check whether a component has a\n     * predefined value using Phalcon\\Tag::setDefault() or value from $_POST\n     *\n     * @param string name\n     * @return mixed\n     *",
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 557,
                    "last-line": 583,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "hasValue",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 584,
                            "char": 45
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "static-property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 589,
                                                "char": 41
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "displayValues",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 589,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 589,
                                            "char": 41
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 589,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 589,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 589,
                                    "char": 49
                                },
                                "right": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "_POST",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 589,
                                            "char": 62
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 589,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 589,
                                        "char": 68
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 589,
                                    "char": 68
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 589,
                                "char": 68
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 590,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check if a helper has a default value set using Phalcon\\Tag::setDefault()\n     * or value from $_POST\n     *\n     * @param string name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 585,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 585,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 584,
                    "last-line": 605,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "hiddenField",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 606,
                            "char": 54
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "self",
                                "dynamic": 0,
                                "name": "inputField",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "hidden",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 608,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 608,
                                        "char": 39
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "parameters",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 608,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 608,
                                        "char": 51
                                    }
                                ],
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 608,
                                "char": 52
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 609,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds a HTML input[type=\"hidden\"] tag\n     *\n     *```php\n     * echo Phalcon\\Tag::hiddenField(\n     *     [\n     *         \"name\",\n     *         \"value\" => \"mike\",\n     *     ]\n     * );\n     *```\n     *\n     * @param array parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 607,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 607,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 606,
                    "last-line": 633,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "image",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 634,
                                "char": 55
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 634,
                            "char": 55
                        },
                        {
                            "type": "parameter",
                            "name": "local",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 634,
                                "char": 74
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 634,
                            "char": 74
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "params",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 636,
                                    "char": 19
                                },
                                {
                                    "variable": "code",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 636,
                                    "char": 25
                                },
                                {
                                    "variable": "src",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 636,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 638,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "parameters",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 638,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 638,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 638,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 638,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "params",
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "parameters",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 639,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 639,
                                                        "char": 37
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 639,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 639,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 640,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "params",
                                            "expr": {
                                                "type": "variable",
                                                "value": "parameters",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 641,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 641,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 643,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "isset",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "params",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 643,
                                                "char": 28
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "1",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 643,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 643,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 643,
                                        "char": 32
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "local",
                                                    "expr": {
                                                        "type": "cast",
                                                        "left": "bool",
                                                        "right": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "params",
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 644,
                                                                "char": 42
                                                            },
                                                            "right": {
                                                                "type": "int",
                                                                "value": "1",
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 644,
                                                                "char": 44
                                                            },
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 644,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 644,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 644,
                                                    "char": 45
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 645,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 646,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 648,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 648,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "src",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 648,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 648,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 648,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 648,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "src",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 649,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "params",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 649,
                                                "char": 33
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 649,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 649,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 649,
                                        "char": 37
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "params",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "src",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 650,
                                                            "char": 31
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "src",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 650,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 650,
                                                    "char": 38
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 651,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "params",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "src",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 652,
                                                            "char": 31
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 652,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 652,
                                                    "char": 35
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 653,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 654,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 659,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "local",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 659,
                                "char": 18
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "params",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "src",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 660,
                                                    "char": 27
                                                }
                                            ],
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "scall",
                                                    "dynamic-class": 0,
                                                    "class": "self",
                                                    "dynamic": 0,
                                                    "name": "getUrlService",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 660,
                                                    "char": 53
                                                },
                                                "name": "getStatic",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "params",
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 660,
                                                                "char": 70
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "src",
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 660,
                                                                "char": 74
                                                            },
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 660,
                                                            "char": 75
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 660,
                                                        "char": 75
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 660,
                                                "char": 76
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 660,
                                            "char": 76
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 661,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 663,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "code",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "self",
                                        "dynamic": 0,
                                        "name": "renderAttributes",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "<img",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 663,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 663,
                                                "char": 47
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 663,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 663,
                                                "char": 55
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 663,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 663,
                                    "char": 56
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 668,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "greater",
                                "left": {
                                    "type": "static-property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "self",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 668,
                                        "char": 31
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "documentType",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 668,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 668,
                                    "char": 31
                                },
                                "right": {
                                    "type": "static-constant-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "self",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 668,
                                        "char": 45
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "HTML5",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 668,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 668,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 668,
                                "char": 45
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "code",
                                            "expr": {
                                                "type": "string",
                                                "value": " \/>",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 669,
                                                "char": 27
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 669,
                                            "char": 27
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 670,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "code",
                                            "expr": {
                                                "type": "string",
                                                "value": ">",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 671,
                                                "char": 25
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 671,
                                            "char": 25
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 672,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 674,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "code",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 674,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 675,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds HTML IMG tags\n     *\n     * ```php\n     * echo Phalcon\\Tag::image(\"img\/bg.png\");\n     *\n     * echo Phalcon\\Tag::image(\n     *     [\n     *         \"img\/photo.jpg\",\n     *         \"alt\" => \"Some Photo\",\n     *     ]\n     * );\n     * ```\n     *\n     * Volt Syntax:\n     * ```php\n     * {{ image(\"img\/bg.png\") }}\n     * {{ image(\"img\/photo.jpg\", \"alt\": \"Some Photo\") }}\n     * {{ image(\"http:\/\/static.mywebsite.com\/img\/bg.png\", false) }}\n     * ```\n     *\n     * @param  array parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 635,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 635,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 634,
                    "last-line": 694,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "imageInput",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 695,
                            "char": 53
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "self",
                                "dynamic": 0,
                                "name": "inputField",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "image",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 697,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 697,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "parameters",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 697,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 697,
                                        "char": 50
                                    },
                                    {
                                        "parameter": {
                                            "type": "bool",
                                            "value": "true",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 697,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 697,
                                        "char": 56
                                    }
                                ],
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 697,
                                "char": 57
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 698,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds a HTML input[type=\"image\"] tag\n     *\n     *```php\n     * echo Phalcon\\Tag::imageInput(\n     *     [\n     *         \"src\" => \"\/img\/button.png\",\n     *     ]\n     * );\n     *```\n     *\n     * Volt syntax:\n     *```php\n     * {{ image_input(\"src\": \"\/img\/button.png\") }}\n     *```\n     *\n     * @param array parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 696,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 696,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 695,
                    "last-line": 719,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "javascriptInclude",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 720,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 720,
                            "char": 67
                        },
                        {
                            "type": "parameter",
                            "name": "local",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 720,
                                "char": 86
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 720,
                            "char": 86
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "params",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 722,
                                    "char": 19
                                },
                                {
                                    "variable": "code",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 722,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 724,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "parameters",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 724,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 724,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 724,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 724,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "params",
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "parameters",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 725,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 725,
                                                        "char": 37
                                                    },
                                                    {
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "local",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 725,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 725,
                                                        "char": 44
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 725,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 725,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 726,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "params",
                                            "expr": {
                                                "type": "variable",
                                                "value": "parameters",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 727,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 727,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 728,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 730,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "params",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 730,
                                        "char": 24
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "1",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 730,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 730,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 730,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "local",
                                            "expr": {
                                                "type": "cast",
                                                "left": "bool",
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "params",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 731,
                                                        "char": 38
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "1",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 731,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 731,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 731,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 731,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 732,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "isset",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "params",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 733,
                                                "char": 28
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "local",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 733,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 733,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 733,
                                        "char": 36
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "local",
                                                    "expr": {
                                                        "type": "cast",
                                                        "left": "bool",
                                                        "right": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "params",
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 734,
                                                                "char": 42
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "local",
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 734,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 734,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 734,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 734,
                                                    "char": 49
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 736,
                                            "char": 21
                                        },
                                        {
                                            "type": "unset",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 736,
                                                    "char": 29
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "local",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 736,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 736,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 737,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 738,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 740,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "isset",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "params",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 740,
                                                "char": 25
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "type",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 740,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 740,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 740,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 740,
                                    "char": 33
                                },
                                "right": {
                                    "type": "less",
                                    "left": {
                                        "type": "static-property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 740,
                                            "char": 54
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "documentType",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 740,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 740,
                                        "char": 54
                                    },
                                    "right": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 740,
                                            "char": 68
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "HTML5",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 740,
                                            "char": 68
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 740,
                                        "char": 68
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 740,
                                    "char": 68
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 740,
                                "char": 68
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "params",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "type",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 741,
                                                    "char": 28
                                                }
                                            ],
                                            "expr": {
                                                "type": "string",
                                                "value": "text\/javascript",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 741,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 741,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 742,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 744,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 744,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "src",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 744,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 744,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 744,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 744,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "isset",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "params",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 745,
                                                "char": 28
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 745,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 745,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 745,
                                        "char": 32
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "params",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "src",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 746,
                                                            "char": 31
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "params",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 746,
                                                            "char": 41
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 746,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 746,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 746,
                                                    "char": 44
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 747,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "params",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "src",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 748,
                                                            "char": 31
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 748,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 748,
                                                    "char": 35
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 749,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 750,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 755,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "local",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 755,
                                "char": 18
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "params",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "src",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 756,
                                                    "char": 27
                                                }
                                            ],
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "scall",
                                                    "dynamic-class": 0,
                                                    "class": "self",
                                                    "dynamic": 0,
                                                    "name": "getUrlService",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 756,
                                                    "char": 53
                                                },
                                                "name": "getStatic",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "params",
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 756,
                                                                "char": 70
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "src",
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 756,
                                                                "char": 74
                                                            },
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 756,
                                                            "char": 75
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 756,
                                                        "char": 75
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 756,
                                                "char": 76
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 756,
                                            "char": 76
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 757,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 759,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "code",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "self",
                                        "dynamic": 0,
                                        "name": "renderAttributes",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "<script",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 759,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 759,
                                                "char": 50
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 759,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 759,
                                                "char": 58
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 759,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 759,
                                    "char": 59
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "concat-assign",
                                    "variable": "code",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "string",
                                            "value": "><\/script>",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 760,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "constant",
                                            "value": "PHP_EOL",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 760,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 760,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 760,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 762,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "code",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 762,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 763,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds a SCRIPT[type=\"javascript\"] tag\n     *\n     * ```php\n     * echo Phalcon\\Tag::javascriptInclude(\n     *     \"http:\/\/ajax.googleapis.com\/ajax\/libs\/jquery\/2.2.3\/jquery.min.js\",\n     *     false\n     * );\n     *\n     * echo Phalcon\\Tag::javascriptInclude(\"javascript\/jquery.js\");\n     * ```\n     *\n     * Volt syntax:\n     * ```php\n     * {{ javascript_include(\"http:\/\/ajax.googleapis.com\/ajax\/libs\/jquery\/2.2.3\/jquery.min.js\", false) }}\n     * {{ javascript_include(\"javascript\/jquery.js\") }}\n     * ```\n     *\n     * @param array parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 721,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 721,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 720,
                    "last-line": 818,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "linkTo",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 819,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "text",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 819,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 819,
                            "char": 58
                        },
                        {
                            "type": "parameter",
                            "name": "local",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 819,
                                "char": 72
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 819,
                            "char": 72
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "params",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 821,
                                    "char": 19
                                },
                                {
                                    "variable": "action",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 821,
                                    "char": 27
                                },
                                {
                                    "variable": "query",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 821,
                                    "char": 34
                                },
                                {
                                    "variable": "url",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 821,
                                    "char": 39
                                },
                                {
                                    "variable": "code",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 821,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 823,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "parameters",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 823,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 823,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 823,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 823,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "params",
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "parameters",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 824,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 824,
                                                        "char": 37
                                                    },
                                                    {
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "text",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 824,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 824,
                                                        "char": 43
                                                    },
                                                    {
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "local",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 824,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 824,
                                                        "char": 50
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 824,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 824,
                                            "char": 51
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 825,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "params",
                                            "expr": {
                                                "type": "variable",
                                                "value": "parameters",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 826,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 826,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 827,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 829,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "action",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 829,
                                        "char": 37
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 829,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 829,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 829,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 829,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 829,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "fetch",
                                            "left": {
                                                "type": "variable",
                                                "value": "action",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 830,
                                                "char": 46
                                            },
                                            "right": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 830,
                                                    "char": 37
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "action",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 830,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 830,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 830,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 830,
                                        "char": 46
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "action",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 831,
                                                        "char": 30
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 831,
                                                    "char": 30
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 832,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "unset",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 833,
                                                    "char": 29
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "action",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 833,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 833,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 834,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 835,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 837,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "text",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 837,
                                        "char": 35
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 837,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "1",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 837,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 837,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 837,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 837,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "fetch",
                                            "left": {
                                                "type": "variable",
                                                "value": "text",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 838,
                                                "char": 42
                                            },
                                            "right": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 838,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "text",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 838,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 838,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 838,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 838,
                                        "char": 42
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "text",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 839,
                                                        "char": 28
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 839,
                                                    "char": 28
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 840,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "unset",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 841,
                                                    "char": 29
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "text",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 841,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 841,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 842,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 843,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 845,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "local",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 845,
                                        "char": 36
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 845,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "2",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 845,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 845,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 845,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 845,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "fetch",
                                            "left": {
                                                "type": "variable",
                                                "value": "local",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 846,
                                                "char": 44
                                            },
                                            "right": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 846,
                                                    "char": 36
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "local",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 846,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 846,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 846,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 846,
                                        "char": 44
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "local",
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "true",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 847,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 847,
                                                    "char": 33
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 848,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "unset",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 849,
                                                    "char": 29
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "local",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 849,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 849,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 850,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 851,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 853,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "query",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 853,
                                    "char": 39
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "params",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 853,
                                        "char": 31
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "query",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 853,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 853,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 853,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "unset",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 854,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "query",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 854,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 854,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 855,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "query",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 856,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 856,
                                            "char": 29
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 857,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 859,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "url",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "self",
                                        "dynamic": 0,
                                        "name": "getUrlService",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 859,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 859,
                                    "char": 40
                                },
                                {
                                    "assign-type": "array-index",
                                    "operator": "assign",
                                    "variable": "params",
                                    "index-expr": [
                                        {
                                            "type": "string",
                                            "value": "href",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 860,
                                            "char": 24
                                        }
                                    ],
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "url",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 860,
                                            "char": 32
                                        },
                                        "name": "get",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "action",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 860,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 860,
                                                "char": 43
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "query",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 860,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 860,
                                                "char": 50
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "local",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 860,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 860,
                                                "char": 57
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 860,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 860,
                                    "char": 58
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "code",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "self",
                                        "dynamic": 0,
                                        "name": "renderAttributes",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "<a",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 861,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 861,
                                                "char": 45
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 861,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 861,
                                                "char": 53
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 861,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 861,
                                    "char": 54
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "concat-assign",
                                    "variable": "code",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "string",
                                                "value": ">",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 862,
                                                "char": 22
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "text",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 862,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 862,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "<\/a>",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 862,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 862,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 862,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 864,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "code",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 864,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 865,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds a HTML A tag using framework conventions\n     *\n     *```php\n     * echo Phalcon\\Tag::linkTo(\"signup\/register\", \"Register Here!\");\n     *\n     * echo Phalcon\\Tag::linkTo(\n     *     [\n     *         \"signup\/register\",\n     *         \"Register Here!\"\n     *     ]\n     * );\n     *\n     * echo Phalcon\\Tag::linkTo(\n     *     [\n     *         \"signup\/register\",\n     *         \"Register Here!\",\n     *         \"class\" => \"btn-primary\",\n     *     ]\n     * );\n     *\n     * echo Phalcon\\Tag::linkTo(\"http:\/\/phalconphp.com\/\", \"Phalcon\", false);\n     *\n     * echo Phalcon\\Tag::linkTo(\n     *     [\n     *         \"http:\/\/phalconphp.com\/\",\n     *         \"Phalcon Home\",\n     *         false,\n     *     ]\n     * );\n     *\n     * echo Phalcon\\Tag::linkTo(\n     *     [\n     *         \"http:\/\/phalconphp.com\/\",\n     *         \"Phalcon Home\",\n     *         \"local\" => false,\n     *     ]\n     * );\n     *\n     * echo Phalcon\\Tag::linkTo(\n     *     [\n     *         \"action\" => \"http:\/\/phalconphp.com\/\",\n     *         \"text\"   => \"Phalcon Home\",\n     *         \"local\"  => false,\n     *         \"target\" => \"_new\"\n     *     ]\n     * );\n     *\n     *```\n     *\n     * @param array|string parameters\n     * @param string text\n     * @param bool local\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 820,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 820,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 819,
                    "last-line": 871,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "monthField",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 872,
                            "char": 53
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "self",
                                "dynamic": 0,
                                "name": "inputField",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "month",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 874,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 874,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "parameters",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 874,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 874,
                                        "char": 50
                                    }
                                ],
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 874,
                                "char": 51
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 875,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds a HTML input[type=\"month\"] tag\n     *\n     * @param array parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 873,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 873,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 872,
                    "last-line": 891,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "numericField",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 892,
                            "char": 55
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "self",
                                "dynamic": 0,
                                "name": "inputField",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "number",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 894,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 894,
                                        "char": 39
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "parameters",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 894,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 894,
                                        "char": 51
                                    }
                                ],
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 894,
                                "char": 52
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 895,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds a HTML input[type=\"number\"] tag\n     *\n     * ```php\n     * echo Phalcon\\Tag::numericField(\n     *     [\n     *         \"price\",\n     *         \"min\" => \"1\",\n     *         \"max\" => \"5\",\n     *     ]\n     * );\n     * ```\n     *\n     * @param array parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 893,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 893,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 892,
                    "last-line": 911,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "passwordField",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 912,
                            "char": 56
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "self",
                                "dynamic": 0,
                                "name": "inputField",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "password",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 914,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 914,
                                        "char": 41
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "parameters",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 914,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 914,
                                        "char": 53
                                    }
                                ],
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 914,
                                "char": 54
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 915,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds a HTML input[type=\"password\"] tag\n     *\n     *```php\n     * echo Phalcon\\Tag::passwordField(\n     *     [\n     *         \"name\",\n     *         \"size\" => 30,\n     *     ]\n     * );\n     *```\n     *\n     * @param array parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 913,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 913,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 912,
                    "last-line": 919,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "prependTitle",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "title",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 920,
                            "char": 50
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "static-property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "self",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 922,
                                        "char": 41
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "documentPrependTitle",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 922,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 922,
                                    "char": 41
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 922,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 922,
                                "char": 48
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "static-property",
                                            "operator": "assign",
                                            "variable": "self",
                                            "property": "documentPrependTitle",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 923,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 923,
                                            "char": 48
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 924,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 926,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "title",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 926,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 926,
                                    "char": 26
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 926,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 926,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "static-property",
                                            "operator": "assign",
                                            "variable": "self",
                                            "property": "documentPrependTitle",
                                            "expr": {
                                                "type": "variable",
                                                "value": "title",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 927,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 927,
                                            "char": 52
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 928,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "static-property-append",
                                            "operator": "assign",
                                            "variable": "self",
                                            "property": "documentPrependTitle",
                                            "expr": {
                                                "type": "variable",
                                                "value": "title",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 929,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 929,
                                            "char": 54
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 930,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 931,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Prepends a text to current document title\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 921,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 920,
                    "last-line": 951,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "radioField",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 952,
                            "char": 53
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "self",
                                "dynamic": 0,
                                "name": "inputFieldChecked",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "radio",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 954,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 954,
                                        "char": 45
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "parameters",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 954,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 954,
                                        "char": 57
                                    }
                                ],
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 954,
                                "char": 58
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 955,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds a HTML input[type=\"radio\"] tag\n     *\n     *```php\n     * echo Phalcon\\Tag::radioField(\n     *     [\n     *         \"weather\",\n     *         \"value\" => \"hot\",\n     *     ]\n     * );\n     *```\n     *\n     * Volt syntax:\n     *```php\n     * {{ radio_field(\"Save\") }}\n     *```\n     *\n     * @param array parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 953,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 953,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 952,
                    "last-line": 961,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "rangeField",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 962,
                            "char": 53
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "self",
                                "dynamic": 0,
                                "name": "inputField",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "range",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 964,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 964,
                                        "char": 38
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "parameters",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 964,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 964,
                                        "char": 50
                                    }
                                ],
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 964,
                                "char": 51
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 965,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n    * Builds a HTML input[type=\"range\"] tag\n    *\n    * @param array parameters\n    *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 963,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 963,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 962,
                    "last-line": 969,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "renderAttributes",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "code",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 970,
                            "char": 57
                        },
                        {
                            "type": "parameter",
                            "name": "attributes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 970,
                            "char": 76
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "order",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 972,
                                    "char": 18
                                },
                                {
                                    "variable": "escaper",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 972,
                                    "char": 27
                                },
                                {
                                    "variable": "attrs",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 972,
                                    "char": 34
                                },
                                {
                                    "variable": "attribute",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 972,
                                    "char": 45
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 972,
                                    "char": 52
                                },
                                {
                                    "variable": "escaped",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 972,
                                    "char": 61
                                },
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 972,
                                    "char": 66
                                },
                                {
                                    "variable": "newCode",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 972,
                                    "char": 75
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 974,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "order",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "rel",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 975,
                                                    "char": 20
                                                },
                                                "value": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 975,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 975,
                                                "char": 26
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "type",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 976,
                                                    "char": 20
                                                },
                                                "value": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 976,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 976,
                                                "char": 26
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "for",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 977,
                                                    "char": 20
                                                },
                                                "value": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 977,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 977,
                                                "char": 26
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "src",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 978,
                                                    "char": 20
                                                },
                                                "value": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 978,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 978,
                                                "char": 26
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "href",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 979,
                                                    "char": 20
                                                },
                                                "value": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 979,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 979,
                                                "char": 26
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "action",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 980,
                                                    "char": 20
                                                },
                                                "value": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 980,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 980,
                                                "char": 26
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "id",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 981,
                                                    "char": 20
                                                },
                                                "value": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 981,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 981,
                                                "char": 26
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 982,
                                                    "char": 20
                                                },
                                                "value": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 982,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 982,
                                                "char": 26
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 983,
                                                    "char": 20
                                                },
                                                "value": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 983,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 983,
                                                "char": 26
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "class",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 984,
                                                    "char": 20
                                                },
                                                "value": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 985,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 985,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 985,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 985,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 987,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "attrs",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 987,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 987,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 989,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "order",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 989,
                                "char": 33
                            },
                            "key": "key",
                            "value": "value",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "attribute",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 990,
                                            "char": 49
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "attributes",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 990,
                                                "char": 43
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "key",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 990,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 990,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 990,
                                        "char": 49
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "attrs",
                                                    "index-expr": [
                                                        {
                                                            "type": "variable",
                                                            "value": "key",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 991,
                                                            "char": 30
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "attribute",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 991,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 991,
                                                    "char": 43
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 992,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 993,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 995,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "attributes",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 995,
                                "char": 38
                            },
                            "key": "key",
                            "value": "value",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "isset",
                                            "left": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "attrs",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 996,
                                                    "char": 28
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 996,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 996,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 996,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 996,
                                        "char": 34
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "attrs",
                                                    "index-expr": [
                                                        {
                                                            "type": "variable",
                                                            "value": "key",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 997,
                                                            "char": 30
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 997,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 997,
                                                    "char": 39
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 998,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 999,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1001,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "escaper",
                                    "expr": {
                                        "type": "type-hint",
                                        "left": {
                                            "type": "variable",
                                            "value": "EscaperInterface",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1001,
                                            "char": 70
                                        },
                                        "right": {
                                            "type": "scall",
                                            "dynamic-class": 0,
                                            "class": "self",
                                            "dynamic": 0,
                                            "name": "getEscaper",
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "attributes",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1001,
                                                        "char": 69
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1001,
                                                    "char": 69
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1001,
                                            "char": 70
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1001,
                                        "char": 70
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1001,
                                    "char": 70
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1003,
                            "char": 13
                        },
                        {
                            "type": "unset",
                            "expr": {
                                "type": "array-access",
                                "left": {
                                    "type": "variable",
                                    "value": "attrs",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1003,
                                    "char": 20
                                },
                                "right": {
                                    "type": "string",
                                    "value": "escape",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1003,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1003,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1005,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "newCode",
                                    "expr": {
                                        "type": "variable",
                                        "value": "code",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1005,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1005,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1007,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "attrs",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1007,
                                "char": 33
                            },
                            "key": "key",
                            "value": "value",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "equals",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1008,
                                                    "char": 28
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1008,
                                                "char": 28
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "string",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1008,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1008,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1008,
                                                "char": 48
                                            },
                                            "right": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1008,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1008,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1008,
                                        "char": 55
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "unlikely",
                                                "left": {
                                                    "type": "list",
                                                    "left": {
                                                        "type": "or",
                                                        "left": {
                                                            "type": "equals",
                                                            "left": {
                                                                "type": "typeof",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "value",
                                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                                    "line": 1009,
                                                                    "char": 44
                                                                },
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 1009,
                                                                "char": 44
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "array",
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 1009,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1009,
                                                            "char": 53
                                                        },
                                                        "right": {
                                                            "type": "equals",
                                                            "left": {
                                                                "type": "typeof",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "value",
                                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                                    "line": 1009,
                                                                    "char": 69
                                                                },
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 1009,
                                                                "char": 69
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "resource",
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 1009,
                                                                "char": 79
                                                            },
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1009,
                                                            "char": 79
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1009,
                                                        "char": 79
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1009,
                                                    "char": 81
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1009,
                                                "char": 81
                                            },
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
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "concat",
                                                                                "left": {
                                                                                    "type": "string",
                                                                                    "value": "Value at index: '",
                                                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                                                    "line": 1011,
                                                                                    "char": 43
                                                                                },
                                                                                "right": {
                                                                                    "type": "variable",
                                                                                    "value": "key",
                                                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                                                    "line": 1011,
                                                                                    "char": 49
                                                                                },
                                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                                "line": 1011,
                                                                                "char": 49
                                                                            },
                                                                            "right": {
                                                                                "type": "string",
                                                                                "value": "' type: '",
                                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                                "line": 1011,
                                                                                "char": 61
                                                                            },
                                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                                            "line": 1011,
                                                                            "char": 61
                                                                        },
                                                                        "right": {
                                                                            "type": "fcall",
                                                                            "name": "gettype",
                                                                            "call-type": 1,
                                                                            "parameters": [
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "variable",
                                                                                        "value": "value",
                                                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                                                        "line": 1011,
                                                                                        "char": 76
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                                                    "line": 1011,
                                                                                    "char": 76
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                                            "line": 1011,
                                                                            "char": 78
                                                                        },
                                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                                        "line": 1011,
                                                                        "char": 78
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "' cannot be rendered",
                                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                                        "line": 1012,
                                                                        "char": 21
                                                                    },
                                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                                    "line": 1012,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 1012,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1012,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1013,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1015,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "variable",
                                                "value": "escaper",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1015,
                                                "char": 28
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "escaped",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "escaper",
                                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                                    "line": 1016,
                                                                    "char": 43
                                                                },
                                                                "name": "escapeHtmlAttr",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "value",
                                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                                            "line": 1016,
                                                                            "char": 64
                                                                        },
                                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                                        "line": 1016,
                                                                        "char": 64
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 1016,
                                                                "char": 65
                                                            },
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1016,
                                                            "char": 65
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1017,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "escaped",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "value",
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 1018,
                                                                "char": 40
                                                            },
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1018,
                                                            "char": 40
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1019,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1021,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "newCode",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "string",
                                                                        "value": " ",
                                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                                        "line": 1021,
                                                                        "char": 33
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "key",
                                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                                        "line": 1021,
                                                                        "char": 39
                                                                    },
                                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                                    "line": 1021,
                                                                    "char": 39
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "=\\\"",
                                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                                    "line": 1021,
                                                                    "char": 45
                                                                },
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 1021,
                                                                "char": 45
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "escaped",
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 1021,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1021,
                                                            "char": 55
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "\\\"",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1021,
                                                            "char": 59
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1021,
                                                        "char": 59
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1021,
                                                    "char": 59
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1022,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1023,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1025,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "newCode",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1025,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1026,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Renders parameters keeping order in their HTML attributes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 971,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 971,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 970,
                    "last-line": 1045,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "renderTitle",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "prepend",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1046,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1046,
                            "char": 59
                        },
                        {
                            "type": "parameter",
                            "name": "append",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1046,
                                "char": 79
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1046,
                            "char": 79
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "concat",
                                    "left": {
                                        "type": "concat",
                                        "left": {
                                            "type": "string",
                                            "value": "<title>",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1048,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "scall",
                                            "dynamic-class": 0,
                                            "class": "self",
                                            "dynamic": 0,
                                            "name": "getTitle",
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "prepend",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1048,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1048,
                                                    "char": 48
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "append",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1048,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1048,
                                                    "char": 56
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1048,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1048,
                                        "char": 58
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "<\/title>",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1048,
                                        "char": 69
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1048,
                                    "char": 69
                                },
                                "right": {
                                    "type": "constant",
                                    "value": "PHP_EOL",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1048,
                                    "char": 78
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1048,
                                "char": 78
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1049,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Renders the title with title tags. The title is automaticall escaped\n     *\n     * ```php\n     * Tag::prependTitle('Hello');\n     * Tag::setTitle('World');\n     * Tag::appendTitle('from Phalcon');\n     *\n     * echo Tag::renderTitle();             \/\/ <title>Hello World from Phalcon<\/title>\n     * echo Tag::renderTitle(false);        \/\/ <title>World from Phalcon<\/title>\n     * echo Tag::renderTitle(true, false);  \/\/ <title>Hello World<\/title>\n     * echo Tag::renderTitle(false, false); \/\/ <title>World<\/title>\n     * ```\n     *\n     * ```php\n     * {{ render_title() }}\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1047,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 1047,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 1046,
                    "last-line": 1056,
                    "char": 26
                },
                {
                    "visibility": [
                        "deprecated",
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "resetInput",
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "static-property",
                                    "operator": "assign",
                                    "variable": "self",
                                    "property": "displayValues",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1059,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1059,
                                    "char": 37
                                },
                                {
                                    "assign-type": "static-property",
                                    "operator": "assign",
                                    "variable": "self",
                                    "property": "documentTitle",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1060,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1060,
                                    "char": 39
                                },
                                {
                                    "assign-type": "static-property",
                                    "operator": "assign",
                                    "variable": "self",
                                    "property": "documentAppendTitle",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1061,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1061,
                                    "char": 43
                                },
                                {
                                    "assign-type": "static-property",
                                    "operator": "assign",
                                    "variable": "self",
                                    "property": "documentPrependTitle",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1062,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1062,
                                    "char": 44
                                },
                                {
                                    "assign-type": "static-property",
                                    "operator": "assign",
                                    "variable": "self",
                                    "property": "documentTitleSeparator",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1063,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1063,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1064,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resets the request and internal values to avoid those fields will have\n     * any default value.\n     *\n     * @deprecated Will be removed in 4.0.0\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 1058,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 1057,
                    "last-line": 1070,
                    "char": 37
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "searchField",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1071,
                            "char": 54
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "self",
                                "dynamic": 0,
                                "name": "inputField",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "search",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1073,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1073,
                                        "char": 39
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "parameters",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1073,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1073,
                                        "char": 51
                                    }
                                ],
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1073,
                                "char": 52
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1074,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds a HTML input[type=\"search\"] tag\n     *\n     * @param array parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1072,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 1072,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 1071,
                    "last-line": 1096,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "select",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1097,
                            "char": 49
                        },
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1097,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1097,
                            "char": 62
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "Select",
                                "dynamic": 0,
                                "name": "selectField",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "parameters",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1099,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1099,
                                        "char": 46
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1099,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1099,
                                        "char": 52
                                    }
                                ],
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1099,
                                "char": 53
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1100,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds a HTML SELECT tag using a Phalcon\\Mvc\\Model resultset as options\n     *\n     *```php\n     * echo Phalcon\\Tag::select(\n     *     [\n     *         \"robotId\",\n     *         Robots::find(\"type = \"mechanical\"\"),\n     *         \"using\" => [\"id\", \"name\"],\n     *     ]\n     * );\n     *```\n     *\n     * Volt syntax:\n     *```php\n     * {{ select(\"robotId\", robots, \"using\": [\"id\", \"name\"]) }}\n     *```\n     *\n     * @param array parameters\n     * @param array data\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1098,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 1098,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 1097,
                    "last-line": 1117,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "selectStatic",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1118,
                            "char": 51
                        },
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1118,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1118,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "Select",
                                "dynamic": 0,
                                "name": "selectField",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "parameters",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1120,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1120,
                                        "char": 46
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1120,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1120,
                                        "char": 52
                                    }
                                ],
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1120,
                                "char": 53
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1121,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds a HTML SELECT tag using a PHP array for options\n     *\n     *```php\n     * echo Phalcon\\Tag::selectStatic(\n     *     \"status\",\n     *     [\n     *         \"A\" => \"Active\",\n     *         \"I\" => \"Inactive\",\n     *     ]\n     * );\n     *```\n     *\n     * @param array parameters\n     * @param array data\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1119,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 1119,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 1118,
                    "last-line": 1125,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "setAutoescape",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "autoescape",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1126,
                            "char": 57
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "static-property",
                                    "operator": "assign",
                                    "variable": "self",
                                    "property": "autoEscape",
                                    "expr": {
                                        "type": "variable",
                                        "value": "autoescape",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1128,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1128,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1129,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set autoescape mode in generated html\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 1127,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 1126,
                    "last-line": 1143,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "setDefault",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "id",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1144,
                            "char": 49
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1144,
                            "char": 56
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "variable",
                                    "value": "value",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1146,
                                    "char": 20
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1146,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1146,
                                "char": 27
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "list",
                                            "left": {
                                                "type": "or",
                                                "left": {
                                                    "type": "equals",
                                                    "left": {
                                                        "type": "typeof",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1147,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1147,
                                                        "char": 40
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "array",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1147,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1147,
                                                    "char": 49
                                                },
                                                "right": {
                                                    "type": "equals",
                                                    "left": {
                                                        "type": "typeof",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1147,
                                                            "char": 65
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1147,
                                                        "char": 65
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "object",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1147,
                                                        "char": 73
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1147,
                                                    "char": 73
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1147,
                                                "char": 73
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1147,
                                            "char": 75
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1147,
                                        "char": 75
                                    },
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
                                                            "value": "Only scalar values can be assigned to UI components",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1150,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1150,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1150,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1151,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1152,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1154,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "static-property-array-index",
                                    "operator": "assign",
                                    "variable": "self",
                                    "property": "displayValues",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "id",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1154,
                                            "char": 35
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1154,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1154,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1155,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Assigns default values to generated tags by helpers\n     *\n     * ```php\n     * \/\/ Assigning \"peter\" to \"name\" component\n     * Phalcon\\Tag::setDefault(\"name\", \"peter\");\n     *\n     * \/\/ Later in the view\n     * echo Phalcon\\Tag::textField(\"name\"); \/\/ Will have the value \"peter\" by default\n     * ```\n     *\n     * @param string value\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 1145,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 1144,
                    "last-line": 1171,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "setDefaults",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "values",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1172,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "merge",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1172,
                                "char": 73
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1172,
                            "char": 73
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "variable",
                                    "value": "merge",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1174,
                                    "char": 19
                                },
                                "right": {
                                    "type": "equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "static-property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1174,
                                                "char": 49
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "displayValues",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1174,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1174,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1174,
                                        "char": 49
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1174,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1174,
                                    "char": 57
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1174,
                                "char": 57
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "static-property",
                                            "operator": "assign",
                                            "variable": "self",
                                            "property": "displayValues",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "array_merge",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "static-property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "self",
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 1175,
                                                                "char": 70
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "displayValues",
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 1175,
                                                                "char": 70
                                                            },
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1175,
                                                            "char": 70
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1175,
                                                        "char": 70
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "values",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1175,
                                                            "char": 78
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1175,
                                                        "char": 78
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1175,
                                                "char": 79
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1175,
                                            "char": 79
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1176,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "static-property",
                                            "operator": "assign",
                                            "variable": "self",
                                            "property": "displayValues",
                                            "expr": {
                                                "type": "variable",
                                                "value": "values",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1177,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1177,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1178,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1179,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Assigns default values to generated tags by helpers\n     *\n     * ```php\n     * \/\/ Assigning \"peter\" to \"name\" component\n     * Phalcon\\Tag::setDefaults(\n     *     [\n     *         \"name\" => \"peter\",\n     *     ]\n     * );\n     *\n     * \/\/ Later in the view\n     * echo Phalcon\\Tag::textField(\"name\"); \/\/ Will have the value \"peter\" by default\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 1173,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 1172,
                    "last-line": 1183,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "setDI",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "container",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "DiInterface",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1184,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1184,
                            "char": 57
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "static-property",
                                    "operator": "assign",
                                    "variable": "self",
                                    "property": "container",
                                    "expr": {
                                        "type": "variable",
                                        "value": "container",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1186,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1186,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1187,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the dependency injector container.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 1185,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 1184,
                    "last-line": 1191,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "setDocType",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "doctype",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1192,
                            "char": 50
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "less",
                                    "left": {
                                        "type": "variable",
                                        "value": "doctype",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1194,
                                        "char": 20
                                    },
                                    "right": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1194,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "HTML32",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1194,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1194,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1194,
                                    "char": 36
                                },
                                "right": {
                                    "type": "greater",
                                    "left": {
                                        "type": "variable",
                                        "value": "doctype",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1194,
                                        "char": 46
                                    },
                                    "right": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1194,
                                            "char": 61
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "XHTML5",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1194,
                                            "char": 61
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1194,
                                        "char": 61
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1194,
                                    "char": 61
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1194,
                                "char": 61
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "static-property",
                                            "operator": "assign",
                                            "variable": "self",
                                            "property": "documentType",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1195,
                                                    "char": 49
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "HTML5",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1195,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1195,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1195,
                                            "char": 49
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1196,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "static-property",
                                            "operator": "assign",
                                            "variable": "self",
                                            "property": "documentType",
                                            "expr": {
                                                "type": "variable",
                                                "value": "doctype",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1197,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1197,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1198,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1199,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set the document type of content\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 1193,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 1192,
                    "last-line": 1207,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "setTitle",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "title",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1208,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "static-property",
                                    "operator": "assign",
                                    "variable": "self",
                                    "property": "documentTitle",
                                    "expr": {
                                        "type": "variable",
                                        "value": "title",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1210,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1210,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1211,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set the title of view content\n     *\n     *```php\n     * Phalcon\\Tag::setTitle(\"Welcome to my Page\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 1209,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 1208,
                    "last-line": 1219,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "setTitleSeparator",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "titleSeparator",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1220,
                            "char": 67
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "static-property",
                                    "operator": "assign",
                                    "variable": "self",
                                    "property": "documentTitleSeparator",
                                    "expr": {
                                        "type": "variable",
                                        "value": "titleSeparator",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1222,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1222,
                                    "char": 58
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1223,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set the title separator of view content\n     *\n     *```php\n     * Phalcon\\Tag::setTitleSeparator(\"-\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 1221,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 1220,
                    "last-line": 1244,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "stylesheetLink",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1245,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1245,
                            "char": 64
                        },
                        {
                            "type": "parameter",
                            "name": "local",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1245,
                                "char": 83
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1245,
                            "char": 83
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "params",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1247,
                                    "char": 19
                                },
                                {
                                    "variable": "code",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1247,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1249,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "parameters",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1249,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1249,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1249,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1249,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "params",
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "parameters",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1250,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1250,
                                                        "char": 37
                                                    },
                                                    {
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "local",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1250,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1250,
                                                        "char": 44
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1250,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1250,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1251,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "params",
                                            "expr": {
                                                "type": "variable",
                                                "value": "parameters",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1252,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1252,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1253,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1255,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "params",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1255,
                                        "char": 24
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "1",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1255,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1255,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1255,
                                "char": 28
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "local",
                                            "expr": {
                                                "type": "cast",
                                                "left": "bool",
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "params",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1256,
                                                        "char": 38
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "1",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1256,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1256,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1256,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1256,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1257,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "isset",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "params",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1258,
                                                "char": 28
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "local",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1258,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1258,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1258,
                                        "char": 36
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "local",
                                                    "expr": {
                                                        "type": "cast",
                                                        "left": "bool",
                                                        "right": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "params",
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 1259,
                                                                "char": 42
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "local",
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 1259,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1259,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1259,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1259,
                                                    "char": 49
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1261,
                                            "char": 21
                                        },
                                        {
                                            "type": "unset",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1261,
                                                    "char": 29
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "local",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1261,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1261,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1262,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1263,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1265,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1265,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "type",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1265,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1265,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1265,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1265,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "params",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "type",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1266,
                                                    "char": 28
                                                }
                                            ],
                                            "expr": {
                                                "type": "string",
                                                "value": "text\/css",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1266,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1266,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1267,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1269,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1269,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "href",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1269,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1269,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1269,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1269,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "isset",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "params",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1270,
                                                "char": 28
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1270,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1270,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1270,
                                        "char": 32
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "params",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "href",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1271,
                                                            "char": 32
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "params",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1271,
                                                            "char": 42
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1271,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1271,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1271,
                                                    "char": 45
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1272,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "params",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "href",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1273,
                                                            "char": 32
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1273,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1273,
                                                    "char": 36
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1274,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1275,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1280,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "local",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1280,
                                "char": 18
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "params",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "href",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1281,
                                                    "char": 28
                                                }
                                            ],
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "scall",
                                                    "dynamic-class": 0,
                                                    "class": "self",
                                                    "dynamic": 0,
                                                    "name": "getUrlService",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1281,
                                                    "char": 54
                                                },
                                                "name": "getStatic",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "params",
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 1282,
                                                                "char": 23
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "href",
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 1282,
                                                                "char": 28
                                                            },
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1283,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1283,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1283,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1283,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1284,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1286,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1286,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "rel",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1286,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1286,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1286,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1286,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "params",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "rel",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1287,
                                                    "char": 27
                                                }
                                            ],
                                            "expr": {
                                                "type": "string",
                                                "value": "stylesheet",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1287,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1287,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1288,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1290,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "code",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "self",
                                        "dynamic": 0,
                                        "name": "renderAttributes",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "<link",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1290,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1290,
                                                "char": 48
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1290,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1290,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1290,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1290,
                                    "char": 57
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1295,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "greater",
                                "left": {
                                    "type": "static-property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "self",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1295,
                                        "char": 31
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "documentType",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1295,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1295,
                                    "char": 31
                                },
                                "right": {
                                    "type": "static-constant-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "self",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1295,
                                        "char": 45
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "HTML5",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1295,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1295,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1295,
                                "char": 45
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "code",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": " \/>",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1296,
                                                    "char": 28
                                                },
                                                "right": {
                                                    "type": "constant",
                                                    "value": "PHP_EOL",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1296,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1296,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1296,
                                            "char": 37
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1297,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "code",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": ">",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1298,
                                                    "char": 26
                                                },
                                                "right": {
                                                    "type": "constant",
                                                    "value": "PHP_EOL",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1298,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1298,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1298,
                                            "char": 35
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1299,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1301,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "code",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1301,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1302,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds a LINK[rel=\"stylesheet\"] tag\n     *\n     * ```php\n     * echo Phalcon\\Tag::stylesheetLink(\n     *     \"http:\/\/fonts.googleapis.com\/css?family=Rosario\",\n     *     false\n     * );\n     *\n     * echo Phalcon\\Tag::stylesheetLink(\"css\/style.css\");\n     * ```\n     *\n     * Volt Syntax:\n     *```php\n     * {{ stylesheet_link(\"http:\/\/fonts.googleapis.com\/css?family=Rosario\", false) }}\n     * {{ stylesheet_link(\"css\/style.css\") }}\n     *```\n     *\n     * @param array parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1246,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 1246,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 1245,
                    "last-line": 1317,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "submitButton",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1318,
                            "char": 55
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "self",
                                "dynamic": 0,
                                "name": "inputField",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "submit",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1320,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1320,
                                        "char": 39
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "parameters",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1320,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1320,
                                        "char": 51
                                    },
                                    {
                                        "parameter": {
                                            "type": "bool",
                                            "value": "true",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1320,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1320,
                                        "char": 57
                                    }
                                ],
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1320,
                                "char": 58
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1321,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds a HTML input[type=\"submit\"] tag\n     *\n     *```php\n     * echo Phalcon\\Tag::submitButton(\"Save\")\n     *```\n     *\n     * Volt syntax:\n     *```php\n     * {{ submit_button(\"Save\") }}\n     *```\n     *\n     * @param array parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1319,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 1319,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 1318,
                    "last-line": 1325,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "tagHtml",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "tagName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1327,
                            "char": 23
                        },
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1328,
                                "char": 30
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1328,
                            "char": 30
                        },
                        {
                            "type": "parameter",
                            "name": "selfClose",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1329,
                                "char": 31
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1329,
                            "char": 31
                        },
                        {
                            "type": "parameter",
                            "name": "onlyStart",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1330,
                                "char": 31
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1330,
                            "char": 31
                        },
                        {
                            "type": "parameter",
                            "name": "useEol",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1332,
                                "char": 5
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1332,
                            "char": 5
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "params",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1334,
                                    "char": 19
                                },
                                {
                                    "variable": "localCode",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1334,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1336,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "parameters",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1336,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1336,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1336,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1336,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "params",
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "parameters",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1337,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1337,
                                                        "char": 37
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1337,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1337,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1338,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "params",
                                            "expr": {
                                                "type": "variable",
                                                "value": "parameters",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1339,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1339,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1340,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1342,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "localCode",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "self",
                                        "dynamic": 0,
                                        "name": "renderAttributes",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "string",
                                                        "value": "<",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1342,
                                                        "char": 50
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "tagName",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1342,
                                                        "char": 59
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1342,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1342,
                                                "char": 59
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1342,
                                                    "char": 67
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1342,
                                                "char": 67
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1342,
                                        "char": 68
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1342,
                                    "char": 68
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1347,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "greater",
                                "left": {
                                    "type": "static-property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "self",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1347,
                                        "char": 31
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "documentType",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1347,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1347,
                                    "char": 31
                                },
                                "right": {
                                    "type": "static-constant-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "self",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1347,
                                        "char": 45
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "HTML5",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1347,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1347,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1347,
                                "char": 45
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "selfClose",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1348,
                                        "char": 26
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "localCode",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": " \/>",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1349,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1349,
                                                    "char": 36
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1350,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "localCode",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": ">",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1351,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1351,
                                                    "char": 34
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1352,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1353,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "onlyStart",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1354,
                                        "char": 26
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "localCode",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": ">",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1355,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1355,
                                                    "char": 34
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1356,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "concat-assign",
                                                    "variable": "localCode",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "string",
                                                                "value": "><\/",
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 1357,
                                                                "char": 37
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "tagName",
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 1357,
                                                                "char": 47
                                                            },
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1357,
                                                            "char": 47
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": ">",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1357,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1357,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1357,
                                                    "char": 50
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1358,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1359,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1361,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "useEol",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1361,
                                "char": 19
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "localCode",
                                            "expr": {
                                                "type": "constant",
                                                "value": "PHP_EOL",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1362,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1362,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1363,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1365,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "localCode",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1365,
                                "char": 25
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1366,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds a HTML tag\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1333,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 1333,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 1326,
                    "last-line": 1374,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "tagHtmlClose",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "tagName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1375,
                            "char": 55
                        },
                        {
                            "type": "parameter",
                            "name": "useEol",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1375,
                                "char": 76
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1375,
                            "char": 76
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "useEol",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1377,
                                "char": 19
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": "<\/",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1378,
                                                    "char": 23
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "tagName",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1378,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1378,
                                                "char": 33
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": ">",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1378,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1378,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "constant",
                                            "value": "PHP_EOL",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1378,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1378,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1379,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1381,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "concat",
                                    "left": {
                                        "type": "string",
                                        "value": "<\/",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1381,
                                        "char": 19
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "tagName",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1381,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1381,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": ">",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1381,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1381,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1382,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds a HTML tag closing tag\n     *\n     *```php\n     * echo Phalcon\\Tag::tagHtmlClose(\"script\", true);\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1376,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 1376,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 1375,
                    "last-line": 1388,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "telField",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1389,
                            "char": 51
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "self",
                                "dynamic": 0,
                                "name": "inputField",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "tel",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1391,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1391,
                                        "char": 36
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "parameters",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1391,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1391,
                                        "char": 48
                                    }
                                ],
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1391,
                                "char": 49
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1392,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n    * Builds a HTML input[type=\"tel\"] tag\n    *\n    * @param array parameters\n    *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1390,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 1390,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 1389,
                    "last-line": 1413,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "textArea",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1414,
                            "char": 51
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "params",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1416,
                                    "char": 19
                                },
                                {
                                    "variable": "id",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1416,
                                    "char": 23
                                },
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1416,
                                    "char": 29
                                },
                                {
                                    "variable": "content",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1416,
                                    "char": 38
                                },
                                {
                                    "variable": "code",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1416,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1418,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "parameters",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1418,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1418,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1418,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1418,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "params",
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "parameters",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1419,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1419,
                                                        "char": 37
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1419,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1419,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1420,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "params",
                                            "expr": {
                                                "type": "variable",
                                                "value": "parameters",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1421,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1421,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1422,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1424,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1424,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1424,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1424,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1424,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1424,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "isset",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "params",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1425,
                                                "char": 28
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "id",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1425,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1425,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1425,
                                        "char": 33
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "params",
                                                    "index-expr": [
                                                        {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1426,
                                                            "char": 29
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "params",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1426,
                                                            "char": 39
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "id",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1426,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1426,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1426,
                                                    "char": 43
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1427,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1428,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1430,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "id",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1430,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1430,
                                            "char": 26
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1430,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1430,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1432,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1432,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1432,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1432,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1432,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1432,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "params",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1433,
                                                    "char": 28
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "id",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1433,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1433,
                                            "char": 34
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1434,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "name",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1435,
                                                    "char": 30
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1435,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1435,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1435,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1437,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "empty",
                                        "left": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1437,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1437,
                                        "char": 27
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "params",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1438,
                                                            "char": 32
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "id",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1438,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1438,
                                                    "char": 38
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1439,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1440,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1442,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1442,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "id",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1442,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1442,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1442,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1442,
                                "char": 30
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "params",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "id",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1443,
                                                    "char": 26
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "id",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1443,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1443,
                                            "char": 32
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1444,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1446,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "params",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1446,
                                        "char": 24
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1446,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1446,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1446,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "content",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1447,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1447,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1447,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1447,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1449,
                                    "char": 17
                                },
                                {
                                    "type": "unset",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1449,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1449,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1449,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1450,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "content",
                                            "expr": {
                                                "type": "scall",
                                                "dynamic-class": 0,
                                                "class": "self",
                                                "dynamic": 0,
                                                "name": "getValue",
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "id",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1451,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1451,
                                                        "char": 44
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "params",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1451,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1451,
                                                        "char": 52
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1451,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1451,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1452,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1454,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "code",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "self",
                                        "dynamic": 0,
                                        "name": "renderAttributes",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "<textarea",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1454,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1454,
                                                "char": 52
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1454,
                                                    "char": 60
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1454,
                                                "char": 60
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1454,
                                        "char": 61
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1454,
                                    "char": 61
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "concat-assign",
                                    "variable": "code",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "string",
                                                "value": ">",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1455,
                                                "char": 22
                                            },
                                            "right": {
                                                "type": "fcall",
                                                "name": "htmlspecialchars",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "content",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1455,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1455,
                                                        "char": 48
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1455,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1455,
                                            "char": 50
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "<\/textarea>",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1455,
                                            "char": 63
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1455,
                                        "char": 63
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1455,
                                    "char": 63
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1457,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "code",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1457,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1458,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds a HTML TEXTAREA tag\n     *\n     *```php\n     * echo Phalcon\\Tag::textArea(\n     *     [\n     *         \"comments\",\n     *         \"cols\" => 10,\n     *         \"rows\" => 4,\n     *     ]\n     * );\n     *```\n     *\n     * Volt syntax:\n     *```php\n     * {{ text_area(\"comments\", \"cols\": 10, \"rows\": 4) }}\n     *```\n     *\n     * @param array parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1415,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 1415,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 1414,
                    "last-line": 1473,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "textField",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1474,
                            "char": 52
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "self",
                                "dynamic": 0,
                                "name": "inputField",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "text",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1476,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1476,
                                        "char": 37
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "parameters",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1476,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1476,
                                        "char": 49
                                    }
                                ],
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1476,
                                "char": 50
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1477,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds a HTML input[type=\"text\"] tag\n     *\n     * ```php\n     * echo Phalcon\\Tag::textField(\n     *     [\n     *         \"name\",\n     *         \"size\" => 30,\n     *     ]\n     * );\n     * ```\n     *\n     * @param array parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1475,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 1475,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 1474,
                    "last-line": 1483,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "timeField",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1484,
                            "char": 52
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "self",
                                "dynamic": 0,
                                "name": "inputField",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "time",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1486,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1486,
                                        "char": 37
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "parameters",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1486,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1486,
                                        "char": 49
                                    }
                                ],
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1486,
                                "char": 50
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1487,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds a HTML input[type=\"time\"] tag\n     *\n     * @param array parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1485,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 1485,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 1484,
                    "last-line": 1493,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "urlField",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1494,
                            "char": 51
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "self",
                                "dynamic": 0,
                                "name": "inputField",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "url",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1496,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1496,
                                        "char": 36
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "parameters",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1496,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1496,
                                        "char": 48
                                    }
                                ],
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1496,
                                "char": 49
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1497,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds a HTML input[type=\"url\"] tag\n     *\n     * @param array parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1495,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 1495,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 1494,
                    "last-line": 1503,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "weekField",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1504,
                            "char": 52
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "self",
                                "dynamic": 0,
                                "name": "inputField",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "week",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1506,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1506,
                                        "char": 37
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "parameters",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1506,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1506,
                                        "char": 49
                                    }
                                ],
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1506,
                                "char": 50
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1507,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds a HTML input[type=\"week\"] tag\n     *\n     * @param array parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1505,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 1505,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 1504,
                    "last-line": 1513,
                    "char": 26
                },
                {
                    "visibility": [
                        "static",
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "inputField",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "type",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1514,
                            "char": 59
                        },
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1514,
                            "char": 71
                        },
                        {
                            "type": "parameter",
                            "name": "asValue",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1514,
                                "char": 93
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1514,
                            "char": 93
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "params",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1516,
                                    "char": 19
                                },
                                {
                                    "variable": "id",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1516,
                                    "char": 23
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1516,
                                    "char": 30
                                },
                                {
                                    "variable": "code",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1516,
                                    "char": 36
                                },
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1516,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1518,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "params",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1518,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1518,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1520,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "parameters",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1520,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1520,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1520,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1520,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "params",
                                            "expr": {
                                                "type": "variable",
                                                "value": "parameters",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1521,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1521,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1522,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "params",
                                            "expr": {
                                                "type": "variable",
                                                "value": "parameters",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1523,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1523,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1524,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1526,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "variable",
                                    "value": "asValue",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1526,
                                    "char": 21
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1526,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1526,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "fetch",
                                            "left": {
                                                "type": "variable",
                                                "value": "id",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1527,
                                                "char": 37
                                            },
                                            "right": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1527,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1527,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1527,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1527,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1527,
                                        "char": 37
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "params",
                                                    "index-expr": [
                                                        {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1528,
                                                            "char": 29
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "params",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1528,
                                                            "char": 39
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "id",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1528,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1528,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1528,
                                                    "char": 43
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1529,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1531,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1531,
                                            "char": 41
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "params",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1531,
                                                "char": 34
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1531,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1531,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1531,
                                        "char": 41
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1532,
                                                    "char": 31
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1532,
                                                "char": 31
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "params",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "name",
                                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                                    "line": 1533,
                                                                    "char": 36
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "id",
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 1533,
                                                                "char": 42
                                                            },
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1533,
                                                            "char": 42
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1534,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1535,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "params",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1536,
                                                            "char": 32
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "id",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1536,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1536,
                                                    "char": 38
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1537,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1542,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "id",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1542,
                                                "char": 27
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1542,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "string",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1542,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1542,
                                        "char": 36
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "and",
                                                "left": {
                                                    "type": "not",
                                                    "left": {
                                                        "type": "fcall",
                                                        "name": "memstr",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "id",
                                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                                    "line": 1543,
                                                                    "char": 30
                                                                },
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 1543,
                                                                "char": 30
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "[",
                                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                                    "line": 1543,
                                                                    "char": 33
                                                                },
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 1543,
                                                                "char": 33
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1543,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1543,
                                                    "char": 36
                                                },
                                                "right": {
                                                    "type": "not",
                                                    "left": {
                                                        "type": "isset",
                                                        "left": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "params",
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 1543,
                                                                "char": 51
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "id",
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 1543,
                                                                "char": 54
                                                            },
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1543,
                                                            "char": 56
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1543,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1543,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1543,
                                                "char": 56
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "params",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "id",
                                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                                    "line": 1544,
                                                                    "char": 34
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "id",
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 1544,
                                                                "char": 40
                                                            },
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1544,
                                                            "char": 40
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1545,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1546,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1548,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "params",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1548,
                                                    "char": 29
                                                }
                                            ],
                                            "expr": {
                                                "type": "scall",
                                                "dynamic-class": 0,
                                                "class": "self",
                                                "dynamic": 0,
                                                "name": "getValue",
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "id",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1548,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1548,
                                                        "char": 50
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "params",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1548,
                                                            "char": 58
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1548,
                                                        "char": 58
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1548,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1548,
                                            "char": 59
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1549,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "isset",
                                            "left": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1553,
                                                    "char": 29
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1553,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1553,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1553,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1553,
                                        "char": 37
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "fetch",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1554,
                                                    "char": 43
                                                },
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "params",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1554,
                                                        "char": 39
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "0",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1554,
                                                        "char": 41
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1554,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1554,
                                                "char": 43
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "params",
                                                            "index-expr": [
                                                                {
                                                                    "type": "string",
                                                                    "value": "value",
                                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                                    "line": 1555,
                                                                    "char": 37
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "value",
                                                                "file": "\/app\/phalcon\/Tag.zep",
                                                                "line": 1555,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1555,
                                                            "char": 46
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1556,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1557,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1558,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1560,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "array-index",
                                    "operator": "assign",
                                    "variable": "params",
                                    "index-expr": [
                                        {
                                            "type": "string",
                                            "value": "type",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1560,
                                            "char": 24
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "type",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1560,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1560,
                                    "char": 32
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "code",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "self",
                                        "dynamic": 0,
                                        "name": "renderAttributes",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "<input",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1561,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1561,
                                                "char": 49
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1561,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1561,
                                                "char": 57
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1561,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1561,
                                    "char": 58
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1566,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "greater",
                                "left": {
                                    "type": "static-property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "self",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1566,
                                        "char": 31
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "documentType",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1566,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1566,
                                    "char": 31
                                },
                                "right": {
                                    "type": "static-constant-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "self",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1566,
                                        "char": 45
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "HTML5",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1566,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1566,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1566,
                                "char": 45
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "code",
                                            "expr": {
                                                "type": "string",
                                                "value": " \/>",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1567,
                                                "char": 27
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1567,
                                            "char": 27
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1568,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "code",
                                            "expr": {
                                                "type": "string",
                                                "value": ">",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1569,
                                                "char": 25
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1569,
                                            "char": 25
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1570,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1572,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "code",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1572,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1573,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds generic INPUT tags\n     *\n     * @param array parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1515,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 1515,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 1514,
                    "last-line": 1579,
                    "char": 35
                },
                {
                    "visibility": [
                        "static",
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "inputFieldChecked",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "type",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1580,
                            "char": 66
                        },
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1580,
                            "char": 82
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "params",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1582,
                                    "char": 19
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1582,
                                    "char": 26
                                },
                                {
                                    "variable": "id",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1582,
                                    "char": 30
                                },
                                {
                                    "variable": "code",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1582,
                                    "char": 36
                                },
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1582,
                                    "char": 42
                                },
                                {
                                    "variable": "currentValue",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1582,
                                    "char": 56
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1584,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "parameters",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1584,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1584,
                                    "char": 32
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1584,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1584,
                                "char": 40
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "params",
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "parameters",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1585,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1585,
                                                        "char": 37
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1585,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1585,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1586,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "params",
                                            "expr": {
                                                "type": "variable",
                                                "value": "parameters",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1587,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1587,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1588,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1590,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1590,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1590,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1590,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1590,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1590,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "params",
                                            "index-expr": [
                                                {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1591,
                                                    "char": 25
                                                }
                                            ],
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1591,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "id",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1591,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1591,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1591,
                                            "char": 39
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1592,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1594,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "id",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1594,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1594,
                                            "char": 26
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1594,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1594,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1596,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1596,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1596,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1596,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1596,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1596,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "params",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1597,
                                                    "char": 28
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "id",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1597,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1597,
                                            "char": 34
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1598,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "name",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1599,
                                                    "char": 30
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1599,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1599,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1599,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1601,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "empty",
                                        "left": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1601,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1601,
                                        "char": 27
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "params",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1602,
                                                            "char": 32
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "id",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1602,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1602,
                                                    "char": 38
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1603,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1604,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1609,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fcall",
                                    "name": "strpos",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "id",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1609,
                                                "char": 22
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1609,
                                            "char": 22
                                        },
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "[",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1609,
                                                "char": 25
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1609,
                                            "char": 25
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1609,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1609,
                                "char": 27
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "isset",
                                            "left": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1610,
                                                    "char": 29
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "id",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1610,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1610,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1610,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1610,
                                        "char": 34
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "params",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "id",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1611,
                                                            "char": 30
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "id",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1611,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1611,
                                                    "char": 36
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1612,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1613,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1618,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "currentValue",
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1618,
                                    "char": 46
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "params",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1618,
                                        "char": 38
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1618,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1618,
                                    "char": 46
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1618,
                                "char": 46
                            },
                            "statements": [
                                {
                                    "type": "unset",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1619,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1619,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1619,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1621,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "value",
                                            "expr": {
                                                "type": "scall",
                                                "dynamic-class": 0,
                                                "class": "self",
                                                "dynamic": 0,
                                                "name": "getValue",
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "id",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1621,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1621,
                                                        "char": 42
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "params",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1621,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1621,
                                                        "char": 50
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1621,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1621,
                                            "char": 51
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1623,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "not-equals",
                                            "left": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1623,
                                                "char": 23
                                            },
                                            "right": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1623,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1623,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "equals",
                                            "left": {
                                                "type": "variable",
                                                "value": "currentValue",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1623,
                                                "char": 47
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1623,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1623,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1623,
                                        "char": 55
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "params",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "checked",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1624,
                                                            "char": 35
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "checked",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1624,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1624,
                                                    "char": 46
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1625,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1627,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "params",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1627,
                                                    "char": 29
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "currentValue",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1627,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1627,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1628,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "value",
                                            "expr": {
                                                "type": "scall",
                                                "dynamic-class": 0,
                                                "class": "self",
                                                "dynamic": 0,
                                                "name": "getValue",
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "id",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1629,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1629,
                                                        "char": 42
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "params",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1629,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1629,
                                                        "char": 50
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1629,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1629,
                                            "char": 51
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1634,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-equals",
                                        "left": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1634,
                                            "char": 23
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1634,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1634,
                                        "char": 30
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "params",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "checked",
                                                            "file": "\/app\/phalcon\/Tag.zep",
                                                            "line": 1635,
                                                            "char": 35
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "checked",
                                                        "file": "\/app\/phalcon\/Tag.zep",
                                                        "line": 1635,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1635,
                                                    "char": 46
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1636,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1641,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "params",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1641,
                                                    "char": 29
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1641,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1641,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1642,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1644,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "array-index",
                                    "operator": "assign",
                                    "variable": "params",
                                    "index-expr": [
                                        {
                                            "type": "string",
                                            "value": "type",
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1644,
                                            "char": 24
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "type",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1644,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1644,
                                    "char": 32
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "code",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "self",
                                        "dynamic": 0,
                                        "name": "renderAttributes",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "<input",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1645,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1645,
                                                "char": 49
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Tag.zep",
                                                    "line": 1645,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1645,
                                                "char": 57
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1645,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1645,
                                    "char": 58
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1650,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "greater",
                                "left": {
                                    "type": "static-property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "self",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1650,
                                        "char": 31
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "documentType",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1650,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1650,
                                    "char": 31
                                },
                                "right": {
                                    "type": "static-constant-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "self",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1650,
                                        "char": 45
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "HTML5",
                                        "file": "\/app\/phalcon\/Tag.zep",
                                        "line": 1650,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1650,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1650,
                                "char": 45
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "code",
                                            "expr": {
                                                "type": "string",
                                                "value": " \/>",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1651,
                                                "char": 27
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1651,
                                            "char": 27
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1652,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "concat-assign",
                                            "variable": "code",
                                            "expr": {
                                                "type": "string",
                                                "value": ">",
                                                "file": "\/app\/phalcon\/Tag.zep",
                                                "line": 1653,
                                                "char": 25
                                            },
                                            "file": "\/app\/phalcon\/Tag.zep",
                                            "line": 1653,
                                            "char": 25
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Tag.zep",
                                    "line": 1654,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1656,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "code",
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1656,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Tag.zep",
                            "line": 1657,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds INPUT tags that implements the checked attribute\n     *\n     * @param array parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Tag.zep",
                                "line": 1581,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 1581,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 1580,
                    "last-line": 1658,
                    "char": 35
                }
            ],
            "constants": [
                {
                    "type": "const",
                    "name": "HTML32",
                    "default": {
                        "type": "int",
                        "value": "1",
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 24,
                        "char": 21
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 25,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "HTML401_STRICT",
                    "default": {
                        "type": "int",
                        "value": "2",
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 25,
                        "char": 29
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 26,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "HTML401_TRANSITIONAL",
                    "default": {
                        "type": "int",
                        "value": "3",
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 26,
                        "char": 35
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 27,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "HTML401_FRAMESET",
                    "default": {
                        "type": "int",
                        "value": "4",
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 27,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 28,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "HTML5",
                    "default": {
                        "type": "int",
                        "value": "5",
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 28,
                        "char": 20
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 29,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "XHTML10_STRICT",
                    "default": {
                        "type": "int",
                        "value": "6",
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 29,
                        "char": 29
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 30,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "XHTML10_TRANSITIONAL",
                    "default": {
                        "type": "int",
                        "value": "7",
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 30,
                        "char": 35
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 31,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "XHTML10_FRAMESET",
                    "default": {
                        "type": "int",
                        "value": "8",
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 31,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 32,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "XHTML11",
                    "default": {
                        "type": "int",
                        "value": "9",
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 32,
                        "char": 22
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 33,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "XHTML20",
                    "default": {
                        "type": "int",
                        "value": "10",
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 33,
                        "char": 23
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 34,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "XHTML5",
                    "default": {
                        "type": "int",
                        "value": "11",
                        "file": "\/app\/phalcon\/Tag.zep",
                        "line": 34,
                        "char": 22
                    },
                    "file": "\/app\/phalcon\/Tag.zep",
                    "line": 36,
                    "char": 13
                }
            ],
            "file": "\/app\/phalcon\/Tag.zep",
            "line": 22,
            "char": 5
        },
        "file": "\/app\/phalcon\/Tag.zep",
        "line": 22,
        "char": 5
    }
]