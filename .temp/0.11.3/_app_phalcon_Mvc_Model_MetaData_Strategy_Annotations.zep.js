[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model\\MetaData\\Strategy",
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                "line": 13,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\Column",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                "line": 14,
                "char": 22
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ModelInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                "line": 15,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\MetaData",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                "line": 16,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\MetaData\\StrategyInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                "line": 17,
                "char": 49
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Model\\Exception",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                "line": 18,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
        "line": 20,
        "char": 5
    },
    {
        "type": "class",
        "name": "Annotations",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "StrategyInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                "line": 21,
                "char": 1
            }
        ],
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "getColumnMaps",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                "line": 25,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                            "line": 25,
                            "char": 63
                        },
                        {
                            "type": "parameter",
                            "name": "container",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "DiInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                "line": 25,
                                "char": 87
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                            "line": 25,
                            "char": 88
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "annotations",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 27,
                                    "char": 24
                                },
                                {
                                    "variable": "className",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 27,
                                    "char": 35
                                },
                                {
                                    "variable": "reflection",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 27,
                                    "char": 47
                                },
                                {
                                    "variable": "propertiesAnnotations",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 27,
                                    "char": 70
                                },
                                {
                                    "variable": "property",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 27,
                                    "char": 80
                                },
                                {
                                    "variable": "propAnnotations",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 28,
                                    "char": 28
                                },
                                {
                                    "variable": "columnAnnotation",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 28,
                                    "char": 46
                                },
                                {
                                    "variable": "columnName",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 28,
                                    "char": 58
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                            "line": 29,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "orderedColumnMap",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 29,
                                    "char": 31
                                },
                                {
                                    "variable": "reversedColumnMap",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 29,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                            "line": 30,
                            "char": 12
                        },
                        {
                            "type": "declare",
                            "data-type": "bool",
                            "variables": [
                                {
                                    "variable": "hasReversedColumn",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 30,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                            "line": 32,
                            "char": 10
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
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 32,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 32,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 32,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 32,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                "line": 32,
                                "char": 48
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
                                                    "value": "The dependency injector is invalid",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 33,
                                                    "char": 67
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 33,
                                                "char": 67
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 33,
                                        "char": 68
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 34,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                            "line": 36,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "container",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 36,
                                            "char": 37
                                        },
                                        "name": "get",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "annotations",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 36,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 36,
                                                "char": 53
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 36,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 36,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                            "line": 38,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "className",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "get_class",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 38,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 38,
                                                "char": 40
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 38,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 38,
                                    "char": 41
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "reflection",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "annotations",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 39,
                                            "char": 38
                                        },
                                        "name": "get",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "className",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 39,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 39,
                                                "char": 52
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 39,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 39,
                                    "char": 53
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                            "line": 41,
                            "char": 10
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
                                            "value": "reflection",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 41,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 41,
                                        "char": 40
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 41,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 41,
                                    "char": 49
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                "line": 41,
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
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "string",
                                                        "value": "No annotations were found in class ",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                        "line": 43,
                                                        "char": 53
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "className",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                        "line": 44,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 44,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 44,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 44,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 45,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                            "line": 50,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "propertiesAnnotations",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "reflection",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 50,
                                            "char": 48
                                        },
                                        "name": "getPropertiesAnnotations",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 50,
                                        "char": 75
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 50,
                                    "char": 75
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                            "line": 52,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "fcall",
                                        "name": "count",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "propertiesAnnotations",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 52,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 52,
                                                "char": 49
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 52,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 52,
                                    "char": 51
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                "line": 52,
                                "char": 51
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
                                                        "type": "string",
                                                        "value": "No properties with annotations were found in class ",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                        "line": 54,
                                                        "char": 69
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "className",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                        "line": 55,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 55,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 55,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 55,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 56,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                            "line": 58,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "orderedColumnMap",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 58,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 58,
                                    "char": 34
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "reversedColumnMap",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 59,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 59,
                                    "char": 35
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "hasReversedColumn",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 60,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 60,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                            "line": 62,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "propertiesAnnotations",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                "line": 62,
                                "char": 64
                            },
                            "key": "property",
                            "value": "propAnnotations",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "propAnnotations",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 66,
                                                "char": 33
                                            },
                                            "name": "has",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "Column",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                        "line": 66,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 66,
                                                    "char": 44
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 66,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 66,
                                        "char": 46
                                    },
                                    "statements": [
                                        {
                                            "type": "continue",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 68,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 73,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "columnAnnotation",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "propAnnotations",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 73,
                                                    "char": 52
                                                },
                                                "name": "get",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "Column",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 73,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                        "line": 73,
                                                        "char": 63
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 73,
                                                "char": 64
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 73,
                                            "char": 64
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 78,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "columnName",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "columnAnnotation",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 78,
                                                    "char": 47
                                                },
                                                "name": "getNamedParameter",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "column",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 78,
                                                            "char": 72
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                        "line": 78,
                                                        "char": 72
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 78,
                                                "char": 73
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 78,
                                            "char": 73
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 80,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "empty",
                                        "left": {
                                            "type": "variable",
                                            "value": "columnName",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 80,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 80,
                                        "char": 33
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "columnName",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "property",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                        "line": 81,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 81,
                                                    "char": 42
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 82,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 84,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "orderedColumnMap",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "columnName",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 84,
                                                    "char": 44
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "property",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 84,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 84,
                                            "char": 56
                                        },
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "reversedColumnMap",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "property",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 85,
                                                    "char": 43
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "columnName",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 85,
                                                "char": 57
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 85,
                                            "char": 57
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 87,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "not",
                                            "left": {
                                                "type": "variable",
                                                "value": "hasReversedColumn",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 87,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 87,
                                            "char": 36
                                        },
                                        "right": {
                                            "type": "not-equals",
                                            "left": {
                                                "type": "variable",
                                                "value": "columnName",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 87,
                                                "char": 50
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "property",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 87,
                                                "char": 61
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 87,
                                            "char": 61
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 87,
                                        "char": 61
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "hasReversedColumn",
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "true",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                        "line": 88,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 88,
                                                    "char": 45
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 89,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 90,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                            "line": 92,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "hasReversedColumn",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 92,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                "line": 92,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "value": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 93,
                                                    "char": 25
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 93,
                                                "char": 25
                                            },
                                            {
                                                "value": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 93,
                                                    "char": 31
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 93,
                                                "char": 31
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 93,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 94,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                            "line": 99,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "array",
                                "left": [
                                    {
                                        "value": {
                                            "type": "variable",
                                            "value": "orderedColumnMap",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 99,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 99,
                                        "char": 33
                                    },
                                    {
                                        "value": {
                                            "type": "variable",
                                            "value": "reversedColumnMap",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 99,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 99,
                                        "char": 52
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                "line": 99,
                                "char": 53
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                            "line": 100,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Read the model's column map, this can't be inferred\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                "line": 26,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                        "line": 26,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                    "line": 25,
                    "last-line": 104,
                    "char": 25
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "getMetaData",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                "line": 105,
                                "char": 60
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                            "line": 105,
                            "char": 61
                        },
                        {
                            "type": "parameter",
                            "name": "container",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "DiInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                "line": 105,
                                "char": 85
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                            "line": 105,
                            "char": 86
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "annotations",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 107,
                                    "char": 24
                                },
                                {
                                    "variable": "className",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 107,
                                    "char": 35
                                },
                                {
                                    "variable": "reflection",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 107,
                                    "char": 47
                                },
                                {
                                    "variable": "propertiesAnnotations",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 107,
                                    "char": 70
                                },
                                {
                                    "variable": "property",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 107,
                                    "char": 80
                                },
                                {
                                    "variable": "propAnnotations",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 108,
                                    "char": 28
                                },
                                {
                                    "variable": "columnAnnotation",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 108,
                                    "char": 46
                                },
                                {
                                    "variable": "columnName",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 108,
                                    "char": 58
                                },
                                {
                                    "variable": "feature",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 108,
                                    "char": 67
                                },
                                {
                                    "variable": "fieldTypes",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 108,
                                    "char": 79
                                },
                                {
                                    "variable": "fieldBindTypes",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 109,
                                    "char": 27
                                },
                                {
                                    "variable": "numericTyped",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 109,
                                    "char": 41
                                },
                                {
                                    "variable": "primaryKeys",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 109,
                                    "char": 54
                                },
                                {
                                    "variable": "nonPrimaryKeys",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 109,
                                    "char": 70
                                },
                                {
                                    "variable": "identityField",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 110,
                                    "char": 26
                                },
                                {
                                    "variable": "notNull",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 110,
                                    "char": 35
                                },
                                {
                                    "variable": "attributes",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 110,
                                    "char": 47
                                },
                                {
                                    "variable": "defaultValues",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 110,
                                    "char": 62
                                },
                                {
                                    "variable": "defaultValue",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 110,
                                    "char": 76
                                },
                                {
                                    "variable": "emptyStringValues",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 111,
                                    "char": 30
                                },
                                {
                                    "variable": "skipOnInsert",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 111,
                                    "char": 44
                                },
                                {
                                    "variable": "skipOnUpdate",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 111,
                                    "char": 58
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                            "line": 113,
                            "char": 10
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
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 113,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 113,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 113,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 113,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                "line": 113,
                                "char": 48
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
                                                    "value": "The dependency injector is invalid",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 114,
                                                    "char": 67
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 114,
                                                "char": 67
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 114,
                                        "char": 68
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 115,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                            "line": 117,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "container",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 117,
                                            "char": 37
                                        },
                                        "name": "get",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "annotations",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 117,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 117,
                                                "char": 53
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 117,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 117,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                            "line": 119,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "className",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "get_class",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "model",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 119,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 119,
                                                "char": 40
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 119,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 119,
                                    "char": 41
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "reflection",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "annotations",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 120,
                                            "char": 38
                                        },
                                        "name": "get",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "className",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 120,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 120,
                                                "char": 52
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 120,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 120,
                                    "char": 53
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                            "line": 122,
                            "char": 10
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
                                            "value": "reflection",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 122,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 122,
                                        "char": 40
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 122,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 122,
                                    "char": 49
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                "line": 122,
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
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "string",
                                                        "value": "No annotations were found in class ",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                        "line": 124,
                                                        "char": 53
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "className",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                        "line": 125,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 125,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 125,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 125,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 126,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                            "line": 131,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "propertiesAnnotations",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "reflection",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 131,
                                            "char": 48
                                        },
                                        "name": "getPropertiesAnnotations",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 131,
                                        "char": 75
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 131,
                                    "char": 75
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                            "line": 133,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "fcall",
                                        "name": "count",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "propertiesAnnotations",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 133,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 133,
                                                "char": 49
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 133,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 133,
                                    "char": 51
                                },
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                "line": 133,
                                "char": 51
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
                                                        "type": "string",
                                                        "value": "No properties with annotations were found in class ",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                        "line": 135,
                                                        "char": 69
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "className",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                        "line": 136,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 136,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 136,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 136,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 137,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                            "line": 142,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "attributes",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 142,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 142,
                                    "char": 28
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "primaryKeys",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 143,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 143,
                                    "char": 29
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "nonPrimaryKeys",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 144,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 144,
                                    "char": 32
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "numericTyped",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 145,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 145,
                                    "char": 30
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "notNull",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 146,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 146,
                                    "char": 25
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "fieldTypes",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 147,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 147,
                                    "char": 28
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "fieldBindTypes",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 148,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 148,
                                    "char": 32
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "identityField",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 149,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 149,
                                    "char": 34
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "skipOnInsert",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 150,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 150,
                                    "char": 30
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "skipOnUpdate",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 151,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 151,
                                    "char": 30
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "defaultValues",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 152,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 152,
                                    "char": 31
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "emptyStringValues",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 153,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 153,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                            "line": 155,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "propertiesAnnotations",
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                "line": 155,
                                "char": 64
                            },
                            "key": "property",
                            "value": "propAnnotations",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "propAnnotations",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 160,
                                                "char": 33
                                            },
                                            "name": "has",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "Column",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                        "line": 160,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 160,
                                                    "char": 44
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 160,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 160,
                                        "char": 46
                                    },
                                    "statements": [
                                        {
                                            "type": "continue",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 162,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 167,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "columnAnnotation",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "propAnnotations",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 167,
                                                    "char": 52
                                                },
                                                "name": "get",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "Column",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 167,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                        "line": 167,
                                                        "char": 63
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 167,
                                                "char": 64
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 167,
                                            "char": 64
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 172,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "columnName",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "columnAnnotation",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 172,
                                                    "char": 47
                                                },
                                                "name": "getNamedParameter",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "column",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 172,
                                                            "char": 72
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                        "line": 172,
                                                        "char": 72
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 172,
                                                "char": 73
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 172,
                                            "char": 73
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 174,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "empty",
                                        "left": {
                                            "type": "variable",
                                            "value": "columnName",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 174,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 174,
                                        "char": 33
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "columnName",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "property",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                        "line": 175,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 175,
                                                    "char": 42
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 176,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 181,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "feature",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "columnAnnotation",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 181,
                                                    "char": 44
                                                },
                                                "name": "getNamedParameter",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "type",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 181,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                        "line": 181,
                                                        "char": 67
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 181,
                                                "char": 68
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 181,
                                            "char": 68
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 183,
                                    "char": 18
                                },
                                {
                                    "type": "switch",
                                    "expr": {
                                        "type": "variable",
                                        "value": "feature",
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 183,
                                        "char": 28
                                    },
                                    "clauses": [
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "string",
                                                "value": "biginteger",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 184,
                                                "char": 32
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 185,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 185,
                                                                    "char": 73
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_BIGINTEGER",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 185,
                                                                    "char": 73
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 185,
                                                                "char": 73
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 185,
                                                            "char": 73
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldBindTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 186,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 186,
                                                                    "char": 76
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_INT",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 186,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 186,
                                                                "char": 76
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 186,
                                                            "char": 76
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "numericTyped",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 187,
                                                                    "char": 48
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 187,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 187,
                                                            "char": 56
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 188,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 190,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 190,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "string",
                                                "value": "bit",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 190,
                                                "char": 25
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 191,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 191,
                                                                    "char": 66
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_BIT",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 191,
                                                                    "char": 66
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 191,
                                                                "char": 66
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 191,
                                                            "char": 66
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldBindTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 192,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 192,
                                                                    "char": 76
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_INT",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 192,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 192,
                                                                "char": 76
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 192,
                                                            "char": 76
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "numericTyped",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 193,
                                                                    "char": 48
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 193,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 193,
                                                            "char": 56
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 194,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 196,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 196,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "string",
                                                "value": "blob",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 196,
                                                "char": 26
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 197,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 197,
                                                                    "char": 67
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_BLOB",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 197,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 197,
                                                                "char": 67
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 197,
                                                            "char": 67
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldBindTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 198,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 198,
                                                                    "char": 77
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_BLOB",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 198,
                                                                    "char": 77
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 198,
                                                                "char": 77
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 198,
                                                            "char": 77
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 199,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 201,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 201,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "string",
                                                "value": "boolean",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 201,
                                                "char": 29
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 202,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 202,
                                                                    "char": 70
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_BOOLEAN",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 202,
                                                                    "char": 70
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 202,
                                                                "char": 70
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 202,
                                                            "char": 70
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldBindTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 203,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 203,
                                                                    "char": 77
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_BOOL",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 203,
                                                                    "char": 77
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 203,
                                                                "char": 77
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 203,
                                                            "char": 77
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 204,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 206,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 206,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "string",
                                                "value": "char",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 206,
                                                "char": 26
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 207,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 207,
                                                                    "char": 67
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_CHAR",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 207,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 207,
                                                                "char": 67
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 207,
                                                            "char": 67
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldBindTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 208,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 208,
                                                                    "char": 76
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_STR",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 208,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 208,
                                                                "char": 76
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 208,
                                                            "char": 76
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 209,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 211,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 211,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "string",
                                                "value": "date",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 211,
                                                "char": 26
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 212,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 212,
                                                                    "char": 67
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_DATE",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 212,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 212,
                                                                "char": 67
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 212,
                                                            "char": 67
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldBindTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 213,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 213,
                                                                    "char": 76
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_STR",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 213,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 213,
                                                                "char": 76
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 213,
                                                            "char": 76
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 214,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 216,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 216,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "string",
                                                "value": "datetime",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 216,
                                                "char": 30
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 217,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 217,
                                                                    "char": 71
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_DATETIME",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 217,
                                                                    "char": 71
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 217,
                                                                "char": 71
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 217,
                                                            "char": 71
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldBindTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 218,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 218,
                                                                    "char": 76
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_STR",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 218,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 218,
                                                                "char": 76
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 218,
                                                            "char": 76
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 219,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 221,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 221,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "string",
                                                "value": "decimal",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 221,
                                                "char": 29
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 222,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 222,
                                                                    "char": 70
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_DECIMAL",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 222,
                                                                    "char": 70
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 222,
                                                                "char": 70
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 222,
                                                            "char": 70
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldBindTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 223,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 223,
                                                                    "char": 80
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_DECIMAL",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 223,
                                                                    "char": 80
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 223,
                                                                "char": 80
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 223,
                                                            "char": 80
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "numericTyped",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 224,
                                                                    "char": 48
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 224,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 224,
                                                            "char": 56
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 225,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 227,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 227,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "string",
                                                "value": "double",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 227,
                                                "char": 28
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 228,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 228,
                                                                    "char": 69
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_DOUBLE",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 228,
                                                                    "char": 69
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 228,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 228,
                                                            "char": 69
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldBindTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 229,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 229,
                                                                    "char": 80
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_DECIMAL",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 229,
                                                                    "char": 80
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 229,
                                                                "char": 80
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 229,
                                                            "char": 80
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "numericTyped",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 230,
                                                                    "char": 48
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 230,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 230,
                                                            "char": 56
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 231,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 233,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 233,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "string",
                                                "value": "enum",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 233,
                                                "char": 26
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 234,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 234,
                                                                    "char": 67
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_ENUM",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 234,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 234,
                                                                "char": 67
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 234,
                                                            "char": 67
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldBindTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 235,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 235,
                                                                    "char": 76
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_STR",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 235,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 235,
                                                                "char": 76
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 235,
                                                            "char": 76
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "numericTyped",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 236,
                                                                    "char": 48
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 236,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 236,
                                                            "char": 56
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 237,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 239,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 239,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "string",
                                                "value": "float",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 239,
                                                "char": 27
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 240,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 240,
                                                                    "char": 68
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_FLOAT",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 240,
                                                                    "char": 68
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 240,
                                                                "char": 68
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 240,
                                                            "char": 68
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldBindTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 241,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 241,
                                                                    "char": 80
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_DECIMAL",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 241,
                                                                    "char": 80
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 241,
                                                                "char": 80
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 241,
                                                            "char": 80
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "numericTyped",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 242,
                                                                    "char": 48
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 242,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 242,
                                                            "char": 56
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 243,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 245,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 245,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "string",
                                                "value": "integer",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 245,
                                                "char": 29
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 246,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 246,
                                                                    "char": 70
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_INTEGER",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 246,
                                                                    "char": 70
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 246,
                                                                "char": 70
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 246,
                                                            "char": 70
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldBindTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 247,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 247,
                                                                    "char": 76
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_INT",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 247,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 247,
                                                                "char": 76
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 247,
                                                            "char": 76
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "numericTyped",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 248,
                                                                    "char": 48
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 248,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 248,
                                                            "char": 56
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 249,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 251,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 251,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "string",
                                                "value": "json",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 251,
                                                "char": 26
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 252,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 252,
                                                                    "char": 67
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_JSON",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 252,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 252,
                                                                "char": 67
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 252,
                                                            "char": 67
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldBindTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 253,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 253,
                                                                    "char": 76
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_STR",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 253,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 253,
                                                                "char": 76
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 253,
                                                            "char": 76
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 254,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 256,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 256,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "string",
                                                "value": "jsonb",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 256,
                                                "char": 27
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 257,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 257,
                                                                    "char": 68
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_JSONB",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 257,
                                                                    "char": 68
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 257,
                                                                "char": 68
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 257,
                                                            "char": 68
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldBindTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 258,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 258,
                                                                    "char": 76
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_STR",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 258,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 258,
                                                                "char": 76
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 258,
                                                            "char": 76
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 259,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 261,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 261,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "string",
                                                "value": "longblob",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 261,
                                                "char": 30
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 262,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 262,
                                                                    "char": 71
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_LONGBLOB",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 262,
                                                                    "char": 71
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 262,
                                                                "char": 71
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 262,
                                                            "char": 71
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldBindTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 263,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 263,
                                                                    "char": 77
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_BLOB",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 263,
                                                                    "char": 77
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 263,
                                                                "char": 77
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 263,
                                                            "char": 77
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 264,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 266,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 266,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "string",
                                                "value": "longtext",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 266,
                                                "char": 30
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 267,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 267,
                                                                    "char": 71
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_LONGTEXT",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 267,
                                                                    "char": 71
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 267,
                                                                "char": 71
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 267,
                                                            "char": 71
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldBindTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 268,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 268,
                                                                    "char": 76
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_STR",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 268,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 268,
                                                                "char": 76
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 268,
                                                            "char": 76
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 269,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 271,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 271,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "string",
                                                "value": "mediumblob",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 271,
                                                "char": 32
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 272,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 272,
                                                                    "char": 73
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_MEDIUMBLOB",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 272,
                                                                    "char": 73
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 272,
                                                                "char": 73
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 272,
                                                            "char": 73
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldBindTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 273,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 273,
                                                                    "char": 77
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_BLOB",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 273,
                                                                    "char": 77
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 273,
                                                                "char": 77
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 273,
                                                            "char": 77
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 274,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 276,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 276,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "string",
                                                "value": "mediumint",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 276,
                                                "char": 31
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 277,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 277,
                                                                    "char": 76
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_MEDIUMINTEGER",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 277,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 277,
                                                                "char": 76
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 277,
                                                            "char": 76
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldBindTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 278,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 278,
                                                                    "char": 76
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_INT",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 278,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 278,
                                                                "char": 76
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 278,
                                                            "char": 76
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "numericTyped",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 279,
                                                                    "char": 48
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 279,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 279,
                                                            "char": 56
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 280,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 282,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 282,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "string",
                                                "value": "mediumtext",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 282,
                                                "char": 32
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 283,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 283,
                                                                    "char": 73
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_MEDIUMTEXT",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 283,
                                                                    "char": 73
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 283,
                                                                "char": 73
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 283,
                                                            "char": 73
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldBindTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 284,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 284,
                                                                    "char": 76
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_STR",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 284,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 284,
                                                                "char": 76
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 284,
                                                            "char": 76
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 285,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 287,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 287,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "string",
                                                "value": "smallint",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 287,
                                                "char": 30
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 288,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 288,
                                                                    "char": 75
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_SMALLINTEGER",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 288,
                                                                    "char": 75
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 288,
                                                                "char": 75
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 288,
                                                            "char": 75
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldBindTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 289,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 289,
                                                                    "char": 76
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_INT",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 289,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 289,
                                                                "char": 76
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 289,
                                                            "char": 76
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "numericTyped",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 290,
                                                                    "char": 48
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 290,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 290,
                                                            "char": 56
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 291,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 293,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 293,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "string",
                                                "value": "text",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 293,
                                                "char": 26
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 294,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 294,
                                                                    "char": 67
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_TEXT",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 294,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 294,
                                                                "char": 67
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 294,
                                                            "char": 67
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldBindTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 295,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 295,
                                                                    "char": 76
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_STR",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 295,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 295,
                                                                "char": 76
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 295,
                                                            "char": 76
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 296,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 298,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 298,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "string",
                                                "value": "time",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 298,
                                                "char": 26
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 299,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 299,
                                                                    "char": 67
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_TIME",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 299,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 299,
                                                                "char": 67
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 299,
                                                            "char": 67
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldBindTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 300,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 300,
                                                                    "char": 76
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_STR",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 300,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 300,
                                                                "char": 76
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 300,
                                                            "char": 76
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 301,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 303,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 303,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "string",
                                                "value": "timestamp",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 303,
                                                "char": 31
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 304,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 304,
                                                                    "char": 72
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_TIMESTAMP",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 304,
                                                                    "char": 72
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 304,
                                                                "char": 72
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 304,
                                                            "char": 72
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldBindTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 305,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 305,
                                                                    "char": 76
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_STR",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 305,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 305,
                                                                "char": 76
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 305,
                                                            "char": 76
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 306,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 308,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 308,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "string",
                                                "value": "tinyblob",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 308,
                                                "char": 30
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 309,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 309,
                                                                    "char": 71
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_TINYBLOB",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 309,
                                                                    "char": 71
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 309,
                                                                "char": 71
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 309,
                                                            "char": 71
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldBindTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 310,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 310,
                                                                    "char": 77
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_BLOB",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 310,
                                                                    "char": 77
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 310,
                                                                "char": 77
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 310,
                                                            "char": 77
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 311,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 313,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 313,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "string",
                                                "value": "tinyint",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 313,
                                                "char": 29
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 314,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 314,
                                                                    "char": 74
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_TINYINTEGER",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 314,
                                                                    "char": 74
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 314,
                                                                "char": 74
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 314,
                                                            "char": 74
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldBindTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 315,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 315,
                                                                    "char": 76
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_INT",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 315,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 315,
                                                                "char": 76
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 315,
                                                            "char": 76
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "numericTyped",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 316,
                                                                    "char": 48
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 316,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 316,
                                                            "char": 56
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 317,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 319,
                                                    "char": 20
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 319,
                                            "char": 20
                                        },
                                        {
                                            "type": "case",
                                            "expr": {
                                                "type": "string",
                                                "value": "tinytext",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 319,
                                                "char": 30
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 320,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 320,
                                                                    "char": 71
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_TINYTEXT",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 320,
                                                                    "char": 71
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 320,
                                                                "char": 71
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 320,
                                                            "char": 71
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldBindTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 321,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 321,
                                                                    "char": 76
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_STR",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 321,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 321,
                                                                "char": 76
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 321,
                                                            "char": 76
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 322,
                                                    "char": 25
                                                },
                                                {
                                                    "type": "break",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 324,
                                                    "char": 23
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 324,
                                            "char": 23
                                        },
                                        {
                                            "type": "default",
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 328,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 328,
                                                                    "char": 70
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "TYPE_VARCHAR",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 328,
                                                                    "char": 70
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 328,
                                                                "char": 70
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 328,
                                                            "char": 70
                                                        },
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "fieldBindTypes",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "columnName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 329,
                                                                    "char": 50
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Column",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 329,
                                                                    "char": 76
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "BIND_PARAM_STR",
                                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                    "line": 329,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                                "line": 329,
                                                                "char": 76
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 329,
                                                            "char": 76
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 330,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 330,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 336,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "propAnnotations",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 336,
                                            "char": 32
                                        },
                                        "name": "has",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "Primary",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 336,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 336,
                                                "char": 44
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 336,
                                        "char": 46
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "primaryKeys",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "columnName",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                        "line": 337,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 337,
                                                    "char": 47
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 338,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "nonPrimaryKeys",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "columnName",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                        "line": 339,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 339,
                                                    "char": 50
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 340,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 346,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "propAnnotations",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 346,
                                            "char": 32
                                        },
                                        "name": "has",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "Identity",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 346,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 346,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 346,
                                        "char": 47
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "identityField",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "columnName",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                        "line": 347,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 347,
                                                    "char": 47
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 348,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 353,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "columnAnnotation",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 353,
                                            "char": 33
                                        },
                                        "name": "getNamedParameter",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "skip_on_insert",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 353,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 353,
                                                "char": 66
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 353,
                                        "char": 68
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "skipOnInsert",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "columnName",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                        "line": 354,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 354,
                                                    "char": 48
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 355,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 360,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "columnAnnotation",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 360,
                                            "char": 33
                                        },
                                        "name": "getNamedParameter",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "skip_on_update",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 360,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 360,
                                                "char": 66
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 360,
                                        "char": 68
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "skipOnUpdate",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "columnName",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                        "line": 361,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 361,
                                                    "char": 48
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 362,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 367,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "columnAnnotation",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 367,
                                            "char": 33
                                        },
                                        "name": "getNamedParameter",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "allow_empty_string",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 367,
                                                    "char": 70
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 367,
                                                "char": 70
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 367,
                                        "char": 72
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "emptyStringValues",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "columnName",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                        "line": 368,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 368,
                                                    "char": 53
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 369,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 374,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "columnAnnotation",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 374,
                                                "char": 34
                                            },
                                            "name": "getNamedParameter",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "nullable",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                        "line": 374,
                                                        "char": 61
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 374,
                                                    "char": 61
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 374,
                                            "char": 63
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 374,
                                        "char": 63
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-append",
                                                    "operator": "assign",
                                                    "variable": "notNull",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "columnName",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                        "line": 375,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 375,
                                                    "char": 43
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 376,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 382,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "defaultValue",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "columnAnnotation",
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 382,
                                                    "char": 49
                                                },
                                                "name": "getNamedParameter",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "default",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 382,
                                                            "char": 75
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                        "line": 382,
                                                        "char": 75
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 382,
                                                "char": 76
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 382,
                                            "char": 76
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 383,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "or",
                                        "left": {
                                            "type": "not-identical",
                                            "left": {
                                                "type": "variable",
                                                "value": "defaultValue",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 383,
                                                "char": 31
                                            },
                                            "right": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 383,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 383,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "columnAnnotation",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 383,
                                                "char": 58
                                            },
                                            "name": "getNamedParameter",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "nullable",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                        "line": 383,
                                                        "char": 85
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 383,
                                                    "char": 85
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 383,
                                            "char": 87
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 383,
                                        "char": 87
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "defaultValues",
                                                    "index-expr": [
                                                        {
                                                            "type": "variable",
                                                            "value": "columnName",
                                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                            "line": 384,
                                                            "char": 45
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "defaultValue",
                                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                        "line": 384,
                                                        "char": 61
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                    "line": 384,
                                                    "char": 61
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 385,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 387,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "attributes",
                                            "expr": {
                                                "type": "variable",
                                                "value": "columnName",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 387,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 387,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                    "line": 388,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                            "line": 393,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "array",
                                "left": [
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "MetaData",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 394,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "MODELS_ATTRIBUTES",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 394,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 394,
                                            "char": 55
                                        },
                                        "value": {
                                            "type": "variable",
                                            "value": "attributes",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 394,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 394,
                                        "char": 67
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "MetaData",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 395,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "MODELS_PRIMARY_KEY",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 395,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 395,
                                            "char": 55
                                        },
                                        "value": {
                                            "type": "variable",
                                            "value": "primaryKeys",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 395,
                                            "char": 68
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 395,
                                        "char": 68
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "MetaData",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 396,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "MODELS_NON_PRIMARY_KEY",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 396,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 396,
                                            "char": 55
                                        },
                                        "value": {
                                            "type": "variable",
                                            "value": "nonPrimaryKeys",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 396,
                                            "char": 71
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 396,
                                        "char": 71
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "MetaData",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 397,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "MODELS_NOT_NULL",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 397,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 397,
                                            "char": 55
                                        },
                                        "value": {
                                            "type": "variable",
                                            "value": "notNull",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 397,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 397,
                                        "char": 64
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "MetaData",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 398,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "MODELS_DATA_TYPES",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 398,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 398,
                                            "char": 55
                                        },
                                        "value": {
                                            "type": "variable",
                                            "value": "fieldTypes",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 398,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 398,
                                        "char": 67
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "MetaData",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 399,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "MODELS_DATA_TYPES_NUMERIC",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 399,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 399,
                                            "char": 55
                                        },
                                        "value": {
                                            "type": "variable",
                                            "value": "numericTyped",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 399,
                                            "char": 69
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 399,
                                        "char": 69
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "MetaData",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 400,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "MODELS_IDENTITY_COLUMN",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 400,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 400,
                                            "char": 55
                                        },
                                        "value": {
                                            "type": "variable",
                                            "value": "identityField",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 400,
                                            "char": 70
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 400,
                                        "char": 70
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "MetaData",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 401,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "MODELS_DATA_TYPES_BIND",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 401,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 401,
                                            "char": 55
                                        },
                                        "value": {
                                            "type": "variable",
                                            "value": "fieldBindTypes",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 401,
                                            "char": 71
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 401,
                                        "char": 71
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "MetaData",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 402,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "MODELS_AUTOMATIC_DEFAULT_INSERT",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 402,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 402,
                                            "char": 55
                                        },
                                        "value": {
                                            "type": "variable",
                                            "value": "skipOnInsert",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 402,
                                            "char": 69
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 402,
                                        "char": 69
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "MetaData",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 403,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "MODELS_AUTOMATIC_DEFAULT_UPDATE",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 403,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 403,
                                            "char": 55
                                        },
                                        "value": {
                                            "type": "variable",
                                            "value": "skipOnUpdate",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 403,
                                            "char": 69
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 403,
                                        "char": 69
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "MetaData",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 404,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "MODELS_DEFAULT_VALUES",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 404,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 404,
                                            "char": 55
                                        },
                                        "value": {
                                            "type": "variable",
                                            "value": "defaultValues",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 404,
                                            "char": 70
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 404,
                                        "char": 70
                                    },
                                    {
                                        "key": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "MetaData",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 405,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "MODELS_EMPTY_STRING_VALUES",
                                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                                "line": 405,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 405,
                                            "char": 55
                                        },
                                        "value": {
                                            "type": "variable",
                                            "value": "emptyStringValues",
                                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                            "line": 406,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                        "line": 406,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                "line": 406,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                            "line": 407,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * The meta-data is obtained by reading the column descriptions from the database information schema\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                                "line": 106,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                        "line": 106,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
                    "line": 105,
                    "last-line": 408,
                    "char": 25
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
            "line": 20,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/MetaData\/Strategy\/Annotations.zep",
        "line": 20,
        "char": 5
    }
]