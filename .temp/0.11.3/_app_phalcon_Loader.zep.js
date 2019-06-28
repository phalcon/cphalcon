[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Loader.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon",
        "file": "\/app\/phalcon\/Loader.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Loader\\Exception",
                "file": "\/app\/phalcon\/Loader.zep",
                "line": 13,
                "char": 29
            }
        ],
        "file": "\/app\/phalcon\/Loader.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\ManagerInterface",
                "file": "\/app\/phalcon\/Loader.zep",
                "line": 14,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Loader.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\EventsAwareInterface",
                "file": "\/app\/phalcon\/Loader.zep",
                "line": 15,
                "char": 40
            }
        ],
        "file": "\/app\/phalcon\/Loader.zep",
        "line": 42,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * This component helps to load your project classes automatically based on some\n * conventions\n *\n *```php\n * use Phalcon\\Loader;\n *\n * \/\/ Creates the autoloader\n * $loader = new Loader();\n *\n * \/\/ Register some namespaces\n * $loader->registerNamespaces(\n *     [\n *         \"Example\\\\Base\"    => \"vendor\/example\/base\/\",\n *         \"Example\\\\Adapter\" => \"vendor\/example\/adapter\/\",\n *         \"Example\"          => \"vendor\/example\/\",\n *     ]\n * );\n *\n * \/\/ Register autoloader\n * $loader->register();\n *\n * \/\/ Requiring this class will automatically include file vendor\/example\/adapter\/Some.php\n * $adapter = new \\Example\\Adapter\\Some();\n *```\n *",
        "file": "\/app\/phalcon\/Loader.zep",
        "line": 43,
        "char": 5
    },
    {
        "type": "class",
        "name": "Loader",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "EventsAwareInterface",
                "file": "\/app\/phalcon\/Loader.zep",
                "line": 44,
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
                    "name": "checkedPath",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 45,
                        "char": 33
                    },
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 49,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "classes",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 50,
                        "char": 27
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 54,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "directories",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 55,
                        "char": 31
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 56,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "eventsManager",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 56,
                        "char": 35
                    },
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 60,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "extensions",
                    "default": {
                        "type": "array",
                        "left": [
                            {
                                "value": {
                                    "type": "string",
                                    "value": "php",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 61,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 61,
                                "char": 32
                            }
                        ],
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 61,
                        "char": 33
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 63,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "fileCheckingCallback",
                    "default": {
                        "type": "string",
                        "value": "is_file",
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 63,
                        "char": 45
                    },
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 67,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "files",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 68,
                        "char": 25
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 72,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "foundPath",
                    "default": {
                        "type": "null",
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 73,
                        "char": 31
                    },
                    "docblock": "**\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 77,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "namespaces",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 78,
                        "char": 30
                    },
                    "docblock": "**\n     * @var array\n     *",
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 82,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "registered",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 83,
                        "char": 33
                    },
                    "docblock": "**\n     * @var bool\n     *",
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 87,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "autoLoad",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "className",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 88,
                            "char": 47
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "eventsManager",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 90,
                                    "char": 26
                                },
                                {
                                    "variable": "classes",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 90,
                                    "char": 35
                                },
                                {
                                    "variable": "extensions",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 90,
                                    "char": 47
                                },
                                {
                                    "variable": "filePath",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 90,
                                    "char": 57
                                },
                                {
                                    "variable": "ds",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 90,
                                    "char": 61
                                },
                                {
                                    "variable": "fixedDirectory",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 90,
                                    "char": 77
                                },
                                {
                                    "variable": "directories",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 91,
                                    "char": 24
                                },
                                {
                                    "variable": "ns",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 91,
                                    "char": 28
                                },
                                {
                                    "variable": "namespaces",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 91,
                                    "char": 40
                                },
                                {
                                    "variable": "nsPrefix",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 91,
                                    "char": 50
                                },
                                {
                                    "variable": "directory",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 91,
                                    "char": 61
                                },
                                {
                                    "variable": "fileName",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 91,
                                    "char": 71
                                },
                                {
                                    "variable": "extension",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 92,
                                    "char": 22
                                },
                                {
                                    "variable": "nsClassName",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 92,
                                    "char": 35
                                },
                                {
                                    "variable": "fileCheckingCallback",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 92,
                                    "char": 57
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 94,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "eventsManager",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 94,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "eventsManager",
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 94,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 94,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 94,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 96,
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
                                        "value": "eventsManager",
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 96,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 96,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 96,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 96,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "eventsManager",
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 97,
                                            "char": 27
                                        },
                                        "name": "fire",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "loader:beforeCheckClass",
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 97,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 97,
                                                "char": 56
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 97,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 97,
                                                "char": 62
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "className",
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 97,
                                                    "char": 73
                                                },
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 97,
                                                "char": 73
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 97,
                                        "char": 74
                                    },
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 98,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 103,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "classes",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 103,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "classes",
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 103,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 103,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 103,
                                    "char": 36
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 105,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "filePath",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 105,
                                    "char": 47
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "classes",
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 105,
                                        "char": 35
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "className",
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 105,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 105,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 105,
                                "char": 47
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "eventsManager",
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 106,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 106,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "object",
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 106,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 106,
                                        "char": 47
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "foundPath",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "filePath",
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 107,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 107,
                                                    "char": 47
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 108,
                                            "char": 29
                                        },
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "eventsManager",
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 108,
                                                    "char": 31
                                                },
                                                "name": "fire",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "loader:pathFound",
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 108,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 108,
                                                        "char": 53
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 108,
                                                            "char": 59
                                                        },
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 108,
                                                        "char": 59
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "filePath",
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 108,
                                                            "char": 69
                                                        },
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 108,
                                                        "char": 69
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 108,
                                                "char": 70
                                            },
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 109,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 111,
                                    "char": 19
                                },
                                {
                                    "type": "require",
                                    "expr": {
                                        "type": "variable",
                                        "value": "filePath",
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 111,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 113,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 113,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 114,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 116,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "extensions",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 116,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "extensions",
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 116,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 116,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 116,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 118,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "ds",
                                    "expr": {
                                        "type": "constant",
                                        "value": "DIRECTORY_SEPARATOR",
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 118,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 118,
                                    "char": 37
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "ns",
                                    "expr": {
                                        "type": "string",
                                        "value": "\\\\",
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 119,
                                        "char": 20
                                    },
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 119,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 124,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "namespaces",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 124,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "namespaces",
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 124,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 124,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 124,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 126,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "fileCheckingCallback",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 126,
                                            "char": 41
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "fileCheckingCallback",
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 126,
                                            "char": 62
                                        },
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 126,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 126,
                                    "char": 62
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 128,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "namespaces",
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 128,
                                "char": 49
                            },
                            "key": "nsPrefix",
                            "value": "directories",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "fcall",
                                            "name": "starts_with",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "className",
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 132,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 132,
                                                    "char": 38
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "nsPrefix",
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 132,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 132,
                                                    "char": 48
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 132,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 132,
                                        "char": 50
                                    },
                                    "statements": [
                                        {
                                            "type": "continue",
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 134,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 139,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "fileName",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "substr",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "className",
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 139,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 139,
                                                        "char": 44
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "fcall",
                                                            "name": "strlen",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "nsPrefix",
                                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                                            "line": 139,
                                                                            "char": 62
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "ns",
                                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                                            "line": 139,
                                                                            "char": 66
                                                                        },
                                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                                        "line": 139,
                                                                        "char": 66
                                                                    },
                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                    "line": 139,
                                                                    "char": 66
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 139,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 139,
                                                        "char": 67
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 139,
                                                "char": 68
                                            },
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 139,
                                            "char": 68
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 141,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "variable",
                                            "value": "fileName",
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 141,
                                            "char": 26
                                        },
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 141,
                                        "char": 26
                                    },
                                    "statements": [
                                        {
                                            "type": "continue",
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 143,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 145,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "fileName",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "str_replace",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "ns",
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 145,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 145,
                                                        "char": 42
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "ds",
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 145,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 145,
                                                        "char": 46
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "fileName",
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 145,
                                                            "char": 56
                                                        },
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 145,
                                                        "char": 56
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 145,
                                                "char": 57
                                            },
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 145,
                                            "char": 57
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 147,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "directories",
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 147,
                                        "char": 42
                                    },
                                    "value": "directory",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "fixedDirectory",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "fcall",
                                                            "name": "rtrim",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "directory",
                                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                                        "line": 152,
                                                                        "char": 53
                                                                    },
                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                    "line": 152,
                                                                    "char": 53
                                                                },
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "ds",
                                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                                        "line": 152,
                                                                        "char": 57
                                                                    },
                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                    "line": 152,
                                                                    "char": 57
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 152,
                                                            "char": 59
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "ds",
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 152,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 152,
                                                        "char": 63
                                                    },
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 152,
                                                    "char": 63
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 154,
                                            "char": 19
                                        },
                                        {
                                            "type": "for",
                                            "expr": {
                                                "type": "variable",
                                                "value": "extensions",
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 154,
                                                "char": 45
                                            },
                                            "value": "extension",
                                            "reverse": 0,
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "filePath",
                                                            "expr": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "fixedDirectory",
                                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                                            "line": 155,
                                                                            "char": 51
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "fileName",
                                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                                            "line": 155,
                                                                            "char": 62
                                                                        },
                                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                                        "line": 155,
                                                                        "char": 62
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": ".",
                                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                                        "line": 155,
                                                                        "char": 66
                                                                    },
                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                    "line": 155,
                                                                    "char": 66
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "extension",
                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                    "line": 155,
                                                                    "char": 77
                                                                },
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 155,
                                                                "char": 77
                                                            },
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 155,
                                                            "char": 77
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 160,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "equals",
                                                        "left": {
                                                            "type": "typeof",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "eventsManager",
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 160,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 160,
                                                            "char": 46
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "object",
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 160,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 160,
                                                        "char": 55
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "object-property",
                                                                    "operator": "assign",
                                                                    "variable": "this",
                                                                    "property": "checkedPath",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "filePath",
                                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                                        "line": 161,
                                                                        "char": 57
                                                                    },
                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                    "line": 161,
                                                                    "char": 57
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 163,
                                                            "char": 37
                                                        },
                                                        {
                                                            "type": "mcall",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "eventsManager",
                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                    "line": 163,
                                                                    "char": 39
                                                                },
                                                                "name": "fire",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "loader:beforeCheckPath",
                                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                                            "line": 163,
                                                                            "char": 67
                                                                        },
                                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                                        "line": 163,
                                                                        "char": 67
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                                            "line": 163,
                                                                            "char": 73
                                                                        },
                                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                                        "line": 163,
                                                                        "char": 73
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 163,
                                                                "char": 74
                                                            },
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 164,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 170,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "call_user_func",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "fileCheckingCallback",
                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                    "line": 170,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 170,
                                                                "char": 59
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "filePath",
                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                    "line": 170,
                                                                    "char": 69
                                                                },
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 170,
                                                                "char": 69
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 170,
                                                        "char": 71
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "equals",
                                                                "left": {
                                                                    "type": "typeof",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "eventsManager",
                                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                                        "line": 171,
                                                                        "char": 50
                                                                    },
                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                    "line": 171,
                                                                    "char": 50
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "object",
                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                    "line": 171,
                                                                    "char": 59
                                                                },
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 171,
                                                                "char": 59
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "object-property",
                                                                            "operator": "assign",
                                                                            "variable": "this",
                                                                            "property": "foundPath",
                                                                            "expr": {
                                                                                "type": "variable",
                                                                                "value": "filePath",
                                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                                "line": 172,
                                                                                "char": 59
                                                                            },
                                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                                            "line": 172,
                                                                            "char": 59
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                    "line": 174,
                                                                    "char": 41
                                                                },
                                                                {
                                                                    "type": "mcall",
                                                                    "expr": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "eventsManager",
                                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                                            "line": 174,
                                                                            "char": 43
                                                                        },
                                                                        "name": "fire",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "string",
                                                                                    "value": "loader:pathFound",
                                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                                    "line": 175,
                                                                                    "char": 49
                                                                                },
                                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                                "line": 175,
                                                                                "char": 49
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "this",
                                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                                    "line": 176,
                                                                                    "char": 37
                                                                                },
                                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                                "line": 176,
                                                                                "char": 37
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "filePath",
                                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                                    "line": 178,
                                                                                    "char": 29
                                                                                },
                                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                                "line": 178,
                                                                                "char": 29
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                                        "line": 178,
                                                                        "char": 30
                                                                    },
                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                    "line": 179,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 184,
                                                            "char": 31
                                                        },
                                                        {
                                                            "type": "require",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "filePath",
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 184,
                                                                "char": 41
                                                            },
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 189,
                                                            "char": 30
                                                        },
                                                        {
                                                            "type": "return",
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 189,
                                                                "char": 36
                                                            },
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 190,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 191,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 192,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 193,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 198,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "nsClassName",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "str_replace",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "ns",
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 198,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 198,
                                                "char": 41
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "ds",
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 198,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 198,
                                                "char": 45
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "className",
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 198,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 198,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 198,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 198,
                                    "char": 57
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 203,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "directories",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 203,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "directories",
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 203,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 203,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 203,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 205,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "directories",
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 205,
                                "char": 38
                            },
                            "value": "directory",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "fixedDirectory",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "rtrim",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "directory",
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 209,
                                                                "char": 49
                                                            },
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 209,
                                                            "char": 49
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "ds",
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 209,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 209,
                                                            "char": 53
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 209,
                                                    "char": 55
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "ds",
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 209,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 209,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 209,
                                            "char": 59
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 211,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "extensions",
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 211,
                                        "char": 41
                                    },
                                    "value": "extension",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "filePath",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "fixedDirectory",
                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                    "line": 215,
                                                                    "char": 47
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "nsClassName",
                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                    "line": 215,
                                                                    "char": 61
                                                                },
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 215,
                                                                "char": 61
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": ".",
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 215,
                                                                "char": 65
                                                            },
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 215,
                                                            "char": 65
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "extension",
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 215,
                                                            "char": 76
                                                        },
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 215,
                                                        "char": 76
                                                    },
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 215,
                                                    "char": 76
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 217,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "typeof",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "eventsManager",
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 217,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 217,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "object",
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 217,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 217,
                                                "char": 51
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "checkedPath",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "filePath",
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 218,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 218,
                                                            "char": 53
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 220,
                                                    "char": 33
                                                },
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "eventsManager",
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 220,
                                                            "char": 35
                                                        },
                                                        "name": "fire",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "loader:beforeCheckPath",
                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                    "line": 221,
                                                                    "char": 47
                                                                },
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 221,
                                                                "char": 47
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                    "line": 222,
                                                                    "char": 29
                                                                },
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 222,
                                                                "char": 29
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "filePath",
                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                    "line": 224,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 224,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 224,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 225,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 230,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "call_user_func",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "fileCheckingCallback",
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 230,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 230,
                                                        "char": 55
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "filePath",
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 230,
                                                            "char": 65
                                                        },
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 230,
                                                        "char": 65
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 230,
                                                "char": 67
                                            },
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "equals",
                                                        "left": {
                                                            "type": "typeof",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "eventsManager",
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 234,
                                                                "char": 46
                                                            },
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 234,
                                                            "char": 46
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "object",
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 234,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 234,
                                                        "char": 55
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "object-property",
                                                                    "operator": "assign",
                                                                    "variable": "this",
                                                                    "property": "foundPath",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "filePath",
                                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                                        "line": 235,
                                                                        "char": 55
                                                                    },
                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                    "line": 235,
                                                                    "char": 55
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 237,
                                                            "char": 37
                                                        },
                                                        {
                                                            "type": "mcall",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "eventsManager",
                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                    "line": 237,
                                                                    "char": 39
                                                                },
                                                                "name": "fire",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "string",
                                                                            "value": "loader:pathFound",
                                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                                            "line": 237,
                                                                            "char": 61
                                                                        },
                                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                                        "line": 237,
                                                                        "char": 61
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                                            "line": 237,
                                                                            "char": 67
                                                                        },
                                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                                        "line": 237,
                                                                        "char": 67
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "filePath",
                                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                                            "line": 237,
                                                                            "char": 77
                                                                        },
                                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                                        "line": 237,
                                                                        "char": 77
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 237,
                                                                "char": 78
                                                            },
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 238,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 243,
                                                    "char": 27
                                                },
                                                {
                                                    "type": "require",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "filePath",
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 243,
                                                        "char": 37
                                                    },
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 248,
                                                    "char": 26
                                                },
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "true",
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 248,
                                                        "char": 32
                                                    },
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 249,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 250,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 251,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 256,
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
                                        "value": "eventsManager",
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 256,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 256,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 256,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 256,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "eventsManager",
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 257,
                                            "char": 27
                                        },
                                        "name": "fire",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "loader:afterCheckClass",
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 257,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 257,
                                                "char": 55
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 257,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 257,
                                                "char": 61
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "className",
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 257,
                                                    "char": 72
                                                },
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 257,
                                                "char": 72
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 257,
                                        "char": 73
                                    },
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 258,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 263,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 263,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 264,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Autoloads the registered classes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 89,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 89,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 88,
                    "last-line": 268,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getCheckedPath",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 271,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "checkedPath",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 271,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 271,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 272,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Get the path the loader is checking for a path\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 270,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 270,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 269,
                    "last-line": 275,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getClasses",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 278,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "classes",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 278,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 278,
                                "char": 29
                            },
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 279,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the class-map currently registered in the autoloader\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 277,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 277,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 276,
                    "last-line": 283,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDirs",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 286,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "directories",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 286,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 286,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 287,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the directories currently registered in the autoloader\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 285,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 285,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 284,
                    "last-line": 291,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getEventsManager",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 294,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "eventsManager",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 294,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 294,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 295,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the internal event manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ManagerInterface",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 293,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 293,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 293,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 292,
                    "last-line": 299,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getExtensions",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 302,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "extensions",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 302,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 302,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 303,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the file extensions registered in the loader\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 301,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 301,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 300,
                    "last-line": 307,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getFiles",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 310,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "files",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 310,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 310,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 311,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the files currently registered in the autoloader\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 309,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 309,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 308,
                    "last-line": 315,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getFoundPath",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 318,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "foundPath",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 318,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 318,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 319,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Get the path when a class was found\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 317,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 317,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 316,
                    "last-line": 323,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getNamespaces",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 326,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "namespaces",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 326,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 326,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 327,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the namespaces currently registered in the autoloader\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 325,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 325,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 324,
                    "last-line": 331,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "loadFiles",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "filePath",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 334,
                                    "char": 21
                                },
                                {
                                    "variable": "fileCheckingCallback",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 334,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 336,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "fileCheckingCallback",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 336,
                                            "char": 41
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "fileCheckingCallback",
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 336,
                                            "char": 62
                                        },
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 336,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 336,
                                    "char": 62
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 338,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 338,
                                    "char": 30
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "files",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 338,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 338,
                                "char": 37
                            },
                            "value": "filePath",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 339,
                                                    "char": 28
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "eventsManager",
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 339,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 339,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 339,
                                            "char": 44
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "object",
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 339,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 339,
                                        "char": 53
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "checkedPath",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "filePath",
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 340,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 340,
                                                    "char": 49
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 341,
                                            "char": 24
                                        },
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 341,
                                                        "char": 26
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "eventsManager",
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 341,
                                                        "char": 41
                                                    },
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 341,
                                                    "char": 41
                                                },
                                                "name": "fire",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "loader:beforeCheckPath",
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 342,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 342,
                                                        "char": 47
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 343,
                                                            "char": 29
                                                        },
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 343,
                                                        "char": 29
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "filePath",
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 345,
                                                            "char": 21
                                                        },
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 345,
                                                        "char": 21
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 345,
                                                "char": 22
                                            },
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 346,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 351,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "call_user_func",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "fileCheckingCallback",
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 351,
                                                    "char": 51
                                                },
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 351,
                                                "char": 51
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "filePath",
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 351,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 351,
                                                "char": 61
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 351,
                                        "char": 63
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "equals",
                                                "left": {
                                                    "type": "typeof",
                                                    "left": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 355,
                                                            "char": 32
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "eventsManager",
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 355,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 355,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 355,
                                                    "char": 48
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "object",
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 355,
                                                    "char": 57
                                                },
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 355,
                                                "char": 57
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "foundPath",
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "filePath",
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 356,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 356,
                                                            "char": 51
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 358,
                                                    "char": 24
                                                },
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 358,
                                                                "char": 26
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "eventsManager",
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 358,
                                                                "char": 41
                                                            },
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 358,
                                                            "char": 41
                                                        },
                                                        "name": "fire",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "loader:pathFound",
                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                    "line": 359,
                                                                    "char": 41
                                                                },
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 359,
                                                                "char": 41
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                    "line": 360,
                                                                    "char": 29
                                                                },
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 360,
                                                                "char": 29
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "filePath",
                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                    "line": 362,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 362,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 362,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 363,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 368,
                                            "char": 23
                                        },
                                        {
                                            "type": "require",
                                            "expr": {
                                                "type": "variable",
                                                "value": "filePath",
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 368,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 369,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 370,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 371,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks if a file exists and then adds the file by doing virtual require\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 333,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 332,
                    "last-line": 375,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "register",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "prepend",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 376,
                                "char": 50
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 376,
                            "char": 50
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 378,
                                        "char": 17
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "registered",
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 378,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 378,
                                    "char": 31
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 378,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 378,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 382,
                                            "char": 18
                                        },
                                        "name": "loadFiles",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 382,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 387,
                                    "char": 33
                                },
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "spl_autoload_register",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "array",
                                                    "left": [
                                                        {
                                                            "value": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 388,
                                                                "char": 22
                                                            },
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 388,
                                                            "char": 22
                                                        },
                                                        {
                                                            "value": {
                                                                "type": "string",
                                                                "value": "autoLoad",
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 388,
                                                                "char": 32
                                                            },
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 388,
                                                            "char": 32
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 388,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 388,
                                                "char": 33
                                            },
                                            {
                                                "parameter": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 389,
                                                    "char": 21
                                                },
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 389,
                                                "char": 21
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "prepend",
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 391,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 391,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 391,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 393,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "registered",
                                            "expr": {
                                                "type": "bool",
                                                "value": "true",
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 393,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 393,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 394,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 396,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 396,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 397,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Register the autoload method\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Loader",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 377,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 377,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 377,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 376,
                    "last-line": 401,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "registerClasses",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "classes",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 402,
                            "char": 51
                        },
                        {
                            "type": "parameter",
                            "name": "merge",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 402,
                                "char": 71
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 402,
                            "char": 71
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "merge",
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 404,
                                "char": 18
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "classes",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "array_merge",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 405,
                                                                "char": 50
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "classes",
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 405,
                                                                "char": 58
                                                            },
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 405,
                                                            "char": 58
                                                        },
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 405,
                                                        "char": 58
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "classes",
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 405,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 405,
                                                        "char": 67
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 405,
                                                "char": 68
                                            },
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 405,
                                            "char": 68
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 406,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "classes",
                                            "expr": {
                                                "type": "variable",
                                                "value": "classes",
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 407,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 407,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 408,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 410,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 410,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 411,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Register classes and their locations\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Loader",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 403,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 403,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 403,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 402,
                    "last-line": 415,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "registerDirs",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "directories",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 416,
                            "char": 52
                        },
                        {
                            "type": "parameter",
                            "name": "merge",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 416,
                                "char": 72
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 416,
                            "char": 72
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "merge",
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 418,
                                "char": 18
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "directories",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "array_merge",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 419,
                                                                "char": 54
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "directories",
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 419,
                                                                "char": 66
                                                            },
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 419,
                                                            "char": 66
                                                        },
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 419,
                                                        "char": 66
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "directories",
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 419,
                                                            "char": 79
                                                        },
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 419,
                                                        "char": 79
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 419,
                                                "char": 80
                                            },
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 419,
                                            "char": 80
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 420,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "directories",
                                            "expr": {
                                                "type": "variable",
                                                "value": "directories",
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 421,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 421,
                                            "char": 48
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 422,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 424,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 424,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 425,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Register directories in which \"not found\" classes could be found\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Loader",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 417,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 417,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 417,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 416,
                    "last-line": 430,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "registerFiles",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "files",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 431,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "merge",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 431,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 431,
                            "char": 67
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "merge",
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 433,
                                "char": 18
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "files",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "array_merge",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 434,
                                                                "char": 48
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "files",
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 434,
                                                                "char": 54
                                                            },
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 434,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 434,
                                                        "char": 54
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "files",
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 434,
                                                            "char": 61
                                                        },
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 434,
                                                        "char": 61
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 434,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 434,
                                            "char": 62
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 435,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "files",
                                            "expr": {
                                                "type": "variable",
                                                "value": "files",
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 436,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 436,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 437,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 439,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 439,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 440,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Registers files that are \"non-classes\" hence need a \"require\". This is\n     * very useful for including files that only have functions\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Loader",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 432,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 432,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 432,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 431,
                    "last-line": 444,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "registerNamespaces",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "namespaces",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 445,
                            "char": 57
                        },
                        {
                            "type": "parameter",
                            "name": "merge",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 445,
                                "char": 77
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 445,
                            "char": 77
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "preparedNamespaces",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 447,
                                    "char": 31
                                },
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 447,
                                    "char": 37
                                },
                                {
                                    "variable": "paths",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 447,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 449,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "preparedNamespaces",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 449,
                                            "char": 39
                                        },
                                        "name": "prepareNamespace",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "namespaces",
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 449,
                                                    "char": 67
                                                },
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 449,
                                                "char": 67
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 449,
                                        "char": 68
                                    },
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 449,
                                    "char": 68
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 451,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "merge",
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 451,
                                "char": 18
                            },
                            "statements": [
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "preparedNamespaces",
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 452,
                                        "char": 51
                                    },
                                    "key": "name",
                                    "value": "paths",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
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
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 453,
                                                                "char": 32
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "namespaces",
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 453,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 453,
                                                            "char": 43
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 453,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 453,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 453,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 453,
                                                "char": 50
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property-array-index",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "namespaces",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "name",
                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                    "line": 454,
                                                                    "char": 46
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "empty-array",
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 454,
                                                                "char": 52
                                                            },
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 454,
                                                            "char": 52
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 455,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 457,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property-array-index",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "namespaces",
                                                    "index-expr": [
                                                        {
                                                            "type": "variable",
                                                            "value": "name",
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 457,
                                                            "char": 42
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "array_merge",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "array-access",
                                                                    "left": {
                                                                        "type": "property-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "this",
                                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                                            "line": 458,
                                                                            "char": 26
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "namespaces",
                                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                                            "line": 458,
                                                                            "char": 37
                                                                        },
                                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                                        "line": 458,
                                                                        "char": 37
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "name",
                                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                                        "line": 458,
                                                                        "char": 42
                                                                    },
                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                    "line": 458,
                                                                    "char": 43
                                                                },
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 458,
                                                                "char": 43
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "paths",
                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                    "line": 460,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 460,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 460,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 460,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 461,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 462,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "namespaces",
                                            "expr": {
                                                "type": "variable",
                                                "value": "preparedNamespaces",
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 463,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 463,
                                            "char": 54
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 464,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 466,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 466,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 467,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Register namespaces and their related directories\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Loader",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 446,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 446,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 446,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 445,
                    "last-line": 471,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setEventsManager",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "eventsManager",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ManagerInterface",
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 472,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 472,
                            "char": 70
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
                                    "property": "eventsManager",
                                    "expr": {
                                        "type": "variable",
                                        "value": "eventsManager",
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 474,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 474,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 475,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the events manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 473,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 472,
                    "last-line": 480,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setExtensions",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "extensions",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 481,
                            "char": 52
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
                                    "property": "extensions",
                                    "expr": {
                                        "type": "variable",
                                        "value": "extensions",
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 483,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 483,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 485,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 485,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 486,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets an array of file extensions that the loader must try in each attempt\n     * to locate the file\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Loader",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 482,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 482,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 482,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 481,
                    "last-line": 502,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setFileCheckingCallback",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "callback",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 503,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 503,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "likely",
                                "left": {
                                    "type": "fcall",
                                    "name": "is_callable",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "callback",
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 505,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 505,
                                            "char": 39
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 505,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 505,
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
                                            "property": "fileCheckingCallback",
                                            "expr": {
                                                "type": "variable",
                                                "value": "callback",
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 506,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 506,
                                            "char": 54
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 507,
                                    "char": 9
                                }
                            ],
                            "elseif_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "callback",
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 507,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 507,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 507,
                                        "char": 36
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "fileCheckingCallback",
                                                    "expr": {
                                                        "type": "closure",
                                                        "left": [
                                                            {
                                                                "type": "parameter",
                                                                "name": "file",
                                                                "const": 0,
                                                                "data-type": "variable",
                                                                "mandatory": 0,
                                                                "reference": 0,
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 508,
                                                                "char": 60
                                                            }
                                                        ],
                                                        "right": [
                                                            {
                                                                "type": "return",
                                                                "expr": {
                                                                    "type": "bool",
                                                                    "value": "true",
                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                    "line": 509,
                                                                    "char": 28
                                                                },
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 510,
                                                                "char": 13
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 510,
                                                        "char": 14
                                                    },
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 510,
                                                    "char": 14
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 511,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 511,
                                    "char": 14
                                }
                            ],
                            "else_statements": [
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
                                                    "value": "The 'callback' parameter must be either a callable or NULL.",
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 514,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 514,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 514,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 515,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 517,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 517,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 518,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the file check callback.\n     *\n     * ```php\n     * \/\/ Default behavior.\n     * $loader->setFileCheckingCallback(\"is_file\");\n     *\n     * \/\/ Faster than `is_file()`, but implies some issues if\n     * \/\/ the file is removed from the filesystem.\n     * $loader->setFileCheckingCallback(\"stream_resolve_include_path\");\n     *\n     * \/\/ Do not check file existence.\n     * $loader->setFileCheckingCallback(null);\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Loader",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 504,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 504,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 504,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 508,
                    "last-line": 522,
                    "char": 53
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "unregister",
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 525,
                                        "char": 17
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "registered",
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 525,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 525,
                                    "char": 31
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "true",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 525,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 525,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "fcall",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "spl_autoload_unregister",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "array",
                                                    "left": [
                                                        {
                                                            "value": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 528,
                                                                "char": 25
                                                            },
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 528,
                                                            "char": 25
                                                        },
                                                        {
                                                            "value": {
                                                                "type": "string",
                                                                "value": "autoLoad",
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 530,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Loader.zep",
                                                            "line": 530,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 531,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 531,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 531,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 533,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "registered",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 533,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 533,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 534,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 536,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 536,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 537,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Unregister the autoload method\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Loader",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 524,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 524,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 524,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 523,
                    "last-line": 539,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "prepareNamespace",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "namespaceName",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 539,
                            "char": 61
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "localPaths",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 541,
                                    "char": 23
                                },
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 541,
                                    "char": 29
                                },
                                {
                                    "variable": "paths",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 541,
                                    "char": 36
                                },
                                {
                                    "variable": "prepared",
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 541,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 543,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "prepared",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 543,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 543,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 545,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "namespaceName",
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 545,
                                "char": 42
                            },
                            "key": "name",
                            "value": "paths",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "paths",
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 546,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 546,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 546,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Loader.zep",
                                        "line": 546,
                                        "char": 38
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "localPaths",
                                                    "expr": {
                                                        "type": "array",
                                                        "left": [
                                                            {
                                                                "value": {
                                                                    "type": "variable",
                                                                    "value": "paths",
                                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                                    "line": 547,
                                                                    "char": 40
                                                                },
                                                                "file": "\/app\/phalcon\/Loader.zep",
                                                                "line": 547,
                                                                "char": 40
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 547,
                                                        "char": 41
                                                    },
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 547,
                                                    "char": 41
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 548,
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
                                                    "variable": "localPaths",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "paths",
                                                        "file": "\/app\/phalcon\/Loader.zep",
                                                        "line": 549,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 549,
                                                    "char": 39
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 550,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 552,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "prepared",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Loader.zep",
                                                    "line": 552,
                                                    "char": 30
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "localPaths",
                                                "file": "\/app\/phalcon\/Loader.zep",
                                                "line": 552,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Loader.zep",
                                            "line": 552,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Loader.zep",
                                    "line": 553,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 555,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "prepared",
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 555,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Loader.zep",
                            "line": 556,
                            "char": 5
                        }
                    ],
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Loader.zep",
                                "line": 540,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Loader.zep",
                        "line": 540,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Loader.zep",
                    "line": 539,
                    "last-line": 557,
                    "char": 22
                }
            ],
            "file": "\/app\/phalcon\/Loader.zep",
            "line": 43,
            "char": 5
        },
        "file": "\/app\/phalcon\/Loader.zep",
        "line": 43,
        "char": 5
    }
]