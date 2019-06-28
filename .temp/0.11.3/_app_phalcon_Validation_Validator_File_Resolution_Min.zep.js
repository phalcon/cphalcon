[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Validation\\Validator\\File\\Resolution",
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\Message",
                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                "line": 13,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validation",
                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                "line": 14,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validator\\File\\AbstractFile",
                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                "line": 15,
                "char": 51
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
        "line": 60,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Checks if a file has the rigth resolution\n *\n * ```php\n * use Phalcon\\Validation\\Validation;\n * use Phalcon\\Validation\\Validator\\File\\Resolution\\Min;\n *\n * $validator = new Validation();\n *\n * $validator->add(\n *     \"file\",\n *     new Min(\n *         [\n *             \"resolution\" => \"800x600\",\n *             \"message\"    => \"Min resolution of :field is :resolution\",\n *             \"included\"   => true,\n *         ]\n *     )\n * );\n *\n * $validator->add(\n *     [\n *         \"file\",\n *         \"anotherFile\",\n *     ],\n *     new Min(\n *         [\n *             \"resolution\" => [\n *                 \"file\"        => \"800x600\",\n *                 \"anotherFile\" => \"1024x768\",\n *             ],\n *             \"included\" => [\n *                 \"file\"        => false,\n *                 \"anotherFile\" => true,\n *             ],\n *             \"message\" => [\n *                 \"file\"        => \"Min resolution of file is 800x600\",\n *                 \"anotherFile\" => \"Min resolution of file is 1024x768\",\n *             ],\n *         ]\n *     )\n * );\n * ```\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
        "line": 61,
        "char": 5
    },
    {
        "type": "class",
        "name": "Min",
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
                        "value": "File :field can not have the minimum resolution of :resolution",
                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                        "line": 63,
                        "char": 88
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                    "line": 67,
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                "line": 68,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                            "line": 68,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                            "line": 68,
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
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 70,
                                    "char": 19
                                },
                                {
                                    "variable": "minHeight",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 70,
                                    "char": 30
                                },
                                {
                                    "variable": "minWidth",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 70,
                                    "char": 40
                                },
                                {
                                    "variable": "resolution",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 70,
                                    "char": 52
                                },
                                {
                                    "variable": "resolutionArray",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 70,
                                    "char": 69
                                },
                                {
                                    "variable": "tmp",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 71,
                                    "char": 16
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 71,
                                    "char": 23
                                },
                                {
                                    "variable": "width",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 71,
                                    "char": 30
                                },
                                {
                                    "variable": "replacePairs",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 71,
                                    "char": 44
                                },
                                {
                                    "variable": "included",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                        "line": 71,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 71,
                                    "char": 62
                                },
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 71,
                                    "char": 70
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                            "line": 74,
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
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                        "line": 74,
                                        "char": 17
                                    },
                                    "name": "checkUpload",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "validation",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                "line": 74,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                            "line": 74,
                                            "char": 40
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "field",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                "line": 74,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                            "line": 74,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 74,
                                    "char": 51
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 74,
                                    "char": 59
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                "line": 74,
                                "char": 59
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                        "line": 75,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 76,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                            "line": 78,
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
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                            "line": 78,
                                            "char": 33
                                        },
                                        "name": "getValue",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                    "line": 78,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                "line": 78,
                                                "char": 48
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                        "line": 78,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 78,
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
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                        "line": 79,
                                                        "char": 40
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "tmp_name",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                        "line": 79,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                    "line": 79,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                "line": 79,
                                                "char": 50
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                        "line": 79,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 79,
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
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                            "line": 80,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                            "line": 80,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                        "line": 80,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 80,
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
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                            "line": 81,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "1",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                            "line": 81,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                        "line": 81,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 81,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                            "line": 83,
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
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                            "line": 83,
                                            "char": 31
                                        },
                                        "name": "getOption",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "resolution",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                    "line": 83,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                "line": 83,
                                                "char": 52
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                        "line": 83,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 83,
                                    "char": 53
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                            "line": 85,
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
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                        "line": 85,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 85,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 85,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                "line": 85,
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
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                    "line": 86,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                    "line": 86,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                "line": 86,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                            "line": 86,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 87,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                            "line": 89,
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
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                    "line": 89,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                "line": 89,
                                                "char": 40
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "resolution",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                    "line": 89,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                "line": 89,
                                                "char": 52
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                        "line": 89,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 89,
                                    "char": 53
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "minWidth",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "resolutionArray",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                            "line": 90,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                            "line": 90,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                        "line": 90,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 90,
                                    "char": 42
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "minHeight",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "resolutionArray",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                            "line": 91,
                                            "char": 40
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "1",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                            "line": 91,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                        "line": 91,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 91,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                            "line": 93,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "included",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                            "line": 93,
                                            "char": 29
                                        },
                                        "name": "getOption",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "included",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                    "line": 93,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                "line": 93,
                                                "char": 48
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                        "line": 93,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 93,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                            "line": 95,
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
                                        "value": "included",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                        "line": 95,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 95,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 95,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                "line": 95,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "included",
                                            "expr": {
                                                "type": "cast",
                                                "left": "bool",
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "included",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                        "line": 96,
                                                        "char": 43
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "field",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                        "line": 96,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                    "line": 96,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                "line": 96,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                            "line": 96,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 97,
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
                                            "variable": "included",
                                            "expr": {
                                                "type": "cast",
                                                "left": "bool",
                                                "right": {
                                                    "type": "variable",
                                                    "value": "included",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                    "line": 98,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                "line": 98,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                            "line": 98,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 99,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                            "line": 101,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "included",
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                "line": 101,
                                "char": 21
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "result",
                                            "expr": {
                                                "type": "or",
                                                "left": {
                                                    "type": "less-equal",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "width",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                        "line": 102,
                                                        "char": 32
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "minWidth",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                        "line": 102,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                    "line": 102,
                                                    "char": 44
                                                },
                                                "right": {
                                                    "type": "less-equal",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "height",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                        "line": 102,
                                                        "char": 53
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "minHeight",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                        "line": 102,
                                                        "char": 64
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                    "line": 102,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                "line": 102,
                                                "char": 64
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                            "line": 102,
                                            "char": 64
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 103,
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
                                            "variable": "result",
                                            "expr": {
                                                "type": "or",
                                                "left": {
                                                    "type": "less",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "width",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                        "line": 104,
                                                        "char": 32
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "minWidth",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                        "line": 104,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                    "line": 104,
                                                    "char": 44
                                                },
                                                "right": {
                                                    "type": "less",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "height",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                        "line": 104,
                                                        "char": 53
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "minHeight",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                        "line": 104,
                                                        "char": 64
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                    "line": 104,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                "line": 104,
                                                "char": 64
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                            "line": 104,
                                            "char": 64
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 105,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                            "line": 107,
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
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                        "line": 107,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 107,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 107,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                "line": 107,
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
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                    "line": 108,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                    "line": 108,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                "line": 108,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                            "line": 108,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 109,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                            "line": 111,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "result",
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                "line": 111,
                                "char": 19
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
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                            "line": 113,
                                                            "char": 29
                                                        },
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "resolution",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                            "line": 114,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                        "line": 114,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                "line": 114,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                            "line": 114,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 116,
                                    "char": 22
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "validation",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                            "line": 116,
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
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                        "line": 117,
                                                        "char": 22
                                                    },
                                                    "name": "messageFactory",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "validation",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                                "line": 117,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                            "line": 117,
                                                            "char": 48
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "field",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                                "line": 117,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                            "line": 117,
                                                            "char": 55
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "replacePairs",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                                "line": 117,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                            "line": 117,
                                                            "char": 69
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                    "line": 118,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                                "line": 118,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                        "line": 118,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 120,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                        "line": 120,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                    "line": 121,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                            "line": 123,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                "line": 123,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                            "line": 124,
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                                "line": 69,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                        "line": 69,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
                    "line": 68,
                    "last-line": 125,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
            "line": 61,
            "char": 5
        },
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Resolution\/Min.zep",
        "line": 61,
        "char": 5
    }
]