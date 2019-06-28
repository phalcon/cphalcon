[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Validation\\Validator\\File\\Size",
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\Message",
                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                "line": 13,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validation",
                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                "line": 14,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validator\\File\\Size\\Max",
                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                "line": 15,
                "char": 47
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validator\\File\\AbstractFile",
                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                "line": 16,
                "char": 51
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
        "line": 61,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Checks if a value has a correct file\n *\n * ```php\n * use Phalcon\\Validation\\Validation;\n * use Phalcon\\Validation\\Validator\\File\\Size;\n *\n * $validator = new Validation();\n *\n * $validator->add(\n *     \"file\",\n *     new Max(\n *         [\n *             \"size\"     => \"2M\",\n *             \"included\" => true,\n *             \"message\"  => \":field exceeds the max filesize (:size)\",\n *         ]\n *     )\n * );\n *\n * $validator->add(\n *     [\n *         \"file\",\n *         \"anotherFile\",\n *     ],\n *     new Max(\n *         [\n *             \"size\" => [\n *                 \"file\"        => \"2M\",\n *                 \"anotherFile\" => \"4M\",\n *             ],\n *             \"included\" => [\n *                 \"file\"        => false,\n *                 \"anotherFile\" => true,\n *             ],\n *             \"message\" => [\n *                 \"file\"        => \"file exceeds the max filesize 2M\",\n *                 \"anotherFile\" => \"anotherFile exceeds the max filesize 4M\",\n *             ],\n *         ]\n *     )\n * );\n * ```\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
        "line": 62,
        "char": 5
    },
    {
        "type": "class",
        "name": "Max",
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
                        "value": "File :field exceeds the size of :size",
                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                        "line": 64,
                        "char": 63
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                    "line": 68,
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                "line": 69,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                            "line": 69,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                            "line": 69,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "bytes",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                    "line": 71,
                                    "char": 18
                                },
                                {
                                    "variable": "fileSize",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                    "line": 71,
                                    "char": 28
                                },
                                {
                                    "variable": "included",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                        "line": 71,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                    "line": 71,
                                    "char": 46
                                },
                                {
                                    "variable": "replacePairs",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                    "line": 71,
                                    "char": 60
                                },
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                    "line": 71,
                                    "char": 68
                                },
                                {
                                    "variable": "size",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                    "line": 71,
                                    "char": 74
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                    "line": 71,
                                    "char": 81
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
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
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
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
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                "line": 74,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                            "line": 74,
                                            "char": 40
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "field",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                "line": 74,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                            "line": 74,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                    "line": 74,
                                    "char": 51
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                    "line": 74,
                                    "char": 59
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                "line": 74,
                                "char": 59
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                        "line": 75,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                    "line": 76,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
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
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                            "line": 78,
                                            "char": 32
                                        },
                                        "name": "getValue",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                    "line": 78,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                "line": 78,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                        "line": 78,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                    "line": 78,
                                    "char": 48
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "size",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                            "line": 79,
                                            "char": 25
                                        },
                                        "name": "getOption",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "size",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                    "line": 79,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                "line": 79,
                                                "char": 40
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                        "line": 79,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                    "line": 79,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                            "line": 81,
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
                                        "value": "size",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                        "line": 81,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                    "line": 81,
                                    "char": 25
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                    "line": 81,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                "line": 81,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "size",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "size",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                    "line": 82,
                                                    "char": 28
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                    "line": 82,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                "line": 82,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                            "line": 82,
                                            "char": 35
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                    "line": 83,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                            "line": 85,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "bytes",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "round",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                        "line": 85,
                                                        "char": 32
                                                    },
                                                    "name": "getFileSizeInBytes",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "size",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                                "line": 85,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                            "line": 85,
                                                            "char": 56
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                    "line": 85,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                "line": 85,
                                                "char": 57
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "6",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                    "line": 85,
                                                    "char": 60
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                "line": 85,
                                                "char": 60
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                        "line": 85,
                                        "char": 61
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                    "line": 85,
                                    "char": 61
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "fileSize",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "round",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "fcall",
                                                    "name": "floatval",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "array-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "value",
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                                    "line": 86,
                                                                    "char": 44
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "size",
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                                    "line": 86,
                                                                    "char": 49
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                                "line": 86,
                                                                "char": 50
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                            "line": 86,
                                                            "char": 50
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                    "line": 86,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                "line": 86,
                                                "char": 51
                                            },
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "6",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                    "line": 86,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                "line": 86,
                                                "char": 54
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                        "line": 86,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                    "line": 86,
                                    "char": 55
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                            "line": 88,
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
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                            "line": 88,
                                            "char": 29
                                        },
                                        "name": "getOption",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "included",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                    "line": 88,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                "line": 88,
                                                "char": 48
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                        "line": 88,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                    "line": 88,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                            "line": 90,
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
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                        "line": 90,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                    "line": 90,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                    "line": 90,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                "line": 90,
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
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                        "line": 91,
                                                        "char": 43
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "field",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                        "line": 91,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                    "line": 91,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                "line": 91,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                            "line": 91,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                    "line": 92,
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
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                    "line": 93,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                "line": 93,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                            "line": 93,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                    "line": 94,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                            "line": 96,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "included",
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                "line": 96,
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
                                                "type": "greater-equal",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "fileSize",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                    "line": 97,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "bytes",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                    "line": 97,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                "line": 97,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                            "line": 97,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                    "line": 98,
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
                                                "type": "greater",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "fileSize",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                    "line": 99,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "bytes",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                    "line": 99,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                "line": 99,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                            "line": 99,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                    "line": 100,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                            "line": 102,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "result",
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                "line": 102,
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
                                                            "value": ":size",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                            "line": 104,
                                                            "char": 24
                                                        },
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "size",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                            "line": 105,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                        "line": 105,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                "line": 105,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                            "line": 105,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                    "line": 107,
                                    "char": 22
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "validation",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                            "line": 107,
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
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                        "line": 108,
                                                        "char": 22
                                                    },
                                                    "name": "messageFactory",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "validation",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                                "line": 108,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                            "line": 108,
                                                            "char": 48
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "field",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                                "line": 108,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                            "line": 108,
                                                            "char": 55
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "replacePairs",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                                "line": 108,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                            "line": 108,
                                                            "char": 69
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                    "line": 109,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                                "line": 109,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                        "line": 109,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                    "line": 111,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                        "line": 111,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                    "line": 112,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                            "line": 114,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                "line": 114,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                            "line": 115,
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                                "line": 70,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                        "line": 70,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
                    "line": 69,
                    "last-line": 116,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
            "line": 62,
            "char": 5
        },
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/Size\/Max.zep",
        "line": 62,
        "char": 5
    }
]