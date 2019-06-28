[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Annotations",
        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Countable",
                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                "line": 13,
                "char": 14
            }
        ],
        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Iterator",
                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                "line": 14,
                "char": 13
            }
        ],
        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Annotations\\Annotation",
                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                "line": 15,
                "char": 35
            }
        ],
        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Annotations\\Exception",
                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                "line": 16,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
        "line": 34,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Represents a collection of annotations. This class allows to traverse a group\n * of annotations easily\n *\n *```php\n * \/\/ Traverse annotations\n * foreach ($classAnnotations as $annotation) {\n *     echo \"Name=\", $annotation->getName(), PHP_EOL;\n * }\n *\n * \/\/ Check if the annotations has a specific\n * var_dump($classAnnotations->has(\"Cacheable\"));\n *\n * \/\/ Get an specific annotation in the collection\n * $annotation = $classAnnotations->get(\"Cacheable\");\n *```\n *",
        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
        "line": 35,
        "char": 5
    },
    {
        "type": "class",
        "name": "Collection",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "Iterator",
                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                "line": 35,
                "char": 37
            },
            {
                "type": "variable",
                "value": "Countable",
                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                "line": 36,
                "char": 1
            }
        ],
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "annotations",
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                    "line": 44,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "position",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                        "line": 45,
                        "char": 27
                    },
                    "docblock": "**\n     * @var int\n     *",
                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                    "line": 49,
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
                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                "line": 50,
                                "char": 58
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 50,
                            "char": 58
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "annotations",
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 52,
                                    "char": 24
                                },
                                {
                                    "variable": "annotationData",
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 52,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 54,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "annotations",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                        "line": 54,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 54,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 56,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "reflectionData",
                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                "line": 56,
                                "char": 46
                            },
                            "value": "annotationData",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "annotations",
                                            "expr": {
                                                "type": "new",
                                                "class": "Annotation",
                                                "dynamic": 0,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "annotationData",
                                                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                                            "line": 57,
                                                            "char": 62
                                                        },
                                                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                                        "line": 57,
                                                        "char": 62
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                                "line": 57,
                                                "char": 63
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                            "line": 57,
                                            "char": 63
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 58,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 60,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "annotations",
                                    "expr": {
                                        "type": "variable",
                                        "value": "annotations",
                                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                        "line": 60,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 60,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 61,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Annotations\\Collection constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                        "line": 51,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                    "line": 50,
                    "last-line": 65,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "count",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "count",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                                "line": 68,
                                                "char": 27
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "annotations",
                                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                                "line": 68,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                            "line": 68,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                        "line": 68,
                                        "char": 39
                                    }
                                ],
                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                "line": 68,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 69,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the number of annotations in the collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                "line": 67,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                        "line": 67,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                    "line": 66,
                    "last-line": 73,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "current",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "annotation",
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 76,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 78,
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
                                        "value": "annotation",
                                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                        "line": 78,
                                        "char": 65
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                                "line": 78,
                                                "char": 36
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "annotations",
                                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                                "line": 78,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                            "line": 78,
                                            "char": 48
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                                "line": 78,
                                                "char": 54
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "position",
                                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                                "line": 78,
                                                "char": 63
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                            "line": 78,
                                            "char": 63
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                        "line": 78,
                                        "char": 65
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 78,
                                    "char": 65
                                },
                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                "line": 78,
                                "char": 65
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                        "line": 79,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 80,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 82,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "annotation",
                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                "line": 82,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 83,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the current annotation in the iterator\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Annotation",
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 74,
                                    "char": 47
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                "line": 74,
                                "char": 47
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                "line": 75,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                        "line": 75,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                    "line": 74,
                    "last-line": 87,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "get",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 88,
                            "char": 36
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "annotation",
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 90,
                                    "char": 23
                                },
                                {
                                    "variable": "annotations",
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 90,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 92,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "annotations",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                            "line": 92,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "annotations",
                                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                            "line": 92,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                        "line": 92,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 92,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 94,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "annotations",
                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                "line": 94,
                                "char": 39
                            },
                            "value": "annotation",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                            "line": 95,
                                            "char": 22
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "annotation",
                                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                                "line": 95,
                                                "char": 35
                                            },
                                            "name": "getName",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                            "line": 95,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                        "line": 95,
                                        "char": 46
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "variable",
                                                "value": "annotation",
                                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                                "line": 96,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                            "line": 97,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 98,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 100,
                            "char": 13
                        },
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
                                                    "type": "string",
                                                    "value": "Collection doesn't have an annotation called '",
                                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                                    "line": 101,
                                                    "char": 60
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                                    "line": 101,
                                                    "char": 67
                                                },
                                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                                "line": 101,
                                                "char": 67
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "'",
                                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                                "line": 102,
                                                "char": 9
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                            "line": 102,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                        "line": 102,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                "line": 102,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 103,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the first annotation that match a name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Annotation",
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 89,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                "line": 89,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                        "line": 89,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                    "line": 88,
                    "last-line": 107,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAll",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 108,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "annotations",
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 110,
                                    "char": 24
                                },
                                {
                                    "variable": "annotation",
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 110,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 111,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "found",
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 111,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 113,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "found",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                        "line": 113,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 113,
                                    "char": 23
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "annotations",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                            "line": 114,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "annotations",
                                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                            "line": 114,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                        "line": 114,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 114,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 116,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "annotations",
                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                "line": 116,
                                "char": 39
                            },
                            "value": "annotation",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                            "line": 117,
                                            "char": 22
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "annotation",
                                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                                "line": 117,
                                                "char": 35
                                            },
                                            "name": "getName",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                            "line": 117,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                        "line": 117,
                                        "char": 46
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "found",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "annotation",
                                                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                                        "line": 118,
                                                        "char": 41
                                                    },
                                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                                    "line": 118,
                                                    "char": 41
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                            "line": 119,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 120,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 122,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "found",
                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                "line": 122,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 123,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns all the annotations that match a name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Annotation",
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 109,
                                    "char": 5
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                "line": 109,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                        "line": 109,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                    "line": 108,
                    "last-line": 127,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAnnotations",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 130,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "annotations",
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 130,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                "line": 130,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 131,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the internal annotations as an array\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Annotation",
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 129,
                                    "char": 5
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                "line": 129,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                        "line": 129,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                    "line": 128,
                    "last-line": 135,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "has",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 136,
                            "char": 36
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "annotations",
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 138,
                                    "char": 24
                                },
                                {
                                    "variable": "annotation",
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 138,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 140,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "annotations",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                            "line": 140,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "annotations",
                                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                            "line": 140,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                        "line": 140,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 140,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 142,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "annotations",
                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                "line": 142,
                                "char": 39
                            },
                            "value": "annotation",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                            "line": 143,
                                            "char": 22
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "annotation",
                                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                                "line": 143,
                                                "char": 35
                                            },
                                            "name": "getName",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                            "line": 143,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                        "line": 143,
                                        "char": 46
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "bool",
                                                "value": "true",
                                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                                "line": 144,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                            "line": 145,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 146,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 148,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                "line": 148,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 149,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check if an annotation exists in a collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                "line": 137,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                        "line": 137,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                    "line": 136,
                    "last-line": 153,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "key",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 156,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "position",
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 156,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                "line": 156,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 157,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the current position\/key in the iterator\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                "line": 155,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                        "line": 155,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                    "line": 154,
                    "last-line": 161,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "next",
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-incr",
                                    "variable": "this",
                                    "property": "position",
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 164,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 165,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Moves the internal iteration pointer to the next position\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                        "line": 163,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                    "line": 162,
                    "last-line": 169,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "rewind",
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "position",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                        "line": 172,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 172,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 173,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Rewinds the internal iterator\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                        "line": 171,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                    "line": 170,
                    "last-line": 177,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "valid",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                            "line": 180,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "annotations",
                                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                            "line": 180,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                        "line": 180,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                            "line": 180,
                                            "char": 45
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "position",
                                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                            "line": 180,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                        "line": 180,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                    "line": 180,
                                    "char": 55
                                },
                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                "line": 180,
                                "char": 55
                            },
                            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                            "line": 181,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check if the current annotation in the iterator is valid\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                                "line": 179,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                        "line": 179,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Collection.zep",
                    "line": 178,
                    "last-line": 182,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Annotations\/Collection.zep",
            "line": 35,
            "char": 5
        },
        "file": "\/app\/phalcon\/Annotations\/Collection.zep",
        "line": 35,
        "char": 5
    }
]