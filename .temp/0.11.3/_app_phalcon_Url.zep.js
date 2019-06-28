[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Url.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon",
        "file": "\/app\/phalcon\/Url.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Url.zep",
                "line": 13,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Url.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\UrlInterface",
                "file": "\/app\/phalcon\/Url.zep",
                "line": 14,
                "char": 25
            }
        ],
        "file": "\/app\/phalcon\/Url.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Url\\Exception",
                "file": "\/app\/phalcon\/Url.zep",
                "line": 15,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Url.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\RouterInterface",
                "file": "\/app\/phalcon\/Url.zep",
                "line": 16,
                "char": 32
            }
        ],
        "file": "\/app\/phalcon\/Url.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Router\\RouteInterface",
                "file": "\/app\/phalcon\/Url.zep",
                "line": 17,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Url.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\InjectionAwareInterface",
                "file": "\/app\/phalcon\/Url.zep",
                "line": 18,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Url.zep",
        "line": 36,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * This components helps in the generation of: URIs, URLs and Paths\n *\n *```php\n * \/\/ Generate a URL appending the URI to the base URI\n * echo $url->get(\"products\/edit\/1\");\n *\n * \/\/ Generate a URL for a predefined route\n * echo $url->get(\n *     [\n *         \"for\"   => \"blog-post\",\n *         \"title\" => \"some-cool-stuff\",\n *         \"year\"  => \"2012\",\n *     ]\n * );\n *```\n *",
        "file": "\/app\/phalcon\/Url.zep",
        "line": 37,
        "char": 5
    },
    {
        "type": "class",
        "name": "Url",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "UrlInterface",
                "file": "\/app\/phalcon\/Url.zep",
                "line": 37,
                "char": 34
            },
            {
                "type": "variable",
                "value": "InjectionAwareInterface",
                "file": "\/app\/phalcon\/Url.zep",
                "line": 38,
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
                    "name": "baseUri",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Url.zep",
                        "line": 42,
                        "char": 29
                    },
                    "docblock": "**\n     * @var null | string\n     *",
                    "file": "\/app\/phalcon\/Url.zep",
                    "line": 46,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "basePath",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Url.zep",
                        "line": 47,
                        "char": 30
                    },
                    "docblock": "**\n     * @var null | string\n     *",
                    "file": "\/app\/phalcon\/Url.zep",
                    "line": 51,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "container",
                    "docblock": "**\n     * @var <DiInterface>\n     *",
                    "file": "\/app\/phalcon\/Url.zep",
                    "line": 54,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "router",
                    "file": "\/app\/phalcon\/Url.zep",
                    "line": 58,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "staticBaseUri",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Url.zep",
                        "line": 59,
                        "char": 35
                    },
                    "docblock": "**\n     * @var null | string\n     *",
                    "file": "\/app\/phalcon\/Url.zep",
                    "line": 93,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "get",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "uri",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 94,
                                "char": 39
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 94,
                            "char": 39
                        },
                        {
                            "type": "parameter",
                            "name": "args",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 94,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 94,
                            "char": 56
                        },
                        {
                            "type": "parameter",
                            "name": "local",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 94,
                                "char": 75
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 94,
                            "char": 75
                        },
                        {
                            "type": "parameter",
                            "name": "baseUri",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 94,
                                "char": 95
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 94,
                            "char": 95
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "strUri",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 96,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 97,
                            "char": 11
                        },
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "router",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 97,
                                    "char": 19
                                },
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 97,
                                    "char": 30
                                },
                                {
                                    "variable": "routeName",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 97,
                                    "char": 41
                                },
                                {
                                    "variable": "route",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 97,
                                    "char": 48
                                },
                                {
                                    "variable": "queryString",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 97,
                                    "char": 61
                                }
                            ],
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 99,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "variable",
                                    "value": "local",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 99,
                                    "char": 19
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 99,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 99,
                                "char": 26
                            },
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
                                                    "value": "uri",
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 100,
                                                    "char": 28
                                                },
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 100,
                                                "char": 28
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "string",
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 100,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 100,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "list",
                                            "left": {
                                                "type": "or",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "memstr",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "uri",
                                                                "file": "\/app\/phalcon\/Url.zep",
                                                                "line": 100,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 100,
                                                            "char": 51
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "\/\/",
                                                                "file": "\/app\/phalcon\/Url.zep",
                                                                "line": 100,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 100,
                                                            "char": 55
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 100,
                                                    "char": 58
                                                },
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "memstr",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "uri",
                                                                "file": "\/app\/phalcon\/Url.zep",
                                                                "line": 100,
                                                                "char": 70
                                                            },
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 100,
                                                            "char": 70
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": ":",
                                                                "file": "\/app\/phalcon\/Url.zep",
                                                                "line": 100,
                                                                "char": 73
                                                            },
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 100,
                                                            "char": 73
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 100,
                                                    "char": 74
                                                },
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 100,
                                                "char": 74
                                            },
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 100,
                                            "char": 76
                                        },
                                        "file": "\/app\/phalcon\/Url.zep",
                                        "line": 100,
                                        "char": 76
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "preg_match",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "#^((\/\/)|([a-z0-9]+:\/\/)|([a-z0-9]+:))#i",
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 101,
                                                            "char": 69
                                                        },
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 101,
                                                        "char": 69
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "uri",
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 101,
                                                            "char": 74
                                                        },
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 101,
                                                        "char": 74
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 101,
                                                "char": 76
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "local",
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "false",
                                                                "file": "\/app\/phalcon\/Url.zep",
                                                                "line": 102,
                                                                "char": 38
                                                            },
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 102,
                                                            "char": 38
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 103,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "local",
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Url.zep",
                                                                "line": 104,
                                                                "char": 37
                                                            },
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 104,
                                                            "char": 37
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 105,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 106,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "local",
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "true",
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 107,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 107,
                                                    "char": 33
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 108,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 109,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 111,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "baseUri",
                                        "file": "\/app\/phalcon\/Url.zep",
                                        "line": 111,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 111,
                                    "char": 28
                                },
                                "right": {
                                    "type": "string",
                                    "value": "string",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 111,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 111,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "baseUri",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 112,
                                                    "char": 32
                                                },
                                                "name": "getBaseUri",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 112,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 112,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 113,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 115,
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
                                        "value": "uri",
                                        "file": "\/app\/phalcon\/Url.zep",
                                        "line": 115,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 115,
                                    "char": 24
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 115,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 115,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "not",
                                            "left": {
                                                "type": "fetch",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "routeName",
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 116,
                                                    "char": 52
                                                },
                                                "right": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "uri",
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 116,
                                                        "char": 46
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "for",
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 116,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 116,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 116,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 116,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Url.zep",
                                        "line": 116,
                                        "char": 52
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
                                                            "value": "It's necessary to define the route name with the parameter 'for'",
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 119,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 119,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 119,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 120,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 122,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "router",
                                            "expr": {
                                                "type": "type-hint",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "RouterInterface",
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 122,
                                                    "char": 56
                                                },
                                                "right": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 122,
                                                        "char": 49
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "router",
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 122,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 122,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 122,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 122,
                                            "char": 56
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 127,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "router",
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 127,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 127,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "object",
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 127,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Url.zep",
                                        "line": 127,
                                        "char": 40
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "container",
                                                    "expr": {
                                                        "type": "type-hint",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "DiInterface",
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 128,
                                                            "char": 62
                                                        },
                                                        "right": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Url.zep",
                                                                "line": 128,
                                                                "char": 52
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "container",
                                                                "file": "\/app\/phalcon\/Url.zep",
                                                                "line": 128,
                                                                "char": 62
                                                            },
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 128,
                                                            "char": 62
                                                        },
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 128,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 128,
                                                    "char": 62
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 130,
                                            "char": 18
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
                                                            "value": "container",
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 130,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 130,
                                                        "char": 47
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "object",
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 130,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 130,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 130,
                                                "char": 56
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
                                                                    "type": "scall",
                                                                    "dynamic-class": 0,
                                                                    "class": "Exception",
                                                                    "dynamic": 0,
                                                                    "name": "containerServiceNotFound",
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "string",
                                                                                "value": "the 'router' service",
                                                                                "file": "\/app\/phalcon\/Url.zep",
                                                                                "line": 134,
                                                                                "char": 25
                                                                            },
                                                                            "file": "\/app\/phalcon\/Url.zep",
                                                                            "line": 134,
                                                                            "char": 25
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Url.zep",
                                                                    "line": 135,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Url.zep",
                                                                "line": 135,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 135,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 136,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 138,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "router",
                                                    "expr": {
                                                        "type": "type-hint",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "RouterInterface",
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 138,
                                                            "char": 76
                                                        },
                                                        "right": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "container",
                                                                "file": "\/app\/phalcon\/Url.zep",
                                                                "line": 138,
                                                                "char": 58
                                                            },
                                                            "name": "getShared",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "string",
                                                                        "value": "router",
                                                                        "file": "\/app\/phalcon\/Url.zep",
                                                                        "line": 138,
                                                                        "char": 75
                                                                    },
                                                                    "file": "\/app\/phalcon\/Url.zep",
                                                                    "line": 138,
                                                                    "char": 75
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 138,
                                                            "char": 76
                                                        },
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 138,
                                                        "char": 76
                                                    },
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 138,
                                                    "char": 76
                                                },
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "router",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "router",
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 139,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 139,
                                                    "char": 42
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 140,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 145,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "route",
                                            "expr": {
                                                "type": "type-hint",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "RouteInterface",
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 145,
                                                    "char": 75
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "router",
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 145,
                                                        "char": 49
                                                    },
                                                    "name": "getRouteByName",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "routeName",
                                                                "file": "\/app\/phalcon\/Url.zep",
                                                                "line": 145,
                                                                "char": 74
                                                            },
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 145,
                                                            "char": 74
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 145,
                                                    "char": 75
                                                },
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 145,
                                                "char": 75
                                            },
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 145,
                                            "char": 75
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 147,
                                    "char": 14
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
                                                    "value": "route",
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 147,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 147,
                                                "char": 39
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 147,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 147,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Url.zep",
                                        "line": 147,
                                        "char": 48
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
                                                                    "value": "Cannot obtain a route using the name '",
                                                                    "file": "\/app\/phalcon\/Url.zep",
                                                                    "line": 149,
                                                                    "char": 60
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "routeName",
                                                                    "file": "\/app\/phalcon\/Url.zep",
                                                                    "line": 149,
                                                                    "char": 72
                                                                },
                                                                "file": "\/app\/phalcon\/Url.zep",
                                                                "line": 149,
                                                                "char": 72
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "'",
                                                                "file": "\/app\/phalcon\/Url.zep",
                                                                "line": 150,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 150,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 150,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 150,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 151,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 156,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "uri",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "phalcon_replace_paths",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "route",
                                                                "file": "\/app\/phalcon\/Url.zep",
                                                                "line": 157,
                                                                "char": 23
                                                            },
                                                            "name": "getPattern",
                                                            "call-type": 1,
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 157,
                                                            "char": 36
                                                        },
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 157,
                                                        "char": 36
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "mcall",
                                                            "variable": {
                                                                "type": "variable",
                                                                "value": "route",
                                                                "file": "\/app\/phalcon\/Url.zep",
                                                                "line": 158,
                                                                "char": 23
                                                            },
                                                            "name": "getReversedPaths",
                                                            "call-type": 1,
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 158,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 158,
                                                        "char": 42
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "uri",
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 160,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 160,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 160,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 160,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 161,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 163,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "local",
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 163,
                                "char": 18
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "strUri",
                                            "expr": {
                                                "type": "cast",
                                                "left": "string",
                                                "right": {
                                                    "type": "variable",
                                                    "value": "uri",
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 164,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 164,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 164,
                                            "char": 38
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 166,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "and",
                                            "left": {
                                                "type": "and",
                                                "left": {
                                                    "type": "equals",
                                                    "left": {
                                                        "type": "fcall",
                                                        "name": "substr",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "baseUri",
                                                                    "file": "\/app\/phalcon\/Url.zep",
                                                                    "line": 166,
                                                                    "char": 30
                                                                },
                                                                "file": "\/app\/phalcon\/Url.zep",
                                                                "line": 166,
                                                                "char": 30
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "int",
                                                                    "value": "-1",
                                                                    "file": "\/app\/phalcon\/Url.zep",
                                                                    "line": 166,
                                                                    "char": 34
                                                                },
                                                                "file": "\/app\/phalcon\/Url.zep",
                                                                "line": 166,
                                                                "char": 34
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 166,
                                                        "char": 37
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "\/",
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 166,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 166,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "greater",
                                                    "left": {
                                                        "type": "fcall",
                                                        "name": "strlen",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "strUri",
                                                                    "file": "\/app\/phalcon\/Url.zep",
                                                                    "line": 166,
                                                                    "char": 57
                                                                },
                                                                "file": "\/app\/phalcon\/Url.zep",
                                                                "line": 166,
                                                                "char": 57
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 166,
                                                        "char": 59
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "2",
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 166,
                                                        "char": 64
                                                    },
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 166,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 166,
                                                "char": 64
                                            },
                                            "right": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "strUri",
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 166,
                                                        "char": 72
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "0",
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 166,
                                                        "char": 74
                                                    },
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 166,
                                                    "char": 77
                                                },
                                                "right": {
                                                    "type": "char",
                                                    "value": "\/",
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 166,
                                                    "char": 83
                                                },
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 166,
                                                "char": 83
                                            },
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 166,
                                            "char": 83
                                        },
                                        "right": {
                                            "type": "not-equals",
                                            "left": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "strUri",
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 166,
                                                    "char": 91
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 166,
                                                    "char": 93
                                                },
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 166,
                                                "char": 96
                                            },
                                            "right": {
                                                "type": "char",
                                                "value": "\/",
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 166,
                                                "char": 101
                                            },
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 166,
                                            "char": 101
                                        },
                                        "file": "\/app\/phalcon\/Url.zep",
                                        "line": 166,
                                        "char": 101
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "uri",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "baseUri",
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 167,
                                                            "char": 35
                                                        },
                                                        "right": {
                                                            "type": "fcall",
                                                            "name": "substr",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "strUri",
                                                                        "file": "\/app\/phalcon\/Url.zep",
                                                                        "line": 167,
                                                                        "char": 50
                                                                    },
                                                                    "file": "\/app\/phalcon\/Url.zep",
                                                                    "line": 167,
                                                                    "char": 50
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "int",
                                                                        "value": "1",
                                                                        "file": "\/app\/phalcon\/Url.zep",
                                                                        "line": 167,
                                                                        "char": 53
                                                                    },
                                                                    "file": "\/app\/phalcon\/Url.zep",
                                                                    "line": 167,
                                                                    "char": 53
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 167,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 167,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 167,
                                                    "char": 54
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 168,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "and",
                                                "left": {
                                                    "type": "and",
                                                    "left": {
                                                        "type": "equals",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "baseUri",
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 169,
                                                            "char": 29
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "\/",
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 169,
                                                            "char": 34
                                                        },
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 169,
                                                        "char": 34
                                                    },
                                                    "right": {
                                                        "type": "equals",
                                                        "left": {
                                                            "type": "fcall",
                                                            "name": "strlen",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "strUri",
                                                                        "file": "\/app\/phalcon\/Url.zep",
                                                                        "line": 169,
                                                                        "char": 49
                                                                    },
                                                                    "file": "\/app\/phalcon\/Url.zep",
                                                                    "line": 169,
                                                                    "char": 49
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 169,
                                                            "char": 52
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "1",
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 169,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 169,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 169,
                                                    "char": 57
                                                },
                                                "right": {
                                                    "type": "equals",
                                                    "left": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "strUri",
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 169,
                                                            "char": 65
                                                        },
                                                        "right": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 169,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 169,
                                                        "char": 70
                                                    },
                                                    "right": {
                                                        "type": "char",
                                                        "value": "\/",
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 169,
                                                        "char": 75
                                                    },
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 169,
                                                    "char": 75
                                                },
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 169,
                                                "char": 75
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "uri",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "baseUri",
                                                                "file": "\/app\/phalcon\/Url.zep",
                                                                "line": 170,
                                                                "char": 38
                                                            },
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 170,
                                                            "char": 38
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 171,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "uri",
                                                            "expr": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "baseUri",
                                                                    "file": "\/app\/phalcon\/Url.zep",
                                                                    "line": 172,
                                                                    "char": 39
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "strUri",
                                                                    "file": "\/app\/phalcon\/Url.zep",
                                                                    "line": 172,
                                                                    "char": 47
                                                                },
                                                                "file": "\/app\/phalcon\/Url.zep",
                                                                "line": 172,
                                                                "char": 47
                                                            },
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 172,
                                                            "char": 47
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 173,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 174,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 175,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 177,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "args",
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 177,
                                "char": 17
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "queryString",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "http_build_query",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "args",
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 178,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 178,
                                                        "char": 52
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 178,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 178,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 180,
                                    "char": 14
                                },
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
                                                    "value": "queryString",
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 180,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 180,
                                                "char": 36
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "string",
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 180,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 180,
                                            "char": 46
                                        },
                                        "right": {
                                            "type": "fcall",
                                            "name": "strlen",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "queryString",
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 180,
                                                        "char": 66
                                                    },
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 180,
                                                    "char": 66
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 180,
                                            "char": 68
                                        },
                                        "file": "\/app\/phalcon\/Url.zep",
                                        "line": 180,
                                        "char": 68
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not-identical",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "strpos",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "uri",
                                                                "file": "\/app\/phalcon\/Url.zep",
                                                                "line": 181,
                                                                "char": 30
                                                            },
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 181,
                                                            "char": 30
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "?",
                                                                "file": "\/app\/phalcon\/Url.zep",
                                                                "line": 181,
                                                                "char": 33
                                                            },
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 181,
                                                            "char": 33
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 181,
                                                    "char": 37
                                                },
                                                "right": {
                                                    "type": "bool",
                                                    "value": "false",
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 181,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 181,
                                                "char": 45
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "uri",
                                                            "expr": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "string",
                                                                    "value": "&",
                                                                    "file": "\/app\/phalcon\/Url.zep",
                                                                    "line": 182,
                                                                    "char": 33
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "queryString",
                                                                    "file": "\/app\/phalcon\/Url.zep",
                                                                    "line": 182,
                                                                    "char": 46
                                                                },
                                                                "file": "\/app\/phalcon\/Url.zep",
                                                                "line": 182,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 182,
                                                            "char": 46
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 183,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "concat-assign",
                                                            "variable": "uri",
                                                            "expr": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "string",
                                                                    "value": "?",
                                                                    "file": "\/app\/phalcon\/Url.zep",
                                                                    "line": 184,
                                                                    "char": 33
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "queryString",
                                                                    "file": "\/app\/phalcon\/Url.zep",
                                                                    "line": 184,
                                                                    "char": 46
                                                                },
                                                                "file": "\/app\/phalcon\/Url.zep",
                                                                "line": 184,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 184,
                                                            "char": 46
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 185,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 186,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 187,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 189,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "uri",
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 189,
                                "char": 19
                            },
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 190,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates a URL\n     *\n     *```php\n     * \/\/ Generate a URL appending the URI to the base URI\n     * echo $url->get(\"products\/edit\/1\");\n     *\n     * \/\/ Generate a URL for a predefined route\n     * echo $url->get(\n     *     [\n     *         \"for\"   => \"blog-post\",\n     *         \"title\" => \"some-cool-stuff\",\n     *         \"year\"  => \"2015\",\n     *     ]\n     * );\n     *\n     * \/\/ Generate a URL with GET arguments (\/show\/products?id=1&name=Carrots)\n     * echo $url->get(\n     *     \"show\/products\",\n     *     [\n     *         \"id\"   => 1,\n     *         \"name\" => \"Carrots\",\n     *     ]\n     * );\n     *\n     * \/\/ Generate an absolute URL by setting the third parameter as false.\n     * echo $url->get(\n     *     \"https:\/\/phalconphp.com\/\",\n     *     null,\n     *     false\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 95,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Url.zep",
                        "line": 95,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Url.zep",
                    "line": 94,
                    "last-line": 194,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getBasePath",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 197,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "basePath",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 197,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 197,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 198,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the base path\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 196,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Url.zep",
                        "line": 196,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Url.zep",
                    "line": 195,
                    "last-line": 202,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getBaseUri",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "baseUri",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 205,
                                    "char": 20
                                },
                                {
                                    "variable": "phpSelf",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 205,
                                    "char": 29
                                },
                                {
                                    "variable": "uri",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 205,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 207,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "baseUri",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 207,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "baseUri",
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 207,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Url.zep",
                                        "line": 207,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 207,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 209,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "baseUri",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 209,
                                    "char": 22
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 209,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 209,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "phpSelf",
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 210,
                                            "char": 49
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "_SERVER",
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 210,
                                                "char": 38
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "PHP_SELF",
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 210,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 210,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Url.zep",
                                        "line": 210,
                                        "char": 49
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "uri",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "phalcon_get_uri",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "phpSelf",
                                                                    "file": "\/app\/phalcon\/Url.zep",
                                                                    "line": 211,
                                                                    "char": 50
                                                                },
                                                                "file": "\/app\/phalcon\/Url.zep",
                                                                "line": 211,
                                                                "char": 50
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 211,
                                                        "char": 51
                                                    },
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 211,
                                                    "char": 51
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 212,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "uri",
                                                    "expr": {
                                                        "type": "null",
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 213,
                                                        "char": 31
                                                    },
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 213,
                                                    "char": 31
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 214,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 216,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "variable",
                                            "value": "uri",
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 216,
                                            "char": 21
                                        },
                                        "file": "\/app\/phalcon\/Url.zep",
                                        "line": 216,
                                        "char": 21
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "baseUri",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "\/",
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 217,
                                                        "char": 32
                                                    },
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 217,
                                                    "char": 32
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 218,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "baseUri",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "string",
                                                                "value": "\/",
                                                                "file": "\/app\/phalcon\/Url.zep",
                                                                "line": 219,
                                                                "char": 33
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "uri",
                                                                "file": "\/app\/phalcon\/Url.zep",
                                                                "line": 219,
                                                                "char": 39
                                                            },
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 219,
                                                            "char": 39
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "\/",
                                                            "file": "\/app\/phalcon\/Url.zep",
                                                            "line": 219,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Url.zep",
                                                        "line": 219,
                                                        "char": 41
                                                    },
                                                    "file": "\/app\/phalcon\/Url.zep",
                                                    "line": 219,
                                                    "char": 41
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 220,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 222,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "baseUri",
                                            "expr": {
                                                "type": "variable",
                                                "value": "baseUri",
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 222,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 222,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 223,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 225,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "baseUri",
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 225,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 226,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the prefix for all the generated urls. By default \/\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 204,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Url.zep",
                        "line": 204,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Url.zep",
                    "line": 203,
                    "last-line": 230,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDI",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 233,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "container",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 233,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 233,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 234,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the DependencyInjector container\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "DiInterface",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 232,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 232,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Url.zep",
                        "line": 232,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Url.zep",
                    "line": 231,
                    "last-line": 250,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getStatic",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "uri",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 251,
                                "char": 45
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 251,
                            "char": 45
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 253,
                                    "char": 21
                                },
                                "name": "get",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "uri",
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 254,
                                            "char": 16
                                        },
                                        "file": "\/app\/phalcon\/Url.zep",
                                        "line": 254,
                                        "char": 16
                                    },
                                    {
                                        "parameter": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 255,
                                            "char": 17
                                        },
                                        "file": "\/app\/phalcon\/Url.zep",
                                        "line": 255,
                                        "char": 17
                                    },
                                    {
                                        "parameter": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 256,
                                            "char": 17
                                        },
                                        "file": "\/app\/phalcon\/Url.zep",
                                        "line": 256,
                                        "char": 17
                                    },
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 257,
                                                "char": 18
                                            },
                                            "name": "getStaticBaseUri",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 258,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Url.zep",
                                        "line": 258,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 258,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 259,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates a URL for a static resource\n     *\n     *```php\n     * \/\/ Generate a URL for a static resource\n     * echo $url->getStatic(\"img\/logo.png\");\n     *\n     * \/\/ Generate a URL for a static predefined route\n     * echo $url->getStatic(\n     *     [\n     *         \"for\" => \"logo-cdn\",\n     *     ]\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 252,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Url.zep",
                        "line": 252,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Url.zep",
                    "line": 251,
                    "last-line": 263,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getStaticBaseUri",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "staticBaseUri",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 266,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 268,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "staticBaseUri",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 268,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "staticBaseUri",
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 268,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Url.zep",
                                        "line": 268,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 268,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 270,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "variable",
                                    "value": "staticBaseUri",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 270,
                                    "char": 28
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 270,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 270,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "staticBaseUri",
                                        "file": "\/app\/phalcon\/Url.zep",
                                        "line": 271,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 272,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 274,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 274,
                                    "char": 21
                                },
                                "name": "getBaseUri",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 274,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 275,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the prefix for all the generated static urls. By default \/\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 265,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Url.zep",
                        "line": 265,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Url.zep",
                    "line": 264,
                    "last-line": 283,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setBasePath",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "basePath",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 284,
                            "char": 49
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
                                    "property": "basePath",
                                    "expr": {
                                        "type": "variable",
                                        "value": "basePath",
                                        "file": "\/app\/phalcon\/Url.zep",
                                        "line": 286,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 286,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 288,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 288,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 289,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a base path for all the generated paths\n     *\n     *```php\n     * $url->setBasePath(\"\/var\/www\/htdocs\/\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "UrlInterface",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 285,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 285,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Url.zep",
                        "line": 285,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Url.zep",
                    "line": 284,
                    "last-line": 299,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setBaseUri",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "baseUri",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 300,
                            "char": 47
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
                                    "property": "baseUri",
                                    "expr": {
                                        "type": "variable",
                                        "value": "baseUri",
                                        "file": "\/app\/phalcon\/Url.zep",
                                        "line": 302,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 302,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 304,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Url.zep",
                                        "line": 304,
                                        "char": 17
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "staticBaseUri",
                                        "file": "\/app\/phalcon\/Url.zep",
                                        "line": 304,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 304,
                                    "char": 34
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 304,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 304,
                                "char": 41
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "staticBaseUri",
                                            "expr": {
                                                "type": "variable",
                                                "value": "baseUri",
                                                "file": "\/app\/phalcon\/Url.zep",
                                                "line": 305,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Url.zep",
                                            "line": 305,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 306,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 308,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 308,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 309,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a prefix for all the URIs to be generated\n     *\n     *```php\n     * $url->setBaseUri(\"\/invo\/\");\n     *\n     * $url->setBaseUri(\"\/invo\/index.php\/\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "UrlInterface",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 301,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 301,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Url.zep",
                        "line": 301,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Url.zep",
                    "line": 300,
                    "last-line": 313,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDI",
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
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 314,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 314,
                            "char": 50
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
                                        "file": "\/app\/phalcon\/Url.zep",
                                        "line": 316,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 316,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 317,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the DependencyInjector container\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Url.zep",
                        "line": 315,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Url.zep",
                    "line": 314,
                    "last-line": 325,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setStaticBaseUri",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "staticBaseUri",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 326,
                            "char": 59
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
                                    "property": "staticBaseUri",
                                    "expr": {
                                        "type": "variable",
                                        "value": "staticBaseUri",
                                        "file": "\/app\/phalcon\/Url.zep",
                                        "line": 328,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 328,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 330,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 330,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 331,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a prefix for all static URLs generated\n     *\n     *```php\n     * $url->setStaticBaseUri(\"\/invo\/\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "UrlInterface",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 327,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 327,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Url.zep",
                        "line": 327,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Url.zep",
                    "line": 326,
                    "last-line": 335,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "path",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "path",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 336,
                                "char": 44
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 336,
                            "char": 44
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "concat",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Url.zep",
                                        "line": 338,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "basePath",
                                        "file": "\/app\/phalcon\/Url.zep",
                                        "line": 338,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 338,
                                    "char": 31
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "path",
                                    "file": "\/app\/phalcon\/Url.zep",
                                    "line": 338,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 338,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Url.zep",
                            "line": 339,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Generates a local path\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Url.zep",
                                "line": 337,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Url.zep",
                        "line": 337,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Url.zep",
                    "line": 336,
                    "last-line": 340,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Url.zep",
            "line": 37,
            "char": 5
        },
        "file": "\/app\/phalcon\/Url.zep",
        "line": 37,
        "char": 5
    }
]