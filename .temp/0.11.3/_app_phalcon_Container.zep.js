[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Container.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon",
        "file": "\/app\/phalcon\/Container.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Psr\\Container\\ContainerInterface",
                "file": "\/app\/phalcon\/Container.zep",
                "line": 13,
                "char": 37
            }
        ],
        "file": "\/app\/phalcon\/Container.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Container.zep",
                "line": 14,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Container.zep",
        "line": 18,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * PSR-11 Wrapper for `Phalcon\\Di`\n *",
        "file": "\/app\/phalcon\/Container.zep",
        "line": 19,
        "char": 5
    },
    {
        "type": "class",
        "name": "Container",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "ContainerInterface",
                "file": "\/app\/phalcon\/Container.zep",
                "line": 20,
                "char": 1
            }
        ],
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "container",
                    "docblock": "**\n     * @var <DiInterface>\n     *",
                    "file": "\/app\/phalcon\/Container.zep",
                    "line": 28,
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
                            "name": "container",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "DiInterface",
                                "file": "\/app\/phalcon\/Container.zep",
                                "line": 29,
                                "char": 55
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Container.zep",
                            "line": 29,
                            "char": 56
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "container",
                                    "expr": {
                                        "type": "variable",
                                        "value": "container",
                                        "file": "\/app\/phalcon\/Container.zep",
                                        "line": 31,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Container.zep",
                                    "line": 31,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Container.zep",
                            "line": 32,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Container constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Container.zep",
                        "line": 30,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Container.zep",
                    "line": 29,
                    "last-line": 36,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "get",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Container.zep",
                            "line": 37,
                            "char": 33
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Container.zep",
                                        "line": 39,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "container",
                                        "file": "\/app\/phalcon\/Container.zep",
                                        "line": 39,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Container.zep",
                                    "line": 39,
                                    "char": 32
                                },
                                "name": "getService",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Container.zep",
                                            "line": 39,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Container.zep",
                                        "line": 39,
                                        "char": 48
                                    }
                                ],
                                "file": "\/app\/phalcon\/Container.zep",
                                "line": 39,
                                "char": 49
                            },
                            "file": "\/app\/phalcon\/Container.zep",
                            "line": 40,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return the service\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Container.zep",
                                "line": 38,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Container.zep",
                        "line": 38,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Container.zep",
                    "line": 37,
                    "last-line": 44,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "has",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Container.zep",
                            "line": 45,
                            "char": 33
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Container.zep",
                                        "line": 47,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "container",
                                        "file": "\/app\/phalcon\/Container.zep",
                                        "line": 47,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Container.zep",
                                    "line": 47,
                                    "char": 32
                                },
                                "name": "has",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "name",
                                            "file": "\/app\/phalcon\/Container.zep",
                                            "line": 47,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Container.zep",
                                        "line": 47,
                                        "char": 41
                                    }
                                ],
                                "file": "\/app\/phalcon\/Container.zep",
                                "line": 47,
                                "char": 42
                            },
                            "file": "\/app\/phalcon\/Container.zep",
                            "line": 48,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Whether a service exists or not in the container\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Container.zep",
                                "line": 46,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Container.zep",
                        "line": 46,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Container.zep",
                    "line": 45,
                    "last-line": 49,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Container.zep",
            "line": 19,
            "char": 5
        },
        "file": "\/app\/phalcon\/Container.zep",
        "line": 19,
        "char": 5
    }
]