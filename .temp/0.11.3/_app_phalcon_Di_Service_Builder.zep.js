[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Di\\Service",
        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                "line": 13,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\Exception",
                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                "line": 14,
                "char": 25
            }
        ],
        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
        "line": 20,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Di\\Service\\Builder\n *\n * This class builds instances based on complex definitions\n *",
        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
        "line": 21,
        "char": 5
    },
    {
        "type": "class",
        "name": "Builder",
        "abstract": 0,
        "final": 0,
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "build",
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
                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                "line": 29,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                            "line": 29,
                            "char": 50
                        },
                        {
                            "type": "parameter",
                            "name": "definition",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                            "line": 29,
                            "char": 69
                        },
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                "line": 29,
                                "char": 88
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                            "line": 29,
                            "char": 88
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "className",
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 31,
                                    "char": 22
                                },
                                {
                                    "variable": "arguments",
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 31,
                                    "char": 33
                                },
                                {
                                    "variable": "paramCalls",
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 31,
                                    "char": 45
                                },
                                {
                                    "variable": "methodPosition",
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 31,
                                    "char": 61
                                },
                                {
                                    "variable": "method",
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 31,
                                    "char": 69
                                },
                                {
                                    "variable": "methodName",
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 32,
                                    "char": 23
                                },
                                {
                                    "variable": "methodCall",
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 32,
                                    "char": 35
                                },
                                {
                                    "variable": "instance",
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 32,
                                    "char": 45
                                },
                                {
                                    "variable": "propertyPosition",
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 32,
                                    "char": 63
                                },
                                {
                                    "variable": "property",
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 32,
                                    "char": 73
                                },
                                {
                                    "variable": "propertyName",
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 33,
                                    "char": 25
                                },
                                {
                                    "variable": "propertyValue",
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 33,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                            "line": 38,
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
                                            "value": "className",
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 38,
                                            "char": 61
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "definition",
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 38,
                                                "char": 49
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "className",
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 38,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 38,
                                            "char": 61
                                        },
                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                        "line": 38,
                                        "char": 61
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 38,
                                    "char": 61
                                },
                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                "line": 38,
                                "char": 61
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
                                                    "value": "Invalid service definition. Missing 'className' parameter",
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 41,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 41,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                        "line": 41,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 42,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                            "line": 44,
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
                                        "value": "parameters",
                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                        "line": 44,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 44,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 44,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                "line": 44,
                                "char": 39
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
                                                    "value": "parameters",
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 50,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 50,
                                                "char": 32
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                        "line": 50,
                                        "char": 34
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "instance",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "create_instance_params",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "className",
                                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                    "line": 51,
                                                                    "char": 64
                                                                },
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 51,
                                                                "char": 64
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "parameters",
                                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                    "line": 51,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 51,
                                                                "char": 76
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 51,
                                                        "char": 77
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 51,
                                                    "char": 77
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 52,
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
                                                    "variable": "instance",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "create_instance",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "className",
                                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                    "line": 53,
                                                                    "char": 57
                                                                },
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 53,
                                                                "char": 57
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 53,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 53,
                                                    "char": 58
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 54,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 56,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "arguments",
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 61,
                                            "char": 55
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "definition",
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 61,
                                                "char": 43
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "arguments",
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 61,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 61,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                        "line": 61,
                                        "char": 55
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "instance",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "create_instance_params",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "className",
                                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                    "line": 67,
                                                                    "char": 30
                                                                },
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 67,
                                                                "char": 30
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                        "line": 68,
                                                                        "char": 26
                                                                    },
                                                                    "name": "buildParameters",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "container",
                                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                                "line": 68,
                                                                                "char": 52
                                                                            },
                                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                            "line": 68,
                                                                            "char": 52
                                                                        },
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "arguments",
                                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                                "line": 68,
                                                                                "char": 63
                                                                            },
                                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                            "line": 68,
                                                                            "char": 63
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                    "line": 69,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 69,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 69,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 69,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 71,
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
                                                    "variable": "instance",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "create_instance",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "className",
                                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                    "line": 72,
                                                                    "char": 57
                                                                },
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 72,
                                                                "char": 57
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 72,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 72,
                                                    "char": 58
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 73,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 74,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                            "line": 79,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "paramCalls",
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 79,
                                    "char": 48
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                        "line": 79,
                                        "char": 40
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "calls",
                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                        "line": 79,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 79,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                "line": 79,
                                "char": 48
                            },
                            "statements": [
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
                                                    "value": "instance",
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 80,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 80,
                                                "char": 42
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 80,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 80,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                        "line": 80,
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
                                                            "type": "string",
                                                            "value": "The definition has setter injection parameters but the constructor didn't return an instance",
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 83,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 83,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 83,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 84,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 86,
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
                                                    "value": "paramCalls",
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 86,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 86,
                                                "char": 44
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "array",
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 86,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 86,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                        "line": 86,
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
                                                            "type": "string",
                                                            "value": "Setter injection parameters must be an array",
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 89,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 89,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 89,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 90,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 95,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "paramCalls",
                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                        "line": 95,
                                        "char": 54
                                    },
                                    "key": "methodPosition",
                                    "value": "method",
                                    "reverse": 0,
                                    "statements": [
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
                                                            "value": "method",
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 100,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 100,
                                                        "char": 44
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "array",
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 100,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 100,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 100,
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
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "string",
                                                                        "value": "Method call must be an array on position ",
                                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                        "line": 102,
                                                                        "char": 67
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "methodPosition",
                                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                        "line": 103,
                                                                        "char": 21
                                                                    },
                                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                    "line": 103,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 103,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 103,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 104,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 109,
                                            "char": 18
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
                                                            "value": "methodName",
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 109,
                                                            "char": 63
                                                        },
                                                        "right": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "method",
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 109,
                                                                "char": 54
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "method",
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 109,
                                                                "char": 61
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 109,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 109,
                                                        "char": 63
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 109,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 109,
                                                "char": 63
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
                                                                        "value": "The method name is required on position ",
                                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                        "line": 111,
                                                                        "char": 66
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "methodPosition",
                                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                        "line": 112,
                                                                        "char": 21
                                                                    },
                                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                    "line": 112,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 112,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 112,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 113,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 118,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "methodCall",
                                                    "expr": {
                                                        "type": "array",
                                                        "left": [
                                                            {
                                                                "value": {
                                                                    "type": "variable",
                                                                    "value": "instance",
                                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                    "line": 118,
                                                                    "char": 43
                                                                },
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 118,
                                                                "char": 43
                                                            },
                                                            {
                                                                "value": {
                                                                    "type": "variable",
                                                                    "value": "methodName",
                                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                    "line": 118,
                                                                    "char": 55
                                                                },
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 118,
                                                                "char": 55
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 118,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 118,
                                                    "char": 56
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 120,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "fetch",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "arguments",
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 120,
                                                    "char": 55
                                                },
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "method",
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 120,
                                                        "char": 43
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "arguments",
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 120,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 120,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 120,
                                                "char": 55
                                            },
                                            "statements": [
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
                                                                    "value": "arguments",
                                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                    "line": 121,
                                                                    "char": 51
                                                                },
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 121,
                                                                "char": 51
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "array",
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 121,
                                                                "char": 59
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 121,
                                                            "char": 59
                                                        },
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 121,
                                                        "char": 59
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
                                                                                "value": "Call arguments must be an array ",
                                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                                "line": 123,
                                                                                "char": 62
                                                                            },
                                                                            "right": {
                                                                                "type": "variable",
                                                                                "value": "methodPosition",
                                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                                "line": 124,
                                                                                "char": 25
                                                                            },
                                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                            "line": 124,
                                                                            "char": 25
                                                                        },
                                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                        "line": 124,
                                                                        "char": 25
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 124,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 125,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 127,
                                                    "char": 22
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
                                                                    "value": "arguments",
                                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                    "line": 127,
                                                                    "char": 39
                                                                },
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 127,
                                                                "char": 39
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 127,
                                                        "char": 41
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "fcall",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "call_user_func_array",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "methodCall",
                                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                            "line": 132,
                                                                            "char": 39
                                                                        },
                                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                        "line": 132,
                                                                        "char": 39
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "mcall",
                                                                            "variable": {
                                                                                "type": "variable",
                                                                                "value": "this",
                                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                                "line": 133,
                                                                                "char": 34
                                                                            },
                                                                            "name": "buildParameters",
                                                                            "call-type": 1,
                                                                            "parameters": [
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "variable",
                                                                                        "value": "container",
                                                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                                        "line": 133,
                                                                                        "char": 60
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                                    "line": 133,
                                                                                    "char": 60
                                                                                },
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "variable",
                                                                                        "value": "arguments",
                                                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                                        "line": 133,
                                                                                        "char": 71
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                                    "line": 133,
                                                                                    "char": 71
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                            "line": 134,
                                                                            "char": 25
                                                                        },
                                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                        "line": 134,
                                                                        "char": 25
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 134,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 139,
                                                            "char": 32
                                                        },
                                                        {
                                                            "type": "continue",
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 140,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 141,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 146,
                                            "char": 30
                                        },
                                        {
                                            "type": "fcall",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "call_user_func",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "methodCall",
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 146,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 146,
                                                        "char": 42
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 146,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 147,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 148,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                            "line": 153,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "paramCalls",
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 153,
                                    "char": 53
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "definition",
                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                        "line": 153,
                                        "char": 40
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "properties",
                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                        "line": 153,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 153,
                                    "char": 53
                                },
                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                "line": 153,
                                "char": 53
                            },
                            "statements": [
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
                                                    "value": "instance",
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 155,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 155,
                                                "char": 42
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 155,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 155,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                        "line": 155,
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
                                                            "type": "string",
                                                            "value": "The definition has properties injection parameters but the constructor didn't return an instance",
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 158,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 158,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 158,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 159,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 161,
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
                                                    "value": "paramCalls",
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 161,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 161,
                                                "char": 44
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "array",
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 161,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 161,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                        "line": 161,
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
                                                            "type": "string",
                                                            "value": "Setter injection parameters must be an array",
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 164,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 164,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 164,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 165,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 170,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "paramCalls",
                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                        "line": 170,
                                        "char": 58
                                    },
                                    "key": "propertyPosition",
                                    "value": "property",
                                    "reverse": 0,
                                    "statements": [
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
                                                            "value": "property",
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 175,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 175,
                                                        "char": 46
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "array",
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 175,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 175,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 175,
                                                "char": 54
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
                                                                        "value": "Property must be an array on position ",
                                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                        "line": 177,
                                                                        "char": 64
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "propertyPosition",
                                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                        "line": 178,
                                                                        "char": 21
                                                                    },
                                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                    "line": 178,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 178,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 178,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 179,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 184,
                                            "char": 18
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
                                                            "value": "propertyName",
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 184,
                                                            "char": 65
                                                        },
                                                        "right": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "property",
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 184,
                                                                "char": 58
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "name",
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 184,
                                                                "char": 63
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 184,
                                                            "char": 65
                                                        },
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 184,
                                                        "char": 65
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 184,
                                                    "char": 65
                                                },
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 184,
                                                "char": 65
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
                                                                        "value": "The property name is required on position ",
                                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                        "line": 186,
                                                                        "char": 68
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "propertyPosition",
                                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                        "line": 187,
                                                                        "char": 21
                                                                    },
                                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                    "line": 187,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 187,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 187,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 188,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 193,
                                            "char": 18
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
                                                            "value": "propertyValue",
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 193,
                                                            "char": 67
                                                        },
                                                        "right": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "property",
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 193,
                                                                "char": 59
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "value",
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 193,
                                                                "char": 65
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 193,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 193,
                                                        "char": 67
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 193,
                                                    "char": 67
                                                },
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 193,
                                                "char": 67
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
                                                                        "value": "The property value is required on position ",
                                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                        "line": 195,
                                                                        "char": 69
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "propertyPosition",
                                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                        "line": 196,
                                                                        "char": 21
                                                                    },
                                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                    "line": 196,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 196,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 196,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 197,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 202,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-dynamic-object-property",
                                                    "operator": "assign",
                                                    "variable": "instance",
                                                    "property": "propertyName",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 202,
                                                            "char": 53
                                                        },
                                                        "name": "buildParameter",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "container",
                                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                    "line": 203,
                                                                    "char": 30
                                                                },
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 203,
                                                                "char": 30
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "propertyPosition",
                                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                    "line": 204,
                                                                    "char": 37
                                                                },
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 204,
                                                                "char": 37
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "propertyValue",
                                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                    "line": 206,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 206,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 206,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 206,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 207,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 208,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                            "line": 210,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "instance",
                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                "line": 210,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                            "line": 211,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Builds a service using a complex service definition\n     *\n     * @param array parameters\n     * @return mixed\n     *",
                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                    "line": 29,
                    "last-line": 217,
                    "char": 19
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "buildParameter",
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
                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                "line": 218,
                                "char": 59
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                            "line": 218,
                            "char": 60
                        },
                        {
                            "type": "parameter",
                            "name": "position",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                            "line": 218,
                            "char": 74
                        },
                        {
                            "type": "parameter",
                            "name": "argument",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                            "line": 218,
                            "char": 91
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "type",
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 220,
                                    "char": 17
                                },
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 220,
                                    "char": 23
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 220,
                                    "char": 30
                                },
                                {
                                    "variable": "instanceArguments",
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 220,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                            "line": 225,
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
                                            "value": "type",
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 225,
                                            "char": 49
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "argument",
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 225,
                                                "char": 42
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "type",
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 225,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 225,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                        "line": 225,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 225,
                                    "char": 49
                                },
                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                "line": 225,
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
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "string",
                                                            "value": "Argument at position ",
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 227,
                                                            "char": 39
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "position",
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 227,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 227,
                                                        "char": 50
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": " must have a type",
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 228,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 228,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 228,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                        "line": 228,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 229,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                            "line": 231,
                            "char": 14
                        },
                        {
                            "type": "switch",
                            "expr": {
                                "type": "variable",
                                "value": "type",
                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                "line": 231,
                                "char": 21
                            },
                            "clauses": [
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "service",
                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                        "line": 237,
                                        "char": 25
                                    },
                                    "statements": [
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
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 238,
                                                            "char": 57
                                                        },
                                                        "right": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "argument",
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 238,
                                                                "char": 50
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "name",
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 238,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 238,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 238,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 238,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 238,
                                                "char": 57
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
                                                                        "value": "Service 'name' is required in parameter on position ",
                                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                        "line": 240,
                                                                        "char": 78
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "position",
                                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                        "line": 241,
                                                                        "char": 21
                                                                    },
                                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                    "line": 241,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 241,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 241,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 242,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 244,
                                            "char": 18
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
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 244,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 244,
                                                        "char": 47
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "object",
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 244,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 244,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 244,
                                                "char": 56
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
                                                                    "value": "The dependency injector container is not valid",
                                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                    "line": 247,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 247,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 247,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 248,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 250,
                                            "char": 22
                                        },
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 250,
                                                    "char": 34
                                                },
                                                "name": "get",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 250,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 250,
                                                        "char": 43
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 250,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 255,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 255,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "parameter",
                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                        "line": 255,
                                        "char": 27
                                    },
                                    "statements": [
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
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 256,
                                                            "char": 59
                                                        },
                                                        "right": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "argument",
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 256,
                                                                "char": 51
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "value",
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 256,
                                                                "char": 57
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 256,
                                                            "char": 59
                                                        },
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 256,
                                                        "char": 59
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 256,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 256,
                                                "char": 59
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
                                                                        "value": "Service 'value' is required in parameter on position ",
                                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                        "line": 258,
                                                                        "char": 79
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "position",
                                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                        "line": 259,
                                                                        "char": 21
                                                                    },
                                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                    "line": 259,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 259,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 259,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 260,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 262,
                                            "char": 22
                                        },
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 262,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 267,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 267,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "instance",
                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                        "line": 267,
                                        "char": 26
                                    },
                                    "statements": [
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
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 269,
                                                            "char": 62
                                                        },
                                                        "right": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "argument",
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 269,
                                                                "char": 50
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "className",
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 269,
                                                                "char": 60
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 269,
                                                            "char": 62
                                                        },
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 269,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 269,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 269,
                                                "char": 62
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
                                                                        "value": "Service 'className' is required in parameter on position ",
                                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                        "line": 271,
                                                                        "char": 83
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "position",
                                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                        "line": 272,
                                                                        "char": 21
                                                                    },
                                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                    "line": 272,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 272,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 272,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 273,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 275,
                                            "char": 18
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
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 275,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 275,
                                                        "char": 47
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "object",
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 275,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 275,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 275,
                                                "char": 56
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
                                                                    "value": "The dependency injector container is not valid",
                                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                    "line": 278,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 278,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 278,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 279,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 281,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "fetch",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "instanceArguments",
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 281,
                                                    "char": 65
                                                },
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "argument",
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 281,
                                                        "char": 53
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "arguments",
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 281,
                                                        "char": 63
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 281,
                                                    "char": 65
                                                },
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 281,
                                                "char": 65
                                            },
                                            "statements": [
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "container",
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 285,
                                                            "char": 38
                                                        },
                                                        "name": "get",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "name",
                                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                    "line": 285,
                                                                    "char": 47
                                                                },
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 285,
                                                                "char": 47
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "instanceArguments",
                                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                    "line": 285,
                                                                    "char": 66
                                                                },
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 285,
                                                                "char": 66
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 285,
                                                        "char": 67
                                                    },
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 286,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 292,
                                            "char": 22
                                        },
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 292,
                                                    "char": 34
                                                },
                                                "name": "get",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 292,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 292,
                                                        "char": 43
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 292,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 294,
                                            "char": 19
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 294,
                                    "char": 19
                                },
                                {
                                    "type": "default",
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
                                                                "value": "Unknown service type in parameter on position ",
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 299,
                                                                "char": 68
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "position",
                                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                                "line": 300,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 300,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 300,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 300,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 301,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 301,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                            "line": 302,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resolves a constructor\/call parameter\n     *\n     * @return mixed\n     *",
                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                    "line": 218,
                    "last-line": 306,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "buildParameters",
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
                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                "line": 307,
                                "char": 60
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                            "line": 307,
                            "char": 61
                        },
                        {
                            "type": "parameter",
                            "name": "arguments",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                            "line": 307,
                            "char": 79
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "position",
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 309,
                                    "char": 21
                                },
                                {
                                    "variable": "argument",
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 309,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                            "line": 310,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "buildArguments",
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 310,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                            "line": 312,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "buildArguments",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                        "line": 312,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 312,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                            "line": 314,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "arguments",
                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                "line": 314,
                                "char": 45
                            },
                            "key": "position",
                            "value": "argument",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "buildArguments",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                    "line": 315,
                                                    "char": 41
                                                },
                                                "name": "buildParameter",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "container",
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 316,
                                                            "char": 26
                                                        },
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 316,
                                                        "char": 26
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "position",
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 317,
                                                            "char": 25
                                                        },
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 317,
                                                        "char": 25
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "argument",
                                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                            "line": 319,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                        "line": 319,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                                "line": 319,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                            "line": 319,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                    "line": 320,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                            "line": 322,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "buildArguments",
                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                "line": 322,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                            "line": 323,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Resolves an array of parameters\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                                "line": 308,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                        "line": 308,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
                    "line": 307,
                    "last-line": 324,
                    "char": 20
                }
            ],
            "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
            "line": 21,
            "char": 5
        },
        "file": "\/app\/phalcon\/Di\/Service\/Builder.zep",
        "line": 21,
        "char": 5
    }
]