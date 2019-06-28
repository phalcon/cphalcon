[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Router",
        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                "line": 13,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Router",
                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                "line": 14,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Annotations\\Annotation",
                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                "line": 15,
                "char": 35
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Router\\Exception",
                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                "line": 16,
                "char": 33
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
        "line": 39,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Router\\Annotations\n *\n * A router that reads routes annotations from classes\/resources\n *\n * ```php\n * use Phalcon\\Mvc\\Router\\Annotations;\n *\n * $di->setShared(\n *     \"router\",\n *     function() {\n *         \/\/ Use the annotations router\n *         $router = new Annotations(false);\n *\n *         \/\/ This will do the same as above but only if the handled uri starts with \/robots\n *         $router->addResource(\"Robots\", \"\/robots\");\n *\n *         return $router;\n *     }\n * );\n * ```\n *",
        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
        "line": 40,
        "char": 5
    },
    {
        "type": "class",
        "name": "Annotations",
        "abstract": 0,
        "final": 0,
        "extends": "Router",
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "actionSuffix",
                    "default": {
                        "type": "string",
                        "value": "Action",
                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                        "line": 42,
                        "char": 36
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                    "line": 44,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "controllerSuffix",
                    "default": {
                        "type": "string",
                        "value": "Controller",
                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                        "line": 44,
                        "char": 44
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                    "line": 46,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "handlers",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                        "line": 46,
                        "char": 28
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                    "line": 48,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "routePrefix",
                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                    "line": 54,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addModuleResource",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "module",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 55,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 55,
                            "char": 70
                        },
                        {
                            "type": "parameter",
                            "name": "prefix",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                "line": 55,
                                "char": 93
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 55,
                            "char": 93
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-append",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "handlers",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "value": {
                                                    "type": "variable",
                                                    "value": "prefix",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 57,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 57,
                                                "char": 39
                                            },
                                            {
                                                "value": {
                                                    "type": "variable",
                                                    "value": "handler",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 57,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 57,
                                                "char": 48
                                            },
                                            {
                                                "value": {
                                                    "type": "variable",
                                                    "value": "module",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 57,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 57,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 57,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 57,
                                    "char": 57
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 59,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                "line": 59,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 60,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a resource to the annotations handler\n     * A resource is a class that contains routing annotations\n     * The class is located in a module\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Annotations",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 56,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                "line": 56,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                        "line": 56,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                    "line": 55,
                    "last-line": 65,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addResource",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 66,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "prefix",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                "line": 66,
                                "char": 71
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 66,
                            "char": 71
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-append",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "handlers",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "value": {
                                                    "type": "variable",
                                                    "value": "prefix",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 68,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 68,
                                                "char": 39
                                            },
                                            {
                                                "value": {
                                                    "type": "variable",
                                                    "value": "handler",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 68,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 68,
                                                "char": 48
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 68,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 68,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 70,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                "line": 70,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 71,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a resource to the annotations handler\n     * A resource is a class that contains routing annotations\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Annotations",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 67,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                "line": 67,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                        "line": 67,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                    "line": 66,
                    "last-line": 75,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getResources",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 78,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "handlers",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 78,
                                    "char": 30
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                "line": 78,
                                "char": 30
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 79,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return the registered resources\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                "line": 77,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                        "line": 77,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                    "line": 76,
                    "last-line": 83,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "handle",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "uri",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 84,
                            "char": 39
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "annotationsService",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 86,
                                    "char": 31
                                },
                                {
                                    "variable": "handlers",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 86,
                                    "char": 41
                                },
                                {
                                    "variable": "controllerSuffix",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 86,
                                    "char": 59
                                },
                                {
                                    "variable": "scope",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 86,
                                    "char": 66
                                },
                                {
                                    "variable": "prefix",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 86,
                                    "char": 74
                                },
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 87,
                                    "char": 22
                                },
                                {
                                    "variable": "handler",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 87,
                                    "char": 31
                                },
                                {
                                    "variable": "controllerName",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 87,
                                    "char": 47
                                },
                                {
                                    "variable": "lowerControllerName",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 87,
                                    "char": 68
                                },
                                {
                                    "variable": "namespaceName",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 88,
                                    "char": 26
                                },
                                {
                                    "variable": "moduleName",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 88,
                                    "char": 38
                                },
                                {
                                    "variable": "handlerAnnotations",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 88,
                                    "char": 58
                                },
                                {
                                    "variable": "classAnnotations",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 88,
                                    "char": 76
                                },
                                {
                                    "variable": "annotations",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 89,
                                    "char": 24
                                },
                                {
                                    "variable": "annotation",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 89,
                                    "char": 36
                                },
                                {
                                    "variable": "methodAnnotations",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 89,
                                    "char": 55
                                },
                                {
                                    "variable": "method",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 89,
                                    "char": 63
                                },
                                {
                                    "variable": "collection",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 89,
                                    "char": 75
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 90,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "sufixed",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 90,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 92,
                            "char": 11
                        },
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
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 92,
                                            "char": 54
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 92,
                                                "char": 44
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "container",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 92,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 92,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 92,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 92,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
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
                                            "value": "container",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 94,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 94,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 94,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 94,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                "line": 94,
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
                                                    "type": "scall",
                                                    "dynamic-class": 0,
                                                    "class": "Exception",
                                                    "dynamic": 0,
                                                    "name": "containerServiceNotFound",
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "the 'annotations' service",
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                "line": 96,
                                                                "char": 78
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                            "line": 96,
                                                            "char": 78
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 97,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 97,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 97,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 98,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 100,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "annotationsService",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "container",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 100,
                                            "char": 44
                                        },
                                        "name": "getShared",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "annotations",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 100,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 100,
                                                "char": 66
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 100,
                                        "char": 67
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 100,
                                    "char": 67
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 102,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "handlers",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 102,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "handlers",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 102,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 102,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 102,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 104,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "controllerSuffix",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 104,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "controllerSuffix",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 104,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 104,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 104,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 106,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "handlers",
                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                "line": 106,
                                "char": 31
                            },
                            "value": "scope",
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
                                                "value": "scope",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 107,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 107,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 107,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 107,
                                        "char": 38
                                    },
                                    "statements": [
                                        {
                                            "type": "continue",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 109,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 114,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "prefix",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "scope",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 114,
                                                    "char": 31
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 114,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 114,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 114,
                                            "char": 34
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 116,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "and",
                                        "left": {
                                            "type": "not",
                                            "left": {
                                                "type": "empty",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "prefix",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 116,
                                                    "char": 31
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 116,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 116,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "not",
                                            "left": {
                                                "type": "fcall",
                                                "name": "starts_with",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "uri",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                            "line": 116,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                        "line": 116,
                                                        "char": 49
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "prefix",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                            "line": 116,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                        "line": 116,
                                                        "char": 57
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 116,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 116,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 116,
                                        "char": 59
                                    },
                                    "statements": [
                                        {
                                            "type": "continue",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 118,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 123,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "handler",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "scope",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 123,
                                                    "char": 32
                                                },
                                                "right": {
                                                    "type": "int",
                                                    "value": "1",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 123,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 123,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 123,
                                            "char": 35
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 125,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "memstr",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "handler",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 125,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 125,
                                                "char": 30
                                            },
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "\\\\",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 125,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 125,
                                                "char": 34
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 125,
                                        "char": 36
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "controllerName",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "get_class_ns",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "handler",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                    "line": 131,
                                                                    "char": 58
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                "line": 131,
                                                                "char": 58
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                        "line": 131,
                                                        "char": 59
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 131,
                                                    "char": 59
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "namespaceName",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "get_ns_class",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "handler",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                    "line": 132,
                                                                    "char": 57
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                "line": 132,
                                                                "char": 57
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                        "line": 132,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 132,
                                                    "char": 58
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 133,
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
                                                    "variable": "controllerName",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "handler",
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                        "line": 134,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 134,
                                                    "char": 45
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 136,
                                            "char": 21
                                        },
                                        {
                                            "type": "fetch",
                                            "expr": {
                                                "type": "fetch",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "namespaceName",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 136,
                                                    "char": 60
                                                },
                                                "right": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                        "line": 136,
                                                        "char": 43
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "defaultNamespace",
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                        "line": 136,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 136,
                                                    "char": 60
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 136,
                                                "char": 60
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 137,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 139,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "routePrefix",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 139,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 139,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 144,
                                    "char": 17
                                },
                                {
                                    "type": "fetch",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "moduleName",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 144,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "scope",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 144,
                                                "char": 36
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "2",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 144,
                                                "char": 38
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 144,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 144,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 146,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "sufixed",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "controllerName",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 146,
                                                    "char": 42
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "controllerSuffix",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 146,
                                                    "char": 60
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 146,
                                                "char": 60
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 146,
                                            "char": 60
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 151,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "namespaceName",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 151,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 151,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 151,
                                        "char": 39
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "sufixed",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "namespaceName",
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                "line": 152,
                                                                "char": 45
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "\\\\",
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                "line": 152,
                                                                "char": 50
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                            "line": 152,
                                                            "char": 50
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "sufixed",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                            "line": 152,
                                                            "char": 59
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                        "line": 152,
                                                        "char": 59
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 152,
                                                    "char": 59
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 153,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 158,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "handlerAnnotations",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "annotationsService",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 158,
                                                    "char": 57
                                                },
                                                "name": "get",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "sufixed",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                            "line": 158,
                                                            "char": 69
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                        "line": 158,
                                                        "char": 69
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 158,
                                                "char": 70
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 158,
                                            "char": 70
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 160,
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
                                                "value": "handlerAnnotations",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 160,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 160,
                                            "char": 43
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "object",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 160,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 160,
                                        "char": 52
                                    },
                                    "statements": [
                                        {
                                            "type": "continue",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 162,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 167,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "classAnnotations",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "handlerAnnotations",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 167,
                                                    "char": 55
                                                },
                                                "name": "getClassAnnotations",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 167,
                                                "char": 77
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 167,
                                            "char": 77
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 169,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "classAnnotations",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 169,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 169,
                                            "char": 41
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "object",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 169,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 169,
                                        "char": 50
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "annotations",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "classAnnotations",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                            "line": 170,
                                                            "char": 52
                                                        },
                                                        "name": "getAnnotations",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                        "line": 170,
                                                        "char": 69
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 170,
                                                    "char": 69
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 172,
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
                                                        "value": "annotations",
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                        "line": 172,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 172,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "array",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 172,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 172,
                                                "char": 48
                                            },
                                            "statements": [
                                                {
                                                    "type": "for",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "annotations",
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                        "line": 173,
                                                        "char": 51
                                                    },
                                                    "value": "annotation",
                                                    "reverse": 0,
                                                    "statements": [
                                                        {
                                                            "type": "mcall",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                    "line": 174,
                                                                    "char": 30
                                                                },
                                                                "name": "processControllerAnnotation",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "controllerName",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                            "line": 175,
                                                                            "char": 43
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                        "line": 175,
                                                                        "char": 43
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "annotation",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                            "line": 177,
                                                                            "char": 25
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                        "line": 177,
                                                                        "char": 25
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                "line": 177,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                            "line": 178,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 179,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 180,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 185,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "methodAnnotations",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "handlerAnnotations",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 185,
                                                    "char": 56
                                                },
                                                "name": "getMethodsAnnotations",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 185,
                                                "char": 80
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 185,
                                            "char": 80
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 187,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "methodAnnotations",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 187,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 187,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 187,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 187,
                                        "char": 50
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "lowerControllerName",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "uncamelize",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "controllerName",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                    "line": 188,
                                                                    "char": 68
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                "line": 188,
                                                                "char": 68
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                        "line": 188,
                                                        "char": 69
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 188,
                                                    "char": 69
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 190,
                                            "char": 19
                                        },
                                        {
                                            "type": "for",
                                            "expr": {
                                                "type": "variable",
                                                "value": "methodAnnotations",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 190,
                                                "char": 61
                                            },
                                            "key": "method",
                                            "value": "collection",
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
                                                                "value": "collection",
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                "line": 191,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                            "line": 191,
                                                            "char": 43
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "object",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                            "line": 191,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                        "line": 191,
                                                        "char": 52
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "continue",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                            "line": 193,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 195,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "for",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "collection",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                            "line": 195,
                                                            "char": 50
                                                        },
                                                        "name": "getAnnotations",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                        "line": 195,
                                                        "char": 68
                                                    },
                                                    "value": "annotation",
                                                    "reverse": 0,
                                                    "statements": [
                                                        {
                                                            "type": "mcall",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                    "line": 196,
                                                                    "char": 30
                                                                },
                                                                "name": "processActionAnnotation",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "moduleName",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                            "line": 197,
                                                                            "char": 39
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                        "line": 197,
                                                                        "char": 39
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "namespaceName",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                            "line": 198,
                                                                            "char": 42
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                        "line": 198,
                                                                        "char": 42
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "lowerControllerName",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                            "line": 199,
                                                                            "char": 48
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                        "line": 199,
                                                                        "char": 48
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "method",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                            "line": 200,
                                                                            "char": 35
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                        "line": 200,
                                                                        "char": 35
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "annotation",
                                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                            "line": 202,
                                                                            "char": 25
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                        "line": 202,
                                                                        "char": 25
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                "line": 202,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                            "line": 203,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 204,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 205,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 206,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 211,
                            "char": 14
                        },
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "handle",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "uri",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 211,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 211,
                                        "char": 27
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                "line": 211,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 212,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Produce the routing parameters from the rewrite information\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                    "line": 84,
                    "last-line": 216,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "processActionAnnotation",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "module",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 217,
                            "char": 59
                        },
                        {
                            "type": "parameter",
                            "name": "namespaceName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 217,
                            "char": 82
                        },
                        {
                            "type": "parameter",
                            "name": "controller",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 217,
                            "char": 102
                        },
                        {
                            "type": "parameter",
                            "name": "action",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 217,
                            "char": 118
                        },
                        {
                            "type": "parameter",
                            "name": "annotation",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Annotation",
                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                "line": 218,
                                "char": 31
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 218,
                            "char": 32
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 220,
                                    "char": 17
                                },
                                {
                                    "variable": "actionName",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 220,
                                    "char": 29
                                },
                                {
                                    "variable": "routePrefix",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 220,
                                    "char": 42
                                },
                                {
                                    "variable": "paths",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 220,
                                    "char": 49
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 220,
                                    "char": 56
                                },
                                {
                                    "variable": "uri",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 220,
                                    "char": 61
                                },
                                {
                                    "variable": "route",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 220,
                                    "char": 68
                                },
                                {
                                    "variable": "methods",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 220,
                                    "char": 77
                                },
                                {
                                    "variable": "converts",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 221,
                                    "char": 21
                                },
                                {
                                    "variable": "param",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 221,
                                    "char": 28
                                },
                                {
                                    "variable": "convert",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 221,
                                    "char": 37
                                },
                                {
                                    "variable": "conversorParam",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 221,
                                    "char": 53
                                },
                                {
                                    "variable": "routeName",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 221,
                                    "char": 64
                                },
                                {
                                    "variable": "beforeMatch",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 221,
                                    "char": 77
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 222,
                            "char": 12
                        },
                        {
                            "type": "declare",
                            "data-type": "bool",
                            "variables": [
                                {
                                    "variable": "isRoute",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 222,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 224,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "isRoute",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 224,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 224,
                                    "char": 28
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "methods",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 225,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 225,
                                    "char": 27
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "name",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "annotation",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 226,
                                            "char": 31
                                        },
                                        "name": "getName",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 226,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 226,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 231,
                            "char": 14
                        },
                        {
                            "type": "switch",
                            "expr": {
                                "type": "variable",
                                "value": "name",
                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                "line": 231,
                                "char": 21
                            },
                            "clauses": [
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "Route",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 232,
                                        "char": 23
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "isRoute",
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "true",
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                        "line": 233,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 233,
                                                    "char": 35
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 234,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 236,
                                            "char": 16
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 236,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "Get",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 236,
                                        "char": 21
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 237,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "Post",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 237,
                                        "char": 22
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 238,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "Put",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 238,
                                        "char": 21
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 239,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "Patch",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 239,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 240,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "Delete",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 240,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 241,
                                    "char": 16
                                },
                                {
                                    "type": "case",
                                    "expr": {
                                        "type": "string",
                                        "value": "Options",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 241,
                                        "char": 25
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "isRoute",
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "true",
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                        "line": 242,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 242,
                                                    "char": 35
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "methods",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "strtoupper",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "name",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                    "line": 243,
                                                                    "char": 46
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                "line": 243,
                                                                "char": 46
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                        "line": 243,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 243,
                                                    "char": 47
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 244,
                                            "char": 21
                                        },
                                        {
                                            "type": "break",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 245,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 245,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 247,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "isRoute",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 247,
                                    "char": 21
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                "line": 247,
                                "char": 21
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 249,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 251,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "actionName",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "strtolower",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "fcall",
                                                    "name": "str_replace",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "property-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                    "line": 251,
                                                                    "char": 54
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "actionSuffix",
                                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                    "line": 251,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                "line": 251,
                                                                "char": 67
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                            "line": 251,
                                                            "char": 67
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "",
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                "line": 251,
                                                                "char": 69
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                            "line": 251,
                                                            "char": 69
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "action",
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                "line": 251,
                                                                "char": 77
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                            "line": 251,
                                                            "char": 77
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 251,
                                                    "char": 78
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 251,
                                                "char": 78
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 251,
                                        "char": 79
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 251,
                                    "char": 79
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "routePrefix",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 252,
                                            "char": 32
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "routePrefix",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 252,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 252,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 252,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 257,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "paths",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "annotation",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 257,
                                            "char": 32
                                        },
                                        "name": "getNamedArgument",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "paths",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 257,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 257,
                                                "char": 55
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 257,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 257,
                                    "char": 56
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 259,
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
                                        "value": "paths",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 259,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 259,
                                    "char": 26
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 259,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                "line": 259,
                                "char": 34
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "paths",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 260,
                                                "char": 27
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 260,
                                            "char": 27
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 261,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 266,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "empty",
                                    "left": {
                                        "type": "variable",
                                        "value": "module",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 266,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 266,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                "line": 266,
                                "char": 26
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "paths",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "module",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 267,
                                                    "char": 29
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "module",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 267,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 267,
                                            "char": 39
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 268,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 273,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "empty",
                                    "left": {
                                        "type": "variable",
                                        "value": "namespaceName",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 273,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 273,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                "line": 273,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "array-index",
                                            "operator": "assign",
                                            "variable": "paths",
                                            "index-expr": [
                                                {
                                                    "type": "string",
                                                    "value": "namespace",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 274,
                                                    "char": 32
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "namespaceName",
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 274,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 274,
                                            "char": 49
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 275,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 277,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "array-index",
                                    "operator": "assign",
                                    "variable": "paths",
                                    "index-expr": [
                                        {
                                            "type": "string",
                                            "value": "controller",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 277,
                                            "char": 29
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "controller",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 277,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 277,
                                    "char": 43
                                },
                                {
                                    "assign-type": "array-index",
                                    "operator": "assign",
                                    "variable": "paths",
                                    "index-expr": [
                                        {
                                            "type": "string",
                                            "value": "action",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 278,
                                            "char": 25
                                        }
                                    ],
                                    "expr": {
                                        "type": "variable",
                                        "value": "actionName",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 278,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 278,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 280,
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
                                            "value": "annotation",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 280,
                                            "char": 32
                                        },
                                        "name": "getArgument",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "int",
                                                    "value": "0",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 280,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 280,
                                                "char": 46
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 280,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 280,
                                    "char": 47
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 285,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "variable",
                                    "value": "value",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 285,
                                    "char": 20
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 285,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                "line": 285,
                                "char": 27
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-equals",
                                        "left": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 286,
                                            "char": 23
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "\/",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 286,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 286,
                                        "char": 27
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
                                                            "value": "routePrefix",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                            "line": 287,
                                                            "char": 39
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "value",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                            "line": 287,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                        "line": 287,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 287,
                                                    "char": 46
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 288,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not-identical",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "routePrefix",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 289,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 289,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 289,
                                                "char": 41
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
                                                                "value": "routePrefix",
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                "line": 290,
                                                                "char": 42
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                            "line": 290,
                                                            "char": 42
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 291,
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
                                                                "type": "variable",
                                                                "value": "value",
                                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                                "line": 292,
                                                                "char": 36
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                            "line": 292,
                                                            "char": 36
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 293,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 294,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 295,
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
                                            "variable": "uri",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "routePrefix",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 296,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "actionName",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 296,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 296,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 296,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 297,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 302,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "route",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 302,
                                            "char": 26
                                        },
                                        "name": "add",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "uri",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 302,
                                                    "char": 34
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 302,
                                                "char": 34
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "paths",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 302,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 302,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 302,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 302,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 307,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "methods",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 307,
                                    "char": 22
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 307,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                "line": 307,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "methods",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "annotation",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 308,
                                                    "char": 38
                                                },
                                                "name": "getNamedArgument",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "methods",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                            "line": 308,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                        "line": 308,
                                                        "char": 63
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 308,
                                                "char": 64
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 308,
                                            "char": 64
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 309,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 311,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "methods",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 311,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 311,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 311,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 311,
                                    "char": 37
                                },
                                "right": {
                                    "type": "equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "methods",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 311,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 311,
                                        "char": 55
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "string",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 311,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 311,
                                    "char": 64
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                "line": 311,
                                "char": 64
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "route",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 312,
                                            "char": 19
                                        },
                                        "name": "via",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "methods",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 312,
                                                    "char": 31
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 312,
                                                "char": 31
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 312,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 313,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 318,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "converts",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "annotation",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 318,
                                            "char": 35
                                        },
                                        "name": "getNamedArgument",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "converts",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 318,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 318,
                                                "char": 61
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 318,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 318,
                                    "char": 62
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 320,
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
                                        "value": "converts",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 320,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 320,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 320,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                "line": 320,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "converts",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 321,
                                        "char": 44
                                    },
                                    "key": "param",
                                    "value": "convert",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "route",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 322,
                                                    "char": 23
                                                },
                                                "name": "convert",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "param",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                            "line": 322,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                        "line": 322,
                                                        "char": 37
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "convert",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                            "line": 322,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                        "line": 322,
                                                        "char": 46
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 322,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 323,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 324,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 329,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "converts",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "annotation",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 329,
                                            "char": 35
                                        },
                                        "name": "getNamedArgument",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "conversors",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 329,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 329,
                                                "char": 63
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 329,
                                        "char": 64
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 329,
                                    "char": 64
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 331,
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
                                        "value": "converts",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 331,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 331,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 331,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                "line": 331,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "converts",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 332,
                                        "char": 53
                                    },
                                    "key": "conversorParam",
                                    "value": "convert",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "route",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 333,
                                                    "char": 23
                                                },
                                                "name": "convert",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "conversorParam",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                            "line": 333,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                        "line": 333,
                                                        "char": 46
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "convert",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                            "line": 333,
                                                            "char": 55
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                        "line": 333,
                                                        "char": 55
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 333,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 334,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 335,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 340,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "beforeMatch",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "annotation",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 340,
                                            "char": 38
                                        },
                                        "name": "getNamedArgument",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "beforeMatch",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 340,
                                                    "char": 67
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 340,
                                                "char": 67
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 340,
                                        "char": 68
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 340,
                                    "char": 68
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 342,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "beforeMatch",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 342,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 342,
                                        "char": 32
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 342,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 342,
                                    "char": 41
                                },
                                "right": {
                                    "type": "equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "beforeMatch",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 342,
                                            "char": 63
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 342,
                                        "char": 63
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "string",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 342,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 342,
                                    "char": 72
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                "line": 342,
                                "char": 72
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "route",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 343,
                                            "char": 19
                                        },
                                        "name": "beforeMatch",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "beforeMatch",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 343,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 343,
                                                "char": 43
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 343,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 344,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 346,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "routeName",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "annotation",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 346,
                                            "char": 36
                                        },
                                        "name": "getNamedArgument",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "name",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 346,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 346,
                                                "char": 58
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 346,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 346,
                                    "char": 59
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 348,
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
                                        "value": "routeName",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 348,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 348,
                                    "char": 30
                                },
                                "right": {
                                    "type": "string",
                                    "value": "string",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 348,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                "line": 348,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "route",
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 349,
                                            "char": 19
                                        },
                                        "name": "setName",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "routeName",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 349,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 349,
                                                "char": 37
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 349,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 350,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 352,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                "line": 352,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 353,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks for annotations in the public methods of the controller\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                    "line": 217,
                    "last-line": 357,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "processControllerAnnotation",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "handler",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 358,
                            "char": 64
                        },
                        {
                            "type": "parameter",
                            "name": "annotation",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Annotation",
                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                "line": 358,
                                "char": 88
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 358,
                            "char": 89
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "annotation",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 363,
                                        "char": 23
                                    },
                                    "name": "getName",
                                    "call-type": 1,
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 363,
                                    "char": 35
                                },
                                "right": {
                                    "type": "string",
                                    "value": "RoutePrefix",
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 363,
                                    "char": 49
                                },
                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                "line": 363,
                                "char": 49
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "routePrefix",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "annotation",
                                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                    "line": 364,
                                                    "char": 48
                                                },
                                                "name": "getArgument",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "int",
                                                            "value": "0",
                                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                            "line": 364,
                                                            "char": 62
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                        "line": 364,
                                                        "char": 62
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                                "line": 364,
                                                "char": 63
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                            "line": 364,
                                            "char": 63
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 365,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 366,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks for annotations in the controller docblock\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                    "line": 358,
                    "last-line": 370,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setActionSuffix",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "actionSuffix",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 371,
                            "char": 57
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
                                    "property": "actionSuffix",
                                    "expr": {
                                        "type": "variable",
                                        "value": "actionSuffix",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 373,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 373,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 374,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Changes the action method suffix\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                    "line": 371,
                    "last-line": 378,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setControllerSuffix",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "controllerSuffix",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 379,
                            "char": 65
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
                                    "property": "controllerSuffix",
                                    "expr": {
                                        "type": "variable",
                                        "value": "controllerSuffix",
                                        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                        "line": 381,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                                    "line": 381,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                            "line": 382,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Changes the controller class suffix\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
                    "line": 379,
                    "last-line": 383,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
            "line": 40,
            "char": 5
        },
        "file": "\/app\/phalcon\/Mvc\/Router\/Annotations.zep",
        "line": 40,
        "char": 5
    }
]