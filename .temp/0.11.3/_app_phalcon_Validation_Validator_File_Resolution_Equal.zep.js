[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Validation\\Validator\\File\\Resolution",
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\Message",
                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                "line": 13,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validation",
                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                "line": 14,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validator\\File\\AbstractFile",
                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                "line": 15,
                "char": 51
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
        "line": 55,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Checks if a file has the rigth resolution\n *\n * ```php\n * use Phalcon\\Validation\\Validation;\n * use Phalcon\\Validation\\Validator\\File\\Resolution\\Equal;\n *\n * $validator = new Validation();\n *\n * $validator->add(\n *     \"file\",\n *     new Equal(\n *         [\n *             \"resolution\" => \"800x600\",\n *             \"message\"    => \"The resolution of the field :field has to be equal :resolution\",\n *         ]\n *     )\n * );\n *\n * $validator->add(\n *     [\n *         \"file\",\n *         \"anotherFile\",\n *     ],\n *     new Equal(\n *         [\n *             \"resolution\" => [\n *                 \"file\"        => \"800x600\",\n *                 \"anotherFile\" => \"1024x768\",\n *             ],\n *             \"message\" => [\n *                 \"file\"        => \"Equal resolution of file has to be 800x600\",\n *                 \"anotherFile\" => \"Equal resolution of file has to be 1024x768\",\n *             ],\n *         ]\n *     )\n * );\n * ```\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
        "line": 56,
        "char": 5
    },
    {
        "type": "class",
        "name": "Equal",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractFile",
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "template",
                    "default": {
                        "type": "string",
                        "value": "The resolution of the field :field has to be equal :resolution",
                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                        "line": 58,
                        "char": 88
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                    "line": 62,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "validate",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "validation",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Validation",
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                "line": 63,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                            "line": 63,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                            "line": 63,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "height",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 65,
                                    "char": 19
                                },
                                {
                                    "variable": "equalHeight",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 65,
                                    "char": 32
                                },
                                {
                                    "variable": "equalWidth",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 65,
                                    "char": 44
                                },
                                {
                                    "variable": "resolution",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 65,
                                    "char": 56
                                },
                                {
                                    "variable": "resolutionArray",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 65,
                                    "char": 73
                                },
                                {
                                    "variable": "tmp",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 66,
                                    "char": 16
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 66,
                                    "char": 23
                                },
                                {
                                    "variable": "width",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 66,
                                    "char": 30
                                },
                                {
                                    "variable": "replacePairs",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 66,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                            "line": 69,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                        "line": 69,
                                        "char": 17
                                    },
                                    "name": "checkUpload",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "validation",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                "line": 69,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                            "line": 69,
                                            "char": 40
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "field",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                "line": 69,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                            "line": 69,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 69,
                                    "char": 51
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 69,
                                    "char": 59
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                "line": 69,
                                "char": 59
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                        "line": 70,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 71,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                            "line": 73,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "value",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "validation",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                            "line": 73,
                                            "char": 33
                                        },
                                        "name": "getValue",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                    "line": 73,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                "line": 73,
                                                "char": 48
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                        "line": 73,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 73,
                                    "char": 49
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "tmp",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "getimagesize",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                        "line": 74,
                                                        "char": 40
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "tmp_name",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                        "line": 74,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                    "line": 74,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                "line": 74,
                                                "char": 50
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                        "line": 74,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 74,
                                    "char": 51
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "width",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "tmp",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                            "line": 75,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                            "line": 75,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                        "line": 75,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 75,
                                    "char": 28
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "height",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "tmp",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                            "line": 76,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "1",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                            "line": 76,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                        "line": 76,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 76,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                            "line": 78,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "resolution",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                            "line": 78,
                                            "char": 31
                                        },
                                        "name": "getOption",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "resolution",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                    "line": 78,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                "line": 78,
                                                "char": 52
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                        "line": 78,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 78,
                                    "char": 53
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                            "line": 80,
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
                                        "value": "resolution",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                        "line": 80,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 80,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 80,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                "line": 80,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "resolution",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "resolution",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                    "line": 81,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                    "line": 81,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                "line": 81,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                            "line": 81,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 82,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                            "line": 84,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "resolutionArray",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "explode",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "x",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                    "line": 84,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                "line": 84,
                                                "char": 40
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "resolution",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                    "line": 84,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                "line": 84,
                                                "char": 52
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                        "line": 84,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 84,
                                    "char": 53
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "equalWidth",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "resolutionArray",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                            "line": 85,
                                            "char": 41
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                            "line": 85,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                        "line": 85,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 85,
                                    "char": 44
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "equalHeight",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "resolutionArray",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                            "line": 86,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "1",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                            "line": 86,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                        "line": 86,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 86,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                            "line": 88,
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
                                        "value": "resolution",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                        "line": 88,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 88,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 88,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                "line": 88,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "resolution",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "resolution",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                    "line": 89,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                    "line": 89,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                "line": 89,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                            "line": 89,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 90,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                            "line": 92,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "variable",
                                        "value": "width",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                        "line": 92,
                                        "char": 19
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "equalWidth",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                        "line": 92,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 92,
                                    "char": 33
                                },
                                "right": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "variable",
                                        "value": "height",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                        "line": 92,
                                        "char": 43
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "equalHeight",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                        "line": 92,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 92,
                                    "char": 57
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                "line": 92,
                                "char": 57
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "replacePairs",
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": ":resolution",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                            "line": 94,
                                                            "char": 29
                                                        },
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "resolution",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                            "line": 95,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                        "line": 95,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                "line": 95,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                            "line": 95,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 97,
                                    "char": 22
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "validation",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                            "line": 97,
                                            "char": 24
                                        },
                                        "name": "appendMessage",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                        "line": 98,
                                                        "char": 22
                                                    },
                                                    "name": "messageFactory",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "validation",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                                "line": 98,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                            "line": 98,
                                                            "char": 48
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "field",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                                "line": 98,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                            "line": 98,
                                                            "char": 55
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "replacePairs",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                                "line": 98,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                            "line": 98,
                                                            "char": 69
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                    "line": 99,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                                "line": 99,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                        "line": 99,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 101,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                        "line": 101,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                    "line": 102,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                            "line": 104,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                "line": 104,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                            "line": 105,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Executes the validation\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                                "line": 64,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                        "line": 64,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
                    "line": 63,
                    "last-line": 106,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
            "line": 56,
            "char": 5
        },
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Equal.zep",
        "line": 56,
        "char": 5
    }
]