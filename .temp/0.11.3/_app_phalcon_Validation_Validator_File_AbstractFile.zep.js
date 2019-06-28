[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Validation\\Validator\\File",
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\Message",
                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                "line": 13,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validation",
                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                "line": 14,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\AbstractValidator",
                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                "line": 15,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
        "line": 55,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Checks if a value has a correct file\n *\n * ```php\n * use Phalcon\\Validation\\Validation;\n * use Phalcon\\Validation\\Validator\\File\\Size;\n *\n * $validator = new Validation();\n *\n * $validator->add(\n *     \"file\",\n *     new Size(\n *         [\n *             \"maxSize\"              => \"2M\",\n *             \"messageSize\"          => \":field exceeds the max filesize (:size)\",\n *         ]\n *     )\n * );\n *\n * $validator->add(\n *     [\n *         \"file\",\n *         \"anotherFile\",\n *     ],\n *     new FileValidator(\n *         [\n *             \"maxSize\" => [\n *                 \"file\"        => \"2M\",\n *                 \"anotherFile\" => \"4M\",\n *             ],\n *             \"messageSize\" => [\n *                 \"file\"        => \"file exceeds the max filesize 2M\",\n *                 \"anotherFile\" => \"anotherFile exceeds the max filesize 4M\",\n *             ],\n *         ]\n *     )\n * );\n * ```\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
        "line": 56,
        "char": 8
    },
    {
        "type": "class",
        "name": "AbstractFile",
        "abstract": 1,
        "final": 0,
        "extends": "AbstractValidator",
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "messageFileEmpty",
                    "default": {
                        "type": "string",
                        "value": "Field :field must not be empty",
                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                        "line": 61,
                        "char": 65
                    },
                    "docblock": "**\n    * Empty is empty\n    *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 61,
                            "char": 70
                        },
                        {
                            "type": "shortcut",
                            "name": "set",
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 61,
                            "char": 76
                        }
                    ],
                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                    "line": 65,
                    "char": 5
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "messageIniSize",
                    "default": {
                        "type": "string",
                        "value": "File :field exceeds the maximum file size",
                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                        "line": 66,
                        "char": 74
                    },
                    "docblock": "**\n    * File exceeed the file size setted in PHP configuration\n    *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 66,
                            "char": 79
                        },
                        {
                            "type": "shortcut",
                            "name": "set",
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 66,
                            "char": 85
                        }
                    ],
                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                    "line": 70,
                    "char": 5
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "messageValid",
                    "default": {
                        "type": "string",
                        "value": "Field :field is not valid",
                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                        "line": 71,
                        "char": 56
                    },
                    "docblock": "**\n    * File is not valid\n    *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 71,
                            "char": 61
                        },
                        {
                            "type": "shortcut",
                            "name": "set",
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 71,
                            "char": 67
                        }
                    ],
                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                    "line": 79,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isAllowEmpty",
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                "line": 80,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 80,
                            "char": 57
                        },
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 80,
                            "char": 72
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "value",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "validation",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 82,
                                            "char": 32
                                        },
                                        "name": "getValue",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 82,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 82,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 82,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 82,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 84,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "empty",
                                    "left": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 84,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 84,
                                    "char": 29
                                },
                                "right": {
                                    "type": "and",
                                    "left": {
                                        "type": "isset",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 84,
                                                "char": 42
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "error",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 84,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 84,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 84,
                                        "char": 51
                                    },
                                    "right": {
                                        "type": "identical",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 84,
                                                "char": 58
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "error",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 84,
                                                "char": 64
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 84,
                                            "char": 68
                                        },
                                        "right": {
                                            "type": "constant",
                                            "value": "UPLOAD_ERR_NO_FILE",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 84,
                                            "char": 88
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 84,
                                        "char": 88
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 84,
                                    "char": 88
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                "line": 84,
                                "char": 88
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 85,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check on empty\n     *\n     * @param Valiation $validation\n     * @param mixed $field\n     * @return bool\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                "line": 81,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                        "line": 81,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                    "line": 80,
                    "last-line": 93,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "checkUpload",
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                "line": 94,
                                "char": 55
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 94,
                            "char": 56
                        },
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 94,
                            "char": 67
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "and",
                                    "left": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 96,
                                            "char": 21
                                        },
                                        "name": "checkUploadMaxSize",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "validation",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 96,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 96,
                                                "char": 51
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 96,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 96,
                                                "char": 58
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 96,
                                        "char": 61
                                    },
                                    "right": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 97,
                                            "char": 21
                                        },
                                        "name": "checkUploadIsEmpty",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "validation",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 97,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 97,
                                                "char": 51
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 97,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 97,
                                                "char": 58
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 97,
                                        "char": 61
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 97,
                                    "char": 61
                                },
                                "right": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 98,
                                        "char": 21
                                    },
                                    "name": "checkUploadIsValid",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "validation",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 98,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 98,
                                            "char": 51
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "field",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 98,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 98,
                                            "char": 58
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 98,
                                    "char": 59
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                "line": 98,
                                "char": 59
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 99,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n    * Check upload\n    *\n    * @param Valiation $validation\n    * @param mixed $field\n    * @return bool\n    *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                "line": 95,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                        "line": 95,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                    "line": 94,
                    "last-line": 107,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "checkUploadMaxSize",
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                "line": 108,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 108,
                            "char": 63
                        },
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 108,
                            "char": 74
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "label",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 110,
                                    "char": 18
                                },
                                {
                                    "variable": "replacePairs",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 110,
                                    "char": 32
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 110,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 112,
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
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 112,
                                            "char": 32
                                        },
                                        "name": "getValue",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 112,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 112,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 112,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 112,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 115,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "and",
                                    "left": {
                                        "type": "and",
                                        "left": {
                                            "type": "and",
                                            "left": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "_SERVER",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                        "line": 115,
                                                        "char": 19
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "REQUEST_METHOD",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                        "line": 115,
                                                        "char": 34
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 115,
                                                    "char": 37
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "POST",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 115,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 115,
                                                "char": 45
                                            },
                                            "right": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "_POST",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 116,
                                                    "char": 26
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 116,
                                                "char": 26
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 116,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "empty",
                                            "left": {
                                                "type": "variable",
                                                "value": "_FILES",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 117,
                                                "char": 27
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 117,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 117,
                                        "char": 27
                                    },
                                    "right": {
                                        "type": "greater",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "_SERVER",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 118,
                                                "char": 20
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "CONTENT_LENGTH",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 118,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 118,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 118,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 118,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 118,
                                    "char": 42
                                },
                                "right": {
                                    "type": "and",
                                    "left": {
                                        "type": "isset",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 119,
                                                "char": 24
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "error",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 119,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 119,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 119,
                                        "char": 33
                                    },
                                    "right": {
                                        "type": "identical",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 119,
                                                "char": 40
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "error",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 119,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 119,
                                            "char": 50
                                        },
                                        "right": {
                                            "type": "constant",
                                            "value": "UPLOAD_ERR_INI_SIZE",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 120,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 120,
                                        "char": 9
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 120,
                                    "char": 9
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                "line": 120,
                                "char": 9
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "label",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 121,
                                                    "char": 30
                                                },
                                                "name": "prepareLabel",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "validation",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                            "line": 121,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                        "line": 121,
                                                        "char": 54
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "field",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                            "line": 121,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                        "line": 121,
                                                        "char": 61
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 121,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 121,
                                            "char": 62
                                        },
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
                                                            "value": ":field",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                            "line": 123,
                                                            "char": 27
                                                        },
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "label",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                            "line": 124,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                        "line": 124,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 124,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 124,
                                            "char": 18
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 126,
                                    "char": 22
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "validation",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 126,
                                            "char": 24
                                        },
                                        "name": "appendMessage",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "new",
                                                    "class": "Message",
                                                    "dynamic": 0,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "fcall",
                                                                "name": "strtr",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "mcall",
                                                                            "variable": {
                                                                                "type": "variable",
                                                                                "value": "this",
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                                "line": 128,
                                                                                "char": 32
                                                                            },
                                                                            "name": "getMessageIniSize",
                                                                            "call-type": 1,
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                            "line": 128,
                                                                            "char": 52
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                        "line": 128,
                                                                        "char": 52
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "replacePairs",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                            "line": 128,
                                                                            "char": 66
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                        "line": 128,
                                                                        "char": 66
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                "line": 128,
                                                                "char": 67
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                            "line": 128,
                                                            "char": 67
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "field",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                "line": 129,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                            "line": 129,
                                                            "char": 26
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "fcall",
                                                                "name": "get_class",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                            "line": 130,
                                                                            "char": 35
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                        "line": 130,
                                                                        "char": 35
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                "line": 130,
                                                                "char": 36
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                            "line": 130,
                                                            "char": 36
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                    "line": 131,
                                                                    "char": 26
                                                                },
                                                                "name": "prepareCode",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "field",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                            "line": 131,
                                                                            "char": 44
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                        "line": 131,
                                                                        "char": 44
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                "line": 132,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                            "line": 132,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 133,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 133,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 133,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 135,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 135,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 136,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 138,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                "line": 138,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 139,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n    * Check if uploaded file is larger than PHP allowed size\n    *\n    * @param Valiation $validation\n    * @param mixed $field\n    * @return boolean\n    *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                "line": 109,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                        "line": 109,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                    "line": 108,
                    "last-line": 147,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "checkUploadIsEmpty",
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                "line": 148,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 148,
                            "char": 63
                        },
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 148,
                            "char": 74
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "label",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 150,
                                    "char": 18
                                },
                                {
                                    "variable": "replacePairs",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 150,
                                    "char": 32
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 150,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 152,
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
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 152,
                                            "char": 32
                                        },
                                        "name": "getValue",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 152,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 152,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 152,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 152,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 154,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "or",
                                    "left": {
                                        "type": "or",
                                        "left": {
                                            "type": "not",
                                            "left": {
                                                "type": "isset",
                                                "left": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                        "line": 154,
                                                        "char": 24
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "error",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                        "line": 154,
                                                        "char": 30
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 154,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 154,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 154,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "not",
                                            "left": {
                                                "type": "isset",
                                                "left": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                        "line": 154,
                                                        "char": 47
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "tmp_name",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                        "line": 154,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 154,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 154,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 154,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 154,
                                        "char": 59
                                    },
                                    "right": {
                                        "type": "not-identical",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 154,
                                                "char": 66
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "error",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 154,
                                                "char": 72
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 154,
                                            "char": 76
                                        },
                                        "right": {
                                            "type": "constant",
                                            "value": "UPLOAD_ERR_OK",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 154,
                                            "char": 93
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 154,
                                        "char": 93
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 154,
                                    "char": 93
                                },
                                "right": {
                                    "type": "not",
                                    "left": {
                                        "type": "fcall",
                                        "name": "is_uploaded_file",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                        "line": 154,
                                                        "char": 118
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "tmp_name",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                        "line": 154,
                                                        "char": 127
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 154,
                                                    "char": 128
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 154,
                                                "char": 128
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 154,
                                        "char": 130
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 154,
                                    "char": 130
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                "line": 154,
                                "char": 130
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "label",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 155,
                                                    "char": 30
                                                },
                                                "name": "prepareLabel",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "validation",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                            "line": 155,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                        "line": 155,
                                                        "char": 54
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "field",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                            "line": 155,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                        "line": 155,
                                                        "char": 61
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 155,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 155,
                                            "char": 62
                                        },
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
                                                            "value": ":field",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                            "line": 157,
                                                            "char": 27
                                                        },
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "label",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                            "line": 158,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                        "line": 158,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 158,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 158,
                                            "char": 18
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 160,
                                    "char": 22
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "validation",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 160,
                                            "char": 24
                                        },
                                        "name": "appendMessage",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "new",
                                                    "class": "Message",
                                                    "dynamic": 0,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "fcall",
                                                                "name": "strtr",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "mcall",
                                                                            "variable": {
                                                                                "type": "variable",
                                                                                "value": "this",
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                                "line": 162,
                                                                                "char": 32
                                                                            },
                                                                            "name": "getMessageFileEmpty",
                                                                            "call-type": 1,
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                            "line": 162,
                                                                            "char": 54
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                        "line": 162,
                                                                        "char": 54
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "replacePairs",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                            "line": 162,
                                                                            "char": 68
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                        "line": 162,
                                                                        "char": 68
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                "line": 162,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                            "line": 162,
                                                            "char": 69
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "field",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                "line": 163,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                            "line": 163,
                                                            "char": 26
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "fcall",
                                                                "name": "get_class",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                            "line": 164,
                                                                            "char": 35
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                        "line": 164,
                                                                        "char": 35
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                "line": 164,
                                                                "char": 36
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                            "line": 164,
                                                            "char": 36
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                    "line": 165,
                                                                    "char": 26
                                                                },
                                                                "name": "prepareCode",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "field",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                            "line": 165,
                                                                            "char": 44
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                        "line": 165,
                                                                        "char": 44
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                "line": 166,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                            "line": 166,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 167,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 167,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 167,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 169,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 169,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 170,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 172,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                "line": 172,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 173,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n    * Check if upload is empty\n    *\n    * @param Valiation $validation\n    * @param mixed $field\n    * @return boolean\n    *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                "line": 149,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                        "line": 149,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                    "line": 148,
                    "last-line": 181,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "checkUploadIsValid",
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                "line": 182,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 182,
                            "char": 63
                        },
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 182,
                            "char": 74
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "label",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 184,
                                    "char": 18
                                },
                                {
                                    "variable": "replacePairs",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 184,
                                    "char": 32
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 184,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 186,
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
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 186,
                                            "char": 32
                                        },
                                        "name": "getValue",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 186,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 186,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 186,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 186,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 188,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "or",
                                    "left": {
                                        "type": "not",
                                        "left": {
                                            "type": "isset",
                                            "left": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 188,
                                                    "char": 24
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 188,
                                                    "char": 29
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 188,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 188,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 188,
                                        "char": 32
                                    },
                                    "right": {
                                        "type": "not",
                                        "left": {
                                            "type": "isset",
                                            "left": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 188,
                                                    "char": 46
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "type",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 188,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 188,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 188,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 188,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 188,
                                    "char": 54
                                },
                                "right": {
                                    "type": "not",
                                    "left": {
                                        "type": "isset",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 188,
                                                "char": 68
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "size",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 188,
                                                "char": 73
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 188,
                                            "char": 75
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 188,
                                        "char": 75
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 188,
                                    "char": 75
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                "line": 188,
                                "char": 75
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "label",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 189,
                                                    "char": 30
                                                },
                                                "name": "prepareLabel",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "validation",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                            "line": 189,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                        "line": 189,
                                                        "char": 54
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "field",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                            "line": 189,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                        "line": 189,
                                                        "char": 61
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 189,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 189,
                                            "char": 62
                                        },
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
                                                            "value": ":field",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                            "line": 191,
                                                            "char": 27
                                                        },
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "label",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                            "line": 192,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                        "line": 192,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 192,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 192,
                                            "char": 18
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 194,
                                    "char": 22
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "validation",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 194,
                                            "char": 24
                                        },
                                        "name": "appendMessage",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "new",
                                                    "class": "Message",
                                                    "dynamic": 0,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "fcall",
                                                                "name": "strtr",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "mcall",
                                                                            "variable": {
                                                                                "type": "variable",
                                                                                "value": "this",
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                                "line": 196,
                                                                                "char": 32
                                                                            },
                                                                            "name": "getMessageValid",
                                                                            "call-type": 1,
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                            "line": 196,
                                                                            "char": 50
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                        "line": 196,
                                                                        "char": 50
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "replacePairs",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                            "line": 196,
                                                                            "char": 64
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                        "line": 196,
                                                                        "char": 64
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                "line": 196,
                                                                "char": 65
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                            "line": 196,
                                                            "char": 65
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "field",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                "line": 197,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                            "line": 197,
                                                            "char": 26
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "fcall",
                                                                "name": "get_class",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                            "line": 198,
                                                                            "char": 35
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                        "line": 198,
                                                                        "char": 35
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                "line": 198,
                                                                "char": 36
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                            "line": 198,
                                                            "char": 36
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                    "line": 199,
                                                                    "char": 26
                                                                },
                                                                "name": "prepareCode",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "field",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                            "line": 199,
                                                                            "char": 44
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                        "line": 199,
                                                                        "char": 44
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                "line": 200,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                            "line": 200,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 201,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 201,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 201,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 203,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 203,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 204,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 206,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                "line": 206,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 207,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n    * Check if upload is valid\n    *\n    * @param Valiation $validation\n    * @param mixed $field\n    * @return boolean\n    *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                "line": 183,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                        "line": 183,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                    "line": 182,
                    "last-line": 214,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getFileSizeInBytes",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "size",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 215,
                            "char": 52
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "byteUnits",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "B",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 218,
                                                    "char": 14
                                                },
                                                "value": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 218,
                                                    "char": 17
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 218,
                                                "char": 17
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "K",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 219,
                                                    "char": 14
                                                },
                                                "value": {
                                                    "type": "int",
                                                    "value": "10",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 219,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 219,
                                                "char": 18
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "M",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 220,
                                                    "char": 14
                                                },
                                                "value": {
                                                    "type": "int",
                                                    "value": "20",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 220,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 220,
                                                "char": 18
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "G",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 221,
                                                    "char": 14
                                                },
                                                "value": {
                                                    "type": "int",
                                                    "value": "30",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 221,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 221,
                                                "char": 18
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "T",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 222,
                                                    "char": 14
                                                },
                                                "value": {
                                                    "type": "int",
                                                    "value": "40",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 222,
                                                    "char": 18
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 222,
                                                "char": 18
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "KB",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 223,
                                                    "char": 15
                                                },
                                                "value": {
                                                    "type": "int",
                                                    "value": "10",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 223,
                                                    "char": 19
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 223,
                                                "char": 19
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "MB",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 224,
                                                    "char": 15
                                                },
                                                "value": {
                                                    "type": "int",
                                                    "value": "20",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 224,
                                                    "char": 19
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 224,
                                                "char": 19
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "GB",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 225,
                                                    "char": 15
                                                },
                                                "value": {
                                                    "type": "int",
                                                    "value": "30",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 225,
                                                    "char": 19
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 225,
                                                "char": 19
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "TB",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 226,
                                                    "char": 15
                                                },
                                                "value": {
                                                    "type": "int",
                                                    "value": "40",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 227,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 227,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 227,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 227,
                                    "char": 10
                                },
                                {
                                    "variable": "unit",
                                    "expr": {
                                        "type": "string",
                                        "value": "B",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 227,
                                        "char": 20
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 227,
                                    "char": 20
                                },
                                {
                                    "variable": "matches",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 227,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 227,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 229,
                            "char": 18
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "preg_match",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "concat",
                                            "left": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "string",
                                                    "value": "\/^([0-9]+(?:\\\\.[0-9]+)?)(",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 230,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "implode",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "|",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                "line": 230,
                                                                "char": 50
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                            "line": 230,
                                                            "char": 50
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "fcall",
                                                                "name": "array_keys",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "byteUnits",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                            "line": 230,
                                                                            "char": 72
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                        "line": 230,
                                                                        "char": 72
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                                "line": 230,
                                                                "char": 73
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                            "line": 230,
                                                            "char": 73
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 230,
                                                    "char": 75
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 230,
                                                "char": 75
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": ")?$\/Di",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 230,
                                                "char": 83
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 230,
                                            "char": 83
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 230,
                                        "char": 83
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "size",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 231,
                                            "char": 17
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 231,
                                        "char": 17
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "matches",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 233,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 233,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                "line": 233,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 235,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "matches",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 235,
                                        "char": 25
                                    },
                                    "right": {
                                        "type": "int",
                                        "value": "2",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                        "line": 235,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 235,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                "line": 235,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "unit",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "matches",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 236,
                                                    "char": 31
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "2",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 236,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 236,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 236,
                                            "char": 34
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 237,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 239,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mul",
                                "left": {
                                    "type": "fcall",
                                    "name": "floatval",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "matches",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 239,
                                                    "char": 32
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 239,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 239,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 239,
                                            "char": 35
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 239,
                                    "char": 37
                                },
                                "right": {
                                    "type": "fcall",
                                    "name": "pow",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "int",
                                                "value": "2",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 239,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 239,
                                            "char": 44
                                        },
                                        {
                                            "parameter": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "byteUnits",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 239,
                                                    "char": 55
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "unit",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                    "line": 239,
                                                    "char": 60
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                                "line": 239,
                                                "char": 61
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                            "line": 239,
                                            "char": 61
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                    "line": 239,
                                    "char": 62
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                "line": 239,
                                "char": 62
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                            "line": 240,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n    * Convert a string like \"2.5MB\" in bytes\n    *\n    * @param string $size\n    * @return float\n    *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "double",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                                "line": 216,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                        "line": 216,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
                    "line": 215,
                    "last-line": 241,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
            "line": 56,
            "char": 14
        },
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/AbstractFile.zep",
        "line": 56,
        "char": 14
    }
]