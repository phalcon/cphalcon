[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Validation\\Validator",
        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\Validation",
                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                "line": 13,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\AbstractValidator",
                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                "line": 14,
                "char": 41
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\Message",
                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                "line": 15,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
        "line": 67,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Check for IP addresses\n *\n * ```php\n * use Phalcon\\Validation\\Validator\\Ip as IpValidator;\n *\n * $validator->add(\n *     \"ip_address\",\n *     new IpValidator(\n *         [\n *             \"message\"       => \":field must contain only ip addresses\",\n *             \"version\"       => IP::VERSION_4 | IP::VERSION_6, \/\/ v6 and v4. The same if not specified\n *             \"allowReserved\" => false,   \/\/ False if not specified. Ignored for v6\n *             \"allowPrivate\"  => false,   \/\/ False if not specified\n *             \"allowEmpty\"    => false,\n *         ]\n *     )\n * );\n *\n * $validator->add(\n *     [\n *         \"source_address\",\n *         \"destination_address\",\n *     ],\n *     new IpValidator(\n *         [\n *             \"message\" => [\n *                 \"source_address\"      => \"source_address must be a valid IP address\",\n *                 \"destination_address\" => \"destination_address must be a valid IP address\",\n *             ],\n *             \"version\" => [\n *                  \"source_address\"      => Ip::VERSION_4 | IP::VERSION_6,\n *                  \"destination_address\" => Ip::VERSION_4,\n *             ],\n *             \"allowReserved\" => [\n *                  \"source_address\"      => false,\n *                  \"destination_address\" => true,\n *             ],\n *             \"allowPrivate\" => [\n *                  \"source_address\"      => false,\n *                  \"destination_address\" => true,\n *             ],\n *             \"allowEmpty\" => [\n *                  \"source_address\"      => false,\n *                  \"destination_address\" => true,\n *             ],\n *         ]\n *     )\n * );\n * ```\n *",
        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
        "line": 68,
        "char": 5
    },
    {
        "type": "class",
        "name": "Ip",
        "abstract": 0,
        "final": 0,
        "extends": "AbstractValidator",
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
                        "value": "Field :field must be a valid IP address",
                        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                        "line": 73,
                        "char": 65
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                    "line": 77,
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                "line": 78,
                                "char": 52
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                            "line": 78,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                            "line": 78,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 80,
                                    "char": 18
                                },
                                {
                                    "variable": "version",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 80,
                                    "char": 27
                                },
                                {
                                    "variable": "allowPrivate",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 80,
                                    "char": 41
                                },
                                {
                                    "variable": "allowReserved",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 80,
                                    "char": 56
                                },
                                {
                                    "variable": "allowEmpty",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 80,
                                    "char": 68
                                },
                                {
                                    "variable": "options",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 80,
                                    "char": 77
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                            "line": 82,
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
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
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
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                    "line": 82,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                "line": 82,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                        "line": 82,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 82,
                                    "char": 48
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "version",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                            "line": 83,
                                            "char": 28
                                        },
                                        "name": "getOption",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "version",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                    "line": 83,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                "line": 83,
                                                "char": 46
                                            },
                                            {
                                                "parameter": {
                                                    "type": "bitwise_or",
                                                    "left": {
                                                        "type": "constant",
                                                        "value": "FILTER_FLAG_IPV4",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                        "line": 83,
                                                        "char": 65
                                                    },
                                                    "right": {
                                                        "type": "constant",
                                                        "value": "FILTER_FLAG_IPV6",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                        "line": 83,
                                                        "char": 83
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                    "line": 83,
                                                    "char": 83
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                "line": 83,
                                                "char": 83
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                        "line": 83,
                                        "char": 84
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 83,
                                    "char": 84
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
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
                                        "value": "version",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                        "line": 85,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 85,
                                    "char": 28
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 85,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                "line": 85,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "version",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "version",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                    "line": 86,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                    "line": 86,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                "line": 86,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                            "line": 86,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 87,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                            "line": 89,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "allowPrivate",
                                    "expr": {
                                        "type": "ternary",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                "line": 89,
                                                "char": 33
                                            },
                                            "name": "getOption",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "allowPrivate",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                        "line": 89,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                    "line": 89,
                                                    "char": 56
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                            "line": 89,
                                            "char": 58
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                            "line": 89,
                                            "char": 62
                                        },
                                        "extra": {
                                            "type": "constant",
                                            "value": "FILTER_FLAG_NO_PRIV_RANGE",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                            "line": 89,
                                            "char": 89
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                        "line": 89,
                                        "char": 89
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 89,
                                    "char": 89
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                            "line": 91,
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
                                        "value": "allowPrivate",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                        "line": 91,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 91,
                                    "char": 33
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 91,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                "line": 91,
                                "char": 41
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "allowPrivate",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "allowPrivate",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                    "line": 92,
                                                    "char": 44
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                    "line": 92,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                "line": 92,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                            "line": 92,
                                            "char": 51
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 93,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                            "line": 95,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "allowReserved",
                                    "expr": {
                                        "type": "ternary",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                "line": 95,
                                                "char": 34
                                            },
                                            "name": "getOption",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "allowReserved",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                        "line": 95,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                    "line": 95,
                                                    "char": 58
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                            "line": 95,
                                            "char": 60
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                            "line": 95,
                                            "char": 64
                                        },
                                        "extra": {
                                            "type": "constant",
                                            "value": "FILTER_FLAG_NO_RES_RANGE",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                            "line": 95,
                                            "char": 90
                                        },
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                        "line": 95,
                                        "char": 90
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 95,
                                    "char": 90
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                            "line": 97,
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
                                        "value": "allowReserved",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                        "line": 97,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 97,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 97,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                "line": 97,
                                "char": 42
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "allowReserved",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "allowReserved",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                    "line": 98,
                                                    "char": 46
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "field",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                    "line": 98,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                "line": 98,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                            "line": 98,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 99,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                            "line": 101,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "allowEmpty",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                            "line": 101,
                                            "char": 31
                                        },
                                        "name": "getOption",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "allowEmpty",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                    "line": 101,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                "line": 101,
                                                "char": 52
                                            },
                                            {
                                                "parameter": {
                                                    "type": "bool",
                                                    "value": "false",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                    "line": 101,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                "line": 101,
                                                "char": 59
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                        "line": 101,
                                        "char": 60
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 101,
                                    "char": 60
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                            "line": 103,
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
                                        "value": "allowEmpty",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                        "line": 103,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 103,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 103,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                "line": 103,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "allowEmpty",
                                            "expr": {
                                                "type": "ternary",
                                                "left": {
                                                    "type": "isset",
                                                    "left": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "allowEmpty",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                            "line": 104,
                                                            "char": 46
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "field",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                            "line": 104,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                        "line": 104,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                    "line": 104,
                                                    "char": 54
                                                },
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "allowEmpty",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                        "line": 104,
                                                        "char": 66
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "field",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                        "line": 104,
                                                        "char": 72
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                    "line": 104,
                                                    "char": 74
                                                },
                                                "extra": {
                                                    "type": "bool",
                                                    "value": "false",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                    "line": 104,
                                                    "char": 81
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                "line": 104,
                                                "char": 81
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                            "line": 104,
                                            "char": 81
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 105,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                            "line": 107,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "variable",
                                    "value": "allowEmpty",
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 107,
                                    "char": 24
                                },
                                "right": {
                                    "type": "empty",
                                    "left": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                        "line": 107,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 107,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                "line": 107,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                        "line": 108,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 109,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                            "line": 111,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "options",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "options",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                    "line": 112,
                                                    "char": 20
                                                },
                                                "value": {
                                                    "type": "array",
                                                    "left": [
                                                        {
                                                            "key": {
                                                                "type": "string",
                                                                "value": "default",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                                "line": 113,
                                                                "char": 24
                                                            },
                                                            "value": {
                                                                "type": "bool",
                                                                "value": "false",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                                "line": 114,
                                                                "char": 13
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                            "line": 114,
                                                            "char": 13
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                    "line": 114,
                                                    "char": 14
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                "line": 114,
                                                "char": 14
                                            },
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "flags",
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                    "line": 115,
                                                    "char": 18
                                                },
                                                "value": {
                                                    "type": "bitwise_or",
                                                    "left": {
                                                        "type": "bitwise_or",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "version",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                            "line": 115,
                                                            "char": 28
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "allowPrivate",
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                            "line": 115,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                        "line": 115,
                                                        "char": 43
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "allowReserved",
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                        "line": 116,
                                                        "char": 9
                                                    },
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                    "line": 116,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                "line": 116,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                        "line": 116,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 116,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                            "line": 118,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fcall",
                                    "name": "filter_var",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                "line": 118,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                            "line": 118,
                                            "char": 29
                                        },
                                        {
                                            "parameter": {
                                                "type": "constant",
                                                "value": "FILTER_VALIDATE_IP",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                "line": 118,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                            "line": 118,
                                            "char": 49
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "options",
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                "line": 118,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                            "line": 118,
                                            "char": 58
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 118,
                                    "char": 60
                                },
                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                "line": 118,
                                "char": 60
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "validation",
                                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                            "line": 119,
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
                                                        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                        "line": 120,
                                                        "char": 22
                                                    },
                                                    "name": "messageFactory",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "validation",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                                "line": 120,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                            "line": 120,
                                                            "char": 48
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "field",
                                                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                                "line": 120,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                            "line": 120,
                                                            "char": 55
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                    "line": 121,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                                "line": 121,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                        "line": 121,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 123,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                        "line": 123,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                    "line": 124,
                                    "char": 8
                                }
                            ],
                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                            "line": 126,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                "line": 126,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                            "line": 127,
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
                                "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                                "line": 79,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                        "line": 79,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                    "line": 78,
                    "last-line": 128,
                    "char": 19
                }
            ],
            "constants": [
                {
                    "type": "const",
                    "name": "VERSION_4",
                    "default": {
                        "type": "constant",
                        "value": "FILTER_FLAG_IPV4",
                        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                        "line": 70,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                    "line": 71,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "VERSION_6",
                    "default": {
                        "type": "constant",
                        "value": "FILTER_FLAG_IPV6",
                        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                        "line": 71,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
                    "line": 73,
                    "char": 13
                }
            ],
            "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
            "line": 68,
            "char": 5
        },
        "file": "\/app\/phalcon\/Validation\/Validator\/Ip.zep",
        "line": 68,
        "char": 5
    }
]