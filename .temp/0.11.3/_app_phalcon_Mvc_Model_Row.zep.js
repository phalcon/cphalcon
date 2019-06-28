[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model",
        "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "ArrayAccess",
                "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                "line": 13,
                "char": 16
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "JsonSerializable",
                "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                "line": 14,
                "char": 21
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ModelInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                "line": 15,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\EntityInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                "line": 16,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\Exception",
                "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                "line": 17,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\ResultInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                "line": 18,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
        "line": 25,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\Row\n *\n * This component allows Phalcon\\Mvc\\Model to return rows without an associated entity.\n * This objects implements the ArrayAccess interface to allow access the object as object->x or array[x].\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
        "line": 26,
        "char": 5
    },
    {
        "type": "class",
        "name": "Row",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "EntityInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                "line": 26,
                "char": 37
            },
            {
                "type": "variable",
                "value": "ResultInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                "line": 26,
                "char": 54
            },
            {
                "type": "variable",
                "value": "ArrayAccess",
                "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                "line": 26,
                "char": 67
            },
            {
                "type": "variable",
                "value": "JsonSerializable",
                "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                "line": 27,
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
                    "name": "jsonSerialize",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                    "line": 33,
                                    "char": 21
                                },
                                "name": "toArray",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                "line": 33,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                            "line": 34,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n    * Serializes the object for json_encode\n    *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                "line": 32,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                        "line": 32,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                    "line": 31,
                    "last-line": 42,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "offsetGet",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "index",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                            "line": 43,
                            "char": 40
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                    "line": 45,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                            "line": 47,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                            "line": 47,
                                            "char": 49
                                        },
                                        "right": {
                                            "type": "property-dynamic-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                                "line": 47,
                                                "char": 40
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "index",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                                "line": 47,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                            "line": 47,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                        "line": 47,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                    "line": 47,
                                    "char": 49
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                "line": 47,
                                "char": 49
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
                                                    "value": "The index does not exist in the row",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                                    "line": 48,
                                                    "char": 68
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                                "line": 48,
                                                "char": 68
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                        "line": 48,
                                        "char": 69
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                    "line": 49,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                            "line": 51,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "value",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                "line": 51,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                            "line": 52,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets a record in a specific position of the row\n     *\n     * @param string|int index\n     *\n     * @return string|Phalcon\\Mvc\\ModelInterface\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                "line": 44,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                        "line": 44,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                    "line": 43,
                    "last-line": 58,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "offsetExists",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "index",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                            "line": 59,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "property-dynamic-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                        "line": 61,
                                        "char": 27
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "index",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                        "line": 61,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                    "line": 61,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                "line": 61,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                            "line": 62,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks whether offset exists in the row\n     *\n     * @param string|int $index\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                "line": 60,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                        "line": 60,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                    "line": 59,
                    "last-line": 69,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "offsetSet",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "index",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                            "line": 70,
                            "char": 40
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                            "line": 70,
                            "char": 51
                        }
                    ],
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
                                            "value": "Row is an immutable ArrayAccess object",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                            "line": 72,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                        "line": 72,
                                        "char": 67
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                "line": 72,
                                "char": 68
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                            "line": 73,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Rows cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface\n     *\n     * @param string|int index\n     * @param \\Phalcon\\Mvc\\ModelInterface value\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                        "line": 71,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                    "line": 70,
                    "last-line": 79,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "offsetUnset",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "offset",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                            "line": 80,
                            "char": 43
                        }
                    ],
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
                                            "value": "Row is an immutable ArrayAccess object",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                            "line": 82,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                        "line": 82,
                                        "char": 67
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                "line": 82,
                                "char": 68
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                            "line": 83,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Rows cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface\n     *\n     * @param string|int offset\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                        "line": 81,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                    "line": 80,
                    "last-line": 93,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "readAttribute",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "attribute",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                            "line": 94,
                            "char": 52
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                    "line": 96,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                            "line": 98,
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
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                        "line": 98,
                                        "char": 44
                                    },
                                    "right": {
                                        "type": "property-dynamic-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                            "line": 98,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "attribute",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                            "line": 98,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                        "line": 98,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                    "line": 98,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                "line": 98,
                                "char": 44
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                        "line": 99,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                    "line": 100,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                            "line": 102,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "value",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                "line": 102,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                            "line": 103,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Reads an attribute value by its name\n     *\n     *```php\n     * echo $robot->readAttribute(\"name\");\n     *```\n     *\n     * @return mixed\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                    "line": 94,
                    "last-line": 107,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDirtyState",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "dirtyState",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                            "line": 108,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                "line": 110,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                            "line": 111,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set the current object's state\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ModelInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                    "line": 108,
                                    "char": 71
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                "line": 108,
                                "char": 71
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                "line": 109,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                        "line": 109,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                    "line": 108,
                    "last-line": 115,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "toArray",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "get_object_vars",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                            "line": 118,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                        "line": 118,
                                        "char": 36
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                "line": 118,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                            "line": 119,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the instance as an array representation\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                "line": 117,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                        "line": 117,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                    "line": 116,
                    "last-line": 129,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "writeAttribute",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "attribute",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                            "line": 130,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                            "line": 130,
                            "char": 60
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable-dynamic-object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "attribute",
                                    "expr": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                        "line": 132,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                                    "line": 132,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                            "line": 133,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Writes an attribute value by its name\n     *\n     *```php\n     * $robot->writeAttribute(\"name\", \"Rosey\");\n     *```\n     *\n     * @param mixed value\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                        "line": 131,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
                    "line": 130,
                    "last-line": 134,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
            "line": 26,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/Row.zep",
        "line": 26,
        "char": 5
    }
]