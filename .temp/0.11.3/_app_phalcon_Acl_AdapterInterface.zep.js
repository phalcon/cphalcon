[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Acl",
        "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
        "line": 15,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Interface for Phalcon\\Acl adapters\n *",
        "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
        "line": 16,
        "char": 9
    },
    {
        "type": "interface",
        "name": "AdapterInterface",
        "definition": {
            "methods": [
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
                            "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                            "line": 21,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "roleToInherit",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                            "line": 21,
                            "char": 62
                        }
                    ],
                    "docblock": "**\n     * Do a role inherit from another existing role\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                                "line": 21,
                                "char": 71
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                        "line": 21,
                        "char": 71
                    },
                    "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                    "line": 21,
                    "last-line": 26,
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
                            "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                            "line": 27,
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
                                "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                                "line": 27,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                            "line": 27,
                            "char": 56
                        }
                    ],
                    "docblock": "**\n     * Adds a role to the ACL list. Second parameter lets to inherit access data\n     * from other existing role\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                                "line": 27,
                                "char": 65
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                        "line": 27,
                        "char": 65
                    },
                    "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                    "line": 27,
                    "last-line": 34,
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
                            "name": "componentObject",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                            "line": 35,
                            "char": 49
                        },
                        {
                            "type": "parameter",
                            "name": "accessList",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                            "line": 35,
                            "char": 61
                        }
                    ],
                    "docblock": "**\n     * Adds a component to the ACL list\n     *\n     * Access names can be a particular action, by example\n     * search, update, delete, etc or a list of them\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                                "line": 35,
                                "char": 70
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                        "line": 35,
                        "char": 70
                    },
                    "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                    "line": 35,
                    "last-line": 39,
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
                            "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                            "line": 40,
                            "char": 60
                        },
                        {
                            "type": "parameter",
                            "name": "accessList",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                            "line": 40,
                            "char": 72
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
                                "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                                "line": 40,
                                "char": 81
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                        "line": 40,
                        "char": 81
                    },
                    "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                    "line": 40,
                    "last-line": 44,
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
                            "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                            "line": 45,
                            "char": 42
                        },
                        {
                            "type": "parameter",
                            "name": "componentName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                            "line": 45,
                            "char": 64
                        },
                        {
                            "type": "parameter",
                            "name": "access",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                            "line": 45,
                            "char": 72
                        },
                        {
                            "type": "parameter",
                            "name": "func",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                                "line": 45,
                                "char": 85
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                            "line": 45,
                            "char": 85
                        }
                    ],
                    "docblock": "**\n     * Allow access to a role on a component\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                        "line": 45,
                        "char": 94
                    },
                    "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                    "line": 45,
                    "last-line": 49,
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
                            "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                            "line": 50,
                            "char": 41
                        },
                        {
                            "type": "parameter",
                            "name": "componentName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                            "line": 50,
                            "char": 63
                        },
                        {
                            "type": "parameter",
                            "name": "access",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                            "line": 50,
                            "char": 71
                        },
                        {
                            "type": "parameter",
                            "name": "func",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                                "line": 50,
                                "char": 84
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                            "line": 50,
                            "char": 84
                        }
                    ],
                    "docblock": "**\n     * Deny access to a role on a component\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                        "line": 50,
                        "char": 93
                    },
                    "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                    "line": 50,
                    "last-line": 54,
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
                            "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                            "line": 55,
                            "char": 61
                        },
                        {
                            "type": "parameter",
                            "name": "accessList",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                            "line": 55,
                            "char": 73
                        }
                    ],
                    "docblock": "**\n     * Removes an access from a component\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                        "line": 55,
                        "char": 82
                    },
                    "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                    "line": 55,
                    "last-line": 59,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getActiveAccess",
                    "docblock": "**\n     * Returns the access which the list is checking if some role can access it\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                                "line": 60,
                                "char": 48
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                        "line": 60,
                        "char": 48
                    },
                    "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                    "line": 60,
                    "last-line": 65,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getActiveRole",
                    "docblock": "**\n     * Returns the role which the list is checking if it's allowed to certain\n     * component\/access\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                                "line": 66,
                                "char": 46
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                        "line": 66,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                    "line": 66,
                    "last-line": 71,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getActiveComponent",
                    "docblock": "**\n     * Returns the component which the list is checking if some role can access\n     * it\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                                "line": 72,
                                "char": 51
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                        "line": 72,
                        "char": 51
                    },
                    "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                    "line": 72,
                    "last-line": 76,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDefaultAction",
                    "docblock": "**\n     * Returns the default ACL access level\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                                "line": 77,
                                "char": 46
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                        "line": 77,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                    "line": 77,
                    "last-line": 82,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getNoArgumentsDefaultAction",
                    "docblock": "**\n     * Returns the default ACL access level for no arguments provided in\n     * isAllowed action if there exists func for accessKey\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                                "line": 83,
                                "char": 57
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                        "line": 83,
                        "char": 57
                    },
                    "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                    "line": 83,
                    "last-line": 87,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRoles",
                    "docblock": "**\n     * Return an array with every role registered in the list\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "RoleInterface",
                                    "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                                    "line": 88,
                                    "char": 52
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                                "line": 88,
                                "char": 52
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                        "line": 88,
                        "char": 52
                    },
                    "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                    "line": 88,
                    "last-line": 92,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getComponents",
                    "docblock": "**\n     * Return an array with every component registered in the list\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ComponentInterface",
                                    "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                                    "line": 93,
                                    "char": 62
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                                "line": 93,
                                "char": 62
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                        "line": 93,
                        "char": 62
                    },
                    "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                    "line": 93,
                    "last-line": 97,
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
                            "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                            "line": 98,
                            "char": 39
                        },
                        {
                            "type": "parameter",
                            "name": "componentName",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                            "line": 98,
                            "char": 54
                        },
                        {
                            "type": "parameter",
                            "name": "access",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                            "line": 98,
                            "char": 69
                        },
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                                "line": 98,
                                "char": 94
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                            "line": 98,
                            "char": 94
                        }
                    ],
                    "docblock": "**\n     * Check whether a role is allowed to access an action from a component\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                                "line": 98,
                                "char": 103
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                        "line": 98,
                        "char": 103
                    },
                    "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                    "line": 98,
                    "last-line": 102,
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
                            "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                            "line": 103,
                            "char": 53
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
                                "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                                "line": 103,
                                "char": 62
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                        "line": 103,
                        "char": 62
                    },
                    "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                    "line": 103,
                    "last-line": 107,
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
                            "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                            "line": 108,
                            "char": 43
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
                                "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                                "line": 108,
                                "char": 52
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                        "line": 108,
                        "char": 52
                    },
                    "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                    "line": 108,
                    "last-line": 112,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDefaultAction",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "defaultAccess",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                            "line": 113,
                            "char": 55
                        }
                    ],
                    "docblock": "**\n     * Sets the default access level (Phalcon\\Acl::ALLOW or Phalcon\\Acl::DENY)\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                        "line": 113,
                        "char": 64
                    },
                    "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                    "line": 113,
                    "last-line": 119,
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
                            "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                            "line": 120,
                            "char": 66
                        }
                    ],
                    "docblock": "**\n     * Sets the default access level (Phalcon\\Acl::ALLOW or Phalcon\\Acl::DENY)\n     * for no arguments provided in isAllowed action if there exists func for\n     * accessKey\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                        "line": 120,
                        "char": 75
                    },
                    "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
                    "line": 120,
                    "last-line": 121,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
            "line": 121,
            "char": 1
        },
        "file": "\/app\/phalcon\/Acl\/AdapterInterface.zep",
        "line": 0,
        "char": 0
    }
]