[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Collection",
        "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "ArrayAccess",
                "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                "line": 13,
                "char": 16
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\EntityInterface",
                "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                "line": 14,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Collection\\Exception",
                "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                "line": 15,
                "char": 37
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
        "line": 22,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Collection\\Document\n *\n * This component allows Phalcon\\Mvc\\Collection to return rows without an associated entity.\n * This objects implements the ArrayAccess interface to allow access the object as object->x or array[x].\n *",
        "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
        "line": 23,
        "char": 5
    },
    {
        "type": "class",
        "name": "Document",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "EntityInterface",
                "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                "line": 23,
                "char": 42
            },
            {
                "type": "variable",
                "value": "ArrayAccess",
                "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                "line": 24,
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
                    "name": "offsetGet",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "index",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                            "line": 28,
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
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                    "line": 30,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                            "line": 32,
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
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                            "line": 32,
                                            "char": 49
                                        },
                                        "right": {
                                            "type": "property-dynamic-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                                "line": 32,
                                                "char": 40
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "index",
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                                "line": 32,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                            "line": 32,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                        "line": 32,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                    "line": 32,
                                    "char": 49
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                "line": 32,
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
                                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                                    "line": 33,
                                                    "char": 68
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                                "line": 33,
                                                "char": 68
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                        "line": 33,
                                        "char": 69
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                    "line": 34,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                            "line": 36,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "value",
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                "line": 36,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                            "line": 37,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the value of a field using the ArrayAccess interfase\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                "line": 29,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                        "line": 29,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                    "line": 28,
                    "last-line": 41,
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
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                            "line": 42,
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
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                        "line": 44,
                                        "char": 27
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "index",
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                        "line": 44,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                    "line": 44,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                "line": 44,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                            "line": 45,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks whether an offset exists in the document\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                "line": 43,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                        "line": 43,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                    "line": 42,
                    "last-line": 49,
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
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                            "line": 50,
                            "char": 40
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                            "line": 50,
                            "char": 47
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
                                    "property": "index",
                                    "expr": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                        "line": 52,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                    "line": 52,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                            "line": 53,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Change a value using the ArrayAccess interface\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                        "line": 51,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                    "line": 50,
                    "last-line": 57,
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
                            "name": "index",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                            "line": 58,
                            "char": 42
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
                                            "value": "The index does not exist in the row",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                            "line": 60,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                        "line": 60,
                                        "char": 64
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                "line": 60,
                                "char": 65
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                            "line": 61,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Rows cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                        "line": 59,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                    "line": 58,
                    "last-line": 69,
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
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                            "line": 70,
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
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                    "line": 72,
                                    "char": 18
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                            "line": 74,
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
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                        "line": 74,
                                        "char": 44
                                    },
                                    "right": {
                                        "type": "property-dynamic-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                            "line": 74,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "attribute",
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                            "line": 74,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                        "line": 74,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                    "line": 74,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                "line": 74,
                                "char": 44
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                        "line": 75,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                    "line": 76,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                            "line": 78,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "value",
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                "line": 78,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                            "line": 79,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Reads an attribute value by its name\n     *\n     *```php\n     *  echo $robot->readAttribute(\"name\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                "line": 70,
                                "char": 61
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                "line": 71,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                        "line": 71,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                    "line": 70,
                    "last-line": 83,
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
                                            "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                            "line": 86,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                        "line": 86,
                                        "char": 36
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                "line": 86,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                            "line": 87,
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
                                "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                "line": 85,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                        "line": 85,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                    "line": 84,
                    "last-line": 95,
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
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                            "line": 96,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                            "line": 96,
                            "char": 64
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
                                        "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                        "line": 98,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                                    "line": 98,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                            "line": 99,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Writes an attribute value by its name\n     *\n     *```php\n     *  $robot->writeAttribute(\"name\", \"Rosey\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                        "line": 97,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
                    "line": 96,
                    "last-line": 100,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
            "line": 23,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/Collection\/Document.zep",
        "line": 23,
        "char": 5
    }
]