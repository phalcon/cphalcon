[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Validation\\Validator\\File",
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\Message",
                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                "line": 13,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validation",
                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                "line": 14,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Exception",
                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                "line": 15,
                "char": 33
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validator\\File\\AbstractFile",
                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                "line": 16,
                "char": 51
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
        "line": 65,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Checks if a value has a correct file mime type\n *\n * ```php\n * use Phalcon\\Validation\\Validation;\n * use Phalcon\\Validation\\Validator\\File\\MimeType;\n *\n * $validator = new Validation();\n *\n * $validator->add(\n *     \"file\",\n *     new MimeType(\n *         [\n *             \"types\" => [\n *                 \"image\/jpeg\",\n *                 \"image\/png\",\n *             ],\n *             \"message\" => \"Allowed file types are :types\"\n *         ]\n *     )\n * );\n *\n * $validator->add(\n *     [\n *         \"file\",\n *         \"anotherFile\",\n *     ],\n *     new MimeType(\n *         [\n *             \"types\" => [\n *                 \"file\"        => [\n *                     \"image\/jpeg\",\n *                     \"image\/png\",\n *                 ],\n *                 \"anotherFile\" => [\n *                     \"image\/gif\",\n *                     \"image\/bmp\",\n *                 ],\n *             ],\n *             \"message\" => [\n *                 \"file\"        => \"Allowed file types are image\/jpeg and image\/png\",\n *                 \"anotherFile\" => \"Allowed file types are image\/gif and image\/bmp\",\n *             ]\n *         ]\n *     )\n * );\n * ```\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
        "line": 66,
        "char": 5
    },
    {
        "type": "class",
        "name": "MimeType",
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
                        "value": "File :field must be of type: :types",
                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                        "line": 68,
                        "char": 61
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                    "line": 76,
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                "line": 77,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                            "line": 77,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                            "line": 77,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "fieldTypes",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                    "line": 79,
                                    "char": 23
                                },
                                {
                                    "variable": "mime",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                    "line": 79,
                                    "char": 29
                                },
                                {
                                    "variable": "replacePairs",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                    "line": 79,
                                    "char": 43
                                },
                                {
                                    "variable": "tmp",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                    "line": 79,
                                    "char": 48
                                },
                                {
                                    "variable": "types",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                    "line": 79,
                                    "char": 55
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                    "line": 79,
                                    "char": 62
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                            "line": 82,
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
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                        "line": 82,
                                        "char": 17
                                    },
                                    "name": "checkUpload",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "validation",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                "line": 82,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                            "line": 82,
                                            "char": 40
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "field",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                "line": 82,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                            "line": 82,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                    "line": 82,
                                    "char": 51
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                    "line": 82,
                                    "char": 59
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                "line": 82,
                                "char": 59
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                        "line": 83,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                    "line": 84,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                            "line": 86,
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
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                            "line": 86,
                                            "char": 32
                                        },
                                        "name": "getValue",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                    "line": 86,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                "line": 86,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                        "line": 86,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                    "line": 86,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                            "line": 88,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "types",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                            "line": 88,
                                            "char": 26
                                        },
                                        "name": "getOption",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "types",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                    "line": 88,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                "line": 88,
                                                "char": 42
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                        "line": 88,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                    "line": 88,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                            "line": 90,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "fieldTypes",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                    "line": 90,
                                    "char": 43
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "types",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                        "line": 90,
                                        "char": 35
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "field",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                        "line": 90,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                    "line": 90,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                "line": 90,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "types",
                                            "expr": {
                                                "type": "variable",
                                                "value": "fieldTypes",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                "line": 91,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                            "line": 91,
                                            "char": 35
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                    "line": 92,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                            "line": 94,
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
                                            "value": "types",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                            "line": 94,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                        "line": 94,
                                        "char": 35
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                        "line": 94,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                    "line": 94,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                "line": 94,
                                "char": 43
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
                                                    "value": "Option 'allowedTypes' must be an array",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                    "line": 97,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                "line": 97,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                        "line": 97,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                    "line": 98,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                            "line": 100,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "function_exists",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "finfo_open",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                            "line": 100,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                        "line": 100,
                                        "char": 38
                                    }
                                ],
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                "line": 100,
                                "char": 40
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "tmp",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "finfo_open",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "constant",
                                                            "value": "FILEINFO_MIME_TYPE",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                            "line": 101,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                        "line": 101,
                                                        "char": 52
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                "line": 101,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                            "line": 101,
                                            "char": 53
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "mime",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "finfo_file",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "tmp",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                            "line": 102,
                                                            "char": 38
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                        "line": 102,
                                                        "char": 38
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "value",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                                "line": 102,
                                                                "char": 45
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "tmp_name",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                                "line": 102,
                                                                "char": 54
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                            "line": 102,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                        "line": 102,
                                                        "char": 55
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                "line": 102,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                            "line": 102,
                                            "char": 56
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                    "line": 104,
                                    "char": 23
                                },
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "finfo_close",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "tmp",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                    "line": 104,
                                                    "char": 28
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                "line": 104,
                                                "char": 28
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                        "line": 104,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                    "line": 105,
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
                                            "variable": "mime",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                    "line": 106,
                                                    "char": 29
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "type",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                    "line": 106,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                "line": 106,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                            "line": 106,
                                            "char": 35
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                    "line": 107,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                            "line": 109,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fcall",
                                    "name": "in_array",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "mime",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                "line": 109,
                                                "char": 26
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                            "line": 109,
                                            "char": 26
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "types",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                "line": 109,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                            "line": 109,
                                            "char": 33
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                    "line": 109,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                "line": 109,
                                "char": 35
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
                                                            "value": ":types",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                            "line": 111,
                                                            "char": 23
                                                        },
                                                        "value": {
                                                            "type": "fcall",
                                                            "name": "join",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": ", ",
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                                        "line": 111,
                                                                        "char": 32
                                                                    },
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                                    "line": 111,
                                                                    "char": 32
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "types",
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                                        "line": 111,
                                                                        "char": 39
                                                                    },
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                                    "line": 111,
                                                                    "char": 39
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                            "line": 112,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                        "line": 112,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                "line": 112,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                            "line": 112,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                    "line": 114,
                                    "char": 22
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "validation",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                            "line": 114,
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
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                        "line": 115,
                                                        "char": 22
                                                    },
                                                    "name": "messageFactory",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "validation",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                                "line": 115,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                            "line": 115,
                                                            "char": 48
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "field",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                                "line": 115,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                            "line": 115,
                                                            "char": 55
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "replacePairs",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                                "line": 115,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                            "line": 115,
                                                            "char": 69
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                    "line": 116,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                                "line": 116,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                        "line": 116,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                    "line": 118,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                        "line": 118,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                    "line": 119,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                            "line": 121,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                "line": 121,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                            "line": 122,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Executes the validation\n     *\n     * @param Valiation $validation\n     * @param mixed $field\n     * @return bool\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                                "line": 78,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                        "line": 78,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
                    "line": 77,
                    "last-line": 123,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
            "line": 66,
            "char": 5
        },
        "file": "\/app\/phalcon\/Validation\/Validator\/File\/MimeType.zep",
        "line": 66,
        "char": 5
    }
]