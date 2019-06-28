[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Acl\/Component.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Acl",
        "file": "\/app\/phalcon\/Acl\/Component.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Acl\\Exception",
                "file": "\/app\/phalcon\/Acl\/Component.zep",
                "line": 13,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Acl\/Component.zep",
        "line": 17,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * This class defines component entity and its description\n *",
        "file": "\/app\/phalcon\/Acl\/Component.zep",
        "line": 18,
        "char": 5
    },
    {
        "type": "class",
        "name": "Component",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "ComponentInterface",
                "file": "\/app\/phalcon\/Acl\/Component.zep",
                "line": 19,
                "char": 1
            }
        ],
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "description",
                    "docblock": "**\n     * Component description\n     *\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Acl\/Component.zep",
                            "line": 25,
                            "char": 31
                        }
                    ],
                    "file": "\/app\/phalcon\/Acl\/Component.zep",
                    "line": 31,
                    "char": 6
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "property",
                    "name": "name",
                    "docblock": "**\n     * Component name\n     *\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Acl\/Component.zep",
                            "line": 32,
                            "char": 23
                        },
                        {
                            "type": "shortcut",
                            "name": "__toString",
                            "file": "\/app\/phalcon\/Acl\/Component.zep",
                            "line": 32,
                            "char": 36
                        }
                    ],
                    "file": "\/app\/phalcon\/Acl\/Component.zep",
                    "line": 36,
                    "char": 6
                }
            ],
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
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Component.zep",
                            "line": 37,
                            "char": 45
                        },
                        {
                            "type": "parameter",
                            "name": "description",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Acl\/Component.zep",
                                "line": 37,
                                "char": 72
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Component.zep",
                            "line": 37,
                            "char": 72
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "equals",
                                    "left": {
                                        "type": "variable",
                                        "value": "name",
                                        "file": "\/app\/phalcon\/Acl\/Component.zep",
                                        "line": 39,
                                        "char": 27
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "*",
                                        "file": "\/app\/phalcon\/Acl\/Component.zep",
                                        "line": 39,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Component.zep",
                                    "line": 39,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Acl\/Component.zep",
                                "line": 39,
                                "char": 31
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
                                                    "value": "Component name cannot be '*'",
                                                    "file": "\/app\/phalcon\/Acl\/Component.zep",
                                                    "line": 40,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Component.zep",
                                                "line": 40,
                                                "char": 61
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Acl\/Component.zep",
                                        "line": 40,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Component.zep",
                                    "line": 41,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Component.zep",
                            "line": 43,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "name",
                                    "expr": {
                                        "type": "variable",
                                        "value": "name",
                                        "file": "\/app\/phalcon\/Acl\/Component.zep",
                                        "line": 43,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Component.zep",
                                    "line": 43,
                                    "char": 30
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "description",
                                    "expr": {
                                        "type": "variable",
                                        "value": "description",
                                        "file": "\/app\/phalcon\/Acl\/Component.zep",
                                        "line": 44,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Component.zep",
                                    "line": 44,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Component.zep",
                            "line": 45,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Acl\\Component constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Acl\/Component.zep",
                        "line": 38,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Acl\/Component.zep",
                    "line": 37,
                    "last-line": 46,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Acl\/Component.zep",
            "line": 18,
            "char": 5
        },
        "file": "\/app\/phalcon\/Acl\/Component.zep",
        "line": 18,
        "char": 5
    }
]