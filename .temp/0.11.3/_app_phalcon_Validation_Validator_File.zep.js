[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Validation\\Validator",
        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Helper\\Arr",
                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                "line": 13,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\Message",
                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                "line": 14,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validation",
                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                "line": 15,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\AbstractValidatorComposite",
                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                "line": 16,
                "char": 50
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validator\\File\\MimeType",
                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                "line": 17,
                "char": 47
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validator\\File\\Resolution\\Equal",
                "alias": "EqualResolution",
                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                "line": 18,
                "char": 74
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validator\\File\\Resolution\\Max",
                "alias": "MaxResolution",
                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                "line": 19,
                "char": 70
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validator\\File\\Resolution\\Min",
                "alias": "MinResolution",
                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                "line": 20,
                "char": 70
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
        "line": 21,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validator\\File\\Size\\Equal",
                "alias": "EqualFileSize",
                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                "line": 21,
                "char": 66
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
        "line": 22,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validator\\File\\Size\\Max",
                "alias": "MaxFileSize",
                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                "line": 22,
                "char": 62
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
        "line": 23,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validator\\File\\Size\\Min",
                "alias": "MinFileSize",
                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                "line": 23,
                "char": 62
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
        "line": 91,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Checks if a value has a correct file\n *\n * ```php\n * use Phalcon\\Validation\\Validation;\n * use Phalcon\\Validation\\Validator\\File as FileValidator;\n *\n * $validator = new Validation();\n *\n * $validator->add(\n *     \"file\",\n *     new FileValidator(\n *         [\n *             \"maxSize\"              => \"2M\",\n *             \"messageSize\"          => \":field exceeds the max filesize (:size)\",\n *             \"allowedTypes\"         => [\n *                 \"image\/jpeg\",\n *                 \"image\/png\",\n *             ],\n *             \"messageType\"          => \"Allowed file types are :types\",\n *             \"maxResolution\"        => \"800x600\",\n *             \"messageMaxResolution\" => \"Max resolution of :field is :resolution\",\n *         ]\n *     )\n * );\n *\n * $validator->add(\n *     [\n *         \"file\",\n *         \"anotherFile\",\n *     ],\n *     new FileValidator(\n *         [\n *             \"maxSize\" => [\n *                 \"file\"        => \"2M\",\n *                 \"anotherFile\" => \"4M\",\n *             ],\n *             \"messageSize\" => [\n *                 \"file\"        => \"file exceeds the max filesize 2M\",\n *                 \"anotherFile\" => \"anotherFile exceeds the max filesize 4M\",\n *             \"allowedTypes\" => [\n *                 \"file\"        => [\n *                     \"image\/jpeg\",\n *                     \"image\/png\",\n *                 ],\n *                 \"anotherFile\" => [\n *                     \"image\/gif\",\n *                     \"image\/bmp\",\n *                 ],\n *             ],\n *             \"messageType\" => [\n *                 \"file\"        => \"Allowed file types are image\/jpeg and image\/png\",\n *                 \"anotherFile\" => \"Allowed file types are image\/gif and image\/bmp\",\n *             ],\n *             \"maxResolution\" => [\n *                 \"file\"        => \"800x600\",\n *                 \"anotherFile\" => \"1024x768\",\n *             ],\n *             \"messageMaxResolution\" => [\n *                 \"file\"        => \"Max resolution of file is 800x600\",\n *                 \"anotherFile\" => \"Max resolution of file is 1024x768\",\n *             ],\n *         ]\n *     )\n * );\n * ```\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
        "line": 92,
        "char": 5
    },
    {
        "type": "class",
        "name": "File",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractValidatorComposite",
        "definition": {
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
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                "line": 97,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                            "line": 97,
                            "char": 52
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "included",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                        "line": 99,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                    "line": 99,
                                    "char": 28
                                },
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                    "line": 99,
                                    "char": 33
                                },
                                {
                                    "variable": "message",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                        "line": 99,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                    "line": 99,
                                    "char": 49
                                },
                                {
                                    "variable": "validator",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                    "line": 99,
                                    "char": 60
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                    "line": 99,
                                    "char": 67
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                            "line": 102,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "options",
                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                "line": 102,
                                "char": 35
                            },
                            "key": "key",
                            "value": "value",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "fcall",
                                            "name": "strcasecmp",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "key",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                        "line": 104,
                                                        "char": 30
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 104,
                                                    "char": 30
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "minSize",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                        "line": 104,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 104,
                                                    "char": 39
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                            "line": 104,
                                            "char": 43
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                            "line": 104,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                        "line": 104,
                                        "char": 47
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "message",
                                                    "expr": {
                                                        "type": "scall",
                                                        "dynamic-class": 0,
                                                        "class": "Arr",
                                                        "dynamic": 0,
                                                        "name": "get",
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "options",
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                    "line": 105,
                                                                    "char": 48
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 105,
                                                                "char": 48
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "messageMinSize",
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                    "line": 105,
                                                                    "char": 64
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 105,
                                                                "char": 64
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                        "line": 105,
                                                        "char": 65
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 105,
                                                    "char": 65
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "included",
                                                    "expr": {
                                                        "type": "scall",
                                                        "dynamic-class": 0,
                                                        "class": "Arr",
                                                        "dynamic": 0,
                                                        "name": "get",
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "options",
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                    "line": 106,
                                                                    "char": 48
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 106,
                                                                "char": 48
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "includedMinSize",
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                    "line": 106,
                                                                    "char": 65
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 106,
                                                                "char": 65
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                        "line": 106,
                                                        "char": 66
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 106,
                                                    "char": 66
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                            "line": 108,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "validator",
                                                    "expr": {
                                                        "type": "new",
                                                        "class": "MinFileSize",
                                                        "dynamic": 0,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "array",
                                                                    "left": [
                                                                        {
                                                                            "key": {
                                                                                "type": "string",
                                                                                "value": "size",
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                "line": 110,
                                                                                "char": 34
                                                                            },
                                                                            "value": {
                                                                                "type": "variable",
                                                                                "value": "value",
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                "line": 110,
                                                                                "char": 41
                                                                            },
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                            "line": 110,
                                                                            "char": 41
                                                                        },
                                                                        {
                                                                            "key": {
                                                                                "type": "string",
                                                                                "value": "message",
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                "line": 111,
                                                                                "char": 34
                                                                            },
                                                                            "value": {
                                                                                "type": "variable",
                                                                                "value": "message",
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                "line": 111,
                                                                                "char": 43
                                                                            },
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                            "line": 111,
                                                                            "char": 43
                                                                        },
                                                                        {
                                                                            "key": {
                                                                                "type": "string",
                                                                                "value": "included",
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                "line": 112,
                                                                                "char": 34
                                                                            },
                                                                            "value": {
                                                                                "type": "variable",
                                                                                "value": "included",
                                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                "line": 113,
                                                                                "char": 21
                                                                            },
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                            "line": 113,
                                                                            "char": 21
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                    "line": 114,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 114,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                        "line": 114,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 114,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                            "line": 116,
                                            "char": 21
                                        },
                                        {
                                            "type": "unset",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 116,
                                                    "char": 30
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "messageMinSize",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 116,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                "line": 116,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                            "line": 117,
                                            "char": 21
                                        },
                                        {
                                            "type": "unset",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 117,
                                                    "char": 30
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "includedMinSize",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 117,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                "line": 117,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                            "line": 118,
                                            "char": 13
                                        }
                                    ],
                                    "elseif_statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "strcasecmp",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "key",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 121,
                                                                "char": 34
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 121,
                                                            "char": 34
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "maxSize",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 121,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 121,
                                                            "char": 43
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 121,
                                                    "char": 47
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 121,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                "line": 121,
                                                "char": 51
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "message",
                                                            "expr": {
                                                                "type": "scall",
                                                                "dynamic-class": 0,
                                                                "class": "Arr",
                                                                "dynamic": 0,
                                                                "name": "get",
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "options",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                            "line": 122,
                                                                            "char": 48
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                        "line": 122,
                                                                        "char": 48
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "messageSize",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                            "line": 122,
                                                                            "char": 61
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                        "line": 122,
                                                                        "char": 61
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 122,
                                                                "char": 62
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 122,
                                                            "char": 62
                                                        },
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "included",
                                                            "expr": {
                                                                "type": "scall",
                                                                "dynamic-class": 0,
                                                                "class": "Arr",
                                                                "dynamic": 0,
                                                                "name": "get",
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "options",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                            "line": 123,
                                                                            "char": 48
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                        "line": 123,
                                                                        "char": 48
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "includedSize",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                            "line": 123,
                                                                            "char": 62
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                        "line": 123,
                                                                        "char": 62
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 123,
                                                                "char": 63
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 123,
                                                            "char": 63
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 125,
                                                    "char": 19
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "validator",
                                                            "expr": {
                                                                "type": "new",
                                                                "class": "MaxFileSize",
                                                                "dynamic": 0,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "array",
                                                                            "left": [
                                                                                {
                                                                                    "key": {
                                                                                        "type": "string",
                                                                                        "value": "size",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 127,
                                                                                        "char": 35
                                                                                    },
                                                                                    "value": {
                                                                                        "type": "variable",
                                                                                        "value": "value",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 127,
                                                                                        "char": 42
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                    "line": 127,
                                                                                    "char": 42
                                                                                },
                                                                                {
                                                                                    "key": {
                                                                                        "type": "string",
                                                                                        "value": "message",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 128,
                                                                                        "char": 34
                                                                                    },
                                                                                    "value": {
                                                                                        "type": "variable",
                                                                                        "value": "message",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 128,
                                                                                        "char": 43
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                    "line": 128,
                                                                                    "char": 43
                                                                                },
                                                                                {
                                                                                    "key": {
                                                                                        "type": "string",
                                                                                        "value": "included",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 129,
                                                                                        "char": 34
                                                                                    },
                                                                                    "value": {
                                                                                        "type": "variable",
                                                                                        "value": "included",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 130,
                                                                                        "char": 21
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                    "line": 130,
                                                                                    "char": 21
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                            "line": 131,
                                                                            "char": 17
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                        "line": 131,
                                                                        "char": 17
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 131,
                                                                "char": 18
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 131,
                                                            "char": 18
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 133,
                                                    "char": 21
                                                },
                                                {
                                                    "type": "unset",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 133,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "maxSize",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 133,
                                                            "char": 38
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                        "line": 133,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 134,
                                                    "char": 21
                                                },
                                                {
                                                    "type": "unset",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 134,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "messageSize",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 134,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                        "line": 134,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 135,
                                                    "char": 21
                                                },
                                                {
                                                    "type": "unset",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 135,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "includedSize",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 135,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                        "line": 135,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 136,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                            "line": 139,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "strcasecmp",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "key",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 139,
                                                                "char": 34
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 139,
                                                            "char": 34
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "equalSize",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 139,
                                                                "char": 45
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 139,
                                                            "char": 45
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 139,
                                                    "char": 49
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 139,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                "line": 139,
                                                "char": 53
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "message",
                                                            "expr": {
                                                                "type": "scall",
                                                                "dynamic-class": 0,
                                                                "class": "Arr",
                                                                "dynamic": 0,
                                                                "name": "get",
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "options",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                            "line": 140,
                                                                            "char": 47
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                        "line": 140,
                                                                        "char": 47
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "messageEqualSize",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                            "line": 140,
                                                                            "char": 65
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                        "line": 140,
                                                                        "char": 65
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 140,
                                                                "char": 66
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 140,
                                                            "char": 66
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 142,
                                                    "char": 19
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "validator",
                                                            "expr": {
                                                                "type": "new",
                                                                "class": "EqualFileSize",
                                                                "dynamic": 0,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "array",
                                                                            "left": [
                                                                                {
                                                                                    "key": {
                                                                                        "type": "string",
                                                                                        "value": "size",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 144,
                                                                                        "char": 33
                                                                                    },
                                                                                    "value": {
                                                                                        "type": "variable",
                                                                                        "value": "value",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 144,
                                                                                        "char": 40
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                    "line": 144,
                                                                                    "char": 40
                                                                                },
                                                                                {
                                                                                    "key": {
                                                                                        "type": "string",
                                                                                        "value": "message",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 145,
                                                                                        "char": 33
                                                                                    },
                                                                                    "value": {
                                                                                        "type": "variable",
                                                                                        "value": "message",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 146,
                                                                                        "char": 21
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                    "line": 146,
                                                                                    "char": 21
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                            "line": 147,
                                                                            "char": 17
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                        "line": 147,
                                                                        "char": 17
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 147,
                                                                "char": 18
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 147,
                                                            "char": 18
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 149,
                                                    "char": 21
                                                },
                                                {
                                                    "type": "unset",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 149,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "equalSize",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 149,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                        "line": 149,
                                                        "char": 41
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 150,
                                                    "char": 21
                                                },
                                                {
                                                    "type": "unset",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 150,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "messageEqualSize",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 150,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                        "line": 150,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 151,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                            "line": 154,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "strcasecmp",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "key",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 154,
                                                                "char": 34
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 154,
                                                            "char": 34
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "allowedTypes",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 154,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 154,
                                                            "char": 48
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 154,
                                                    "char": 52
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 154,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                "line": 154,
                                                "char": 56
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "message",
                                                            "expr": {
                                                                "type": "scall",
                                                                "dynamic-class": 0,
                                                                "class": "Arr",
                                                                "dynamic": 0,
                                                                "name": "get",
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "options",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                            "line": 155,
                                                                            "char": 47
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                        "line": 155,
                                                                        "char": 47
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "messageType",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                            "line": 155,
                                                                            "char": 60
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                        "line": 155,
                                                                        "char": 60
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 155,
                                                                "char": 61
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 155,
                                                            "char": 61
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 157,
                                                    "char": 19
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "validator",
                                                            "expr": {
                                                                "type": "new",
                                                                "class": "MimeType",
                                                                "dynamic": 0,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "array",
                                                                            "left": [
                                                                                {
                                                                                    "key": {
                                                                                        "type": "string",
                                                                                        "value": "types",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 159,
                                                                                        "char": 33
                                                                                    },
                                                                                    "value": {
                                                                                        "type": "variable",
                                                                                        "value": "value",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 159,
                                                                                        "char": 40
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                    "line": 159,
                                                                                    "char": 40
                                                                                },
                                                                                {
                                                                                    "key": {
                                                                                        "type": "string",
                                                                                        "value": "message",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 160,
                                                                                        "char": 33
                                                                                    },
                                                                                    "value": {
                                                                                        "type": "variable",
                                                                                        "value": "message",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 161,
                                                                                        "char": 21
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                    "line": 161,
                                                                                    "char": 21
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                            "line": 162,
                                                                            "char": 17
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                        "line": 162,
                                                                        "char": 17
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 162,
                                                                "char": 18
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 162,
                                                            "char": 18
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 164,
                                                    "char": 21
                                                },
                                                {
                                                    "type": "unset",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 164,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "allowedTypes",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 164,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                        "line": 164,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 165,
                                                    "char": 21
                                                },
                                                {
                                                    "type": "unset",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 165,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "messageType",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 165,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                        "line": 165,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 166,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                            "line": 169,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "strcasecmp",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "key",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 169,
                                                                "char": 34
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 169,
                                                            "char": 34
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "maxResolution",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 169,
                                                                "char": 49
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 169,
                                                            "char": 49
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 169,
                                                    "char": 53
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 169,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                "line": 169,
                                                "char": 57
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "message",
                                                            "expr": {
                                                                "type": "scall",
                                                                "dynamic-class": 0,
                                                                "class": "Arr",
                                                                "dynamic": 0,
                                                                "name": "get",
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "options",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                            "line": 170,
                                                                            "char": 48
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                        "line": 170,
                                                                        "char": 48
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "messageMaxResolution",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                            "line": 170,
                                                                            "char": 70
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                        "line": 170,
                                                                        "char": 70
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 170,
                                                                "char": 71
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 170,
                                                            "char": 71
                                                        },
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "included",
                                                            "expr": {
                                                                "type": "scall",
                                                                "dynamic-class": 0,
                                                                "class": "Arr",
                                                                "dynamic": 0,
                                                                "name": "get",
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "options",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                            "line": 171,
                                                                            "char": 48
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                        "line": 171,
                                                                        "char": 48
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "includedMaxResolution",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                            "line": 171,
                                                                            "char": 71
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                        "line": 171,
                                                                        "char": 71
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 171,
                                                                "char": 72
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 171,
                                                            "char": 72
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 173,
                                                    "char": 19
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "validator",
                                                            "expr": {
                                                                "type": "new",
                                                                "class": "MaxResolution",
                                                                "dynamic": 0,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "array",
                                                                            "left": [
                                                                                {
                                                                                    "key": {
                                                                                        "type": "string",
                                                                                        "value": "resolution",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 175,
                                                                                        "char": 36
                                                                                    },
                                                                                    "value": {
                                                                                        "type": "variable",
                                                                                        "value": "value",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 175,
                                                                                        "char": 43
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                    "line": 175,
                                                                                    "char": 43
                                                                                },
                                                                                {
                                                                                    "key": {
                                                                                        "type": "string",
                                                                                        "value": "included",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 176,
                                                                                        "char": 36
                                                                                    },
                                                                                    "value": {
                                                                                        "type": "variable",
                                                                                        "value": "included",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 176,
                                                                                        "char": 46
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                    "line": 176,
                                                                                    "char": 46
                                                                                },
                                                                                {
                                                                                    "key": {
                                                                                        "type": "string",
                                                                                        "value": "message",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 177,
                                                                                        "char": 36
                                                                                    },
                                                                                    "value": {
                                                                                        "type": "variable",
                                                                                        "value": "message",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 178,
                                                                                        "char": 21
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                    "line": 178,
                                                                                    "char": 21
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                            "line": 179,
                                                                            "char": 17
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                        "line": 179,
                                                                        "char": 17
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 179,
                                                                "char": 18
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 179,
                                                            "char": 18
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 181,
                                                    "char": 21
                                                },
                                                {
                                                    "type": "unset",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 181,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "maxResolution",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 181,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                        "line": 181,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 182,
                                                    "char": 21
                                                },
                                                {
                                                    "type": "unset",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 182,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "includedMaxResolution",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 182,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                        "line": 182,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 183,
                                                    "char": 21
                                                },
                                                {
                                                    "type": "unset",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 183,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "messageMaxResolution",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 183,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                        "line": 183,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 184,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                            "line": 187,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "strcasecmp",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "key",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 187,
                                                                "char": 34
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 187,
                                                            "char": 34
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "minResolution",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 187,
                                                                "char": 49
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 187,
                                                            "char": 49
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 187,
                                                    "char": 53
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 187,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                "line": 187,
                                                "char": 57
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "message",
                                                            "expr": {
                                                                "type": "scall",
                                                                "dynamic-class": 0,
                                                                "class": "Arr",
                                                                "dynamic": 0,
                                                                "name": "get",
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "options",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                            "line": 188,
                                                                            "char": 48
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                        "line": 188,
                                                                        "char": 48
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "messageMinResolution",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                            "line": 188,
                                                                            "char": 70
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                        "line": 188,
                                                                        "char": 70
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 188,
                                                                "char": 71
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 188,
                                                            "char": 71
                                                        },
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "included",
                                                            "expr": {
                                                                "type": "scall",
                                                                "dynamic-class": 0,
                                                                "class": "Arr",
                                                                "dynamic": 0,
                                                                "name": "get",
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "options",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                            "line": 189,
                                                                            "char": 48
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                        "line": 189,
                                                                        "char": 48
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "includedMinResolution",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                            "line": 189,
                                                                            "char": 71
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                        "line": 189,
                                                                        "char": 71
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 189,
                                                                "char": 72
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 189,
                                                            "char": 72
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 191,
                                                    "char": 19
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "validator",
                                                            "expr": {
                                                                "type": "new",
                                                                "class": "MinResolution",
                                                                "dynamic": 0,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "array",
                                                                            "left": [
                                                                                {
                                                                                    "key": {
                                                                                        "type": "string",
                                                                                        "value": "resolution",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 193,
                                                                                        "char": 36
                                                                                    },
                                                                                    "value": {
                                                                                        "type": "variable",
                                                                                        "value": "value",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 193,
                                                                                        "char": 43
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                    "line": 193,
                                                                                    "char": 43
                                                                                },
                                                                                {
                                                                                    "key": {
                                                                                        "type": "string",
                                                                                        "value": "included",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 194,
                                                                                        "char": 36
                                                                                    },
                                                                                    "value": {
                                                                                        "type": "variable",
                                                                                        "value": "included",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 194,
                                                                                        "char": 46
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                    "line": 194,
                                                                                    "char": 46
                                                                                },
                                                                                {
                                                                                    "key": {
                                                                                        "type": "string",
                                                                                        "value": "message",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 195,
                                                                                        "char": 36
                                                                                    },
                                                                                    "value": {
                                                                                        "type": "variable",
                                                                                        "value": "message",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 196,
                                                                                        "char": 21
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                    "line": 196,
                                                                                    "char": 21
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                            "line": 197,
                                                                            "char": 17
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                        "line": 197,
                                                                        "char": 17
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 197,
                                                                "char": 18
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 197,
                                                            "char": 18
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 199,
                                                    "char": 21
                                                },
                                                {
                                                    "type": "unset",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 199,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "minResolution",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 199,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                        "line": 199,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 200,
                                                    "char": 21
                                                },
                                                {
                                                    "type": "unset",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 200,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "includedMinResolution",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 200,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                        "line": 200,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 201,
                                                    "char": 21
                                                },
                                                {
                                                    "type": "unset",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 201,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "messageMinResolution",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 201,
                                                            "char": 51
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                        "line": 201,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 202,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                            "line": 205,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "identical",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "strcasecmp",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "key",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 205,
                                                                "char": 34
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 205,
                                                            "char": 34
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "equalResolution",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 205,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 205,
                                                            "char": 51
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 205,
                                                    "char": 55
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 205,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                "line": 205,
                                                "char": 59
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "message",
                                                            "expr": {
                                                                "type": "scall",
                                                                "dynamic-class": 0,
                                                                "class": "Arr",
                                                                "dynamic": 0,
                                                                "name": "get",
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "options",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                            "line": 206,
                                                                            "char": 47
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                        "line": 206,
                                                                        "char": 47
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "messageEqualResolution",
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                            "line": 206,
                                                                            "char": 71
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                        "line": 206,
                                                                        "char": 71
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 206,
                                                                "char": 72
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 206,
                                                            "char": 72
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 208,
                                                    "char": 19
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "validator",
                                                            "expr": {
                                                                "type": "new",
                                                                "class": "EqualResolution",
                                                                "dynamic": 0,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "array",
                                                                            "left": [
                                                                                {
                                                                                    "key": {
                                                                                        "type": "string",
                                                                                        "value": "resolution",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 210,
                                                                                        "char": 36
                                                                                    },
                                                                                    "value": {
                                                                                        "type": "variable",
                                                                                        "value": "value",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 210,
                                                                                        "char": 43
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                    "line": 210,
                                                                                    "char": 43
                                                                                },
                                                                                {
                                                                                    "key": {
                                                                                        "type": "string",
                                                                                        "value": "message",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 211,
                                                                                        "char": 36
                                                                                    },
                                                                                    "value": {
                                                                                        "type": "variable",
                                                                                        "value": "message",
                                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                        "line": 212,
                                                                                        "char": 21
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                                    "line": 212,
                                                                                    "char": 21
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                            "line": 213,
                                                                            "char": 17
                                                                        },
                                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                        "line": 213,
                                                                        "char": 17
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                                "line": 213,
                                                                "char": 18
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 213,
                                                            "char": 18
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 215,
                                                    "char": 21
                                                },
                                                {
                                                    "type": "unset",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 215,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "equalResolution",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 215,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                        "line": 215,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 216,
                                                    "char": 21
                                                },
                                                {
                                                    "type": "unset",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "options",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 216,
                                                            "char": 30
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "messageEqualResolution",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                            "line": 216,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                        "line": 216,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                    "line": 217,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                            "line": 217,
                                            "char": 18
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "continue",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                            "line": 219,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                    "line": 221,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property-append",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "validators",
                                            "expr": {
                                                "type": "variable",
                                                "value": "validator",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                                "line": 221,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                            "line": 221,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                    "line": 222,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                            "line": 224,
                            "char": 14
                        },
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "__construct",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                            "line": 224,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                        "line": 224,
                                        "char": 36
                                    }
                                ],
                                "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                                "line": 224,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                            "line": 225,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Constructor\n     *",
                    "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
                    "line": 97,
                    "last-line": 226,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
            "line": 92,
            "char": 5
        },
        "file": "\/app\/phalcon\/Validation\/Validator\/File.zep",
        "line": 92,
        "char": 5
    }
]