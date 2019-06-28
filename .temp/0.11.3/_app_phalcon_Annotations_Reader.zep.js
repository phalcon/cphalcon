[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Annotations",
        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Annotations\\ReaderInterface",
                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                "line": 13,
                "char": 40
            }
        ],
        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "ReflectionClass",
                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                "line": 14,
                "char": 20
            }
        ],
        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
        "line": 18,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Parses docblocks returning an array with the found annotations\n *",
        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
        "line": 19,
        "char": 5
    },
    {
        "type": "class",
        "name": "Reader",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "ReaderInterface",
                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                "line": 20,
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
                    "name": "parse",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "className",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                            "line": 24,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "reflection",
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 26,
                                    "char": 23
                                },
                                {
                                    "variable": "comment",
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 26,
                                    "char": 32
                                },
                                {
                                    "variable": "properties",
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 26,
                                    "char": 44
                                },
                                {
                                    "variable": "methods",
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 26,
                                    "char": 53
                                },
                                {
                                    "variable": "property",
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 26,
                                    "char": 63
                                },
                                {
                                    "variable": "method",
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 26,
                                    "char": 71
                                },
                                {
                                    "variable": "classAnnotations",
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 27,
                                    "char": 29
                                },
                                {
                                    "variable": "line",
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 27,
                                    "char": 35
                                },
                                {
                                    "variable": "annotationsProperties",
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 27,
                                    "char": 58
                                },
                                {
                                    "variable": "propertyAnnotations",
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 27,
                                    "char": 79
                                },
                                {
                                    "variable": "annotationsMethods",
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 28,
                                    "char": 31
                                },
                                {
                                    "variable": "methodAnnotations",
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 28,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                            "line": 29,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "annotations",
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 29,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                            "line": 31,
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
                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                        "line": 31,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 31,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                            "line": 36,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "reflection",
                                    "expr": {
                                        "type": "new",
                                        "class": "ReflectionClass",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "className",
                                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                    "line": 36,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                "line": 36,
                                                "char": 55
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                        "line": 36,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 36,
                                    "char": 56
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                            "line": 38,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "comment",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "reflection",
                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                            "line": 38,
                                            "char": 34
                                        },
                                        "name": "getDocComment",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                        "line": 38,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 38,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                            "line": 39,
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
                                        "value": "comment",
                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                        "line": 39,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 39,
                                    "char": 28
                                },
                                "right": {
                                    "type": "string",
                                    "value": "string",
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 39,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                "line": 39,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "classAnnotations",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "phannot_parse_annotations",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "comment",
                                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                            "line": 45,
                                                            "char": 24
                                                        },
                                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                        "line": 45,
                                                        "char": 24
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "reflection",
                                                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                "line": 46,
                                                                "char": 28
                                                            },
                                                            "name": "getFileName",
                                                            "call-type": 1,
                                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                            "line": 46,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                        "line": 46,
                                                        "char": 42
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "reflection",
                                                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                "line": 47,
                                                                "char": 28
                                                            },
                                                            "name": "getStartLine",
                                                            "call-type": 1,
                                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                            "line": 48,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                        "line": 48,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                "line": 48,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                            "line": 48,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 53,
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
                                                "value": "classAnnotations",
                                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                "line": 53,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                            "line": 53,
                                            "char": 41
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                            "line": 53,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                        "line": 53,
                                        "char": 49
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "annotations",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "class",
                                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                            "line": 54,
                                                            "char": 38
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "classAnnotations",
                                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                        "line": 54,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                    "line": 54,
                                                    "char": 58
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                            "line": 55,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 56,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                            "line": 61,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "properties",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "reflection",
                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                            "line": 61,
                                            "char": 37
                                        },
                                        "name": "getProperties",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                        "line": 61,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 61,
                                    "char": 53
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                            "line": 63,
                            "char": 10
                        },
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
                                            "value": "properties",
                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                            "line": 63,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                        "line": 63,
                                        "char": 28
                                    }
                                ],
                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                "line": 63,
                                "char": 30
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "line",
                                            "expr": {
                                                "type": "int",
                                                "value": "1",
                                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                "line": 67,
                                                "char": 25
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                            "line": 67,
                                            "char": 25
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 69,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "annotationsProperties",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                "line": 69,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                            "line": 69,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 71,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "properties",
                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                        "line": 71,
                                        "char": 40
                                    },
                                    "value": "property",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "comment",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "property",
                                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                            "line": 75,
                                                            "char": 40
                                                        },
                                                        "name": "getDocComment",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                        "line": 75,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                    "line": 75,
                                                    "char": 56
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                            "line": 77,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "typeof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "comment",
                                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                        "line": 77,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                    "line": 77,
                                                    "char": 36
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "string",
                                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                    "line": 77,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                "line": 77,
                                                "char": 45
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "propertyAnnotations",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "phannot_parse_annotations",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "comment",
                                                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                            "line": 82,
                                                                            "char": 32
                                                                        },
                                                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                        "line": 82,
                                                                        "char": 32
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "mcall",
                                                                            "variable": {
                                                                                "type": "variable",
                                                                                "value": "reflection",
                                                                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                                "line": 83,
                                                                                "char": 36
                                                                            },
                                                                            "name": "getFileName",
                                                                            "call-type": 1,
                                                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                            "line": 83,
                                                                            "char": 50
                                                                        },
                                                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                        "line": 83,
                                                                        "char": 50
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "line",
                                                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                            "line": 85,
                                                                            "char": 21
                                                                        },
                                                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                        "line": 85,
                                                                        "char": 21
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                "line": 85,
                                                                "char": 22
                                                            },
                                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                            "line": 85,
                                                            "char": 22
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                    "line": 87,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "equals",
                                                        "left": {
                                                            "type": "typeof",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "propertyAnnotations",
                                                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                "line": 87,
                                                                "char": 52
                                                            },
                                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                            "line": 87,
                                                            "char": 52
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "array",
                                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                            "line": 87,
                                                            "char": 60
                                                        },
                                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                        "line": 87,
                                                        "char": 60
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "array-index",
                                                                    "operator": "assign",
                                                                    "variable": "annotationsProperties",
                                                                    "index-expr": [
                                                                        {
                                                                            "type": "property-access",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "property",
                                                                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                                "line": 88,
                                                                                "char": 60
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "name",
                                                                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                                "line": 88,
                                                                                "char": 65
                                                                            },
                                                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                            "line": 88,
                                                                            "char": 65
                                                                        }
                                                                    ],
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "propertyAnnotations",
                                                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                        "line": 88,
                                                                        "char": 88
                                                                    },
                                                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                    "line": 88,
                                                                    "char": 88
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                            "line": 89,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                    "line": 90,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                            "line": 91,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 93,
                                    "char": 14
                                },
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
                                                    "value": "annotationsProperties",
                                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                    "line": 93,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                "line": 93,
                                                "char": 43
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                        "line": 93,
                                        "char": 45
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "annotations",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "properties",
                                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                            "line": 94,
                                                            "char": 43
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "annotationsProperties",
                                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                        "line": 94,
                                                        "char": 68
                                                    },
                                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                    "line": 94,
                                                    "char": 68
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                            "line": 95,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 96,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                            "line": 101,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "methods",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "reflection",
                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                            "line": 101,
                                            "char": 34
                                        },
                                        "name": "getMethods",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                        "line": 101,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 101,
                                    "char": 47
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                            "line": 103,
                            "char": 10
                        },
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
                                            "value": "methods",
                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                            "line": 103,
                                            "char": 25
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                        "line": 103,
                                        "char": 25
                                    }
                                ],
                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                "line": 103,
                                "char": 27
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "annotationsMethods",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                "line": 104,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                            "line": 104,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 106,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "methods",
                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                        "line": 106,
                                        "char": 35
                                    },
                                    "value": "method",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "comment",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "method",
                                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                            "line": 110,
                                                            "char": 38
                                                        },
                                                        "name": "getDocComment",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                        "line": 110,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                    "line": 110,
                                                    "char": 54
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                            "line": 112,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "typeof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "comment",
                                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                        "line": 112,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                    "line": 112,
                                                    "char": 36
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "string",
                                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                    "line": 112,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                "line": 112,
                                                "char": 45
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "methodAnnotations",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "phannot_parse_annotations",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "comment",
                                                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                            "line": 117,
                                                                            "char": 32
                                                                        },
                                                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                        "line": 117,
                                                                        "char": 32
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "mcall",
                                                                            "variable": {
                                                                                "type": "variable",
                                                                                "value": "method",
                                                                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                                "line": 118,
                                                                                "char": 32
                                                                            },
                                                                            "name": "getFileName",
                                                                            "call-type": 1,
                                                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                            "line": 118,
                                                                            "char": 46
                                                                        },
                                                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                        "line": 118,
                                                                        "char": 46
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "mcall",
                                                                            "variable": {
                                                                                "type": "variable",
                                                                                "value": "method",
                                                                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                                "line": 119,
                                                                                "char": 32
                                                                            },
                                                                            "name": "getStartLine",
                                                                            "call-type": 1,
                                                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                            "line": 120,
                                                                            "char": 21
                                                                        },
                                                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                        "line": 120,
                                                                        "char": 21
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                "line": 120,
                                                                "char": 22
                                                            },
                                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                            "line": 120,
                                                            "char": 22
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                    "line": 122,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "equals",
                                                        "left": {
                                                            "type": "typeof",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "methodAnnotations",
                                                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                "line": 122,
                                                                "char": 50
                                                            },
                                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                            "line": 122,
                                                            "char": 50
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "array",
                                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                            "line": 122,
                                                            "char": 58
                                                        },
                                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                        "line": 122,
                                                        "char": 58
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "array-index",
                                                                    "operator": "assign",
                                                                    "variable": "annotationsMethods",
                                                                    "index-expr": [
                                                                        {
                                                                            "type": "property-access",
                                                                            "left": {
                                                                                "type": "variable",
                                                                                "value": "method",
                                                                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                                "line": 123,
                                                                                "char": 55
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "name",
                                                                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                                "line": 123,
                                                                                "char": 60
                                                                            },
                                                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                            "line": 123,
                                                                            "char": 60
                                                                        }
                                                                    ],
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "methodAnnotations",
                                                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                        "line": 123,
                                                                        "char": 81
                                                                    },
                                                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                                    "line": 123,
                                                                    "char": 81
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                            "line": 124,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                    "line": 125,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                            "line": 126,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 128,
                                    "char": 14
                                },
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
                                                    "value": "annotationsMethods",
                                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                    "line": 128,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                "line": 128,
                                                "char": 40
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                        "line": 128,
                                        "char": 42
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "annotations",
                                                    "index-expr": [
                                                        {
                                                            "type": "string",
                                                            "value": "methods",
                                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                            "line": 129,
                                                            "char": 40
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "annotationsMethods",
                                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                        "line": 129,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                    "line": 129,
                                                    "char": 62
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                            "line": 130,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 131,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                            "line": 133,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "annotations",
                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                "line": 133,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                            "line": 134,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Reads annotations from the class docblocks, its methods and\/or properties\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                "line": 25,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                        "line": 25,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                    "line": 24,
                    "last-line": 138,
                    "char": 19
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "parseDocBlock",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "docBlock",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                            "line": 139,
                            "char": 57
                        },
                        {
                            "type": "parameter",
                            "name": "file",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                "line": 139,
                                "char": 70
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                            "line": 139,
                            "char": 70
                        },
                        {
                            "type": "parameter",
                            "name": "line",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                "line": 139,
                                "char": 83
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                            "line": 139,
                            "char": 83
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "file",
                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                        "line": 141,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 141,
                                    "char": 25
                                },
                                "right": {
                                    "type": "string",
                                    "value": "string",
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 141,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                "line": 141,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "file",
                                            "expr": {
                                                "type": "string",
                                                "value": "eval code",
                                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                                "line": 142,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                            "line": 142,
                                            "char": 33
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                    "line": 143,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                            "line": 145,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "phannot_parse_annotations",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "docBlock",
                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                            "line": 145,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                        "line": 145,
                                        "char": 50
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "file",
                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                            "line": 145,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                        "line": 145,
                                        "char": 56
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "line",
                                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                            "line": 145,
                                            "char": 62
                                        },
                                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                        "line": 145,
                                        "char": 62
                                    }
                                ],
                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                "line": 145,
                                "char": 63
                            },
                            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                            "line": 146,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Parses a raw doc block returning the annotations found\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                                "line": 140,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                        "line": 140,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Annotations\/Reader.zep",
                    "line": 139,
                    "last-line": 147,
                    "char": 26
                }
            ],
            "file": "\/app\/phalcon\/Annotations\/Reader.zep",
            "line": 19,
            "char": 5
        },
        "file": "\/app\/phalcon\/Annotations\/Reader.zep",
        "line": 19,
        "char": 5
    }
]