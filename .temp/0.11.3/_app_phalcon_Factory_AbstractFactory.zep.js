[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Factory",
        "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Config\\Config",
                "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                "line": 13,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Factory\\Exception",
                "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                "line": 14,
                "char": 30
            }
        ],
        "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
        "line": 16,
        "char": 5
    },
    {
        "type": "class",
        "name": "AbstractFactory",
        "abstract": 0,
        "final": 0,
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "mapper",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                        "line": 21,
                        "char": 26
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                    "line": 25,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "services",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                        "line": 26,
                        "char": 28
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                    "line": 30,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "checkService",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                            "line": 31,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "isset",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                                    "line": 33,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "mapper",
                                                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                                    "line": 33,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                                "line": 33,
                                                "char": 40
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                                "line": 33,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                            "line": 33,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                        "line": 33,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                    "line": 33,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                "line": 33,
                                "char": 47
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
                                                            "value": "Service ",
                                                            "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                                            "line": 34,
                                                            "char": 42
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                                            "line": 34,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                                        "line": 34,
                                                        "char": 49
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": " is not registered",
                                                        "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                                        "line": 34,
                                                        "char": 69
                                                    },
                                                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                                    "line": 34,
                                                    "char": 69
                                                },
                                                "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                                "line": 34,
                                                "char": 69
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                        "line": 34,
                                        "char": 70
                                    },
                                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                    "line": 35,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                            "line": 36,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks if a service exists and throws an exception\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                        "line": 32,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                    "line": 31,
                    "last-line": 40,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "checkConfig",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "config",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                            "line": 41,
                            "char": 46
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "config",
                                            "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                            "line": 43,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                        "line": 43,
                                        "char": 27
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                        "line": 43,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                    "line": 43,
                                    "char": 37
                                },
                                "right": {
                                    "type": "instanceof",
                                    "left": {
                                        "type": "variable",
                                        "value": "config",
                                        "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                        "line": 43,
                                        "char": 55
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "Config",
                                        "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                        "line": 43,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                    "line": 43,
                                    "char": 64
                                },
                                "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                "line": 43,
                                "char": 64
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "config",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "config",
                                                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                                    "line": 44,
                                                    "char": 33
                                                },
                                                "name": "toArray",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                                "line": 44,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                            "line": 44,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                    "line": 45,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                            "line": 47,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not-identical",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "config",
                                            "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                            "line": 47,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                        "line": 47,
                                        "char": 37
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                        "line": 47,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                    "line": 47,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                "line": 47,
                                "char": 45
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
                                                    "value": "Config must be array or Phalcon\\\\Config object",
                                                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                                    "line": 50,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                                "line": 50,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                        "line": 50,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                    "line": 51,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                            "line": 53,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "isset",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "config",
                                                "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                                "line": 53,
                                                "char": 34
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "adapter",
                                                "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                                "line": 53,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                            "line": 53,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                        "line": 53,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                    "line": 53,
                                    "char": 44
                                },
                                "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                "line": 53,
                                "char": 44
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
                                                    "value": "You must provide 'adapter' option in factory config parameter.",
                                                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                                    "line": 56,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                                "line": 56,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                        "line": 56,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                    "line": 57,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                            "line": 59,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "config",
                                "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                "line": 59,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                            "line": 60,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks the config if it is a valid object\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                "line": 42,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                        "line": 42,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                    "line": 41,
                    "last-line": 64,
                    "char": 22
                },
                {
                    "visibility": [
                        "abstract",
                        "protected"
                    ],
                    "type": "method",
                    "name": "getAdapters",
                    "docblock": "**\n     * Returns the adapters for the factory\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                "line": 65,
                                "char": 55
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                        "line": 65,
                        "char": 55
                    },
                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                    "line": 65,
                    "last-line": 69,
                    "char": 31
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "init",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "services",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                "line": 70,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                            "line": 70,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "adapters",
                                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                    "line": 72,
                                    "char": 21
                                },
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                    "line": 72,
                                    "char": 27
                                },
                                {
                                    "variable": "service",
                                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                    "line": 72,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                            "line": 74,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "adapters",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                            "line": 74,
                                            "char": 29
                                        },
                                        "name": "getAdapters",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                        "line": 74,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                    "line": 74,
                                    "char": 43
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "adapters",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "array_merge",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "adapters",
                                                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                                    "line": 75,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                                "line": 75,
                                                "char": 44
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "services",
                                                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                                    "line": 75,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                                "line": 75,
                                                "char": 54
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                        "line": 75,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                    "line": 75,
                                    "char": 55
                                }
                            ],
                            "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                            "line": 77,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "adapters",
                                "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                "line": 77,
                                "char": 39
                            },
                            "key": "name",
                            "value": "service",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property-array-index",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "mapper",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                                    "line": 78,
                                                    "char": 34
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "service",
                                                "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                                "line": 78,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                            "line": 78,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                    "line": 79,
                                    "char": 17
                                },
                                {
                                    "type": "unset",
                                    "expr": {
                                        "type": "list",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                                    "line": 79,
                                                    "char": 24
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "services",
                                                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                                    "line": 79,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                                "line": 79,
                                                "char": 33
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                                "line": 79,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                            "line": 79,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                        "line": 79,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                                    "line": 80,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                            "line": 81,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * AdapterFactory constructor.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                        "line": 71,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
                    "line": 70,
                    "last-line": 82,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
            "line": 16,
            "char": 5
        },
        "file": "\/app\/phalcon\/Factory\/AbstractFactory.zep",
        "line": 16,
        "char": 5
    }
]