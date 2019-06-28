[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Annotations",
        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Annotations\\Collection",
                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                "line": 13,
                "char": 35
            }
        ],
        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
        "line": 32,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Allows to manipulate the annotations reflection in an OO manner\n *\n *```php\n * use Phalcon\\Annotations\\Reader;\n * use Phalcon\\Annotations\\Reflection;\n *\n * \/\/ Parse the annotations in a class\n * $reader = new Reader();\n * $parsing = $reader->parse(\"MyComponent\");\n *\n * \/\/ Create the reflection\n * $reflection = new Reflection($parsing);\n *\n * \/\/ Get the annotations in the class docblock\n * $classAnnotations = $reflection->getClassAnnotations();\n *```\n *",
        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
        "line": 33,
        "char": 5
    },
    {
        "type": "class",
        "name": "Reflection",
        "abstract": 0,
        "final": 0,
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "classAnnotations",
                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                    "line": 37,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "methodAnnotations",
                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                    "line": 39,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "propertyAnnotations",
                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                    "line": 43,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "reflectionData",
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                    "line": 48,
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
                            "name": "reflectionData",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                "line": 49,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                            "line": 49,
                            "char": 58
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "reflectionData",
                                    "expr": {
                                        "type": "variable",
                                        "value": "reflectionData",
                                        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                        "line": 51,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 51,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                            "line": 52,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Annotations\\Reflection constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                        "line": 50,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                    "line": 49,
                    "last-line": 56,
                    "char": 19
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "__set_state",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                            "line": 57,
                            "char": 51
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "reflectionData",
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 59,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                            "line": 64,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "reflectionData",
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 64,
                                    "char": 55
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "data",
                                        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                        "line": 64,
                                        "char": 38
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "reflectionData",
                                        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                        "line": 64,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 64,
                                    "char": 55
                                },
                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                "line": 64,
                                "char": 55
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "new",
                                        "class": "self",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "reflectionData",
                                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                    "line": 65,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                "line": 65,
                                                "char": 43
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                        "line": 65,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 66,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                            "line": 68,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "new",
                                "class": "self",
                                "dynamic": 0,
                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                "line": 68,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                            "line": 69,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Restores the state of a Phalcon\\Annotations\\Reflection variable export\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Reflection",
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 58,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                "line": 58,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                        "line": 58,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                    "line": 57,
                    "last-line": 73,
                    "char": 26
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getClassAnnotations",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "reflectionClass",
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 76,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                            "line": 78,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                        "line": 78,
                                        "char": 17
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "classAnnotations",
                                        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                        "line": 78,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 78,
                                    "char": 37
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 78,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                "line": 78,
                                "char": 44
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "reflectionClass",
                                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                            "line": 79,
                                            "char": 67
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                    "line": 79,
                                                    "char": 44
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "reflectionData",
                                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                    "line": 79,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                "line": 79,
                                                "char": 59
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "class",
                                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                "line": 79,
                                                "char": 65
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                            "line": 79,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                        "line": 79,
                                        "char": 67
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "classAnnotations",
                                                    "expr": {
                                                        "type": "new",
                                                        "class": "Collection",
                                                        "dynamic": 0,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "reflectionClass",
                                                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                                    "line": 80,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                                "line": 80,
                                                                "char": 76
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                        "line": 80,
                                                        "char": 77
                                                    },
                                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                    "line": 80,
                                                    "char": 77
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                            "line": 81,
                                            "char": 13
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
                                                    "property": "classAnnotations",
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "false",
                                                        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                        "line": 82,
                                                        "char": 51
                                                    },
                                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                    "line": 82,
                                                    "char": 51
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                            "line": 83,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 84,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                            "line": 86,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 86,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "classAnnotations",
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 86,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                "line": 86,
                                "char": 38
                            },
                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                            "line": 87,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the annotations found in the class docblock\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 74,
                                    "char": 59
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                "line": 74,
                                "char": 59
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                "line": 75,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                        "line": 75,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                    "line": 74,
                    "last-line": 91,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMethodsAnnotations",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "reflectionMethods",
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 94,
                                    "char": 30
                                },
                                {
                                    "variable": "methodName",
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 94,
                                    "char": 42
                                },
                                {
                                    "variable": "reflectionMethod",
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 94,
                                    "char": 60
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                            "line": 96,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                        "line": 96,
                                        "char": 17
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "methodAnnotations",
                                        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                        "line": 96,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 96,
                                    "char": 38
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 96,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                "line": 96,
                                "char": 45
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "reflectionMethods",
                                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                            "line": 97,
                                            "char": 71
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                    "line": 97,
                                                    "char": 46
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "reflectionData",
                                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                    "line": 97,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                "line": 97,
                                                "char": 61
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "methods",
                                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                "line": 97,
                                                "char": 69
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                            "line": 97,
                                            "char": 71
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                        "line": 97,
                                        "char": 71
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "count",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "reflectionMethods",
                                                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                            "line": 98,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                        "line": 98,
                                                        "char": 43
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                "line": 98,
                                                "char": 45
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "methodAnnotations",
                                                            "expr": {
                                                                "type": "empty-array",
                                                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                                "line": 99,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                            "line": 99,
                                                            "char": 53
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                    "line": 101,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "for",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "reflectionMethods",
                                                        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                        "line": 101,
                                                        "char": 75
                                                    },
                                                    "key": "methodName",
                                                    "value": "reflectionMethod",
                                                    "reverse": 0,
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "object-property-array-index",
                                                                    "operator": "assign",
                                                                    "variable": "this",
                                                                    "property": "methodAnnotations",
                                                                    "index-expr": [
                                                                        {
                                                                            "type": "variable",
                                                                            "value": "methodName",
                                                                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                                            "line": 102,
                                                                            "char": 63
                                                                        }
                                                                    ],
                                                                    "expr": {
                                                                        "type": "new",
                                                                        "class": "Collection",
                                                                        "dynamic": 0,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "reflectionMethod",
                                                                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                                                    "line": 104,
                                                                                    "char": 25
                                                                                },
                                                                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                                                "line": 104,
                                                                                "char": 25
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                                        "line": 104,
                                                                        "char": 26
                                                                    },
                                                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                                    "line": 104,
                                                                    "char": 26
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                            "line": 105,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                    "line": 107,
                                                    "char": 26
                                                },
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                            "line": 107,
                                                            "char": 33
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "methodAnnotations",
                                                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                            "line": 107,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                        "line": 107,
                                                        "char": 51
                                                    },
                                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                    "line": 108,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                            "line": 109,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 111,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "methodAnnotations",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                "line": 111,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                            "line": 111,
                                            "char": 48
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 112,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                            "line": 114,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 114,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "methodAnnotations",
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 114,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                "line": 114,
                                "char": 39
                            },
                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                            "line": 115,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the annotations found in the methods' docblocks\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 92,
                                    "char": 63
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                "line": 92,
                                "char": 63
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                "line": 93,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                        "line": 93,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                    "line": 92,
                    "last-line": 119,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getPropertiesAnnotations",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "reflectionProperties",
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 122,
                                    "char": 33
                                },
                                {
                                    "variable": "property",
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 122,
                                    "char": 43
                                },
                                {
                                    "variable": "reflectionProperty",
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 122,
                                    "char": 63
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                            "line": 124,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                        "line": 124,
                                        "char": 17
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "propertyAnnotations",
                                        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                        "line": 124,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 124,
                                    "char": 40
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 124,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                "line": 124,
                                "char": 47
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "reflectionProperties",
                                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                            "line": 125,
                                            "char": 77
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                    "line": 125,
                                                    "char": 49
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "reflectionData",
                                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                    "line": 125,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                "line": 125,
                                                "char": 64
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "properties",
                                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                "line": 125,
                                                "char": 75
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                            "line": 125,
                                            "char": 77
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                        "line": 125,
                                        "char": 77
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "count",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "reflectionProperties",
                                                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                            "line": 126,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                        "line": 126,
                                                        "char": 46
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                "line": 126,
                                                "char": 48
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "propertyAnnotations",
                                                            "expr": {
                                                                "type": "empty-array",
                                                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                                "line": 127,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                            "line": 127,
                                                            "char": 55
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                    "line": 129,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "for",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "reflectionProperties",
                                                        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                        "line": 129,
                                                        "char": 78
                                                    },
                                                    "key": "property",
                                                    "value": "reflectionProperty",
                                                    "reverse": 0,
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "object-property-array-index",
                                                                    "operator": "assign",
                                                                    "variable": "this",
                                                                    "property": "propertyAnnotations",
                                                                    "index-expr": [
                                                                        {
                                                                            "type": "variable",
                                                                            "value": "property",
                                                                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                                            "line": 130,
                                                                            "char": 63
                                                                        }
                                                                    ],
                                                                    "expr": {
                                                                        "type": "new",
                                                                        "class": "Collection",
                                                                        "dynamic": 0,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "reflectionProperty",
                                                                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                                                    "line": 132,
                                                                                    "char": 25
                                                                                },
                                                                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                                                "line": 132,
                                                                                "char": 25
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                                        "line": 132,
                                                                        "char": 26
                                                                    },
                                                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                                    "line": 132,
                                                                    "char": 26
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                            "line": 133,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                    "line": 135,
                                                    "char": 26
                                                },
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                            "line": 135,
                                                            "char": 33
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "propertyAnnotations",
                                                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                            "line": 135,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                        "line": 135,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                    "line": 136,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                            "line": 137,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 139,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "propertyAnnotations",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                                "line": 139,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                            "line": 139,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 140,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                            "line": 142,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 142,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "propertyAnnotations",
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 142,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                "line": 142,
                                "char": 41
                            },
                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                            "line": 143,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the annotations found in the properties' docblocks\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 120,
                                    "char": 66
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                "line": 120,
                                "char": 66
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                "line": 121,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                        "line": 121,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                    "line": 120,
                    "last-line": 148,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getReflectionData",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 151,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "reflectionData",
                                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                    "line": 151,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                "line": 151,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                            "line": 152,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the raw parsing intermediate definitions used to construct the\n     * reflection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                                "line": 150,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                        "line": 150,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
                    "line": 149,
                    "last-line": 153,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
            "line": 33,
            "char": 5
        },
        "file": "\/app\/phalcon\/Annotations\/Reflection.zep",
        "line": 33,
        "char": 5
    }
]