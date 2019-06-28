[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Acl\\Adapter",
        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Acl",
                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                "line": 13,
                "char": 16
            }
        ],
        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Acl\\Adapter",
                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                "line": 14,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Acl\\Role",
                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                "line": 15,
                "char": 21
            }
        ],
        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Acl\\RoleInterface",
                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                "line": 16,
                "char": 30
            }
        ],
        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Acl\\Component",
                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                "line": 17,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Acl\\Exception",
                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                "line": 18,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\Manager",
                "alias": "EventsManager",
                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                "line": 19,
                "char": 44
            }
        ],
        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Acl\\RoleAware",
                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                "line": 20,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
        "line": 21,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Acl\\ComponentAware",
                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                "line": 21,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
        "line": 22,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Acl\\RoleInterface",
                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                "line": 22,
                "char": 30
            }
        ],
        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
        "line": 23,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Acl\\ComponentInterface",
                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                "line": 23,
                "char": 35
            }
        ],
        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
        "line": 24,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "ReflectionFunction",
                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                "line": 24,
                "char": 23
            }
        ],
        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
        "line": 88,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Manages ACL lists in memory\n *\n *```php\n * $acl = new \\Phalcon\\Acl\\Adapter\\Memory();\n *\n * $acl->setDefaultAction(\n *     \\Phalcon\\Acl::DENY\n * );\n *\n * \/\/ Register roles\n * $roles = [\n *     \"users\"  => new \\Phalcon\\Acl\\Role(\"Users\"),\n *     \"guests\" => new \\Phalcon\\Acl\\Role(\"Guests\"),\n * ];\n * foreach ($roles as $role) {\n *     $acl->addRole($role);\n * }\n *\n * \/\/ Private area components\n * $privateComponents = [\n *     \"companies\" => [\"index\", \"search\", \"new\", \"edit\", \"save\", \"create\", \"delete\"],\n *     \"products\"  => [\"index\", \"search\", \"new\", \"edit\", \"save\", \"create\", \"delete\"],\n *     \"invoices\"  => [\"index\", \"profile\"],\n * ];\n *\n * foreach ($privateComponents as $componentName => $actions) {\n *     $acl->addComponent(\n *         new \\Phalcon\\Acl\\Component($componentName),\n *         $actions\n *     );\n * }\n *\n * \/\/ Public area components\n * $publicComponents = [\n *     \"index\"   => [\"index\"],\n *     \"about\"   => [\"index\"],\n *     \"session\" => [\"index\", \"register\", \"start\", \"end\"],\n *     \"contact\" => [\"index\", \"send\"],\n * ];\n *\n * foreach ($publicComponents as $componentName => $actions) {\n *     $acl->addComponent(\n *         new \\Phalcon\\Acl\\Component($componentName),\n *         $actions\n *     );\n * }\n *\n * \/\/ Grant access to public areas to both users and guests\n * foreach ($roles as $role) {\n *     foreach ($publicComponents as $component => $actions) {\n *         $acl->allow($role->getName(), $component, \"*\");\n *     }\n * }\n *\n * \/\/ Grant access to private area to role Users\n * foreach ($privateComponents as $component => $actions) {\n *     foreach ($actions as $action) {\n *         $acl->allow(\"Users\", $component, $action);\n *     }\n * }\n *```\n *",
        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
        "line": 89,
        "char": 5
    },
    {
        "type": "class",
        "name": "Memory",
        "abstract": 0,
        "final": 0,
        "extends": "Adapter",
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "access",
                    "docblock": "**\n     * Access\n     *\n     * @var mixed\n     *",
                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                    "line": 102,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "accessList",
                    "docblock": "**\n     * Access List\n     *\n     * @var mixed\n     *",
                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                    "line": 109,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "activeFunction",
                    "docblock": "**\n     * Returns latest function used to acquire access\n     *\n     * @var mixed\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 110,
                            "char": 36
                        }
                    ],
                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                    "line": 116,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "activeFunctionCustomArgumentsCount",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                        "line": 117,
                        "char": 54
                    },
                    "docblock": "**\n     * Returns number of additional arguments(excluding role and resource) for active function\n     *\n     * @var int\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 117,
                            "char": 60
                        }
                    ],
                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                    "line": 123,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "activeKey",
                    "docblock": "**\n     * Returns latest key used to acquire access\n     *\n     * @var string|null\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 124,
                            "char": 31
                        }
                    ],
                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                    "line": 130,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "components",
                    "docblock": "**\n     * Components\n     *\n     * @var mixed\n     *",
                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                    "line": 137,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "componentsNames",
                    "docblock": "**\n     * Component Names\n     *\n     * @var mixed\n     *",
                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                    "line": 144,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "func",
                    "docblock": "**\n     * Function List\n     *\n     * @var mixed\n     *",
                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                    "line": 151,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "noArgumentsDefaultAction",
                    "default": {
                        "type": "static-constant-access",
                        "left": {
                            "type": "variable",
                            "value": "Acl",
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 152,
                            "char": 51
                        },
                        "right": {
                            "type": "variable",
                            "value": "DENY",
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 152,
                            "char": 51
                        },
                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                        "line": 152,
                        "char": 51
                    },
                    "docblock": "**\n     * Default action for no arguments is allow\n     *\n     * @var mixed\n     *",
                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                    "line": 158,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "roles",
                    "docblock": "**\n     * Roles\n     *\n     * @var mixed\n     *",
                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                    "line": 165,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "roleInherits",
                    "docblock": "**\n     * Role Inherits\n     *\n     * @var mixed\n     *",
                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                    "line": 172,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "rolesNames",
                    "docblock": "**\n     * Roles Names\n     *\n     * @var mixed\n     *",
                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                    "line": 177,
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
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "componentsNames",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "*",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 180,
                                                    "char": 39
                                                },
                                                "value": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 180,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 180,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 180,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 180,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 181,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "accessList",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "*!*",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 181,
                                                    "char": 36
                                                },
                                                "value": {
                                                    "type": "bool",
                                                    "value": "true",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 181,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 181,
                                                "char": 42
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 181,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 181,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 182,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Acl\\Adapter\\Memory constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                        "line": 179,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                    "line": 178,
                    "last-line": 217,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addComponent",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "componentValue",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 218,
                            "char": 52
                        },
                        {
                            "type": "parameter",
                            "name": "accessList",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 218,
                            "char": 68
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "componentName",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 220,
                                    "char": 26
                                },
                                {
                                    "variable": "componentObject",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 220,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 222,
                            "char": 10
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
                                            "value": "componentValue",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 222,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 222,
                                        "char": 35
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 222,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 222,
                                    "char": 45
                                },
                                "right": {
                                    "type": "instanceof",
                                    "left": {
                                        "type": "variable",
                                        "value": "componentValue",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 222,
                                        "char": 71
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "ComponentInterface",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 222,
                                        "char": 92
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 222,
                                    "char": 92
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 222,
                                "char": 92
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "componentObject",
                                            "expr": {
                                                "type": "variable",
                                                "value": "componentValue",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 223,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 223,
                                            "char": 49
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 224,
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
                                            "variable": "componentObject",
                                            "expr": {
                                                "type": "new",
                                                "class": "Component",
                                                "dynamic": 0,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "componentValue",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 225,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 225,
                                                        "char": 63
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 225,
                                                "char": 64
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 225,
                                            "char": 64
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 226,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 228,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "componentName",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "componentObject",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 228,
                                            "char": 45
                                        },
                                        "name": "getName",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 228,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 228,
                                    "char": 55
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 230,
                            "char": 10
                        },
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
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 230,
                                                "char": 24
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "componentsNames",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 230,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 230,
                                            "char": 40
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "componentName",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 230,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 230,
                                        "char": 56
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 230,
                                    "char": 56
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 230,
                                "char": 56
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property-append",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "components",
                                            "expr": {
                                                "type": "variable",
                                                "value": "componentObject",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 231,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 231,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 232,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property-array-index",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "componentsNames",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "componentName",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 232,
                                                    "char": 52
                                                }
                                            ],
                                            "expr": {
                                                "type": "bool",
                                                "value": "true",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 232,
                                                "char": 60
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 232,
                                            "char": 60
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 233,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 235,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 235,
                                    "char": 21
                                },
                                "name": "addComponentAccess",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "componentName",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 235,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 235,
                                        "char": 54
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "accessList",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 235,
                                            "char": 66
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 235,
                                        "char": 66
                                    }
                                ],
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 235,
                                "char": 67
                            },
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 236,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a component to the ACL list\n     *\n     * Access names can be a particular action, by example\n     * search, update, delete, etc or a list of them\n     *\n     * Example:\n     * ```php\n     * \/\/ Add a component to the the list allowing access to an action\n     * $acl->addComponent(\n     *     new Phalcon\\Acl\\Component(\"customers\"),\n     *     \"search\"\n     * );\n     *\n     * $acl->addComponent(\"customers\", \"search\");\n     *\n     * \/\/ Add a component  with an access list\n     * $acl->addComponent(\n     *     new Phalcon\\Acl\\Component(\"customers\"),\n     *     [\n     *         \"create\",\n     *         \"search\",\n     *     ]\n     * );\n     *\n     * $acl->addComponent(\n     *     \"customers\",\n     *     [\n     *         \"create\",\n     *         \"search\",\n     *     ]\n     * );\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 219,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                        "line": 219,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                    "line": 218,
                    "last-line": 240,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addComponentAccess",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "componentName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 241,
                            "char": 60
                        },
                        {
                            "type": "parameter",
                            "name": "accessList",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 241,
                            "char": 76
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "accessName",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 243,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 244,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "accessKey",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 244,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 245,
                            "char": 12
                        },
                        {
                            "type": "declare",
                            "data-type": "bool",
                            "variables": [
                                {
                                    "variable": "exists",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 245,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 247,
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
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 247,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "componentsNames",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 247,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 247,
                                                "char": 49
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "componentName",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 247,
                                                "char": 63
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 247,
                                            "char": 65
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 247,
                                        "char": 65
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 247,
                                    "char": 65
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 247,
                                "char": 65
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
                                                            "value": "Component '",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 249,
                                                            "char": 29
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "componentName",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 249,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 249,
                                                        "char": 45
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "' does not exist in ACL",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 250,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 250,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 250,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 250,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 251,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 253,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "list",
                                    "left": {
                                        "type": "and",
                                        "left": {
                                            "type": "not-equals",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "accessList",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 253,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 253,
                                                "char": 41
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "array",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 253,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 253,
                                            "char": 50
                                        },
                                        "right": {
                                            "type": "not-equals",
                                            "left": {
                                                "type": "typeof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "accessList",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 253,
                                                    "char": 71
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 253,
                                                "char": 71
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "string",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 253,
                                                "char": 79
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 253,
                                            "char": 79
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 253,
                                        "char": 79
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 253,
                                    "char": 81
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 253,
                                "char": 81
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
                                                    "value": "Invalid value for accessList",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 254,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 254,
                                                "char": 61
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 254,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 255,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 257,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "exists",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 257,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 257,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 259,
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
                                        "value": "accessList",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 259,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 259,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 259,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 259,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "accessList",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 260,
                                        "char": 42
                                    },
                                    "value": "accessName",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "accessKey",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "componentName",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 261,
                                                                "char": 47
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "!",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 261,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 261,
                                                            "char": 51
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "accessName",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 261,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 261,
                                                        "char": 63
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 261,
                                                    "char": 63
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 263,
                                            "char": 18
                                        },
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
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 263,
                                                                "char": 32
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "accessList",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 263,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 263,
                                                            "char": 43
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "accessKey",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 263,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 263,
                                                        "char": 55
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 263,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 263,
                                                "char": 55
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property-array-index",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "accessList",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "accessKey",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 264,
                                                                    "char": 51
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "exists",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 264,
                                                                "char": 61
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 264,
                                                            "char": 61
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 265,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 266,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 267,
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
                                            "variable": "accessKey",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "componentName",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 268,
                                                        "char": 43
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "!",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 268,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 268,
                                                    "char": 47
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "accessList",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 268,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 268,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 268,
                                            "char": 59
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 270,
                                    "char": 14
                                },
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
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 270,
                                                        "char": 28
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "accessList",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 270,
                                                        "char": 39
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 270,
                                                    "char": 39
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "accessKey",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 270,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 270,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 270,
                                            "char": 51
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 270,
                                        "char": 51
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property-array-index",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "accessList",
                                                    "index-expr": [
                                                        {
                                                            "type": "variable",
                                                            "value": "accessKey",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 271,
                                                            "char": 47
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "exists",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 271,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 271,
                                                    "char": 57
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 272,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 273,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 275,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 275,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 276,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds access to components\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 242,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                        "line": 242,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                    "line": 241,
                    "last-line": 285,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addInherit",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "roleName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 286,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "roleToInherits",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 286,
                            "char": 67
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "roleInheritName",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 288,
                                    "char": 28
                                },
                                {
                                    "variable": "rolesNames",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 288,
                                    "char": 40
                                },
                                {
                                    "variable": "roleToInherit",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 288,
                                    "char": 55
                                },
                                {
                                    "variable": "checkRoleToInherit",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 288,
                                    "char": 75
                                },
                                {
                                    "variable": "roleToInheritList",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 289,
                                    "char": 30
                                },
                                {
                                    "variable": "usedRoleToInherit",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 289,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 290,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "checkRoleToInherits",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 290,
                                    "char": 34
                                },
                                {
                                    "variable": "usedRoleToInherits",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 290,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 292,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "rolesNames",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 292,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "rolesNames",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 292,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 292,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 292,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 294,
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
                                                "value": "rolesNames",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 294,
                                                "char": 38
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "roleName",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 294,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 294,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 294,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 294,
                                    "char": 49
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 294,
                                "char": 49
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
                                                            "value": "Role '",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 296,
                                                            "char": 24
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "roleName",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 296,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 296,
                                                        "char": 35
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "' does not exist in the role list",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 297,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 297,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 297,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 297,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 298,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 300,
                            "char": 10
                        },
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
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 300,
                                                "char": 24
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "roleInherits",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 300,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 300,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "roleName",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 300,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 300,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 300,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 300,
                                "char": 48
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property-array-index",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "roleInherits",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "roleName",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 301,
                                                    "char": 44
                                                }
                                            ],
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 301,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 301,
                                            "char": 50
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 302,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 307,
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
                                        "value": "roleToInherits",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 307,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 307,
                                    "char": 35
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 307,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 307,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "roleToInheritList",
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "roleToInherits",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 308,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 308,
                                                        "char": 52
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 308,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 308,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 309,
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
                                            "variable": "roleToInheritList",
                                            "expr": {
                                                "type": "variable",
                                                "value": "roleToInherits",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 310,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 310,
                                            "char": 51
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 311,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 316,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "roleToInheritList",
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 316,
                                "char": 48
                            },
                            "value": "roleToInherit",
                            "reverse": 0,
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
                                                    "value": "roleToInherit",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 317,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 317,
                                                "char": 38
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 317,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 317,
                                            "char": 48
                                        },
                                        "right": {
                                            "type": "instanceof",
                                            "left": {
                                                "type": "variable",
                                                "value": "roleToInherit",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 317,
                                                "char": 73
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "RoleInterface",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 317,
                                                "char": 89
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 317,
                                            "char": 89
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 317,
                                        "char": 89
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "roleInheritName",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "roleToInherit",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 318,
                                                            "char": 53
                                                        },
                                                        "name": "getName",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 318,
                                                        "char": 63
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 318,
                                                    "char": 63
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 319,
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
                                                    "variable": "roleInheritName",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "roleToInherit",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 320,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 320,
                                                    "char": 52
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 321,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 326,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "in_array",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "roleInheritName",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 326,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 326,
                                                "char": 40
                                            },
                                            {
                                                "parameter": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 326,
                                                            "char": 47
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "roleInherits",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 326,
                                                            "char": 60
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 326,
                                                        "char": 60
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "roleName",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 326,
                                                        "char": 69
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 326,
                                                    "char": 70
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 326,
                                                "char": 70
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 326,
                                        "char": 72
                                    },
                                    "statements": [
                                        {
                                            "type": "continue",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 328,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 333,
                                    "char": 14
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
                                                        "value": "rolesNames",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 333,
                                                        "char": 42
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "roleInheritName",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 333,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 333,
                                                    "char": 60
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 333,
                                                "char": 60
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 333,
                                            "char": 60
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 333,
                                        "char": 60
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
                                                                    "value": "Role '",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 335,
                                                                    "char": 28
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "roleInheritName",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 335,
                                                                    "char": 46
                                                                },
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 335,
                                                                "char": 46
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "' (to inherit) does not exist in the role list",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 337,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 337,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 337,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 337,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 338,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 340,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "variable",
                                            "value": "roleName",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 340,
                                            "char": 26
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "roleInheritName",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 340,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 340,
                                        "char": 44
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 341,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 342,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 347,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "isset",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 347,
                                                    "char": 27
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "roleInherits",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 347,
                                                    "char": 40
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 347,
                                                "char": 40
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "roleInheritName",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 347,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 347,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 347,
                                        "char": 58
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "checkRoleToInherits",
                                                    "expr": {
                                                        "type": "empty-array",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 348,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 348,
                                                    "char": 45
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 350,
                                            "char": 19
                                        },
                                        {
                                            "type": "for",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 350,
                                                        "char": 47
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "roleInherits",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 350,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 350,
                                                    "char": 60
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "roleInheritName",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 350,
                                                    "char": 76
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 350,
                                                "char": 78
                                            },
                                            "value": "usedRoleToInherit",
                                            "reverse": 0,
                                            "statements": [
                                                {
                                                    "type": "fcall",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "array_push",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "checkRoleToInherits",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 351,
                                                                    "char": 51
                                                                },
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 351,
                                                                "char": 51
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "usedRoleToInherit",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 351,
                                                                    "char": 70
                                                                },
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 351,
                                                                "char": 70
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 351,
                                                        "char": 71
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 352,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 354,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "usedRoleToInherits",
                                                    "expr": {
                                                        "type": "empty-array",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 354,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 354,
                                                    "char": 44
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 356,
                                            "char": 21
                                        },
                                        {
                                            "type": "while",
                                            "expr": {
                                                "type": "not",
                                                "left": {
                                                    "type": "empty",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "checkRoleToInherits",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 356,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 356,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 356,
                                                "char": 50
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "checkRoleToInherit",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "array_shift",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "checkRoleToInherits",
                                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                            "line": 357,
                                                                            "char": 77
                                                                        },
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 357,
                                                                        "char": 77
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 357,
                                                                "char": 78
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 357,
                                                            "char": 78
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 359,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "isset",
                                                        "left": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "usedRoleToInherits",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 359,
                                                                "char": 48
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "checkRoleToInherit",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 359,
                                                                "char": 67
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 359,
                                                            "char": 69
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 359,
                                                        "char": 69
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "continue",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 361,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 363,
                                                    "char": 23
                                                },
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "usedRoleToInherits",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "checkRoleToInherit",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 363,
                                                                    "char": 62
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 363,
                                                                "char": 70
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 363,
                                                            "char": 70
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 365,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "unlikely",
                                                        "left": {
                                                            "type": "equals",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "roleName",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 365,
                                                                "char": 43
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "checkRoleToInherit",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 365,
                                                                "char": 64
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 365,
                                                            "char": 64
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 365,
                                                        "char": 64
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
                                                                                    "value": "Role '",
                                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                    "line": 367,
                                                                                    "char": 36
                                                                                },
                                                                                "right": {
                                                                                    "type": "variable",
                                                                                    "value": "roleInheritName",
                                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                    "line": 367,
                                                                                    "char": 54
                                                                                },
                                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                "line": 367,
                                                                                "char": 54
                                                                            },
                                                                            "right": {
                                                                                "type": "string",
                                                                                "value": "' (to inherit) produces an infinite loop",
                                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                "line": 369,
                                                                                "char": 25
                                                                            },
                                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                            "line": 369,
                                                                            "char": 25
                                                                        },
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 369,
                                                                        "char": 25
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 369,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 370,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 375,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "isset",
                                                        "left": {
                                                            "type": "array-access",
                                                            "left": {
                                                                "type": "property-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 375,
                                                                    "char": 35
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "roleInherits",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 375,
                                                                    "char": 48
                                                                },
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 375,
                                                                "char": 48
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "checkRoleToInherit",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 375,
                                                                "char": 67
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 375,
                                                            "char": 69
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 375,
                                                        "char": 69
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "for",
                                                            "expr": {
                                                                "type": "array-access",
                                                                "left": {
                                                                    "type": "property-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 376,
                                                                        "char": 55
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "roleInherits",
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 376,
                                                                        "char": 68
                                                                    },
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 376,
                                                                    "char": 68
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "checkRoleToInherit",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 376,
                                                                    "char": 87
                                                                },
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 376,
                                                                "char": 89
                                                            },
                                                            "value": "usedRoleToInherit",
                                                            "reverse": 0,
                                                            "statements": [
                                                                {
                                                                    "type": "fcall",
                                                                    "expr": {
                                                                        "type": "fcall",
                                                                        "name": "array_push",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "checkRoleToInherits",
                                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                    "line": 377,
                                                                                    "char": 59
                                                                                },
                                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                "line": 377,
                                                                                "char": 59
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "variable",
                                                                                    "value": "usedRoleToInherit",
                                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                    "line": 377,
                                                                                    "char": 78
                                                                                },
                                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                "line": 377,
                                                                                "char": 78
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 377,
                                                                        "char": 79
                                                                    },
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 378,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 379,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 380,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 381,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 383,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property-array-index-append",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "roleInherits",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "roleName",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 383,
                                                    "char": 44
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "roleInheritName",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 383,
                                                "char": 65
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 383,
                                            "char": 65
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 384,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 386,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 386,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 387,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Do a role inherit from another existing role\n     *\n     * ```php\n     * $acl->addRole(\"administrator\", \"consultant\");\n     * $acl->addRole(\"administrator\", [\"consultant\", \"consultant2\"]);\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 287,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                        "line": 287,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                    "line": 286,
                    "last-line": 401,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "addRole",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "role",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 402,
                            "char": 33
                        },
                        {
                            "type": "parameter",
                            "name": "accessInherits",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 402,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 402,
                            "char": 56
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "roleName",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 404,
                                    "char": 21
                                },
                                {
                                    "variable": "roleObject",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 404,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 406,
                            "char": 10
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
                                            "value": "role",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 406,
                                            "char": 25
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 406,
                                        "char": 25
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 406,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 406,
                                    "char": 35
                                },
                                "right": {
                                    "type": "instanceof",
                                    "left": {
                                        "type": "variable",
                                        "value": "role",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 406,
                                        "char": 51
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "RoleInterface",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 406,
                                        "char": 67
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 406,
                                    "char": 67
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 406,
                                "char": 67
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "roleObject",
                                            "expr": {
                                                "type": "variable",
                                                "value": "role",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 407,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 407,
                                            "char": 34
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 408,
                                    "char": 9
                                }
                            ],
                            "elseif_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "is_string",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "role",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 408,
                                                    "char": 32
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 408,
                                                "char": 32
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 408,
                                        "char": 34
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "roleObject",
                                                    "expr": {
                                                        "type": "new",
                                                        "class": "Role",
                                                        "dynamic": 0,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "role",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 409,
                                                                    "char": 43
                                                                },
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 409,
                                                                "char": 43
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 409,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 409,
                                                    "char": 44
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 410,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 410,
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
                                                    "value": "Role must be either a string or implement RoleInterface",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 413,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 413,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 413,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 414,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 416,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "roleName",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "roleObject",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 416,
                                            "char": 35
                                        },
                                        "name": "getName",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 416,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 416,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 418,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 418,
                                            "char": 23
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "rolesNames",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 418,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 418,
                                        "char": 34
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "roleName",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 418,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 418,
                                    "char": 45
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 418,
                                "char": 45
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 419,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 420,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 422,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property-append",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "roles",
                                    "expr": {
                                        "type": "variable",
                                        "value": "roleObject",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 422,
                                        "char": 52
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 422,
                                    "char": 52
                                },
                                {
                                    "assign-type": "object-property-array-index",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "rolesNames",
                                    "index-expr": [
                                        {
                                            "type": "variable",
                                            "value": "roleName",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 423,
                                            "char": 38
                                        }
                                    ],
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 423,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 423,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 425,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 425,
                                    "char": 19
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "accessInherits",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 425,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 425,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 426,
                                            "char": 25
                                        },
                                        "name": "addInherit",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "roleName",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 426,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 426,
                                                "char": 45
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "accessInherits",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 426,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 426,
                                                "char": 61
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 426,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 427,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 429,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 429,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 430,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Adds a role to the ACL list. Second parameter allows inheriting access data from other existing role\n     *\n     * ```php\n     * $acl->addRole(\n     *     new Phalcon\\Acl\\Role(\"administrator\"),\n     *     \"consultant\"\n     * );\n     *\n     * $acl->addRole(\"administrator\", \"consultant\");\n     * $acl->addRole(\"administrator\", [\"consultant\", \"consultant2\"]);\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 403,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                        "line": 403,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                    "line": 402,
                    "last-line": 447,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "allow",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "roleName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 448,
                            "char": 42
                        },
                        {
                            "type": "parameter",
                            "name": "componentName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 448,
                            "char": 64
                        },
                        {
                            "type": "parameter",
                            "name": "access",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 448,
                            "char": 76
                        },
                        {
                            "type": "parameter",
                            "name": "func",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 448,
                                "char": 93
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 448,
                            "char": 93
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "innerRoleName",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 450,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 452,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "variable",
                                    "value": "roleName",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 452,
                                    "char": 22
                                },
                                "right": {
                                    "type": "string",
                                    "value": "*",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 452,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 452,
                                "char": 26
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 453,
                                            "char": 18
                                        },
                                        "name": "allowOrDeny",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "roleName",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 454,
                                                    "char": 25
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 454,
                                                "char": 25
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "componentName",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 455,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 455,
                                                "char": 30
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "access",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 456,
                                                    "char": 23
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 456,
                                                "char": 23
                                            },
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "Acl",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 457,
                                                        "char": 27
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "ALLOW",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 457,
                                                        "char": 27
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 457,
                                                    "char": 27
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 457,
                                                "char": 27
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "func",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 459,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 459,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 459,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 460,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 461,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "rolesNames",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 461,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 461,
                                        "char": 54
                                    },
                                    "key": "innerRoleName",
                                    "value": "_",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 462,
                                                    "char": 22
                                                },
                                                "name": "allowOrDeny",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "innerRoleName",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 463,
                                                            "char": 34
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 463,
                                                        "char": 34
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "componentName",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 464,
                                                            "char": 34
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 464,
                                                        "char": 34
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "access",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 465,
                                                            "char": 27
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 465,
                                                        "char": 27
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "static-constant-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "Acl",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 466,
                                                                "char": 31
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "ALLOW",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 466,
                                                                "char": 31
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 466,
                                                            "char": 31
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 466,
                                                        "char": 31
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "func",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 468,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 468,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 468,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 469,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 470,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 471,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Allow access to a role on a component. You can use `*` as wildcard\n     *\n     * ```php\n     * \/\/ Allow access to guests to search on customers\n     * $acl->allow(\"guests\", \"customers\", \"search\");\n     *\n     * \/\/ Allow access to guests to search or create on customers\n     * $acl->allow(\"guests\", \"customers\", [\"search\", \"create\"]);\n     *\n     * \/\/ Allow access to any role to browse on products\n     * $acl->allow(\"*\", \"products\", \"browse\");\n     *\n     * \/\/ Allow access to any role to browse on any component\n     * $acl->allow(\"*\", \"*\", \"browse\");\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                        "line": 449,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                    "line": 448,
                    "last-line": 489,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "deny",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "roleName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 490,
                            "char": 41
                        },
                        {
                            "type": "parameter",
                            "name": "componentName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 490,
                            "char": 63
                        },
                        {
                            "type": "parameter",
                            "name": "access",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 490,
                            "char": 75
                        },
                        {
                            "type": "parameter",
                            "name": "func",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 490,
                                "char": 92
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 490,
                            "char": 92
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "innerRoleName",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 492,
                                    "char": 26
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 494,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "string",
                                    "value": "*",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 494,
                                    "char": 16
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "roleName",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 494,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 494,
                                "char": 27
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 495,
                                            "char": 18
                                        },
                                        "name": "allowOrDeny",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "roleName",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 495,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 495,
                                                "char": 39
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "componentName",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 495,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 495,
                                                "char": 54
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "access",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 495,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 495,
                                                "char": 62
                                            },
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "Acl",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 495,
                                                        "char": 73
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "DENY",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 495,
                                                        "char": 73
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 495,
                                                    "char": 73
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 495,
                                                "char": 73
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "func",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 495,
                                                    "char": 79
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 495,
                                                "char": 79
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 495,
                                        "char": 80
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 496,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 497,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "rolesNames",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 497,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 497,
                                        "char": 54
                                    },
                                    "key": "innerRoleName",
                                    "value": "_",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 498,
                                                    "char": 22
                                                },
                                                "name": "allowOrDeny",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "innerRoleName",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 499,
                                                            "char": 34
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 499,
                                                        "char": 34
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "componentName",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 500,
                                                            "char": 34
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 500,
                                                        "char": 34
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "access",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 501,
                                                            "char": 27
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 501,
                                                        "char": 27
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "static-constant-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "Acl",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 502,
                                                                "char": 30
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "DENY",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 502,
                                                                "char": 30
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 502,
                                                            "char": 30
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 502,
                                                        "char": 30
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "func",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 504,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 504,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 504,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 505,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 506,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 507,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Deny access to a role on a component. You can use `*` as wildcard\n     *\n     * ```php\n     * \/\/ Deny access to guests to search on customers\n     * $acl->deny(\"guests\", \"customers\", \"search\");\n     *\n     * \/\/ Deny access to guests to search or create on customers\n     * $acl->deny(\"guests\", \"customers\", [\"search\", \"create\"]);\n     *\n     * \/\/ Deny access to any role to browse on products\n     * $acl->deny(\"*\", \"products\", \"browse\");\n     *\n     * \/\/ Deny access to any role to browse on any component\n     * $acl->deny(\"*\", \"*\", \"browse\");\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                        "line": 491,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                    "line": 490,
                    "last-line": 511,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "dropComponentAccess",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "componentName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 512,
                            "char": 61
                        },
                        {
                            "type": "parameter",
                            "name": "accessList",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 512,
                            "char": 77
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "accessName",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 514,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 515,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "accessKey",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 515,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 516,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "localAccess",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 516,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 516,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 518,
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
                                        "value": "accessList",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 518,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 518,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "string",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 518,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 518,
                                "char": 40
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "localAccess",
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "value": {
                                                            "type": "variable",
                                                            "value": "accessList",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 519,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 519,
                                                        "char": 42
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 519,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 519,
                                            "char": 43
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 520,
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
                                            "variable": "localAccess",
                                            "expr": {
                                                "type": "variable",
                                                "value": "accessList",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 521,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 521,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 522,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 524,
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
                                        "value": "accessList",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 524,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 524,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 524,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 524,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "localAccess",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 525,
                                        "char": 43
                                    },
                                    "value": "accessName",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "accessKey",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "componentName",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 526,
                                                                "char": 47
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "!",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 526,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 526,
                                                            "char": 51
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "accessName",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 526,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 526,
                                                        "char": 63
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 526,
                                                    "char": 63
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 528,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "isset",
                                                "left": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 528,
                                                            "char": 31
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "accessList",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 528,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 528,
                                                        "char": 42
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "accessKey",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 528,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 528,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 528,
                                                "char": 54
                                            },
                                            "statements": [
                                                {
                                                    "type": "unset",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 529,
                                                                "char": 32
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "accessList",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 529,
                                                                "char": 43
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 529,
                                                            "char": 43
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "accessKey",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 529,
                                                            "char": 53
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 529,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 530,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 531,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 532,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 533,
                            "char": 6
                        }
                    ],
                    "docblock": "**\n     * Removes an access from a component\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                        "line": 513,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                    "line": 512,
                    "last-line": 538,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getNoArgumentsDefaultAction",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 541,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "noArgumentsDefaultAction",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 541,
                                    "char": 46
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 541,
                                "char": 46
                            },
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 542,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the default ACL access level for no arguments provided in\n     * `isAllowed` action if a `func` (callable) exists for `accessKey`\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 540,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                        "line": 540,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                    "line": 539,
                    "last-line": 546,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRoles",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 549,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "roles",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 549,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 549,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 550,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return an array with every role registered in the list\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RoleInterface",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 548,
                                    "char": 5
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 548,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                        "line": 548,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                    "line": 547,
                    "last-line": 554,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getComponents",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 557,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "components",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 557,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 557,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 558,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Return an array with every component registered in the list\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ComponentInterface",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 556,
                                    "char": 5
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 556,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                        "line": 556,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                    "line": 555,
                    "last-line": 570,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isAllowed",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "roleName",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 571,
                            "char": 43
                        },
                        {
                            "type": "parameter",
                            "name": "componentName",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 571,
                            "char": 62
                        },
                        {
                            "type": "parameter",
                            "name": "access",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 571,
                            "char": 77
                        },
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 571,
                                "char": 102
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 571,
                            "char": 102
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "accessKey",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 573,
                                    "char": 22
                                },
                                {
                                    "variable": "accessList",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 573,
                                    "char": 34
                                },
                                {
                                    "variable": "componentObject",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 573,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 573,
                                    "char": 58
                                },
                                {
                                    "variable": "haveAccess",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 573,
                                        "char": 77
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 573,
                                    "char": 77
                                },
                                {
                                    "variable": "eventsManager",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 574,
                                    "char": 26
                                },
                                {
                                    "variable": "funcAccess",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 574,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 574,
                                    "char": 45
                                },
                                {
                                    "variable": "funcList",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 574,
                                    "char": 55
                                },
                                {
                                    "variable": "numberOfRequiredParameters",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 574,
                                    "char": 83
                                },
                                {
                                    "variable": "reflectionFunction",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 575,
                                    "char": 31
                                },
                                {
                                    "variable": "reflectionParameters",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 575,
                                    "char": 53
                                },
                                {
                                    "variable": "parameterNumber",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 575,
                                    "char": 70
                                },
                                {
                                    "variable": "parameterToCheck",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 576,
                                    "char": 29
                                },
                                {
                                    "variable": "parametersForFunction",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 576,
                                    "char": 52
                                },
                                {
                                    "variable": "reflectionClass",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 576,
                                    "char": 69
                                },
                                {
                                    "variable": "reflectionParameter",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 577,
                                    "char": 32
                                },
                                {
                                    "variable": "rolesNames",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 577,
                                    "char": 44
                                },
                                {
                                    "variable": "roleObject",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 577,
                                        "char": 63
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 577,
                                    "char": 63
                                },
                                {
                                    "variable": "userParametersSizeShouldBe",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 578,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 580,
                            "char": 12
                        },
                        {
                            "type": "declare",
                            "data-type": "bool",
                            "variables": [
                                {
                                    "variable": "hasComponent",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 580,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 580,
                                    "char": 34
                                },
                                {
                                    "variable": "hasRole",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 580,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 580,
                                    "char": 51
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 582,
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
                                        "value": "roleName",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 582,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 582,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 582,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 582,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "instanceof",
                                        "left": {
                                            "type": "variable",
                                            "value": "roleName",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 583,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "RoleAware",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 583,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 583,
                                        "char": 46
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "roleObject",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "roleName",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 584,
                                                        "char": 42
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 584,
                                                    "char": 42
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "roleName",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "roleObject",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 585,
                                                            "char": 45
                                                        },
                                                        "name": "getRoleName",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 585,
                                                        "char": 59
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 585,
                                                    "char": 59
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 586,
                                            "char": 13
                                        }
                                    ],
                                    "elseif_statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "instanceof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "roleName",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 586,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "RoleInterface",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 586,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 586,
                                                "char": 56
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "roleName",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "roleName",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 587,
                                                                    "char": 41
                                                                },
                                                                "name": "getName",
                                                                "call-type": 1,
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 587,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 587,
                                                            "char": 51
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 588,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 588,
                                            "char": 18
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
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "string",
                                                                "value": "Object passed as roleName must implement ",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 590,
                                                                "char": 63
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "Phalcon\\\\Acl\\\\RoleAware or Phalcon\\\\Acl\\\\RoleInterface",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 592,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 592,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 592,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 592,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 593,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 594,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 596,
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
                                        "value": "componentName",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 596,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 596,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 596,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 596,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "instanceof",
                                        "left": {
                                            "type": "variable",
                                            "value": "componentName",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 597,
                                            "char": 39
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "ComponentAware",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 597,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 597,
                                        "char": 56
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "componentObject",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "componentName",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 598,
                                                        "char": 52
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 598,
                                                    "char": 52
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "componentName",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "componentObject",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 599,
                                                            "char": 55
                                                        },
                                                        "name": "getComponentName",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 599,
                                                        "char": 74
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 599,
                                                    "char": 74
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 600,
                                            "char": 13
                                        }
                                    ],
                                    "elseif_statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "instanceof",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "componentName",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 600,
                                                    "char": 45
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "ComponentInterface",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 600,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 600,
                                                "char": 66
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "componentName",
                                                            "expr": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "componentName",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 601,
                                                                    "char": 51
                                                                },
                                                                "name": "getName",
                                                                "call-type": 1,
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 601,
                                                                "char": 61
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 601,
                                                            "char": 61
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 602,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 602,
                                            "char": 18
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
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "string",
                                                                "value": "Object passed as componentName must implement ",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 604,
                                                                "char": 68
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "Phalcon\\\\Acl\\\\ComponentAware or Phalcon\\\\Acl\\\\ComponentInterface",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 606,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 606,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 606,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 606,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 607,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 608,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 610,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "activeRole",
                                    "expr": {
                                        "type": "variable",
                                        "value": "roleName",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 610,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 610,
                                    "char": 45
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "activeComponent",
                                    "expr": {
                                        "type": "variable",
                                        "value": "componentName",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 611,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 611,
                                    "char": 50
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "activeAccess",
                                    "expr": {
                                        "type": "variable",
                                        "value": "access",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 612,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 612,
                                    "char": 43
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "activeKey",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 613,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 613,
                                    "char": 41
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "activeKey",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 614,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 614,
                                    "char": 41
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "activeFunction",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 615,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 615,
                                    "char": 41
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "accessList",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 616,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "access",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 616,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 616,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 616,
                                    "char": 49
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "eventsManager",
                                    "expr": {
                                        "type": "type-hint",
                                        "left": {
                                            "type": "variable",
                                            "value": "EventsManager",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 617,
                                            "char": 72
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 617,
                                                "char": 58
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "eventsManager",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 617,
                                                "char": 72
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 617,
                                            "char": 72
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 617,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 617,
                                    "char": 72
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "funcList",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 618,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "func",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 618,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 618,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 618,
                                    "char": 47
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 620,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "activeFunctionCustomArgumentsCount",
                                    "expr": {
                                        "type": "int",
                                        "value": "0",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 620,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 620,
                                    "char": 57
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 622,
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
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 622,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 622,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 622,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 622,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "eventsManager",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 623,
                                                "char": 30
                                            },
                                            "name": "fire",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "acl:beforeCheckAccess",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 623,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 623,
                                                    "char": 57
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 623,
                                                        "char": 63
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 623,
                                                    "char": 63
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 623,
                                            "char": 67
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 623,
                                            "char": 75
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 623,
                                        "char": 75
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 624,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 625,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 626,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 631,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "rolesNames",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 631,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "rolesNames",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 631,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 631,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 631,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 633,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "rolesNames",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 633,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "roleName",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 633,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 633,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 633,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 633,
                                "char": 40
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "list",
                                        "left": {
                                            "type": "equals",
                                            "left": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 634,
                                                    "char": 26
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "defaultAccess",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 634,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 634,
                                                "char": 42
                                            },
                                            "right": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "Acl",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 634,
                                                    "char": 54
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "ALLOW",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 634,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 634,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 634,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 634,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 635,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 640,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "accessKey",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 640,
                                            "char": 30
                                        },
                                        "name": "canAccess",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "roleName",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 640,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 640,
                                                "char": 49
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "componentName",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 640,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 640,
                                                "char": 64
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "access",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 640,
                                                    "char": 72
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 640,
                                                "char": 72
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 640,
                                        "char": 73
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 640,
                                    "char": 73
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 642,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "not-equals",
                                    "left": {
                                        "type": "variable",
                                        "value": "accessKey",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 642,
                                        "char": 23
                                    },
                                    "right": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 642,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 642,
                                    "char": 32
                                },
                                "right": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "accessList",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 642,
                                            "char": 50
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "accessKey",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 642,
                                            "char": 60
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 642,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 642,
                                    "char": 62
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 642,
                                "char": 62
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "haveAccess",
                                            "expr": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "accessList",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 643,
                                                    "char": 40
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "accessKey",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 643,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 643,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 643,
                                            "char": 51
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 645,
                                    "char": 17
                                },
                                {
                                    "type": "fetch",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "funcAccess",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 645,
                                            "char": 50
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "funcList",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 645,
                                                "char": 39
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "accessKey",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 645,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 645,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 645,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 646,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 651,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "accessGranted",
                                    "expr": {
                                        "type": "variable",
                                        "value": "haveAccess",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 651,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 651,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 653,
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
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 653,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 653,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 653,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 653,
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
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 654,
                                            "char": 27
                                        },
                                        "name": "fire",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "acl:afterCheckAccess",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 654,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 654,
                                                "char": 53
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 654,
                                                    "char": 59
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 654,
                                                "char": 59
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 654,
                                        "char": 60
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 655,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 657,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "activeKey",
                                    "expr": {
                                        "type": "variable",
                                        "value": "accessKey",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 657,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 657,
                                    "char": 45
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "activeFunction",
                                    "expr": {
                                        "type": "variable",
                                        "value": "funcAccess",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 658,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 658,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 660,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "variable",
                                    "value": "haveAccess",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 660,
                                    "char": 24
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 660,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 660,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "activeKey",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "roleName",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 665,
                                                                "char": 44
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "!",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 665,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 665,
                                                            "char": 48
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "componentName",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 665,
                                                            "char": 64
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 665,
                                                        "char": 64
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "!",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 665,
                                                        "char": 68
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 665,
                                                    "char": 68
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "access",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 665,
                                                    "char": 76
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 665,
                                                "char": 76
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 665,
                                            "char": 76
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 667,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 667,
                                                "char": 25
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "defaultAccess",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 667,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 667,
                                            "char": 41
                                        },
                                        "right": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "Acl",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 667,
                                                "char": 53
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "ALLOW",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 667,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 667,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 667,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 668,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 673,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "is_callable",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "funcAccess",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 673,
                                            "char": 34
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 673,
                                        "char": 34
                                    }
                                ],
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 673,
                                "char": 36
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "reflectionFunction",
                                            "expr": {
                                                "type": "new",
                                                "class": "ReflectionFunction",
                                                "dynamic": 0,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "funcAccess",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 674,
                                                            "char": 73
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 674,
                                                        "char": 73
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 674,
                                                "char": 74
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 674,
                                            "char": 74
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "reflectionParameters",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "reflectionFunction",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 675,
                                                    "char": 59
                                                },
                                                "name": "getParameters",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 675,
                                                "char": 75
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 675,
                                            "char": 75
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "parameterNumber",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "count",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "reflectionParameters",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 676,
                                                            "char": 66
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 676,
                                                        "char": 66
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 676,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 676,
                                            "char": 67
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 682,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "parameterNumber",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 682,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 682,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 682,
                                        "char": 38
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "and",
                                                "left": {
                                                    "type": "equals",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "haveAccess",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 683,
                                                        "char": 36
                                                    },
                                                    "right": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "Acl",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 683,
                                                            "char": 50
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "ALLOW",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 683,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 683,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 683,
                                                    "char": 50
                                                },
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "call_user_func",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "funcAccess",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 683,
                                                                "char": 77
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 683,
                                                            "char": 77
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 683,
                                                    "char": 78
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 683,
                                                "char": 78
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 684,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 686,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "parametersForFunction",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 686,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 686,
                                            "char": 48
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "numberOfRequiredParameters",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "reflectionFunction",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 687,
                                                    "char": 65
                                                },
                                                "name": "getNumberOfRequiredParameters",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 687,
                                                "char": 97
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 687,
                                            "char": 97
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "userParametersSizeShouldBe",
                                            "expr": {
                                                "type": "variable",
                                                "value": "parameterNumber",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 688,
                                                "char": 61
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 688,
                                            "char": 61
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 690,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "reflectionParameters",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 690,
                                        "char": 61
                                    },
                                    "value": "reflectionParameter",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "reflectionClass",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "reflectionParameter",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 691,
                                                            "char": 60
                                                        },
                                                        "name": "getClass",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 691,
                                                        "char": 71
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 691,
                                                    "char": 71
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "parameterToCheck",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "reflectionParameter",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 692,
                                                            "char": 60
                                                        },
                                                        "name": "getName",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 692,
                                                        "char": 70
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 692,
                                                    "char": 70
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 694,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not-identical",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "reflectionClass",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 694,
                                                    "char": 38
                                                },
                                                "right": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 694,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 694,
                                                "char": 45
                                            },
                                            "statements": [
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "list",
                                                        "left": {
                                                            "type": "and",
                                                            "left": {
                                                                "type": "and",
                                                                "left": {
                                                                    "type": "not-identical",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "roleObject",
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 696,
                                                                        "char": 38
                                                                    },
                                                                    "right": {
                                                                        "type": "null",
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 696,
                                                                        "char": 46
                                                                    },
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 696,
                                                                    "char": 46
                                                                },
                                                                "right": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "variable",
                                                                        "value": "reflectionClass",
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 697,
                                                                        "char": 41
                                                                    },
                                                                    "name": "isInstance",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "roleObject",
                                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                "line": 697,
                                                                                "char": 63
                                                                            },
                                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                            "line": 697,
                                                                            "char": 63
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 697,
                                                                    "char": 66
                                                                },
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 697,
                                                                "char": 66
                                                            },
                                                            "right": {
                                                                "type": "not",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "hasRole",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 699,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 699,
                                                                "char": 21
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 699,
                                                            "char": 21
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 699,
                                                        "char": 23
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "hasRole",
                                                                    "expr": {
                                                                        "type": "bool",
                                                                        "value": "true",
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 700,
                                                                        "char": 59
                                                                    },
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 700,
                                                                    "char": 59
                                                                },
                                                                {
                                                                    "assign-type": "variable-append",
                                                                    "operator": "assign",
                                                                    "variable": "parametersForFunction",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "roleObject",
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 701,
                                                                        "char": 65
                                                                    },
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 701,
                                                                    "char": 65
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 702,
                                                            "char": 27
                                                        },
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "decr",
                                                                    "variable": "userParametersSizeShouldBe",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 702,
                                                                    "char": 57
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 704,
                                                            "char": 32
                                                        },
                                                        {
                                                            "type": "continue",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 705,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 708,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "list",
                                                        "left": {
                                                            "type": "and",
                                                            "left": {
                                                                "type": "and",
                                                                "left": {
                                                                    "type": "not-identical",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "componentObject",
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 708,
                                                                        "char": 43
                                                                    },
                                                                    "right": {
                                                                        "type": "null",
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 708,
                                                                        "char": 51
                                                                    },
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 708,
                                                                    "char": 51
                                                                },
                                                                "right": {
                                                                    "type": "mcall",
                                                                    "variable": {
                                                                        "type": "variable",
                                                                        "value": "reflectionClass",
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 709,
                                                                        "char": 41
                                                                    },
                                                                    "name": "isInstance",
                                                                    "call-type": 1,
                                                                    "parameters": [
                                                                        {
                                                                            "parameter": {
                                                                                "type": "variable",
                                                                                "value": "componentObject",
                                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                "line": 709,
                                                                                "char": 68
                                                                            },
                                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                            "line": 709,
                                                                            "char": 68
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 709,
                                                                    "char": 71
                                                                },
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 709,
                                                                "char": 71
                                                            },
                                                            "right": {
                                                                "type": "not",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "hasComponent",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 711,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 711,
                                                                "char": 21
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 711,
                                                            "char": 21
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 711,
                                                        "char": 23
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "hasComponent",
                                                                    "expr": {
                                                                        "type": "bool",
                                                                        "value": "true",
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 712,
                                                                        "char": 59
                                                                    },
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 712,
                                                                    "char": 59
                                                                },
                                                                {
                                                                    "assign-type": "variable-append",
                                                                    "operator": "assign",
                                                                    "variable": "parametersForFunction",
                                                                    "expr": {
                                                                        "type": "variable",
                                                                        "value": "componentObject",
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 713,
                                                                        "char": 70
                                                                    },
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 713,
                                                                    "char": 70
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 714,
                                                            "char": 27
                                                        },
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "decr",
                                                                    "variable": "userParametersSizeShouldBe",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 714,
                                                                    "char": 57
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 716,
                                                            "char": 32
                                                        },
                                                        {
                                                            "type": "continue",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 717,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 723,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "unlikely",
                                                        "left": {
                                                            "type": "list",
                                                            "left": {
                                                                "type": "and",
                                                                "left": {
                                                                    "type": "and",
                                                                    "left": {
                                                                        "type": "isset",
                                                                        "left": {
                                                                            "type": "list",
                                                                            "left": {
                                                                                "type": "array-access",
                                                                                "left": {
                                                                                    "type": "variable",
                                                                                    "value": "parameters",
                                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                    "line": 723,
                                                                                    "char": 50
                                                                                },
                                                                                "right": {
                                                                                    "type": "variable",
                                                                                    "value": "parameterToCheck",
                                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                    "line": 723,
                                                                                    "char": 67
                                                                                },
                                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                "line": 723,
                                                                                "char": 68
                                                                            },
                                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                            "line": 723,
                                                                            "char": 71
                                                                        },
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 723,
                                                                        "char": 71
                                                                    },
                                                                    "right": {
                                                                        "type": "fcall",
                                                                        "name": "is_object",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "array-access",
                                                                                    "left": {
                                                                                        "type": "variable",
                                                                                        "value": "parameters",
                                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                        "line": 724,
                                                                                        "char": 45
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "variable",
                                                                                        "value": "parameterToCheck",
                                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                        "line": 724,
                                                                                        "char": 62
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                    "line": 724,
                                                                                    "char": 63
                                                                                },
                                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                "line": 724,
                                                                                "char": 63
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 724,
                                                                        "char": 66
                                                                    },
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 724,
                                                                    "char": 66
                                                                },
                                                                "right": {
                                                                    "type": "not",
                                                                    "left": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "reflectionClass",
                                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                            "line": 725,
                                                                            "char": 42
                                                                        },
                                                                        "name": "isInstance",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "array-access",
                                                                                    "left": {
                                                                                        "type": "variable",
                                                                                        "value": "parameters",
                                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                        "line": 725,
                                                                                        "char": 64
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "variable",
                                                                                        "value": "parameterToCheck",
                                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                        "line": 725,
                                                                                        "char": 81
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                    "line": 725,
                                                                                    "char": 82
                                                                                },
                                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                "line": 725,
                                                                                "char": 82
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 726,
                                                                        "char": 21
                                                                    },
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 726,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 726,
                                                                "char": 21
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 726,
                                                            "char": 23
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 726,
                                                        "char": 23
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
                                                                                    "type": "concat",
                                                                                    "left": {
                                                                                        "type": "concat",
                                                                                        "left": {
                                                                                            "type": "concat",
                                                                                            "left": {
                                                                                                "type": "concat",
                                                                                                "left": {
                                                                                                    "type": "concat",
                                                                                                    "left": {
                                                                                                        "type": "concat",
                                                                                                        "left": {
                                                                                                            "type": "concat",
                                                                                                            "left": {
                                                                                                                "type": "concat",
                                                                                                                "left": {
                                                                                                                    "type": "concat",
                                                                                                                    "left": {
                                                                                                                        "type": "concat",
                                                                                                                        "left": {
                                                                                                                            "type": "string",
                                                                                                                            "value": "Your passed parameter doesn't have the ",
                                                                                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                                                            "line": 728,
                                                                                                                            "char": 69
                                                                                                                        },
                                                                                                                        "right": {
                                                                                                                            "type": "string",
                                                                                                                            "value": "same class as the parameter in defined function ",
                                                                                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                                                            "line": 729,
                                                                                                                            "char": 78
                                                                                                                        },
                                                                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                                                        "line": 729,
                                                                                                                        "char": 78
                                                                                                                    },
                                                                                                                    "right": {
                                                                                                                        "type": "string",
                                                                                                                        "value": "when checking if ",
                                                                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                                                        "line": 730,
                                                                                                                        "char": 47
                                                                                                                    },
                                                                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                                                    "line": 730,
                                                                                                                    "char": 47
                                                                                                                },
                                                                                                                "right": {
                                                                                                                    "type": "variable",
                                                                                                                    "value": "roleName",
                                                                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                                                    "line": 730,
                                                                                                                    "char": 58
                                                                                                                },
                                                                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                                                "line": 730,
                                                                                                                "char": 58
                                                                                                            },
                                                                                                            "right": {
                                                                                                                "type": "string",
                                                                                                                "value": " can ",
                                                                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                                                "line": 730,
                                                                                                                "char": 66
                                                                                                            },
                                                                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                                            "line": 730,
                                                                                                            "char": 66
                                                                                                        },
                                                                                                        "right": {
                                                                                                            "type": "variable",
                                                                                                            "value": "access",
                                                                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                                            "line": 730,
                                                                                                            "char": 75
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                                        "line": 730,
                                                                                                        "char": 75
                                                                                                    },
                                                                                                    "right": {
                                                                                                        "type": "string",
                                                                                                        "value": " ",
                                                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                                        "line": 731,
                                                                                                        "char": 31
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                                    "line": 731,
                                                                                                    "char": 31
                                                                                                },
                                                                                                "right": {
                                                                                                    "type": "variable",
                                                                                                    "value": "componentName",
                                                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                                    "line": 731,
                                                                                                    "char": 47
                                                                                                },
                                                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                                "line": 731,
                                                                                                "char": 47
                                                                                            },
                                                                                            "right": {
                                                                                                "type": "string",
                                                                                                "value": ". Class passed: ",
                                                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                                "line": 731,
                                                                                                "char": 66
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                            "line": 731,
                                                                                            "char": 66
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "fcall",
                                                                                            "name": "get_class",
                                                                                            "call-type": 1,
                                                                                            "parameters": [
                                                                                                {
                                                                                                    "parameter": {
                                                                                                        "type": "array-access",
                                                                                                        "left": {
                                                                                                            "type": "variable",
                                                                                                            "value": "parameters",
                                                                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                                            "line": 732,
                                                                                                            "char": 49
                                                                                                        },
                                                                                                        "right": {
                                                                                                            "type": "variable",
                                                                                                            "value": "parameterToCheck",
                                                                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                                            "line": 732,
                                                                                                            "char": 66
                                                                                                        },
                                                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                                        "line": 732,
                                                                                                        "char": 67
                                                                                                    },
                                                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                                    "line": 732,
                                                                                                    "char": 67
                                                                                                }
                                                                                            ],
                                                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                            "line": 732,
                                                                                            "char": 69
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                        "line": 732,
                                                                                        "char": 69
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "string",
                                                                                        "value": " , Class in defined function: ",
                                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                        "line": 733,
                                                                                        "char": 60
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                    "line": 733,
                                                                                    "char": 60
                                                                                },
                                                                                "right": {
                                                                                    "type": "mcall",
                                                                                    "variable": {
                                                                                        "type": "variable",
                                                                                        "value": "reflectionClass",
                                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                        "line": 734,
                                                                                        "char": 45
                                                                                    },
                                                                                    "name": "getName",
                                                                                    "call-type": 1,
                                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                    "line": 734,
                                                                                    "char": 56
                                                                                },
                                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                "line": 734,
                                                                                "char": 56
                                                                            },
                                                                            "right": {
                                                                                "type": "string",
                                                                                "value": ".",
                                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                "line": 735,
                                                                                "char": 25
                                                                            },
                                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                            "line": 735,
                                                                            "char": 25
                                                                        },
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 735,
                                                                        "char": 25
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 735,
                                                                "char": 26
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 736,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 737,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 739,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "isset",
                                                "left": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "parameters",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 739,
                                                        "char": 36
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "parameterToCheck",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 739,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 739,
                                                    "char": 55
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 739,
                                                "char": 55
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable-append",
                                                            "operator": "assign",
                                                            "variable": "parametersForFunction",
                                                            "expr": {
                                                                "type": "array-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "parameters",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 744,
                                                                    "char": 61
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "parameterToCheck",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 744,
                                                                    "char": 78
                                                                },
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 744,
                                                                "char": 79
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 744,
                                                            "char": 79
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 745,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 746,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 748,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "activeFunctionCustomArgumentsCount",
                                            "expr": {
                                                "type": "variable",
                                                "value": "userParametersSizeShouldBe",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 748,
                                                "char": 86
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 748,
                                            "char": 86
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 750,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "greater",
                                            "left": {
                                                "type": "fcall",
                                                "name": "count",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "parameters",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 750,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 750,
                                                        "char": 41
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 750,
                                                "char": 43
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "userParametersSizeShouldBe",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 750,
                                                "char": 72
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 750,
                                            "char": 72
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 750,
                                        "char": 72
                                    },
                                    "statements": [
                                        {
                                            "type": "fcall",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "trigger_error",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "concat",
                                                                                "left": {
                                                                                    "type": "concat",
                                                                                    "left": {
                                                                                        "type": "string",
                                                                                        "value": "Number of parameters in array is higher than ",
                                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                        "line": 752,
                                                                                        "char": 67
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "string",
                                                                                        "value": "the number of parameters in defined function when checking if '",
                                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                        "line": 753,
                                                                                        "char": 85
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                    "line": 753,
                                                                                    "char": 85
                                                                                },
                                                                                "right": {
                                                                                    "type": "variable",
                                                                                    "value": "roleName",
                                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                    "line": 754,
                                                                                    "char": 30
                                                                                },
                                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                "line": 754,
                                                                                "char": 30
                                                                            },
                                                                            "right": {
                                                                                "type": "string",
                                                                                "value": "' can '",
                                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                "line": 754,
                                                                                "char": 40
                                                                            },
                                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                            "line": 754,
                                                                            "char": 40
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "access",
                                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                            "line": 754,
                                                                            "char": 49
                                                                        },
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 754,
                                                                        "char": 49
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "' '",
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 754,
                                                                        "char": 55
                                                                    },
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 754,
                                                                    "char": 55
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "componentName",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 754,
                                                                    "char": 71
                                                                },
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 754,
                                                                "char": 71
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "'. Extra parameters will be ignored.",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 755,
                                                                "char": 57
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 755,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 755,
                                                        "char": 57
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "constant",
                                                            "value": "E_USER_WARNING",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 757,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 757,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 757,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 758,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 761,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "fcall",
                                            "name": "count",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "parametersForFunction",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 761,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 761,
                                                    "char": 43
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 761,
                                            "char": 46
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 761,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 761,
                                        "char": 50
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "unlikely",
                                                "left": {
                                                    "type": "greater",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "numberOfRequiredParameters",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 762,
                                                        "char": 56
                                                    },
                                                    "right": {
                                                        "type": "int",
                                                        "value": "0",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 762,
                                                        "char": 60
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 762,
                                                    "char": 60
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 762,
                                                "char": 60
                                            },
                                            "statements": [
                                                {
                                                    "type": "fcall",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "trigger_error",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "concat",
                                                                                "left": {
                                                                                    "type": "concat",
                                                                                    "left": {
                                                                                        "type": "concat",
                                                                                        "left": {
                                                                                            "type": "string",
                                                                                            "value": "You did not provide any parameters when '",
                                                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                            "line": 764,
                                                                                            "char": 67
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "variable",
                                                                                            "value": "roleName",
                                                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                            "line": 764,
                                                                                            "char": 78
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                        "line": 764,
                                                                                        "char": 78
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "string",
                                                                                        "value": "' can '",
                                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                        "line": 765,
                                                                                        "char": 33
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                    "line": 765,
                                                                                    "char": 33
                                                                                },
                                                                                "right": {
                                                                                    "type": "variable",
                                                                                    "value": "access",
                                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                    "line": 765,
                                                                                    "char": 42
                                                                                },
                                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                "line": 765,
                                                                                "char": 42
                                                                            },
                                                                            "right": {
                                                                                "type": "string",
                                                                                "value": "' '",
                                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                "line": 765,
                                                                                "char": 49
                                                                            },
                                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                            "line": 765,
                                                                            "char": 49
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "componentName",
                                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                            "line": 765,
                                                                            "char": 65
                                                                        },
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 765,
                                                                        "char": 65
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "'. We will use default action when no arguments.",
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 767,
                                                                        "char": 21
                                                                    },
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 767,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 767,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 767,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 769,
                                                    "char": 26
                                                },
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "and",
                                                        "left": {
                                                            "type": "equals",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "haveAccess",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 769,
                                                                "char": 40
                                                            },
                                                            "right": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Acl",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 769,
                                                                    "char": 54
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "ALLOW",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 769,
                                                                    "char": 54
                                                                },
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 769,
                                                                "char": 54
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 769,
                                                            "char": 54
                                                        },
                                                        "right": {
                                                            "type": "equals",
                                                            "left": {
                                                                "type": "property-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 769,
                                                                    "char": 61
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "noArgumentsDefaultAction",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 769,
                                                                    "char": 88
                                                                },
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 769,
                                                                "char": 88
                                                            },
                                                            "right": {
                                                                "type": "static-constant-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "Acl",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 769,
                                                                    "char": 100
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "ALLOW",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 769,
                                                                    "char": 100
                                                                },
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 769,
                                                                "char": 100
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 769,
                                                            "char": 100
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 769,
                                                        "char": 100
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 770,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 776,
                                            "char": 22
                                        },
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "and",
                                                "left": {
                                                    "type": "equals",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "haveAccess",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 776,
                                                        "char": 36
                                                    },
                                                    "right": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "Acl",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 776,
                                                            "char": 50
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "ALLOW",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 776,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 776,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 776,
                                                    "char": 50
                                                },
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "call_user_func",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "funcAccess",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 776,
                                                                "char": 77
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 776,
                                                            "char": 77
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 776,
                                                    "char": 78
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 776,
                                                "char": 78
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 777,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 780,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "greater-equal",
                                        "left": {
                                            "type": "fcall",
                                            "name": "count",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "parametersForFunction",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 780,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 780,
                                                    "char": 43
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 780,
                                            "char": 45
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "numberOfRequiredParameters",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 780,
                                            "char": 74
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 780,
                                        "char": 74
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "and",
                                                "left": {
                                                    "type": "equals",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "haveAccess",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 781,
                                                        "char": 36
                                                    },
                                                    "right": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "Acl",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 781,
                                                            "char": 50
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "ALLOW",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 781,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 781,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 781,
                                                    "char": 50
                                                },
                                                "right": {
                                                    "type": "fcall",
                                                    "name": "call_user_func_array",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "funcAccess",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 781,
                                                                "char": 83
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 781,
                                                            "char": 83
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "parametersForFunction",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 781,
                                                                "char": 106
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 781,
                                                            "char": 106
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 781,
                                                    "char": 107
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 781,
                                                "char": 107
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 782,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 785,
                                    "char": 17
                                },
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
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "concat",
                                                                        "left": {
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "string",
                                                                                "value": "You did not provide all necessary parameters for the ",
                                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                "line": 786,
                                                                                "char": 71
                                                                            },
                                                                            "right": {
                                                                                "type": "string",
                                                                                "value": "defined function when checking if '",
                                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                "line": 787,
                                                                                "char": 53
                                                                            },
                                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                            "line": 787,
                                                                            "char": 53
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "roleName",
                                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                            "line": 787,
                                                                            "char": 64
                                                                        },
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 787,
                                                                        "char": 64
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "' can '",
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 787,
                                                                        "char": 74
                                                                    },
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 787,
                                                                    "char": 74
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "access",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 788,
                                                                    "char": 24
                                                                },
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 788,
                                                                "char": 24
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "' for '",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 788,
                                                                "char": 34
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 788,
                                                            "char": 34
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "componentName",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 788,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 788,
                                                        "char": 50
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "'.",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 789,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 789,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 789,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 789,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 790,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 792,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "variable",
                                    "value": "haveAccess",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 792,
                                    "char": 28
                                },
                                "right": {
                                    "type": "static-constant-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "Acl",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 792,
                                        "char": 40
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "ALLOW",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 792,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 792,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 792,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 793,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check whether a role is allowed to access an action from a component\n     *\n     * ```php\n     * \/\/ Does andres have access to the customers component to create?\n     * $acl->isAllowed(\"andres\", \"Products\", \"create\");\n     *\n     * \/\/ Do guests have access to any component to edit?\n     * $acl->isAllowed(\"guests\", \"*\", \"edit\");\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 572,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                        "line": 572,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                    "line": 571,
                    "last-line": 797,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isRole",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "roleName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 798,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 800,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "rolesNames",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 800,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 800,
                                        "char": 38
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "roleName",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 800,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 800,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 800,
                                "char": 48
                            },
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 801,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check whether role exist in the roles list\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 799,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                        "line": 799,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                    "line": 798,
                    "last-line": 805,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isComponent",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "componentName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 806,
                            "char": 53
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 808,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "componentsNames",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 808,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 808,
                                        "char": 43
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "componentName",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 808,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 808,
                                    "char": 58
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 808,
                                "char": 58
                            },
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 809,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check whether component exist in the components list\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 807,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                        "line": 807,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                    "line": 806,
                    "last-line": 815,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setNoArgumentsDefaultAction",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "defaultAccess",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 816,
                            "char": 66
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
                                    "property": "noArgumentsDefaultAction",
                                    "expr": {
                                        "type": "variable",
                                        "value": "defaultAccess",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 818,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 818,
                                    "char": 59
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 819,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the default access level (`Phalcon\\Acl::ALLOW` or `Phalcon\\Acl::DENY`)\n     * for no arguments provided in isAllowed action if there exists func for\n     * accessKey\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                        "line": 817,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                    "line": 816,
                    "last-line": 823,
                    "char": 19
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "allowOrDeny",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "roleName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 824,
                            "char": 49
                        },
                        {
                            "type": "parameter",
                            "name": "componentName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 824,
                            "char": 71
                        },
                        {
                            "type": "parameter",
                            "name": "access",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 824,
                            "char": 83
                        },
                        {
                            "type": "parameter",
                            "name": "action",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 824,
                            "char": 95
                        },
                        {
                            "type": "parameter",
                            "name": "func",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 824,
                                "char": 112
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 824,
                            "char": 112
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "accessList",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 826,
                                    "char": 23
                                },
                                {
                                    "variable": "accessName",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 826,
                                    "char": 35
                                },
                                {
                                    "variable": "accessKey",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 826,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 828,
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
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 828,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "rolesNames",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 828,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 828,
                                                "char": 44
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "roleName",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 828,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 828,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 828,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 828,
                                    "char": 55
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 828,
                                "char": 55
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
                                                            "value": "Role '",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 830,
                                                            "char": 24
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "roleName",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 830,
                                                            "char": 35
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 830,
                                                        "char": 35
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "' does not exist in the ACL",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 831,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 831,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 831,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 831,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 832,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 834,
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
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 834,
                                                    "char": 33
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "componentsNames",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 834,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 834,
                                                "char": 49
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "componentName",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 834,
                                                "char": 63
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 834,
                                            "char": 65
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 834,
                                        "char": 65
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 834,
                                    "char": 65
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 834,
                                "char": 65
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
                                                            "value": "Component '",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 836,
                                                            "char": 29
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "componentName",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 836,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 836,
                                                        "char": 45
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "' does not exist in the ACL",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 837,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 837,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 837,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 837,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 838,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 840,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "accessList",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 840,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "accessList",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 840,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 840,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 840,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 842,
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
                                        "value": "access",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 842,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 842,
                                    "char": 27
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 842,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 842,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "access",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 843,
                                        "char": 38
                                    },
                                    "value": "accessName",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "accessKey",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "componentName",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 844,
                                                                "char": 47
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "!",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 844,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 844,
                                                            "char": 51
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "accessName",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 844,
                                                            "char": 63
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 844,
                                                        "char": 63
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 844,
                                                    "char": 63
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 846,
                                            "char": 18
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
                                                                "value": "accessList",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 846,
                                                                "char": 46
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "accessKey",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 846,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 846,
                                                            "char": 58
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 846,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 846,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 846,
                                                "char": 58
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
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "concat",
                                                                                "left": {
                                                                                    "type": "string",
                                                                                    "value": "Access '",
                                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                    "line": 848,
                                                                                    "char": 34
                                                                                },
                                                                                "right": {
                                                                                    "type": "variable",
                                                                                    "value": "accessName",
                                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                    "line": 848,
                                                                                    "char": 47
                                                                                },
                                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                "line": 848,
                                                                                "char": 47
                                                                            },
                                                                            "right": {
                                                                                "type": "string",
                                                                                "value": "' does not exist in component '",
                                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                "line": 849,
                                                                                "char": 57
                                                                            },
                                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                            "line": 849,
                                                                            "char": 57
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "componentName",
                                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                            "line": 849,
                                                                            "char": 73
                                                                        },
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 849,
                                                                        "char": 73
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "'",
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 850,
                                                                        "char": 21
                                                                    },
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 850,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 850,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 850,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 851,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 852,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 854,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "access",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 854,
                                        "char": 38
                                    },
                                    "value": "accessName",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "accessKey",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "roleName",
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 855,
                                                                        "char": 42
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "!",
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 855,
                                                                        "char": 46
                                                                    },
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 855,
                                                                    "char": 46
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "componentName",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 855,
                                                                    "char": 61
                                                                },
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 855,
                                                                "char": 61
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "!",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 855,
                                                                "char": 65
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 855,
                                                            "char": 65
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "accessName",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 855,
                                                            "char": 77
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 855,
                                                        "char": 77
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 855,
                                                    "char": 77
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 856,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property-array-index",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "access",
                                                    "index-expr": [
                                                        {
                                                            "type": "variable",
                                                            "value": "accessKey",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 856,
                                                            "char": 43
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "action",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 856,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 856,
                                                    "char": 53
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 858,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not-equals",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "func",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 858,
                                                    "char": 26
                                                },
                                                "right": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 858,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 858,
                                                "char": 33
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "object-property-array-index",
                                                            "operator": "assign",
                                                            "variable": "this",
                                                            "property": "func",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "accessKey",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 859,
                                                                    "char": 45
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "func",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 859,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 859,
                                                            "char": 53
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 860,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 861,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 862,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-equals",
                                        "left": {
                                            "type": "variable",
                                            "value": "access",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 863,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "*",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 863,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 863,
                                        "char": 28
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "accessKey",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "componentName",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 864,
                                                                "char": 47
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "!",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 864,
                                                                "char": 51
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 864,
                                                            "char": 51
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "access",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 864,
                                                            "char": 59
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 864,
                                                        "char": 59
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 864,
                                                    "char": 59
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 866,
                                            "char": 18
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
                                                                "value": "accessList",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 866,
                                                                "char": 46
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "accessKey",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 866,
                                                                "char": 56
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 866,
                                                            "char": 58
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 866,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 866,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 866,
                                                "char": 58
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
                                                                            "type": "concat",
                                                                            "left": {
                                                                                "type": "concat",
                                                                                "left": {
                                                                                    "type": "string",
                                                                                    "value": "Access '",
                                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                    "line": 868,
                                                                                    "char": 34
                                                                                },
                                                                                "right": {
                                                                                    "type": "variable",
                                                                                    "value": "access",
                                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                    "line": 868,
                                                                                    "char": 43
                                                                                },
                                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                "line": 868,
                                                                                "char": 43
                                                                            },
                                                                            "right": {
                                                                                "type": "string",
                                                                                "value": "' does not exist in component '",
                                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                                "line": 869,
                                                                                "char": 57
                                                                            },
                                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                            "line": 869,
                                                                            "char": 57
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "componentName",
                                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                            "line": 869,
                                                                            "char": 73
                                                                        },
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 869,
                                                                        "char": 73
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "'",
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 870,
                                                                        "char": 21
                                                                    },
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 870,
                                                                    "char": 21
                                                                },
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 870,
                                                                "char": 21
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 870,
                                                        "char": 22
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 871,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 872,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 874,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "accessKey",
                                            "expr": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "roleName",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 874,
                                                                "char": 38
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "!",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 874,
                                                                "char": 42
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 874,
                                                            "char": 42
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "componentName",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 874,
                                                            "char": 58
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 874,
                                                        "char": 58
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "!",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 874,
                                                        "char": 62
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 874,
                                                    "char": 62
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "access",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 874,
                                                    "char": 70
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 874,
                                                "char": 70
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 874,
                                            "char": 70
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 879,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property-array-index",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "access",
                                            "index-expr": [
                                                {
                                                    "type": "variable",
                                                    "value": "accessKey",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 879,
                                                    "char": 39
                                                }
                                            ],
                                            "expr": {
                                                "type": "variable",
                                                "value": "action",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 879,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 879,
                                            "char": 49
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 881,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not-equals",
                                        "left": {
                                            "type": "variable",
                                            "value": "func",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 881,
                                            "char": 22
                                        },
                                        "right": {
                                            "type": "null",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 881,
                                            "char": 29
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 881,
                                        "char": 29
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property-array-index",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "func",
                                                    "index-expr": [
                                                        {
                                                            "type": "variable",
                                                            "value": "accessKey",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 882,
                                                            "char": 41
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "func",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 882,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 882,
                                                    "char": 49
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 883,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 884,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 885,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks if a role has access to a component\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                        "line": 825,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                    "line": 824,
                    "last-line": 889,
                    "char": 20
                },
                {
                    "visibility": [
                        "private"
                    ],
                    "type": "method",
                    "name": "canAccess",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "roleName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 890,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "componentName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 890,
                            "char": 69
                        },
                        {
                            "type": "parameter",
                            "name": "access",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 890,
                            "char": 84
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "accessList",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 892,
                                    "char": 23
                                },
                                {
                                    "variable": "checkRoleToInherit",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 892,
                                    "char": 43
                                },
                                {
                                    "variable": "usedRoleToInherit",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 892,
                                    "char": 62
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 893,
                            "char": 13
                        },
                        {
                            "type": "declare",
                            "data-type": "array",
                            "variables": [
                                {
                                    "variable": "usedRoleToInherits",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 893,
                                    "char": 33
                                },
                                {
                                    "variable": "checkRoleToInherits",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 893,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 894,
                            "char": 14
                        },
                        {
                            "type": "declare",
                            "data-type": "string",
                            "variables": [
                                {
                                    "variable": "accessKey",
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 894,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 896,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "accessList",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 896,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "access",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 896,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 896,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 896,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 898,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "accessKey",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "concat",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "roleName",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 898,
                                                        "char": 34
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "!",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 898,
                                                        "char": 38
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 898,
                                                    "char": 38
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "componentName",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 898,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 898,
                                                "char": 54
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "!",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 898,
                                                "char": 58
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 898,
                                            "char": 58
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "access",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 898,
                                            "char": 66
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 898,
                                        "char": 66
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 898,
                                    "char": 66
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 903,
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
                                        "value": "accessList",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 903,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "accessKey",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 903,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 903,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 903,
                                "char": 40
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "accessKey",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 904,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 905,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 910,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "accessKey",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "concat",
                                            "left": {
                                                "type": "concat",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "roleName",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 910,
                                                    "char": 34
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "!",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 910,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 910,
                                                "char": 38
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "componentName",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 910,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 910,
                                            "char": 54
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "!*",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 910,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 910,
                                        "char": 58
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 910,
                                    "char": 58
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 912,
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
                                        "value": "accessList",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 912,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "accessKey",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 912,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 912,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 912,
                                "char": 40
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "accessKey",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 913,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 914,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 919,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "accessKey",
                                    "expr": {
                                        "type": "concat",
                                        "left": {
                                            "type": "variable",
                                            "value": "roleName",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 919,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "!*!*",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 919,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 919,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 919,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 921,
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
                                        "value": "accessList",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 921,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "accessKey",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 921,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 921,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 921,
                                "char": 40
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "accessKey",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 922,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 923,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 928,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "isset",
                                "left": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 928,
                                            "char": 23
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "roleInherits",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 928,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 928,
                                        "char": 36
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "roleName",
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 928,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 928,
                                    "char": 47
                                },
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 928,
                                "char": 47
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "checkRoleToInherits",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 929,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 929,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 931,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 931,
                                                "char": 43
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "roleInherits",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 931,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 931,
                                            "char": 56
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "roleName",
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 931,
                                            "char": 65
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 931,
                                        "char": 67
                                    },
                                    "value": "usedRoleToInherit",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "fcall",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "array_push",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "checkRoleToInherits",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 932,
                                                            "char": 47
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 932,
                                                        "char": 47
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "usedRoleToInherit",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 932,
                                                            "char": 66
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 932,
                                                        "char": 66
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 932,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 933,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 935,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "usedRoleToInherits",
                                            "expr": {
                                                "type": "empty-array",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 935,
                                                "char": 40
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 935,
                                            "char": 40
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 937,
                                    "char": 17
                                },
                                {
                                    "type": "while",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "empty",
                                            "left": {
                                                "type": "variable",
                                                "value": "checkRoleToInherits",
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 937,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 937,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                        "line": 937,
                                        "char": 46
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "checkRoleToInherit",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "array_shift",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "checkRoleToInherits",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 938,
                                                                    "char": 73
                                                                },
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 938,
                                                                "char": 73
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 938,
                                                        "char": 74
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 938,
                                                    "char": 74
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 940,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "isset",
                                                "left": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "usedRoleToInherits",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 940,
                                                        "char": 44
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "checkRoleToInherit",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 940,
                                                        "char": 63
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 940,
                                                    "char": 65
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 940,
                                                "char": 65
                                            },
                                            "statements": [
                                                {
                                                    "type": "continue",
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 942,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 944,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "array-index",
                                                    "operator": "assign",
                                                    "variable": "usedRoleToInherits",
                                                    "index-expr": [
                                                        {
                                                            "type": "variable",
                                                            "value": "checkRoleToInherit",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 944,
                                                            "char": 58
                                                        }
                                                    ],
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "true",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 944,
                                                        "char": 66
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 944,
                                                    "char": 66
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 946,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "accessKey",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "concat",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "checkRoleToInherit",
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 946,
                                                                        "char": 52
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "!",
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 946,
                                                                        "char": 56
                                                                    },
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 946,
                                                                    "char": 56
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "componentName",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 946,
                                                                    "char": 72
                                                                },
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 946,
                                                                "char": 72
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "!",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 946,
                                                                "char": 76
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 946,
                                                            "char": 76
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "access",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 946,
                                                            "char": 84
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 946,
                                                        "char": 84
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 946,
                                                    "char": 84
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 952,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "isset",
                                                "left": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "accessList",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 952,
                                                        "char": 36
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "accessKey",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 952,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 952,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 952,
                                                "char": 48
                                            },
                                            "statements": [
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "accessKey",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 953,
                                                        "char": 37
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 954,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 959,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "accessKey",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "concat",
                                                            "left": {
                                                                "type": "concat",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "checkRoleToInherit",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 959,
                                                                    "char": 52
                                                                },
                                                                "right": {
                                                                    "type": "string",
                                                                    "value": "!",
                                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                    "line": 959,
                                                                    "char": 56
                                                                },
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 959,
                                                                "char": 56
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "componentName",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 959,
                                                                "char": 72
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 959,
                                                            "char": 72
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "!*",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 959,
                                                            "char": 76
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 959,
                                                        "char": 76
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 959,
                                                    "char": 76
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 961,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "isset",
                                                "left": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "accessList",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 961,
                                                        "char": 36
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "accessKey",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 961,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 961,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 961,
                                                "char": 48
                                            },
                                            "statements": [
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "accessKey",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 962,
                                                        "char": 37
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 963,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 968,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "accessKey",
                                                    "expr": {
                                                        "type": "concat",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "checkRoleToInherit",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 968,
                                                            "char": 52
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "!*!*",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 968,
                                                            "char": 58
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 968,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 968,
                                                    "char": 58
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 970,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "isset",
                                                "left": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "accessList",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 970,
                                                        "char": 36
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "accessKey",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 970,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 970,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 970,
                                                "char": 48
                                            },
                                            "statements": [
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "accessKey",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 971,
                                                        "char": 37
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 972,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 977,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "isset",
                                                "left": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 977,
                                                            "char": 31
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "roleInherits",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 977,
                                                            "char": 44
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 977,
                                                        "char": 44
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "checkRoleToInherit",
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 977,
                                                        "char": 63
                                                    },
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 977,
                                                    "char": 65
                                                },
                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                "line": 977,
                                                "char": 65
                                            },
                                            "statements": [
                                                {
                                                    "type": "for",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "property-access",
                                                            "left": {
                                                                "type": "variable",
                                                                "value": "this",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 978,
                                                                "char": 51
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "roleInherits",
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 978,
                                                                "char": 64
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 978,
                                                            "char": 64
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "checkRoleToInherit",
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 978,
                                                            "char": 83
                                                        },
                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                        "line": 978,
                                                        "char": 85
                                                    },
                                                    "value": "usedRoleToInherit",
                                                    "reverse": 0,
                                                    "statements": [
                                                        {
                                                            "type": "fcall",
                                                            "expr": {
                                                                "type": "fcall",
                                                                "name": "array_push",
                                                                "call-type": 1,
                                                                "parameters": [
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "checkRoleToInherits",
                                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                            "line": 979,
                                                                            "char": 55
                                                                        },
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 979,
                                                                        "char": 55
                                                                    },
                                                                    {
                                                                        "parameter": {
                                                                            "type": "variable",
                                                                            "value": "usedRoleToInherit",
                                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                            "line": 979,
                                                                            "char": 74
                                                                        },
                                                                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                        "line": 979,
                                                                        "char": 74
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                                "line": 979,
                                                                "char": 75
                                                            },
                                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                            "line": 980,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                                    "line": 981,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                            "line": 982,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                    "line": 983,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 985,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 985,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                            "line": 986,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Check whether a role is allowed to access an action from a component\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 890,
                                "char": 96
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                                "line": 891,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                        "line": 891,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
                    "line": 890,
                    "last-line": 987,
                    "char": 20
                }
            ],
            "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
            "line": 89,
            "char": 5
        },
        "file": "\/app\/phalcon\/Acl\/Adapter\/Memory.zep",
        "line": 89,
        "char": 5
    }
]