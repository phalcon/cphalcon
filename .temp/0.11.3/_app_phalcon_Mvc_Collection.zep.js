[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc",
        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Mongo",
                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                "line": 13,
                "char": 10
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "MongoCollection",
                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                "line": 14,
                "char": 20
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "MongoId",
                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                "line": 15,
                "char": 12
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di",
                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                "line": 16,
                "char": 15
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                "line": 17,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\InjectionAwareInterface",
                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                "line": 18,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\MessageInterface",
                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                "line": 19,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
        "line": 20,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Collection\\BehaviorInterface",
                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                "line": 20,
                "char": 45
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
        "line": 21,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Collection\\Document",
                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                "line": 21,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
        "line": 22,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Collection\\Exception",
                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                "line": 22,
                "char": 37
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
        "line": 23,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\Collection\\ManagerInterface",
                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                "line": 23,
                "char": 44
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
        "line": 24,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\Message",
                "alias": "Message",
                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                "line": 24,
                "char": 40
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
        "line": 25,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Validation\\ValidationInterface",
                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                "line": 25,
                "char": 43
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
        "line": 26,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Serializer\\SerializerInterface",
                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                "line": 26,
                "char": 51
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
        "line": 27,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Serializable",
                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                "line": 27,
                "char": 17
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
        "line": 34,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Collection\n *\n * This component implements a high level abstraction for NoSQL databases which\n * works with documents\n *",
        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
        "line": 35,
        "char": 8
    },
    {
        "type": "class",
        "name": "Collection",
        "abstract": 1,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "EntityInterface",
                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                "line": 35,
                "char": 53
            },
            {
                "type": "variable",
                "value": "CollectionInterface",
                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                "line": 35,
                "char": 74
            },
            {
                "type": "variable",
                "value": "InjectionAwareInterface",
                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                "line": 35,
                "char": 99
            },
            {
                "type": "variable",
                "value": "Serializable",
                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                "line": 36,
                "char": 1
            }
        ],
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "property",
                    "name": "_id",
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 47,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "connection",
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 49,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "container",
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 51,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "dirtyState",
                    "default": {
                        "type": "int",
                        "value": "1",
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 51,
                        "char": 29
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 53,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected",
                        "static"
                    ],
                    "type": "property",
                    "name": "disableEvents",
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 55,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "errorMessages",
                    "default": {
                        "type": "empty-array",
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 55,
                        "char": 33
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 57,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "modelsManager",
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 59,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "operationMade",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 59,
                        "char": 32
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 61,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected",
                        "static"
                    ],
                    "type": "property",
                    "name": "reserved",
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 63,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "skipped",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 63,
                        "char": 30
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 65,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "source",
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 69,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "final",
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
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 70,
                                "char": 61
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 70,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 70,
                            "char": 69
                        },
                        {
                            "type": "parameter",
                            "name": "modelsManager",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ManagerInterface",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 70,
                                "char": 102
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 70,
                                "char": 110
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 70,
                            "char": 110
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "container",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 75,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 75,
                                    "char": 30
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 75,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 75,
                                "char": 39
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
                                                "type": "scall",
                                                "dynamic-class": 0,
                                                "class": "Di",
                                                "dynamic": 0,
                                                "name": "getDefault",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 76,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 76,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 77,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 79,
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
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 79,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 79,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 79,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 79,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 79,
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
                                                                "value": "the services related to the ODM",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 83,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 83,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 84,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 84,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 84,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 85,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 87,
                            "char": 11
                        },
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
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 87,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 87,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 92,
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
                                        "value": "modelsManager",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 92,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 92,
                                    "char": 34
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 92,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 92,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "modelsManager",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 93,
                                                    "char": 43
                                                },
                                                "name": "getShared",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "collectionManager",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 93,
                                                            "char": 71
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 93,
                                                        "char": 71
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 93,
                                                "char": 72
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 93,
                                            "char": 72
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 94,
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
                                                    "value": "modelsManager",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 94,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 94,
                                                "char": 47
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 94,
                                                "char": 56
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 94,
                                            "char": 56
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 94,
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
                                                            "type": "string",
                                                            "value": "The injected service 'modelsManager' is not valid",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 97,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 97,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 97,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 98,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 99,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 104,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "modelsManager",
                                    "expr": {
                                        "type": "variable",
                                        "value": "modelsManager",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 104,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 104,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 109,
                            "char": 21
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "modelsManager",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 109,
                                    "char": 23
                                },
                                "name": "initialize",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 109,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 109,
                                        "char": 39
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 109,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 115,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "method_exists",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 115,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 115,
                                        "char": 30
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "onConstruct",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 115,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 115,
                                        "char": 43
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 115,
                                "char": 45
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 116,
                                            "char": 18
                                        },
                                        "name": "onConstruct",
                                        "call-type": 3,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 116,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 117,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 118,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Mvc\\Collection constructor\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 70,
                    "last-line": 122,
                    "char": 25
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "addBehavior",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "behavior",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "BehaviorInterface",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 123,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 123,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "list",
                                    "left": {
                                        "type": "type-hint",
                                        "left": {
                                            "type": "variable",
                                            "value": "ManagerInterface",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 125,
                                            "char": 48
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 125,
                                                "char": 34
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "modelsManager",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 125,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 125,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 125,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 125,
                                    "char": 50
                                },
                                "name": "addBehavior",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 125,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 125,
                                        "char": 67
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "behavior",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 125,
                                            "char": 77
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 125,
                                        "char": 77
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 125,
                                "char": 78
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 126,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets up a behavior in a collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 124,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 123,
                    "last-line": 130,
                    "char": 22
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "aggregate",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 131,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 131,
                            "char": 61
                        },
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 131,
                                "char": 83
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 131,
                            "char": 83
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "className",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 133,
                                    "char": 22
                                },
                                {
                                    "variable": "model",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 133,
                                    "char": 29
                                },
                                {
                                    "variable": "connection",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 133,
                                    "char": 41
                                },
                                {
                                    "variable": "source",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 133,
                                    "char": 49
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 135,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "className",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "get_called_class",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 135,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 135,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 137,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "model",
                                    "expr": {
                                        "type": "new",
                                        "class": "className",
                                        "dynamic": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 137,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 137,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 139,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "connection",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "model",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 139,
                                            "char": 32
                                        },
                                        "name": "getConnection",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 139,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 139,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 141,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "source",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "model",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 141,
                                            "char": 28
                                        },
                                        "name": "getSource",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 141,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 141,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 142,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "empty",
                                    "left": {
                                        "type": "variable",
                                        "value": "source",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 142,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 142,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 142,
                                "char": 34
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
                                                    "value": "Method getSource() returns empty string",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 143,
                                                    "char": 72
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 143,
                                                "char": 72
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 143,
                                        "char": 73
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 144,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 146,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "connection",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 146,
                                        "char": 27
                                    },
                                    "name": "selectCollection",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "source",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 146,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 146,
                                            "char": 51
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 146,
                                    "char": 53
                                },
                                "name": "aggregate",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "parameters",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 147,
                                            "char": 23
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 147,
                                        "char": 23
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 149,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 149,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 149,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 150,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Perform an aggregation using the Mongo aggregation framework\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 132,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 132,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 131,
                    "last-line": 172,
                    "char": 26
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "appendMessage",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "message",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "MessageInterface",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 173,
                                "char": 60
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 173,
                            "char": 61
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
                                    "property": "errorMessages",
                                    "expr": {
                                        "type": "variable",
                                        "value": "message",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 175,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 175,
                                    "char": 44
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 176,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Appends a customized message on the validation process\n     *\n     *```php\n     * use \\Phalcon\\Messages\\Message as Message;\n     *\n     * class Robots extends \\Phalcon\\Mvc\\Model\n     * {\n     *     public function beforeSave()\n     *     {\n     *         if ($this->name === \"Peter\") {\n     *             $message = new Message(\n     *                 \"Sorry, but a robot cannot be named Peter\"\n     *             );\n     *\n     *             $this->appendMessage(message);\n     *         }\n     *     }\n     * }\n     *```\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 173,
                    "last-line": 180,
                    "char": 19
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "cloneResult",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "collection",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "CollectionInterface",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 181,
                                "char": 71
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 181,
                            "char": 72
                        },
                        {
                            "type": "parameter",
                            "name": "document",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 181,
                            "char": 89
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "clonedCollection",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 183,
                                    "char": 29
                                },
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 183,
                                    "char": 34
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 183,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 185,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "clonedCollection",
                                    "expr": {
                                        "type": "clone",
                                        "left": {
                                            "type": "variable",
                                            "value": "collection",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 185,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 185,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 185,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 186,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "variable",
                                "value": "document",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 186,
                                "char": 36
                            },
                            "key": "key",
                            "value": "value",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "clonedCollection",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 187,
                                            "char": 30
                                        },
                                        "name": "writeAttribute",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "key",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 187,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 187,
                                                "char": 49
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "value",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 187,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 187,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 187,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 188,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 190,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "method_exists",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "clonedCollection",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 190,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 190,
                                        "char": 42
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "afterFetch",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 190,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 190,
                                        "char": 54
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 190,
                                "char": 56
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "clonedCollection",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 191,
                                            "char": 30
                                        },
                                        "name": "afterFetch",
                                        "call-type": 3,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 191,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 192,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 194,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "clonedCollection",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 194,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 195,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a cloned collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CollectionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 182,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 182,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 182,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 181,
                    "last-line": 199,
                    "char": 26
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "create",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 202,
                                    "char": 17
                                },
                                {
                                    "variable": "success",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 202,
                                    "char": 26
                                },
                                {
                                    "variable": "status",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 202,
                                    "char": 34
                                },
                                {
                                    "variable": "id",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 202,
                                    "char": 38
                                },
                                {
                                    "variable": "ok",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 202,
                                    "char": 42
                                },
                                {
                                    "variable": "collection",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 202,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 203,
                            "char": 12
                        },
                        {
                            "type": "declare",
                            "data-type": "bool",
                            "variables": [
                                {
                                    "variable": "exists",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 203,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 205,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "collection",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 205,
                                            "char": 31
                                        },
                                        "name": "prepareCU",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 205,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 205,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 211,
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
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 211,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 211,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 212,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "operationMade",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 212,
                                            "char": 50
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "OP_CREATE",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 212,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 212,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 212,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 217,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "errorMessages",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 217,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 217,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 222,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 222,
                                        "char": 17
                                    },
                                    "name": "preSave",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 222,
                                                    "char": 31
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 222,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 222,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 222,
                                            "char": 41
                                        },
                                        {
                                            "parameter": {
                                                "type": "static-property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 222,
                                                    "char": 62
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "disableEvents",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 222,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 222,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 222,
                                            "char": 62
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "exists",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 222,
                                                "char": 70
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 222,
                                            "char": 70
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 222,
                                    "char": 74
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 222,
                                    "char": 82
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 222,
                                "char": 82
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 223,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 224,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 226,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "data",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 226,
                                            "char": 25
                                        },
                                        "name": "toArray",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 226,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 226,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 228,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "success",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 228,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 228,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 234,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "status",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "collection",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 234,
                                            "char": 33
                                        },
                                        "name": "insert",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "data",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 234,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 234,
                                                "char": 45
                                            },
                                            {
                                                "parameter": {
                                                    "type": "array",
                                                    "left": [
                                                        {
                                                            "key": {
                                                                "type": "string",
                                                                "value": "w",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 234,
                                                                "char": 49
                                                            },
                                                            "value": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 234,
                                                                "char": 55
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 234,
                                                            "char": 55
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 234,
                                                    "char": 56
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 234,
                                                "char": 56
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 234,
                                        "char": 57
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 234,
                                    "char": 57
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 235,
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
                                        "value": "status",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 235,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 235,
                                    "char": 27
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 235,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 235,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "ok",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 236,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "status",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 236,
                                                "char": 32
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "ok",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 236,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 236,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 236,
                                        "char": 37
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "variable",
                                                "value": "ok",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 237,
                                                "char": 23
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "success",
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 238,
                                                                "char": 39
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 238,
                                                            "char": 39
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 239,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "not",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "exists",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 239,
                                                            "char": 32
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 239,
                                                        "char": 32
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "fetch",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "id",
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                    "line": 240,
                                                                    "char": 48
                                                                },
                                                                "right": {
                                                                    "type": "array-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "data",
                                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                        "line": 240,
                                                                        "char": 42
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "_id",
                                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                        "line": 240,
                                                                        "char": 46
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                    "line": 240,
                                                                    "char": 48
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 240,
                                                                "char": 48
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "object-property",
                                                                            "operator": "assign",
                                                                            "variable": "this",
                                                                            "property": "_id",
                                                                            "expr": {
                                                                                "type": "variable",
                                                                                "value": "id",
                                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                                "line": 241,
                                                                                "char": 47
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                            "line": 241,
                                                                            "char": 47
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                    "line": 242,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 243,
                                                            "char": 27
                                                        },
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "object-property",
                                                                    "operator": "assign",
                                                                    "variable": "this",
                                                                    "property": "dirtyState",
                                                                    "expr": {
                                                                        "type": "static-constant-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "self",
                                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                            "line": 243,
                                                                            "char": 76
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "DIRTY_STATE_PERSISTENT",
                                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                            "line": 243,
                                                                            "char": 76
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                        "line": 243,
                                                                        "char": 76
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                    "line": 243,
                                                                    "char": 76
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 244,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 245,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 246,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 247,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 252,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 252,
                                    "char": 21
                                },
                                "name": "postSave",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "static-property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 252,
                                                "char": 50
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "disableEvents",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 252,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 252,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 252,
                                        "char": 50
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "success",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 252,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 252,
                                        "char": 59
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "exists",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 252,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 252,
                                        "char": 67
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 252,
                                "char": 68
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 253,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Creates a collection based on the values in the attributes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 201,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 201,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 200,
                    "last-line": 274,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "createIfNotExist",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "criteria",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 275,
                            "char": 53
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "exists",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 277,
                                    "char": 19
                                },
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 277,
                                    "char": 25
                                },
                                {
                                    "variable": "keys",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 277,
                                    "char": 31
                                },
                                {
                                    "variable": "query",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 277,
                                    "char": 38
                                },
                                {
                                    "variable": "success",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 278,
                                    "char": 20
                                },
                                {
                                    "variable": "status",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 278,
                                    "char": 28
                                },
                                {
                                    "variable": "doc",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 278,
                                    "char": 33
                                },
                                {
                                    "variable": "collection",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 278,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 280,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "empty",
                                    "left": {
                                        "type": "variable",
                                        "value": "criteria",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 280,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 280,
                                    "char": 36
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 280,
                                "char": 36
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
                                                    "value": "Criteria parameter must be array with one or more attributes of the model",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 283,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 283,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 283,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 284,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 289,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "collection",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 289,
                                            "char": 31
                                        },
                                        "name": "prepareCU",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 289,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 289,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 295,
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
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 295,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 295,
                                    "char": 27
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 301,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "operationMade",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 301,
                                            "char": 48
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "OP_NONE",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 301,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 301,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 301,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 306,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "errorMessages",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 306,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 306,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 311,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 311,
                                        "char": 17
                                    },
                                    "name": "preSave",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 311,
                                                    "char": 31
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 311,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 311,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 311,
                                            "char": 41
                                        },
                                        {
                                            "parameter": {
                                                "type": "static-property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 311,
                                                    "char": 62
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "disableEvents",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 311,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 311,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 311,
                                            "char": 62
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "exists",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 311,
                                                "char": 70
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 311,
                                            "char": 70
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 311,
                                    "char": 74
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 311,
                                    "char": 82
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 311,
                                "char": 82
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 312,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 313,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 315,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "keys",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "array_flip",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "criteria",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 315,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 315,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 315,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 315,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 316,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "data",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 316,
                                            "char": 25
                                        },
                                        "name": "toArray",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 316,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 316,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 318,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "fcall",
                                    "name": "array_diff_key",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "keys",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 318,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 318,
                                            "char": 41
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "data",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 318,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 318,
                                            "char": 48
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 318,
                                    "char": 50
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 318,
                                "char": 50
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
                                                    "value": "Criteria parameter must be array with one or more attributes of the model",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 321,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 321,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 321,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 322,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 324,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "query",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "array_intersect_key",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "data",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 324,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 324,
                                                "char": 46
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "keys",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 324,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 324,
                                                "char": 53
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 324,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 324,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 326,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "success",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 326,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 326,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 332,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "status",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "collection",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 332,
                                            "char": 33
                                        },
                                        "name": "findAndModify",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "query",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 332,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 332,
                                                "char": 53
                                            },
                                            {
                                                "parameter": {
                                                    "type": "array",
                                                    "left": [
                                                        {
                                                            "key": {
                                                                "type": "string",
                                                                "value": "$setOnInsert",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 333,
                                                                "char": 26
                                                            },
                                                            "value": {
                                                                "type": "variable",
                                                                "value": "data",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 333,
                                                                "char": 32
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 333,
                                                            "char": 32
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 333,
                                                    "char": 33
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 333,
                                                "char": 33
                                            },
                                            {
                                                "parameter": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 334,
                                                    "char": 17
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 334,
                                                "char": 17
                                            },
                                            {
                                                "parameter": {
                                                    "type": "array",
                                                    "left": [
                                                        {
                                                            "key": {
                                                                "type": "string",
                                                                "value": "new",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 335,
                                                                "char": 17
                                                            },
                                                            "value": {
                                                                "type": "bool",
                                                                "value": "false",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 335,
                                                                "char": 24
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 335,
                                                            "char": 24
                                                        },
                                                        {
                                                            "key": {
                                                                "type": "string",
                                                                "value": "upsert",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 335,
                                                                "char": 32
                                                            },
                                                            "value": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 335,
                                                                "char": 38
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 335,
                                                            "char": 38
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 335,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 335,
                                                "char": 39
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 335,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 335,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 336,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "variable",
                                    "value": "status",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 336,
                                    "char": 20
                                },
                                "right": {
                                    "type": "null",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 336,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 336,
                                "char": 27
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "doc",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "collection",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 337,
                                                    "char": 34
                                                },
                                                "name": "findOne",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "query",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 337,
                                                            "char": 48
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 337,
                                                        "char": 48
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 337,
                                                "char": 49
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 337,
                                            "char": 49
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 338,
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
                                                "value": "doc",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 338,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 338,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 338,
                                            "char": 36
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 338,
                                        "char": 36
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "success",
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "true",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 339,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 339,
                                                    "char": 35
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 340,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "operationMade",
                                                    "expr": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "self",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 340,
                                                            "char": 58
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "OP_CREATE",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 340,
                                                            "char": 58
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 340,
                                                        "char": 58
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 340,
                                                    "char": 58
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 341,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "_id",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "doc",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 341,
                                                            "char": 36
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "_id",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 341,
                                                            "char": 40
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 341,
                                                        "char": 41
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 341,
                                                    "char": 41
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 342,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 343,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 344,
                                            "char": 18
                                        },
                                        "name": "appendMessage",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "new",
                                                    "class": "Message",
                                                    "dynamic": 0,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "Document already exists",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 345,
                                                                "char": 52
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 345,
                                                            "char": 52
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 346,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 346,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 346,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 347,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 352,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 352,
                                    "char": 21
                                },
                                "name": "postSave",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "static-property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 352,
                                                "char": 50
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "disableEvents",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 352,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 352,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 352,
                                        "char": 50
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "success",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 352,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 352,
                                        "char": 59
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "exists",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 352,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 352,
                                        "char": 67
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 352,
                                "char": 68
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 353,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Creates a document based on the values in the attributes, if not found by\n     * criteria. Preferred way to avoid duplication is to create index o\n     * attribute\n     *\n     * ```php\n     * $robot = new Robot();\n     *\n     * $robot->name = \"MyRobot\";\n     * $robot->type = \"Droid\";\n     *\n     * \/\/ Create only if robot with same name and type does not exist\n     * $robot->createIfNotExist(\n     *     [\n     *         \"name\",\n     *         \"type\",\n     *     ]\n     * );\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 276,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 276,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 275,
                    "last-line": 361,
                    "char": 19
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "count",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 362,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 362,
                            "char": 57
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "className",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 364,
                                    "char": 22
                                },
                                {
                                    "variable": "collection",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 364,
                                    "char": 34
                                },
                                {
                                    "variable": "connection",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 364,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 366,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "className",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "get_called_class",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 366,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 366,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 368,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "collection",
                                    "expr": {
                                        "type": "new",
                                        "class": "className",
                                        "dynamic": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 368,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 368,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 370,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "connection",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "collection",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 370,
                                            "char": 37
                                        },
                                        "name": "getConnection",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 370,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 370,
                                    "char": 53
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 372,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "static",
                                "dynamic": 0,
                                "name": "getGroupResultset",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "parameters",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 372,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 372,
                                        "char": 52
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "collection",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 372,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 372,
                                        "char": 64
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "connection",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 372,
                                            "char": 76
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 372,
                                        "char": 76
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 372,
                                "char": 77
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 373,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Perform a count over a collection\n     *\n     *```php\n     * echo \"There are \", Robots::count(), \" robots\";\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 363,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 363,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 362,
                    "last-line": 389,
                    "char": 26
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "delete",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "disableEvents",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 392,
                                    "char": 26
                                },
                                {
                                    "variable": "status",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 392,
                                    "char": 34
                                },
                                {
                                    "variable": "id",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 392,
                                    "char": 38
                                },
                                {
                                    "variable": "connection",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 392,
                                    "char": 50
                                },
                                {
                                    "variable": "source",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 392,
                                    "char": 58
                                },
                                {
                                    "variable": "collection",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 393,
                                    "char": 23
                                },
                                {
                                    "variable": "mongoId",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 393,
                                    "char": 32
                                },
                                {
                                    "variable": "success",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 393,
                                    "char": 41
                                },
                                {
                                    "variable": "ok",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 393,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 395,
                            "char": 10
                        },
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
                                            "value": "id",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 395,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 395,
                                                "char": 37
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "_id",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 395,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 395,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 395,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 395,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 395,
                                "char": 42
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
                                                    "value": "The document cannot be deleted because it doesn't exist",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 398,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 398,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 398,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 399,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 401,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "disableEvents",
                                    "expr": {
                                        "type": "static-property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 401,
                                            "char": 48
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "disableEvents",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 401,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 401,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 401,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 403,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "disableEvents",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 403,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 403,
                                "char": 27
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
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 404,
                                                "char": 21
                                            },
                                            "name": "fireEventCancel",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "beforeDelete",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 404,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 404,
                                                    "char": 50
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 404,
                                            "char": 54
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 404,
                                            "char": 62
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 404,
                                        "char": 62
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 405,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 406,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 407,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 409,
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
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 409,
                                        "char": 17
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "skipped",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 409,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 409,
                                    "char": 28
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "true",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 409,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 409,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 410,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 411,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 413,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "connection",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 413,
                                            "char": 31
                                        },
                                        "name": "getConnection",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 413,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 413,
                                    "char": 47
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 415,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "source",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 415,
                                            "char": 27
                                        },
                                        "name": "getSource",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 415,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 415,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 416,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "empty",
                                    "left": {
                                        "type": "variable",
                                        "value": "source",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 416,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 416,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 416,
                                "char": 34
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
                                                    "value": "Method getSource() returns empty string",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 417,
                                                    "char": 72
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 417,
                                                "char": 72
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 417,
                                        "char": 73
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 418,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 423,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "collection",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "connection",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 423,
                                            "char": 37
                                        },
                                        "name": "selectCollection",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "source",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 423,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 423,
                                                "char": 61
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 423,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 423,
                                    "char": 62
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 425,
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
                                        "value": "id",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 425,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 425,
                                    "char": 23
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 425,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 425,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "mongoId",
                                            "expr": {
                                                "type": "variable",
                                                "value": "id",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 426,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 426,
                                            "char": 29
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 427,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 431,
                                                "char": 21
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "modelsManager",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 431,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 431,
                                            "char": 36
                                        },
                                        "name": "isUsingImplicitObjectIds",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 431,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 431,
                                                "char": 66
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 431,
                                        "char": 68
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "mongoId",
                                                    "expr": {
                                                        "type": "new",
                                                        "class": "MongoId",
                                                        "dynamic": 0,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "id",
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                    "line": 432,
                                                                    "char": 45
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 432,
                                                                "char": 45
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 432,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 432,
                                                    "char": 46
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 433,
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
                                                    "variable": "mongoId",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "id",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 434,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 434,
                                                    "char": 33
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 435,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 436,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 438,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "success",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 438,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 438,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 443,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "status",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "collection",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 443,
                                            "char": 33
                                        },
                                        "name": "remove",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "array",
                                                    "left": [
                                                        {
                                                            "key": {
                                                                "type": "string",
                                                                "value": "_id",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 445,
                                                                "char": 20
                                                            },
                                                            "value": {
                                                                "type": "variable",
                                                                "value": "mongoId",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 446,
                                                                "char": 13
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 446,
                                                            "char": 13
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 446,
                                                    "char": 14
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 446,
                                                "char": 14
                                            },
                                            {
                                                "parameter": {
                                                    "type": "array",
                                                    "left": [
                                                        {
                                                            "key": {
                                                                "type": "string",
                                                                "value": "w",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 448,
                                                                "char": 18
                                                            },
                                                            "value": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 449,
                                                                "char": 13
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 449,
                                                            "char": 13
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 450,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 450,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 450,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 450,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 452,
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
                                        "value": "status",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 452,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 452,
                                    "char": 27
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 452,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 452,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 453,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 454,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 459,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "ok",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 459,
                                    "char": 33
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "status",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 459,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "ok",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 459,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 459,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 459,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "ok",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 460,
                                        "char": 19
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "success",
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "true",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 461,
                                                        "char": 35
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 461,
                                                    "char": 35
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 462,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "disableEvents",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 462,
                                                    "char": 35
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 462,
                                                "char": 35
                                            },
                                            "statements": [
                                                {
                                                    "type": "mcall",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 463,
                                                            "char": 26
                                                        },
                                                        "name": "fireEvent",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "afterDelete",
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                    "line": 463,
                                                                    "char": 48
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 463,
                                                                "char": 48
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 463,
                                                        "char": 49
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 464,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 465,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "dirtyState",
                                                    "expr": {
                                                        "type": "static-constant-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "self",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 465,
                                                            "char": 66
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "DIRTY_STATE_DETACHED",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 465,
                                                            "char": 66
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 465,
                                                        "char": 66
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 465,
                                                    "char": 66
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 466,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 467,
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
                                            "variable": "success",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 468,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 468,
                                            "char": 32
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 469,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 471,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "success",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 471,
                                "char": 23
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 472,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Deletes a model instance. Returning true on success or false otherwise.\n     *\n     * ```php\n     * $robot = Robots::findFirst();\n     *\n     * $robot->delete();\n     *\n     * $robots = Robots::find();\n     *\n     * foreach ($robots as $robot) {\n     *     $robot->delete();\n     * }\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 391,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 391,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 390,
                    "last-line": 527,
                    "char": 19
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "find",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 528,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 528,
                            "char": 56
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "className",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 530,
                                    "char": 22
                                },
                                {
                                    "variable": "collection",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 530,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 532,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "className",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "get_called_class",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 532,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 532,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 533,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "collection",
                                    "expr": {
                                        "type": "new",
                                        "class": "className",
                                        "dynamic": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 533,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 533,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 535,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "static",
                                "dynamic": 0,
                                "name": "getResultset",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "parameters",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 536,
                                            "char": 23
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 536,
                                        "char": 23
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "collection",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 537,
                                            "char": 23
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 537,
                                        "char": 23
                                    },
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "collection",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 538,
                                                "char": 24
                                            },
                                            "name": "getConnection",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 538,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 538,
                                        "char": 40
                                    },
                                    {
                                        "parameter": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 540,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 540,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 540,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 541,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Allows to query a set of records that match the specified conditions\n     *\n     * ```php\n     * \/\/ How many robots are there?\n     * $robots = Robots::find();\n     *\n     * echo \"There are \", count($robots), \"\\n\";\n     *\n     * \/\/ How many mechanical robots are there?\n     * $robots = Robots::find(\n     *     [\n     *         [\n     *             \"type\" => \"mechanical\",\n     *         ]\n     *     ]\n     * );\n     *\n     * echo \"There are \", count(robots), \"\\n\";\n     *\n     * \/\/ Get and print virtual robots ordered by name\n     * $robots = Robots::findFirst(\n     *     [\n     *         [\n     *             \"type\" => \"virtual\"\n     *         ],\n     *         \"order\" => [\n     *             \"name\" => 1,\n     *         ]\n     *     ]\n     * );\n     *\n     * foreach ($robots as $robot) {\n     *       echo $robot->name, \"\\n\";\n     * }\n     *\n     * \/\/ Get first 100 virtual robots ordered by name\n     * $robots = Robots::find(\n     *     [\n     *         [\n     *             \"type\" => \"virtual\",\n     *         ],\n     *         \"order\" => [\n     *             \"name\" => 1,\n     *         ],\n     *         \"limit\" => 100,\n     *     ]\n     * );\n     *\n     * foreach ($robots as $robot) {\n     *       echo $robot->name, \"\\n\";\n     * }\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 529,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 529,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 528,
                    "last-line": 560,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "findById",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "id",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 561,
                            "char": 43
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "className",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 563,
                                    "char": 22
                                },
                                {
                                    "variable": "collection",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 563,
                                    "char": 34
                                },
                                {
                                    "variable": "mongoId",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 563,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 565,
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
                                        "value": "id",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 565,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 565,
                                    "char": 23
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 565,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 565,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "fcall",
                                            "name": "preg_match",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "\/^[a-f\\d]{24}$\/i",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 566,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 566,
                                                    "char": 44
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "id",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 566,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 566,
                                                    "char": 48
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 566,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 566,
                                        "char": 50
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "null",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 567,
                                                "char": 28
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 568,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 570,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "className",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "get_called_class",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 570,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 570,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 572,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "collection",
                                            "expr": {
                                                "type": "new",
                                                "class": "className",
                                                "dynamic": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 572,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 572,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 577,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "collection",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 577,
                                                "char": 27
                                            },
                                            "name": "getCollectionManager",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 577,
                                            "char": 51
                                        },
                                        "name": "isUsingImplicitObjectIds",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "collection",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 577,
                                                    "char": 87
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 577,
                                                "char": 87
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 577,
                                        "char": 89
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "mongoId",
                                                    "expr": {
                                                        "type": "new",
                                                        "class": "MongoId",
                                                        "dynamic": 0,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "id",
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                    "line": 578,
                                                                    "char": 45
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 578,
                                                                "char": 45
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 578,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 578,
                                                    "char": 46
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 579,
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
                                                    "variable": "mongoId",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "id",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 580,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 580,
                                                    "char": 33
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 581,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 583,
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
                                            "variable": "mongoId",
                                            "expr": {
                                                "type": "variable",
                                                "value": "id",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 584,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 584,
                                            "char": 29
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 585,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 587,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "static",
                                "dynamic": 0,
                                "name": "findFirst",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "array",
                                            "left": [
                                                {
                                                    "value": {
                                                        "type": "array",
                                                        "left": [
                                                            {
                                                                "key": {
                                                                    "type": "string",
                                                                    "value": "_id",
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                    "line": 590,
                                                                    "char": 24
                                                                },
                                                                "value": {
                                                                    "type": "variable",
                                                                    "value": "mongoId",
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                    "line": 591,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 591,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 592,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 592,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 593,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 593,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 593,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 594,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Find a document by its id (_id)\n     *\n     * ```php\n     * \/\/ Find user by using \\MongoId object\n     * $user = Users::findById(\n     *     new \\MongoId(\"545eb081631d16153a293a66\")\n     * );\n     *\n     * \/\/ Find user by using id as sting\n     * $user = Users::findById(\"45cbc4a0e4123f6920000002\");\n     *\n     * \/\/ Validate input\n     * if ($user = Users::findById($_POST[\"id\"])) {\n     *     \/\/ ...\n     * }\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CollectionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 561,
                                    "char": 70
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 561,
                                "char": 70
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 562,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 562,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 561,
                    "last-line": 641,
                    "char": 26
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "findFirst",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "parameters",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 642,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 642,
                            "char": 61
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "className",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 644,
                                    "char": 22
                                },
                                {
                                    "variable": "collection",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 644,
                                    "char": 34
                                },
                                {
                                    "variable": "connection",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 644,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 646,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "className",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "get_called_class",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 646,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 646,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 648,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "collection",
                                    "expr": {
                                        "type": "new",
                                        "class": "className",
                                        "dynamic": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 648,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 648,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 650,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "connection",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "collection",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 650,
                                            "char": 37
                                        },
                                        "name": "getConnection",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 650,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 650,
                                    "char": 53
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 652,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "static",
                                "dynamic": 0,
                                "name": "getResultset",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "parameters",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 652,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 652,
                                        "char": 47
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "collection",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 652,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 652,
                                        "char": 59
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "connection",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 652,
                                            "char": 71
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 652,
                                        "char": 71
                                    },
                                    {
                                        "parameter": {
                                            "type": "bool",
                                            "value": "true",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 652,
                                            "char": 77
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 652,
                                        "char": 77
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 652,
                                "char": 78
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 653,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Allows to query the first record that match the specified conditions\n     *\n     * ```php\n     * \/\/ What's the first robot in the robots table?\n     * $robot = Robots::findFirst();\n     *\n     * echo \"The robot name is \", $robot->name, \"\\n\";\n     *\n     * \/\/ What's the first mechanical robot in robots table?\n     * $robot = Robots::findFirst(\n     *     [\n     *         [\n     *             \"type\" => \"mechanical\",\n     *         ]\n     *     ]\n     * );\n     *\n     * echo \"The first mechanical robot name is \", $robot->name, \"\\n\";\n     *\n     * \/\/ Get first virtual robot ordered by name\n     * $robot = Robots::findFirst(\n     *     [\n     *         [\n     *             \"type\" => \"mechanical\",\n     *         ],\n     *         \"order\" => [\n     *             \"name\" => 1,\n     *         ],\n     *     ]\n     * );\n     *\n     * echo \"The first virtual robot name is \", $robot->name, \"\\n\";\n     *\n     * \/\/ Get first robot by id (_id)\n     * $robot = Robots::findFirst(\n     *     [\n     *         [\n     *             \"_id\" => new \\MongoId(\"45cbc4a0e4123f6920000002\"),\n     *         ]\n     *     ]\n     * );\n     *\n     * echo \"The robot id is \", $robot->_id, \"\\n\";\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 643,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 643,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 642,
                    "last-line": 657,
                    "char": 26
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "fireEvent",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "eventName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 658,
                            "char": 48
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "method_exists",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 663,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 663,
                                        "char": 30
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "eventName",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 663,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 663,
                                        "char": 41
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 663,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 664,
                                            "char": 18
                                        },
                                        "name": "eventName",
                                        "call-type": 2,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 664,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 665,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 670,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 670,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "modelsManager",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 670,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 670,
                                    "char": 36
                                },
                                "name": "notifyEvent",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "eventName",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 670,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 670,
                                        "char": 58
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 670,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 670,
                                        "char": 64
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 670,
                                "char": 65
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 671,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Fires an internal event\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 659,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 659,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 658,
                    "last-line": 675,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "fireEventCancel",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "eventName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 676,
                            "char": 54
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "fcall",
                                "name": "method_exists",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 681,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 681,
                                        "char": 30
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "eventName",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 681,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 681,
                                        "char": 41
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 681,
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
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 682,
                                                "char": 21
                                            },
                                            "name": "eventName",
                                            "call-type": 2,
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 682,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 682,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 682,
                                        "char": 46
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 683,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 684,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 685,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 690,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 690,
                                            "char": 17
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "modelsManager",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 690,
                                            "char": 32
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 690,
                                        "char": 32
                                    },
                                    "name": "notifyEvent",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "eventName",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 690,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 690,
                                            "char": 54
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 690,
                                                "char": 60
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 690,
                                            "char": 60
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 690,
                                    "char": 64
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 690,
                                    "char": 72
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 690,
                                "char": 72
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 691,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 692,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 694,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 694,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 695,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Fires an internal event that cancels the operation\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 677,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 677,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 676,
                    "last-line": 699,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getCollectionManager",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 702,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "modelsManager",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 702,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 702,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 703,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the models manager related to the entity instance\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ManagerInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 701,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 701,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 701,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 700,
                    "last-line": 709,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getConnection",
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 712,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "connection",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 712,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 712,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 712,
                                    "char": 37
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 712,
                                    "char": 46
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 712,
                                "char": 46
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "connection",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 713,
                                                        "char": 41
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "modelsManager",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 713,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 713,
                                                    "char": 56
                                                },
                                                "name": "getConnection",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 713,
                                                            "char": 75
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 713,
                                                        "char": 75
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 713,
                                                "char": 76
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 713,
                                            "char": 76
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 714,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 716,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 716,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "connection",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 716,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 716,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 717,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Retrieves a database connection\n     *\n     * @return \\MongoDb\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 710,
                    "last-line": 721,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getConnectionService",
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
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 724,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "modelsManager",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 724,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 724,
                                    "char": 36
                                },
                                "name": "getConnectionService",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 724,
                                            "char": 62
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 724,
                                        "char": 62
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 724,
                                "char": 63
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 725,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns DependencyInjection connection service\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 723,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 723,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 722,
                    "last-line": 729,
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
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 732,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "container",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 732,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 732,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 733,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the dependency injection container\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "DiInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 731,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 731,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 731,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 730,
                    "last-line": 738,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDirtyState",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 741,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "dirtyState",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 741,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 741,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 742,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns one of the DIRTY_STATE_* constants telling if the document exists\n     * in the collection or not\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 740,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 740,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 739,
                    "last-line": 746,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "getEventsManager",
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
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 749,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "modelsManager",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 749,
                                        "char": 36
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 749,
                                    "char": 36
                                },
                                "name": "getCustomEventsManager",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 749,
                                            "char": 64
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 749,
                                        "char": 64
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 749,
                                "char": 65
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 750,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the custom events manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ManagerInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 748,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 748,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 748,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 747,
                    "last-line": 756,
                    "char": 22
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getId",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 759,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "_id",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 759,
                                    "char": 25
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 759,
                                "char": 25
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 760,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the value of the _id property\n     *\n     * @return \\MongoId\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 757,
                    "last-line": 784,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMessages",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 787,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "errorMessages",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 787,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 787,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 788,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns all the validation messages\n     *\n     * ```php\n     * $robot = new Robots();\n     *\n     * $robot->type = \"mechanical\";\n     * $robot->name = \"Astro Boy\";\n     * $robot->year = 1952;\n     *\n     * if ($robot->save() === false) {\n     *     echo \"Umh, We can't store robots right now \";\n     *\n     *     $messages = $robot->getMessages();\n     *\n     *     foreach ($messages as $message) {\n     *         echo $message;\n     *     }\n     * } else {\n     *     echo \"Great, a new robot was saved successfully!\";\n     * }\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "MessageInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 786,
                                    "char": 5
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 786,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 786,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 785,
                    "last-line": 793,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getReservedAttributes",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "reserved",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 796,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 798,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "reserved",
                                    "expr": {
                                        "type": "static-property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 798,
                                            "char": 38
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "reserved",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 798,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 798,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 798,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 799,
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
                                        "value": "reserved",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 799,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 799,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 799,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 799,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "reserved",
                                            "expr": {
                                                "type": "array",
                                                "left": [
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "_connection",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 801,
                                                            "char": 31
                                                        },
                                                        "value": {
                                                            "type": "bool",
                                                            "value": "true",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 801,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 801,
                                                        "char": 37
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "container",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 802,
                                                            "char": 31
                                                        },
                                                        "value": {
                                                            "type": "bool",
                                                            "value": "true",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 802,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 802,
                                                        "char": 37
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "source",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 803,
                                                            "char": 31
                                                        },
                                                        "value": {
                                                            "type": "bool",
                                                            "value": "true",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 803,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 803,
                                                        "char": 37
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "operationMade",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 804,
                                                            "char": 31
                                                        },
                                                        "value": {
                                                            "type": "bool",
                                                            "value": "true",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 804,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 804,
                                                        "char": 37
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "errorMessages",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 805,
                                                            "char": 31
                                                        },
                                                        "value": {
                                                            "type": "bool",
                                                            "value": "true",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 805,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 805,
                                                        "char": 37
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "dirtyState",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 806,
                                                            "char": 31
                                                        },
                                                        "value": {
                                                            "type": "bool",
                                                            "value": "true",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 806,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 806,
                                                        "char": 37
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "modelsManager",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 807,
                                                            "char": 31
                                                        },
                                                        "value": {
                                                            "type": "bool",
                                                            "value": "true",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 807,
                                                            "char": 37
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 807,
                                                        "char": 37
                                                    },
                                                    {
                                                        "key": {
                                                            "type": "string",
                                                            "value": "skipped",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 808,
                                                            "char": 31
                                                        },
                                                        "value": {
                                                            "type": "bool",
                                                            "value": "true",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 809,
                                                            "char": 13
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 809,
                                                        "char": 13
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 809,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 809,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 810,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "static-property",
                                            "operator": "assign",
                                            "variable": "self",
                                            "property": "reserved",
                                            "expr": {
                                                "type": "variable",
                                                "value": "reserved",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 810,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 810,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 811,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 812,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "reserved",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 812,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 813,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns an array with reserved properties that cannot be part of the\n     * insert\/update\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 795,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 795,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 794,
                    "last-line": 817,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getSource",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "collection",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 820,
                                    "char": 23
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 822,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 822,
                                        "char": 18
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "source",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 822,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 822,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 822,
                                "char": 26
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "collection",
                                            "expr": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 823,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 823,
                                            "char": 34
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 824,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "source",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "uncamelize",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "fcall",
                                                            "name": "get_class_ns",
                                                            "call-type": 1,
                                                            "parameters": [
                                                                {
                                                                    "parameter": {
                                                                        "type": "variable",
                                                                        "value": "collection",
                                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                        "line": 824,
                                                                        "char": 66
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                    "line": 824,
                                                                    "char": 66
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 824,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 824,
                                                        "char": 67
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 824,
                                                "char": 68
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 824,
                                            "char": 68
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 825,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 827,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 827,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "source",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 827,
                                    "char": 28
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 827,
                                "char": 28
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 828,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns collection name mapped in the model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 819,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 819,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 818,
                    "last-line": 836,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "readAttribute",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "attribute",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 837,
                            "char": 52
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "isset",
                                    "left": {
                                        "type": "property-dynamic-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 839,
                                            "char": 24
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "attribute",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 839,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 839,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 839,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 839,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "null",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 840,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 841,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 843,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-dynamic-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 843,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "attribute",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 843,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 843,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 844,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Reads an attribute value by its name\n     *\n     *```php\n     *    echo $robot->readAttribute(\"name\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 837,
                                "char": 61
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 838,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 838,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 837,
                    "last-line": 848,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "save",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "exists",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 851,
                                    "char": 19
                                },
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 851,
                                    "char": 25
                                },
                                {
                                    "variable": "success",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 851,
                                    "char": 34
                                },
                                {
                                    "variable": "status",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 851,
                                    "char": 42
                                },
                                {
                                    "variable": "id",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 851,
                                    "char": 46
                                },
                                {
                                    "variable": "ok",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 851,
                                    "char": 50
                                },
                                {
                                    "variable": "collection",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 851,
                                    "char": 62
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 853,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "collection",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 853,
                                            "char": 31
                                        },
                                        "name": "prepareCU",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 853,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 853,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 859,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 859,
                                            "char": 27
                                        },
                                        "name": "exists",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "collection",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 859,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 859,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 859,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 859,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 861,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "exists",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 861,
                                    "char": 21
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 861,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 861,
                                "char": 29
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "operationMade",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 862,
                                                    "char": 54
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "OP_CREATE",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 862,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 862,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 862,
                                            "char": 54
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 863,
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
                                            "property": "operationMade",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 864,
                                                    "char": 54
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "OP_UPDATE",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 864,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 864,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 864,
                                            "char": 54
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 865,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 870,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "errorMessages",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 870,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 870,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 875,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 875,
                                        "char": 17
                                    },
                                    "name": "preSave",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 875,
                                                    "char": 31
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 875,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 875,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 875,
                                            "char": 41
                                        },
                                        {
                                            "parameter": {
                                                "type": "static-property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 875,
                                                    "char": 62
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "disableEvents",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 875,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 875,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 875,
                                            "char": 62
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "exists",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 875,
                                                "char": 70
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 875,
                                            "char": 70
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 875,
                                    "char": 74
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 875,
                                    "char": 82
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 875,
                                "char": 82
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 876,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 877,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 879,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "data",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 879,
                                            "char": 25
                                        },
                                        "name": "toArray",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 879,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 879,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 881,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "success",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 881,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 881,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 887,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "status",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "collection",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 887,
                                            "char": 33
                                        },
                                        "name": "save",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "data",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 887,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 887,
                                                "char": 43
                                            },
                                            {
                                                "parameter": {
                                                    "type": "array",
                                                    "left": [
                                                        {
                                                            "key": {
                                                                "type": "string",
                                                                "value": "w",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 887,
                                                                "char": 47
                                                            },
                                                            "value": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 887,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 887,
                                                            "char": 53
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 887,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 887,
                                                "char": 54
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 887,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 887,
                                    "char": 55
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 888,
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
                                        "value": "status",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 888,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 888,
                                    "char": 27
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 888,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 888,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "ok",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 889,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "status",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 889,
                                                "char": 32
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "ok",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 889,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 889,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 889,
                                        "char": 37
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "variable",
                                                "value": "ok",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 890,
                                                "char": 23
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "success",
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 891,
                                                                "char": 39
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 891,
                                                            "char": 39
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 892,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "identical",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "exists",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 892,
                                                            "char": 33
                                                        },
                                                        "right": {
                                                            "type": "bool",
                                                            "value": "false",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 892,
                                                            "char": 41
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 892,
                                                        "char": 41
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "if",
                                                            "expr": {
                                                                "type": "fetch",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "id",
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                    "line": 893,
                                                                    "char": 48
                                                                },
                                                                "right": {
                                                                    "type": "array-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "data",
                                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                        "line": 893,
                                                                        "char": 42
                                                                    },
                                                                    "right": {
                                                                        "type": "string",
                                                                        "value": "_id",
                                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                        "line": 893,
                                                                        "char": 46
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                    "line": 893,
                                                                    "char": 48
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 893,
                                                                "char": 48
                                                            },
                                                            "statements": [
                                                                {
                                                                    "type": "let",
                                                                    "assignments": [
                                                                        {
                                                                            "assign-type": "object-property",
                                                                            "operator": "assign",
                                                                            "variable": "this",
                                                                            "property": "_id",
                                                                            "expr": {
                                                                                "type": "variable",
                                                                                "value": "id",
                                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                                "line": 894,
                                                                                "char": 47
                                                                            },
                                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                            "line": 894,
                                                                            "char": 47
                                                                        }
                                                                    ],
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                    "line": 895,
                                                                    "char": 25
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 896,
                                                            "char": 27
                                                        },
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "object-property",
                                                                    "operator": "assign",
                                                                    "variable": "this",
                                                                    "property": "dirtyState",
                                                                    "expr": {
                                                                        "type": "static-constant-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "self",
                                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                            "line": 896,
                                                                            "char": 76
                                                                        },
                                                                        "right": {
                                                                            "type": "variable",
                                                                            "value": "DIRTY_STATE_PERSISTENT",
                                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                            "line": 896,
                                                                            "char": 76
                                                                        },
                                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                        "line": 896,
                                                                        "char": 76
                                                                    },
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                    "line": 896,
                                                                    "char": 76
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 897,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 898,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 899,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 900,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 905,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 905,
                                    "char": 21
                                },
                                "name": "postSave",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "static-property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 905,
                                                "char": 50
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "disableEvents",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 905,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 905,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 905,
                                        "char": 50
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "success",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 905,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 905,
                                        "char": 59
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "exists",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 905,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 905,
                                        "char": 67
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 905,
                                "char": 68
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 906,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Creates\/Updates a collection based on the values in the attributes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 850,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 850,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 849,
                    "last-line": 910,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "serialize",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 913,
                                    "char": 22
                                },
                                {
                                    "variable": "serializer",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 913,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 918,
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
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "Di",
                                        "dynamic": 0,
                                        "name": "getDefault",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 918,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 918,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 919,
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
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 919,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 919,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 919,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 919,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 919,
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
                                                    "type": "string",
                                                    "value": "The dependency injector container is not valid",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 922,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 922,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 922,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 923,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 925,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "container",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 925,
                                    "char": 22
                                },
                                "name": "has",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "serializer",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 925,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 925,
                                        "char": 37
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 925,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "serializer",
                                            "expr": {
                                                "type": "type-hint",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "SerializerInterface",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 926,
                                                    "char": 90
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 926,
                                                            "char": 57
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "container",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 926,
                                                            "char": 68
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 926,
                                                        "char": 68
                                                    },
                                                    "name": "getShared",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "serializer",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 926,
                                                                "char": 89
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 926,
                                                            "char": 89
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 926,
                                                    "char": 90
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 926,
                                                "char": 90
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 926,
                                            "char": 90
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 927,
                                    "char": 22
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "serializer",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 927,
                                            "char": 24
                                        },
                                        "name": "setData",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 927,
                                                        "char": 38
                                                    },
                                                    "name": "toArray",
                                                    "call-type": 1,
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 927,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 927,
                                                "char": 48
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 927,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 929,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "serializer",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 929,
                                            "char": 31
                                        },
                                        "name": "serialize",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 929,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 930,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 935,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "serialize",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 935,
                                                "char": 31
                                            },
                                            "name": "toArray",
                                            "call-type": 1,
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 935,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 935,
                                        "char": 41
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 935,
                                "char": 42
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 936,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Serializes the object ignoring connections or protected properties\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 912,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 912,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 911,
                    "last-line": 940,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setConnectionService",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "connectionService",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 941,
                            "char": 67
                        }
                    ],
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 943,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "modelsManager",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 943,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 943,
                                    "char": 29
                                },
                                "name": "setConnectionService",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 943,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 943,
                                        "char": 55
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "connectionService",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 943,
                                            "char": 74
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 943,
                                        "char": 74
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 943,
                                "char": 75
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 944,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 944,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 945,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the DependencyInjection connection service name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 942,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 942,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 942,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 941,
                    "last-line": 949,
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
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 950,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 950,
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
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 952,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 952,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 953,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the dependency injection container\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 951,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 950,
                    "last-line": 958,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setDirtyState",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "dirtyState",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 959,
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
                                    "property": "dirtyState",
                                    "expr": {
                                        "type": "variable",
                                        "value": "dirtyState",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 961,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 961,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 962,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 962,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 963,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the dirty state of the object using one of the DIRTY_STATE_*\n     * constants\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CollectionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 960,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 960,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 960,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 959,
                    "last-line": 967,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
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
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 968,
                                "char": 72
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 968,
                            "char": 73
                        }
                    ],
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 970,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "modelsManager",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 970,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 970,
                                    "char": 29
                                },
                                "name": "setCustomEventsManager",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 970,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 970,
                                        "char": 57
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "eventsManager",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 970,
                                            "char": 72
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 970,
                                        "char": 72
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 970,
                                "char": 73
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 971,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a custom events manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 969,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 968,
                    "last-line": 977,
                    "char": 22
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setId",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "id",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 978,
                            "char": 29
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "mongoId",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 980,
                                    "char": 20
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 982,
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
                                        "value": "id",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 982,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 982,
                                    "char": 23
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 982,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 982,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 987,
                                                "char": 21
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "modelsManager",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 987,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 987,
                                            "char": 36
                                        },
                                        "name": "isUsingImplicitObjectIds",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 987,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 987,
                                                "char": 66
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 987,
                                        "char": 68
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "mongoId",
                                                    "expr": {
                                                        "type": "new",
                                                        "class": "MongoId",
                                                        "dynamic": 0,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "id",
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                    "line": 988,
                                                                    "char": 45
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 988,
                                                                "char": 45
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 988,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 988,
                                                    "char": 46
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 989,
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
                                                    "variable": "mongoId",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "id",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 990,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 990,
                                                    "char": 33
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 991,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 993,
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
                                            "variable": "mongoId",
                                            "expr": {
                                                "type": "variable",
                                                "value": "id",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 994,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 994,
                                            "char": 29
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 995,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 996,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "_id",
                                    "expr": {
                                        "type": "variable",
                                        "value": "mongoId",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 996,
                                        "char": 32
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 996,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 997,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets a value for the _id property, creates a MongoId object if needed\n     *\n     * @param mixed id\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 978,
                    "last-line": 1001,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "setSource",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "source",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1002,
                            "char": 48
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
                                    "property": "source",
                                    "expr": {
                                        "type": "variable",
                                        "value": "source",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1004,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1004,
                                    "char": 34
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1005,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "this",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1005,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1006,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets collection name which model should be mapped\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1003,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1003,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 1003,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 1002,
                    "last-line": 1010,
                    "char": 22
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "skipOperation",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "skip",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1011,
                            "char": 44
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
                                    "property": "skipped",
                                    "expr": {
                                        "type": "variable",
                                        "value": "skip",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1013,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1013,
                                    "char": 33
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1014,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Skips the current operation forcing a success state\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 1011,
                    "last-line": 1018,
                    "char": 19
                },
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "summatory",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "field",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1019,
                            "char": 51
                        },
                        {
                            "type": "parameter",
                            "name": "conditions",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1019,
                                "char": 70
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1019,
                            "char": 70
                        },
                        {
                            "type": "parameter",
                            "name": "finalize",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1019,
                                "char": 87
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1019,
                            "char": 87
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "className",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1021,
                                    "char": 22
                                },
                                {
                                    "variable": "model",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1021,
                                    "char": 29
                                },
                                {
                                    "variable": "connection",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1021,
                                    "char": 41
                                },
                                {
                                    "variable": "source",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1021,
                                    "char": 49
                                },
                                {
                                    "variable": "collection",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1021,
                                    "char": 61
                                },
                                {
                                    "variable": "initial",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1021,
                                    "char": 70
                                },
                                {
                                    "variable": "reduce",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1022,
                                    "char": 19
                                },
                                {
                                    "variable": "group",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1022,
                                    "char": 26
                                },
                                {
                                    "variable": "retval",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1022,
                                    "char": 34
                                },
                                {
                                    "variable": "firstRetval",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1022,
                                    "char": 47
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1024,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "className",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "get_called_class",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1024,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1024,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1026,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "model",
                                    "expr": {
                                        "type": "new",
                                        "class": "className",
                                        "dynamic": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1026,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1026,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1028,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "connection",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "model",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1028,
                                            "char": 32
                                        },
                                        "name": "getConnection",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1028,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1028,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1030,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "source",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "model",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1030,
                                            "char": 28
                                        },
                                        "name": "getSource",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1030,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1030,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1031,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "empty",
                                    "left": {
                                        "type": "variable",
                                        "value": "source",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1031,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1031,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1031,
                                "char": 34
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
                                                    "value": "Method getSource() returns empty string",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1032,
                                                    "char": 72
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1032,
                                                "char": 72
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1032,
                                        "char": 73
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1033,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1035,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "collection",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "connection",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1035,
                                            "char": 37
                                        },
                                        "name": "selectCollection",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "source",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1035,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1035,
                                                "char": 61
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1035,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1035,
                                    "char": 62
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1040,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "initial",
                                    "expr": {
                                        "type": "array",
                                        "left": [
                                            {
                                                "key": {
                                                    "type": "string",
                                                    "value": "summatory",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1041,
                                                    "char": 22
                                                },
                                                "value": {
                                                    "type": "empty-array",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1042,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1042,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1042,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1042,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1048,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "reduce",
                                    "expr": {
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
                                                                "value": "function (curr, result) { if (typeof result.summatory[curr.",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 1048,
                                                                "char": 82
                                                            },
                                                            "right": {
                                                                "type": "variable",
                                                                "value": "field",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 1048,
                                                                "char": 90
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1048,
                                                            "char": 90
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "] === \\\"undefined\\\") { result.summatory[curr.",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1048,
                                                            "char": 138
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1048,
                                                        "char": 138
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "field",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1048,
                                                        "char": 146
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1048,
                                                    "char": 146
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "] = 1; } else { result.summatory[curr.",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1048,
                                                    "char": 187
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1048,
                                                "char": 187
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "field",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1048,
                                                "char": 195
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1048,
                                            "char": 195
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "]++; } }",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1048,
                                            "char": 205
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1048,
                                        "char": 205
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1048,
                                    "char": 205
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1050,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "group",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "collection",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1050,
                                            "char": 32
                                        },
                                        "name": "group",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "empty-array",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1050,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1050,
                                                "char": 41
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "initial",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1050,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1050,
                                                "char": 50
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "reduce",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1050,
                                                    "char": 58
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1050,
                                                "char": 58
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1050,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1050,
                                    "char": 59
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1052,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "retval",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1052,
                                    "char": 40
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "group",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1052,
                                        "char": 31
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "retval",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1052,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1052,
                                    "char": 40
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1052,
                                "char": 40
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "firstRetval",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1053,
                                            "char": 45
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "retval",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1053,
                                                "char": 41
                                            },
                                            "right": {
                                                "type": "int",
                                                "value": "0",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1053,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1053,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1053,
                                        "char": 45
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "isset",
                                                "left": {
                                                    "type": "array-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "firstRetval",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1054,
                                                        "char": 37
                                                    },
                                                    "right": {
                                                        "type": "string",
                                                        "value": "summatory",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1054,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1054,
                                                    "char": 49
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1054,
                                                "char": 49
                                            },
                                            "statements": [
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "array-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "firstRetval",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1055,
                                                            "char": 39
                                                        },
                                                        "right": {
                                                            "type": "string",
                                                            "value": "summatory",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1055,
                                                            "char": 49
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1055,
                                                        "char": 50
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1056,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1057,
                                            "char": 22
                                        },
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "variable",
                                                "value": "firstRetval",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1057,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1058,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1059,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "retval",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1059,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1060,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1062,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1062,
                                "char": 18
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1063,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Allows to perform a summatory group for a column in the collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1020,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 1020,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 1019,
                    "last-line": 1073,
                    "char": 26
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "toArray",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1076,
                                    "char": 17
                                },
                                {
                                    "variable": "reserved",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1076,
                                    "char": 27
                                },
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1076,
                                    "char": 32
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1076,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1078,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "reserved",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1078,
                                            "char": 29
                                        },
                                        "name": "getReservedAttributes",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1078,
                                        "char": 53
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1078,
                                    "char": 53
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1084,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "data",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1084,
                                        "char": 22
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1084,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1085,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "fcall",
                                "name": "get_object_vars",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1085,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1085,
                                        "char": 47
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1085,
                                "char": 49
                            },
                            "key": "key",
                            "value": "value",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "variable",
                                            "value": "key",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1086,
                                            "char": 21
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "_id",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1086,
                                            "char": 27
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1086,
                                        "char": 27
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "variable",
                                                "value": "value",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1087,
                                                "char": 26
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "data",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "key",
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                    "line": 1088,
                                                                    "char": 33
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "value",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 1088,
                                                                "char": 42
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1088,
                                                            "char": 42
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1089,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1090,
                                            "char": 13
                                        }
                                    ],
                                    "else_statements": [
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
                                                            "value": "reserved",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1091,
                                                            "char": 35
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "key",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1091,
                                                            "char": 39
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1091,
                                                        "char": 41
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1091,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1091,
                                                "char": 41
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "array-index",
                                                            "operator": "assign",
                                                            "variable": "data",
                                                            "index-expr": [
                                                                {
                                                                    "type": "variable",
                                                                    "value": "key",
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                    "line": 1092,
                                                                    "char": 33
                                                                }
                                                            ],
                                                            "expr": {
                                                                "type": "variable",
                                                                "value": "value",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 1092,
                                                                "char": 42
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1092,
                                                            "char": 42
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1093,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1094,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1095,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1097,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "data",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1097,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1098,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the instance as an array representation\n     *\n     *```php\n     * print_r(\n     *     $robot->toArray()\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1075,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 1075,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 1074,
                    "last-line": 1102,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "unserialize",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1103,
                            "char": 41
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "attributes",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1105,
                                    "char": 23
                                },
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1105,
                                    "char": 34
                                },
                                {
                                    "variable": "manager",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1105,
                                    "char": 43
                                },
                                {
                                    "variable": "key",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1105,
                                    "char": 48
                                },
                                {
                                    "variable": "value",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1105,
                                    "char": 55
                                },
                                {
                                    "variable": "serializer",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1105,
                                    "char": 67
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1110,
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
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "Di",
                                        "dynamic": 0,
                                        "name": "getDefault",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1110,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1110,
                                    "char": 41
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1111,
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
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1111,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1111,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1111,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1111,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1111,
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
                                                                "value": "the services related to the ODM",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 1115,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1115,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1116,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1116,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1116,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1117,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1122,
                            "char": 11
                        },
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
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1122,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1122,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1123,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "container",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1123,
                                    "char": 22
                                },
                                "name": "has",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "serializer",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1123,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1123,
                                        "char": 37
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1123,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "serializer",
                                            "expr": {
                                                "type": "type-hint",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "SerializerInterface",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1124,
                                                    "char": 84
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "container",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1124,
                                                        "char": 62
                                                    },
                                                    "name": "getShared",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "serializer",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 1124,
                                                                "char": 83
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1124,
                                                            "char": 83
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1124,
                                                    "char": 84
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1124,
                                                "char": 84
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1124,
                                            "char": 84
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1125,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "attributes",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "serializer",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1125,
                                                    "char": 41
                                                },
                                                "name": "unserialize",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "data",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1125,
                                                            "char": 58
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1125,
                                                        "char": 58
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1125,
                                                "char": 59
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1125,
                                            "char": 59
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1126,
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
                                            "variable": "attributes",
                                            "expr": {
                                                "type": "fcall",
                                                "name": "unserialize",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "data",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1127,
                                                            "char": 46
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1127,
                                                        "char": 46
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1127,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1127,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1128,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1129,
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
                                        "value": "attributes",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1129,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1129,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1129,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1129,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "manager",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1133,
                                                    "char": 37
                                                },
                                                "name": "getShared",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "collectionManager",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1133,
                                                            "char": 65
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1133,
                                                        "char": 65
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1133,
                                                "char": 66
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1133,
                                            "char": 66
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1134,
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
                                                    "value": "manager",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1134,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1134,
                                                "char": 41
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1134,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1134,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1134,
                                        "char": 50
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
                                                            "value": "The injected service 'collectionManager' is not valid",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1137,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1137,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1137,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1138,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1143,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "modelsManager",
                                            "expr": {
                                                "type": "variable",
                                                "value": "manager",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1143,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1143,
                                            "char": 46
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1148,
                                    "char": 15
                                },
                                {
                                    "type": "for",
                                    "expr": {
                                        "type": "variable",
                                        "value": "attributes",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1148,
                                        "char": 42
                                    },
                                    "key": "key",
                                    "value": "value",
                                    "reverse": 0,
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable-dynamic-object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "key",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "value",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1149,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1149,
                                                    "char": 40
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1150,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1151,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1152,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Unserializes the object from a serialized string\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 1103,
                    "last-line": 1156,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "update",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "exists",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1159,
                                    "char": 19
                                },
                                {
                                    "variable": "data",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1159,
                                    "char": 25
                                },
                                {
                                    "variable": "success",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1159,
                                    "char": 34
                                },
                                {
                                    "variable": "status",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1159,
                                    "char": 42
                                },
                                {
                                    "variable": "ok",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1159,
                                    "char": 46
                                },
                                {
                                    "variable": "collection",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1159,
                                    "char": 58
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1161,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "collection",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1161,
                                            "char": 31
                                        },
                                        "name": "prepareCU",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1161,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1161,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1167,
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
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1167,
                                            "char": 27
                                        },
                                        "name": "exists",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "collection",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1167,
                                                    "char": 45
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1167,
                                                "char": 45
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1167,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1167,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1169,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "not",
                                    "left": {
                                        "type": "variable",
                                        "value": "exists",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1169,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1169,
                                    "char": 29
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1169,
                                "char": 29
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
                                                    "value": "The document cannot be updated because it doesn't exist",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1172,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1172,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1172,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1173,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1175,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "operationMade",
                                    "expr": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "self",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1175,
                                            "char": 50
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "OP_UPDATE",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1175,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1175,
                                        "char": 50
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1175,
                                    "char": 50
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1180,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "errorMessages",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1180,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1180,
                                    "char": 37
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1185,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1185,
                                        "char": 17
                                    },
                                    "name": "preSave",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1185,
                                                    "char": 31
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1185,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1185,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1185,
                                            "char": 41
                                        },
                                        {
                                            "parameter": {
                                                "type": "static-property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1185,
                                                    "char": 62
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "disableEvents",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1185,
                                                    "char": 62
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1185,
                                                "char": 62
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1185,
                                            "char": 62
                                        },
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "exists",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1185,
                                                "char": 70
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1185,
                                            "char": 70
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1185,
                                    "char": 74
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1185,
                                    "char": 82
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1185,
                                "char": 82
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1186,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1187,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1189,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "data",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1189,
                                            "char": 25
                                        },
                                        "name": "toArray",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1189,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1189,
                                    "char": 35
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1191,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "success",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1191,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1191,
                                    "char": 28
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1197,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "status",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "collection",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1197,
                                            "char": 33
                                        },
                                        "name": "update",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "array",
                                                    "left": [
                                                        {
                                                            "key": {
                                                                "type": "string",
                                                                "value": "_id",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 1199,
                                                                "char": 20
                                                            },
                                                            "value": {
                                                                "type": "property-access",
                                                                "left": {
                                                                    "type": "variable",
                                                                    "value": "this",
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                    "line": 1199,
                                                                    "char": 27
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "_id",
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                    "line": 1200,
                                                                    "char": 13
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 1200,
                                                                "char": 13
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1200,
                                                            "char": 13
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1200,
                                                    "char": 14
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1200,
                                                "char": 14
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "data",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1201,
                                                    "char": 17
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1201,
                                                "char": 17
                                            },
                                            {
                                                "parameter": {
                                                    "type": "array",
                                                    "left": [
                                                        {
                                                            "key": {
                                                                "type": "string",
                                                                "value": "w",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 1203,
                                                                "char": 18
                                                            },
                                                            "value": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 1204,
                                                                "char": 13
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1204,
                                                            "char": 13
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1205,
                                                    "char": 9
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1205,
                                                "char": 9
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1205,
                                        "char": 10
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1205,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1207,
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
                                        "value": "status",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1207,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1207,
                                    "char": 27
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1207,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1207,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "ok",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1208,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "status",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1208,
                                                "char": 32
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "ok",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1208,
                                                "char": 35
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1208,
                                            "char": 37
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1208,
                                        "char": 37
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "variable",
                                                "value": "ok",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1209,
                                                "char": 23
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "success",
                                                            "expr": {
                                                                "type": "bool",
                                                                "value": "true",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 1210,
                                                                "char": 39
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1210,
                                                            "char": 39
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1211,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1212,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1213,
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
                                            "variable": "success",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1214,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1214,
                                            "char": 32
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1215,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1220,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1220,
                                    "char": 21
                                },
                                "name": "postSave",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "static-property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1220,
                                                "char": 50
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "disableEvents",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1220,
                                                "char": 50
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1220,
                                            "char": 50
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1220,
                                        "char": 50
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "success",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1220,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1220,
                                        "char": 59
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "exists",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1220,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1220,
                                        "char": 67
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1220,
                                "char": 68
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1221,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Creates\/Updates a collection based on the values in the attributes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1158,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 1158,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 1157,
                    "last-line": 1253,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "validate",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "validator",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ValidationInterface",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1254,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1254,
                            "char": 64
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "messages",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1256,
                                    "char": 21
                                },
                                {
                                    "variable": "message",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1256,
                                    "char": 30
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1258,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "messages",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "validator",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1258,
                                            "char": 34
                                        },
                                        "name": "validate",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "null",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1258,
                                                    "char": 48
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1258,
                                                "char": 48
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1258,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1258,
                                                "char": 54
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1258,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1258,
                                    "char": 55
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1262,
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
                                        "value": "messages",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1262,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1262,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "boolean",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1262,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1262,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "messages",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1263,
                                        "char": 28
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1264,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1266,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "fcall",
                                "name": "iterator",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "messages",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1266,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1266,
                                        "char": 41
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1266,
                                "char": 43
                            },
                            "value": "message",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1267,
                                            "char": 18
                                        },
                                        "name": "appendMessage",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "new",
                                                    "class": "Message",
                                                    "dynamic": 0,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "message",
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                    "line": 1269,
                                                                    "char": 29
                                                                },
                                                                "name": "getMessage",
                                                                "call-type": 1,
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 1269,
                                                                "char": 42
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1269,
                                                            "char": 42
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "message",
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                    "line": 1270,
                                                                    "char": 29
                                                                },
                                                                "name": "getField",
                                                                "call-type": 1,
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 1270,
                                                                "char": 40
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1270,
                                                            "char": 40
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "message",
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                    "line": 1271,
                                                                    "char": 29
                                                                },
                                                                "name": "getType",
                                                                "call-type": 1,
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 1271,
                                                                "char": 39
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1271,
                                                            "char": 39
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "null",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 1272,
                                                                "char": 25
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1272,
                                                            "char": 25
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "mcall",
                                                                "variable": {
                                                                    "type": "variable",
                                                                    "value": "message",
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                    "line": 1273,
                                                                    "char": 29
                                                                },
                                                                "name": "getCode",
                                                                "call-type": 1,
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 1274,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1274,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1275,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1275,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1275,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1276,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1279,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fcall",
                                    "name": "count",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "messages",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1279,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1279,
                                            "char": 31
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1279,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1279,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1280,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Executes validators on every validation call\n     *\n     *```php\n     * use Phalcon\\Mvc\\Collection;\n     * use Phalcon\\Validation\\Validation;\n     * use Phalcon\\Validation\\Validator\\ExclusionIn;\n     *\n     * class Subscriptors extends Collection\n     * {\n     *     public function validation()\n     *     {\n     *         $validator = new Validation();\n     *\n     *         $validator->add(\n     *             \"status\",\n     *             new ExclusionIn(\n     *                 [\n     *                     \"domain\" => [\n     *                         \"A\",\n     *                         \"I\",\n     *                     ],\n     *                 ]\n     *             )\n     *         );\n     *\n     *         return $this->validate($validator);\n     *     }\n     * }\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1255,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 1255,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 1254,
                    "last-line": 1284,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "useImplicitObjectIds",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "useImplicitObjectIds",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1285,
                            "char": 70
                        }
                    ],
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1287,
                                        "char": 14
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "modelsManager",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1287,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1287,
                                    "char": 29
                                },
                                "name": "useImplicitObjectIds",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1287,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1287,
                                        "char": 55
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "useImplicitObjectIds",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1287,
                                            "char": 77
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1287,
                                        "char": 77
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1287,
                                "char": 78
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1288,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets if a model must use implicit objects ids\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 1285,
                    "last-line": 1296,
                    "char": 22
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "writeAttribute",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "attribute",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1297,
                            "char": 52
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1297,
                            "char": 63
                        }
                    ],
                    "statements": [
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable-dynamic-object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "attribute",
                                    "expr": {
                                        "type": "variable",
                                        "value": "value",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1299,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1299,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1300,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Writes an attribute value by its name\n     *\n     *```php\n     *    $robot->writeAttribute(\"name\", \"Rosey\");\n     *```\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 1297,
                    "last-line": 1304,
                    "char": 19
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "cancelOperation",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "disableEvents",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1305,
                            "char": 58
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "eventName",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1307,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1309,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "disableEvents",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1309,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1309,
                                "char": 27
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1310,
                                                "char": 21
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "operationMade",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1310,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1310,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "self",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1310,
                                                "char": 55
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "OP_DELETE",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1310,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1310,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1310,
                                        "char": 55
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "eventName",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "notDeleted",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1311,
                                                        "char": 43
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1311,
                                                    "char": 43
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1312,
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
                                                    "variable": "eventName",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "notSaved",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1313,
                                                        "char": 41
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1313,
                                                    "char": 41
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1314,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1315,
                                    "char": 16
                                },
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1315,
                                            "char": 18
                                        },
                                        "name": "fireEvent",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "eventName",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1315,
                                                    "char": 38
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1315,
                                                "char": 38
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1315,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1316,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1317,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1317,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1318,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Cancel the current operation\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1306,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 1306,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 1305,
                    "last-line": 1324,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "exists",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "collection",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1325,
                            "char": 41
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "id",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1327,
                                    "char": 15
                                },
                                {
                                    "variable": "mongoId",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1327,
                                    "char": 24
                                },
                                {
                                    "variable": "exists",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1327,
                                    "char": 32
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1329,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "id",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1329,
                                        "char": 33
                                    },
                                    "right": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1329,
                                            "char": 28
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "_id",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1329,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1329,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1329,
                                    "char": 33
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1329,
                                "char": 33
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1330,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1331,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1333,
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
                                        "value": "id",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1333,
                                        "char": 23
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1333,
                                    "char": 23
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1333,
                                    "char": 32
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1333,
                                "char": 32
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "mongoId",
                                            "expr": {
                                                "type": "variable",
                                                "value": "id",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1334,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1334,
                                            "char": 29
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1335,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1340,
                                                "char": 21
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "modelsManager",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1340,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1340,
                                            "char": 36
                                        },
                                        "name": "isUsingImplicitObjectIds",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1340,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1340,
                                                "char": 66
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1340,
                                        "char": 68
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "mongoId",
                                                    "expr": {
                                                        "type": "new",
                                                        "class": "MongoId",
                                                        "dynamic": 0,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "id",
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                    "line": 1341,
                                                                    "char": 45
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 1341,
                                                                "char": 45
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1341,
                                                        "char": 46
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1341,
                                                    "char": 46
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1342,
                                            "char": 19
                                        },
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "_id",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "mongoId",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1342,
                                                        "char": 40
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1342,
                                                    "char": 40
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1343,
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
                                                    "variable": "mongoId",
                                                    "expr": {
                                                        "type": "variable",
                                                        "value": "id",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1344,
                                                        "char": 33
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1344,
                                                    "char": 33
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1345,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1346,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1351,
                            "char": 11
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1351,
                                        "char": 19
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "dirtyState",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1351,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1351,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1351,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "true",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1352,
                                        "char": 24
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1353,
                                    "char": 10
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1358,
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
                                        "type": "greater",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "collection",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1358,
                                                "char": 33
                                            },
                                            "name": "count",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "array",
                                                        "left": [
                                                            {
                                                                "key": {
                                                                    "type": "string",
                                                                    "value": "_id",
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                    "line": 1358,
                                                                    "char": 44
                                                                },
                                                                "value": {
                                                                    "type": "variable",
                                                                    "value": "mongoId",
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                    "line": 1358,
                                                                    "char": 53
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 1358,
                                                                "char": 53
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1358,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1358,
                                                    "char": 54
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1358,
                                            "char": 56
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1358,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1358,
                                        "char": 59
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1358,
                                    "char": 59
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1360,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "exists",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1360,
                                "char": 19
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "dirtyState",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1361,
                                                    "char": 64
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "DIRTY_STATE_PERSISTENT",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1361,
                                                    "char": 64
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1361,
                                                "char": 64
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1361,
                                            "char": 64
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1362,
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
                                            "property": "dirtyState",
                                            "expr": {
                                                "type": "static-constant-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "self",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1363,
                                                    "char": 63
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "DIRTY_STATE_TRANSIENT",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1363,
                                                    "char": 63
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1363,
                                                "char": 63
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1363,
                                            "char": 63
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1364,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1366,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "exists",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1366,
                                "char": 22
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1367,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks if the document exists in the collection\n     *\n     * @param MongoCollection collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1326,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 1326,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 1325,
                    "last-line": 1374,
                    "char": 22
                },
                {
                    "visibility": [
                        "protected",
                        "static"
                    ],
                    "type": "method",
                    "name": "getGroupResultset",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "params",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1375,
                            "char": 55
                        },
                        {
                            "type": "parameter",
                            "name": "collection",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Collection",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1375,
                                "char": 79
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1375,
                            "char": 80
                        },
                        {
                            "type": "parameter",
                            "name": "connection",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1375,
                            "char": 92
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "source",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1377,
                                    "char": 19
                                },
                                {
                                    "variable": "mongoCollection",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1377,
                                    "char": 36
                                },
                                {
                                    "variable": "conditions",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1377,
                                    "char": 48
                                },
                                {
                                    "variable": "limit",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1377,
                                    "char": 55
                                },
                                {
                                    "variable": "sort",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1377,
                                    "char": 61
                                },
                                {
                                    "variable": "documentsCursor",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1377,
                                    "char": 78
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1379,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "source",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "collection",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1379,
                                            "char": 33
                                        },
                                        "name": "getSource",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1379,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1379,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1380,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "empty",
                                    "left": {
                                        "type": "variable",
                                        "value": "source",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1380,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1380,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1380,
                                "char": 34
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
                                                    "value": "Method getSource() returns empty string",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1381,
                                                    "char": 72
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1381,
                                                "char": 72
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1381,
                                        "char": 73
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1382,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1384,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "mongoCollection",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "connection",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1384,
                                            "char": 42
                                        },
                                        "name": "selectCollection",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "source",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1384,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1384,
                                                "char": 66
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1384,
                                        "char": 67
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1384,
                                    "char": 67
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1389,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "conditions",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1389,
                                        "char": 41
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1389,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1389,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1389,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1389,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1389,
                                "char": 41
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "fetch",
                                            "left": {
                                                "type": "variable",
                                                "value": "conditions",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1390,
                                                "char": 54
                                            },
                                            "right": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1390,
                                                    "char": 41
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "conditions",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1390,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1390,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1390,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1390,
                                        "char": 54
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "conditions",
                                                    "expr": {
                                                        "type": "empty-array",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1391,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1391,
                                                    "char": 36
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1392,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1393,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1395,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "or",
                                    "left": {
                                        "type": "isset",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "params",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1395,
                                                "char": 24
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "limit",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1395,
                                                "char": 30
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1395,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1395,
                                        "char": 33
                                    },
                                    "right": {
                                        "type": "isset",
                                        "left": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "params",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1395,
                                                "char": 47
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "sort",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1395,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1395,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1395,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1395,
                                    "char": 55
                                },
                                "right": {
                                    "type": "isset",
                                    "left": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1395,
                                            "char": 69
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "skip",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1395,
                                            "char": 74
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1395,
                                        "char": 76
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1395,
                                    "char": 76
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1395,
                                "char": 76
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "documentsCursor",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "mongoCollection",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1400,
                                                    "char": 51
                                                },
                                                "name": "find",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "conditions",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1400,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1400,
                                                        "char": 67
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1400,
                                                "char": 68
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1400,
                                            "char": 68
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1405,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "limit",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1405,
                                            "char": 43
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "params",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1405,
                                                "char": 35
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "limit",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1405,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1405,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1405,
                                        "char": 43
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "documentsCursor",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1406,
                                                    "char": 33
                                                },
                                                "name": "limit",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "limit",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1406,
                                                            "char": 45
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1406,
                                                        "char": 45
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1406,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1407,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1412,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "sort",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1412,
                                            "char": 41
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "params",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1412,
                                                "char": 34
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "sort",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1412,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1412,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1412,
                                        "char": 41
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "documentsCursor",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1413,
                                                    "char": 33
                                                },
                                                "name": "sort",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "sort",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1413,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1413,
                                                        "char": 43
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1413,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1414,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1419,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fetch",
                                        "left": {
                                            "type": "variable",
                                            "value": "sort",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1419,
                                            "char": 41
                                        },
                                        "right": {
                                            "type": "array-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "params",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1419,
                                                "char": 34
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "skip",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1419,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1419,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1419,
                                        "char": 41
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "documentsCursor",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1420,
                                                    "char": 33
                                                },
                                                "name": "skip",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "sort",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1420,
                                                            "char": 43
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1420,
                                                        "char": 43
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1420,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1421,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1426,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "count",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "documentsCursor",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1426,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1426,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1426,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1427,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1429,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "mongoCollection",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1429,
                                    "char": 32
                                },
                                "name": "count",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "conditions",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1429,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1429,
                                        "char": 49
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1429,
                                "char": 50
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1430,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Perform a count over a resultset\n     *\n     * @param array params\n     * @param \\MongoDb connection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1376,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 1376,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 1375,
                    "last-line": 1438,
                    "char": 29
                },
                {
                    "visibility": [
                        "protected",
                        "static"
                    ],
                    "type": "method",
                    "name": "getResultset",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "params",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1439,
                            "char": 54
                        },
                        {
                            "type": "parameter",
                            "name": "collection",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "CollectionInterface",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1439,
                                "char": 87
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1439,
                            "char": 88
                        },
                        {
                            "type": "parameter",
                            "name": "connection",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1439,
                            "char": 100
                        },
                        {
                            "type": "parameter",
                            "name": "unique",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1439,
                            "char": 113
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "source",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1441,
                                    "char": 19
                                },
                                {
                                    "variable": "mongoCollection",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1441,
                                    "char": 36
                                },
                                {
                                    "variable": "conditions",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1441,
                                    "char": 48
                                },
                                {
                                    "variable": "base",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1441,
                                    "char": 54
                                },
                                {
                                    "variable": "documentsCursor",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1441,
                                    "char": 71
                                },
                                {
                                    "variable": "fields",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1442,
                                    "char": 19
                                },
                                {
                                    "variable": "skip",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1442,
                                    "char": 25
                                },
                                {
                                    "variable": "limit",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1442,
                                    "char": 32
                                },
                                {
                                    "variable": "sort",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1442,
                                    "char": 38
                                },
                                {
                                    "variable": "document",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1442,
                                    "char": 48
                                },
                                {
                                    "variable": "collections",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1442,
                                    "char": 61
                                },
                                {
                                    "variable": "className",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1442,
                                    "char": 72
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1447,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "className",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1447,
                                    "char": 43
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "params",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1447,
                                        "char": 35
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "class",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1447,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1447,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1447,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "base",
                                            "expr": {
                                                "type": "new",
                                                "class": "className",
                                                "dynamic": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1448,
                                                "char": 41
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1448,
                                            "char": 41
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1450,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "unlikely",
                                        "left": {
                                            "type": "not",
                                            "left": {
                                                "type": "list",
                                                "left": {
                                                    "type": "or",
                                                    "left": {
                                                        "type": "instanceof",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "base",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1450,
                                                            "char": 41
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "CollectionInterface",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1450,
                                                            "char": 64
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1450,
                                                        "char": 64
                                                    },
                                                    "right": {
                                                        "type": "instanceof",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "base",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1450,
                                                            "char": 80
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "Collection\\Document",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1450,
                                                            "char": 101
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1450,
                                                        "char": 101
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1450,
                                                    "char": 101
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1450,
                                                "char": 103
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1450,
                                            "char": 103
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1450,
                                        "char": 103
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
                                                                    "value": "Object of class '",
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                    "line": 1452,
                                                                    "char": 39
                                                                },
                                                                "right": {
                                                                    "type": "variable",
                                                                    "value": "className",
                                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                    "line": 1452,
                                                                    "char": 51
                                                                },
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 1452,
                                                                "char": 51
                                                            },
                                                            "right": {
                                                                "type": "string",
                                                                "value": "' must be an implementation of Phalcon\\\\Mvc\\\\CollectionInterface or an instance of Phalcon\\\\Mvc\\\\Collection\\\\Document",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 1453,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1453,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1453,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1453,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1454,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1455,
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
                                            "variable": "base",
                                            "expr": {
                                                "type": "variable",
                                                "value": "collection",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1456,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1456,
                                            "char": 34
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1457,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1459,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "instanceof",
                                "left": {
                                    "type": "variable",
                                    "value": "base",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1459,
                                    "char": 26
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "Collection",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1459,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1459,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "base",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1460,
                                            "char": 18
                                        },
                                        "name": "setDirtyState",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "static-constant-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "self",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1460,
                                                        "char": 61
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "DIRTY_STATE_PERSISTENT",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1460,
                                                        "char": 61
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1460,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1460,
                                                "char": 61
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1460,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1461,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1463,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "source",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "collection",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1463,
                                            "char": 33
                                        },
                                        "name": "getSource",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1463,
                                        "char": 45
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1463,
                                    "char": 45
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1464,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "empty",
                                    "left": {
                                        "type": "variable",
                                        "value": "source",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1464,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1464,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1464,
                                "char": 34
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
                                                    "value": "Method getSource() returns empty string",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1465,
                                                    "char": 72
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1465,
                                                "char": 72
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1465,
                                        "char": 73
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1466,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1468,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "mongoCollection",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "connection",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1468,
                                            "char": 42
                                        },
                                        "name": "selectCollection",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "source",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1468,
                                                    "char": 66
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1468,
                                                "char": 66
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1468,
                                        "char": 67
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1468,
                                    "char": 67
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1470,
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
                                            "value": "mongoCollection",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1470,
                                            "char": 45
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1470,
                                        "char": 45
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1470,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1470,
                                    "char": 54
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1470,
                                "char": 54
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
                                                    "value": "Couldn't select mongo collection",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1471,
                                                    "char": 65
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1471,
                                                "char": 65
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1471,
                                        "char": 66
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1472,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1477,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "fetch",
                                    "left": {
                                        "type": "variable",
                                        "value": "conditions",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1477,
                                        "char": 41
                                    },
                                    "right": {
                                        "type": "array-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "params",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1477,
                                            "char": 37
                                        },
                                        "right": {
                                            "type": "int",
                                            "value": "0",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1477,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1477,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1477,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1477,
                                "char": 41
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "fetch",
                                            "left": {
                                                "type": "variable",
                                                "value": "conditions",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1478,
                                                "char": 54
                                            },
                                            "right": {
                                                "type": "array-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "params",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1478,
                                                    "char": 41
                                                },
                                                "right": {
                                                    "type": "string",
                                                    "value": "conditions",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1478,
                                                    "char": 52
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1478,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1478,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1478,
                                        "char": 54
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "conditions",
                                                    "expr": {
                                                        "type": "empty-array",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1479,
                                                        "char": 36
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1479,
                                                    "char": 36
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1480,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1481,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1483,
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
                                            "value": "conditions",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1483,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1483,
                                        "char": 40
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "array",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1483,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1483,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1483,
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
                                                    "type": "string",
                                                    "value": "Find parameters must be an array",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1484,
                                                    "char": 65
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1484,
                                                "char": 65
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1484,
                                        "char": 66
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1485,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1490,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "fields",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1490,
                                    "char": 41
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "params",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1490,
                                        "char": 32
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "fields",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1490,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1490,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1490,
                                "char": 41
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "documentsCursor",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "mongoCollection",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1491,
                                                    "char": 51
                                                },
                                                "name": "find",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "conditions",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1491,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1491,
                                                        "char": 67
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "fields",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1491,
                                                            "char": 75
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1491,
                                                        "char": 75
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1491,
                                                "char": 76
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1491,
                                            "char": 76
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1492,
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
                                            "variable": "documentsCursor",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "mongoCollection",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1493,
                                                    "char": 51
                                                },
                                                "name": "find",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "conditions",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1493,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1493,
                                                        "char": 67
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1493,
                                                "char": 68
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1493,
                                            "char": 68
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1494,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1499,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "limit",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1499,
                                    "char": 39
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "params",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1499,
                                        "char": 31
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "limit",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1499,
                                        "char": 37
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1499,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1499,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "documentsCursor",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1500,
                                            "char": 29
                                        },
                                        "name": "limit",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "limit",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1500,
                                                    "char": 41
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1500,
                                                "char": 41
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1500,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1501,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1506,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "sort",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1506,
                                    "char": 37
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "params",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1506,
                                        "char": 30
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "sort",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1506,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1506,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1506,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "documentsCursor",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1507,
                                            "char": 29
                                        },
                                        "name": "sort",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "sort",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1507,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1507,
                                                "char": 39
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1507,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1508,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1513,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "skip",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1513,
                                    "char": 37
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "params",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1513,
                                        "char": 30
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "skip",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1513,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1513,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1513,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "documentsCursor",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1514,
                                            "char": 29
                                        },
                                        "name": "skip",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "skip",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1514,
                                                    "char": 39
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1514,
                                                "char": 39
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1514,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1515,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1517,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "unique",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1517,
                                "char": 19
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "documentsCursor",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1522,
                                            "char": 29
                                        },
                                        "name": "rewind",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1522,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1524,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "document",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "documentsCursor",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1524,
                                                    "char": 44
                                                },
                                                "name": "current",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1524,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1524,
                                            "char": 54
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1526,
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
                                                "value": "document",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1526,
                                                "char": 33
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1526,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "array",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1526,
                                            "char": 41
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1526,
                                        "char": 41
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1527,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1528,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1533,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "scall",
                                        "dynamic-class": 0,
                                        "class": "static",
                                        "dynamic": 0,
                                        "name": "cloneResult",
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "base",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1533,
                                                    "char": 44
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1533,
                                                "char": 44
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "document",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1533,
                                                    "char": 54
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1533,
                                                "char": 54
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1533,
                                        "char": 55
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1534,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1539,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "collections",
                                    "expr": {
                                        "type": "empty-array",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1539,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1539,
                                    "char": 29
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1540,
                            "char": 11
                        },
                        {
                            "type": "for",
                            "expr": {
                                "type": "fcall",
                                "name": "iterator_to_array",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "documentsCursor",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1540,
                                            "char": 58
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1540,
                                        "char": 58
                                    },
                                    {
                                        "parameter": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1540,
                                            "char": 65
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1540,
                                        "char": 65
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1540,
                                "char": 67
                            },
                            "value": "document",
                            "reverse": 0,
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-append",
                                            "operator": "assign",
                                            "variable": "collections",
                                            "expr": {
                                                "type": "scall",
                                                "dynamic-class": 0,
                                                "class": "static",
                                                "dynamic": 0,
                                                "name": "cloneResult",
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "base",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1545,
                                                            "char": 57
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1545,
                                                        "char": 57
                                                    },
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "document",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1545,
                                                            "char": 67
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1545,
                                                        "char": 67
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1545,
                                                "char": 68
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1545,
                                            "char": 68
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1546,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1548,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "collections",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1548,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1549,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a collection resultset\n     *\n     * @param array params\n     * @param \\MongoDb connection\n     * @return array\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 1439,
                    "last-line": 1553,
                    "char": 29
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "preSave",
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
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1554,
                                "char": 60
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1554,
                            "char": 61
                        },
                        {
                            "type": "parameter",
                            "name": "disableEvents",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1554,
                            "char": 81
                        },
                        {
                            "type": "parameter",
                            "name": "exists",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1554,
                            "char": 94
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "eventName",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1556,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1561,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "disableEvents",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1561,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1561,
                                "char": 27
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
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1563,
                                                "char": 21
                                            },
                                            "name": "fireEventCancel",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "beforeValidation",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1563,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1563,
                                                    "char": 54
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1563,
                                            "char": 58
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1563,
                                            "char": 66
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1563,
                                        "char": 66
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1564,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1565,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1567,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "variable",
                                            "value": "exists",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1567,
                                            "char": 24
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1567,
                                        "char": 24
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "eventName",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "beforeValidationOnCreate",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1568,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1568,
                                                    "char": 57
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1569,
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
                                                    "variable": "eventName",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "beforeValidationOnUpdate",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1570,
                                                        "char": 57
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1570,
                                                    "char": 57
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1571,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1573,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1573,
                                                "char": 21
                                            },
                                            "name": "fireEventCancel",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "eventName",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1573,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1573,
                                                    "char": 47
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1573,
                                            "char": 51
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1573,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1573,
                                        "char": 59
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1574,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1575,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1577,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1582,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "mcall",
                                    "variable": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1582,
                                        "char": 17
                                    },
                                    "name": "fireEventCancel",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "string",
                                                "value": "validation",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1582,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1582,
                                            "char": 44
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1582,
                                    "char": 48
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1582,
                                    "char": 56
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1582,
                                "char": 56
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "variable",
                                            "value": "disableEvents",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1583,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1583,
                                        "char": 31
                                    },
                                    "statements": [
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1584,
                                                    "char": 22
                                                },
                                                "name": "fireEvent",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "onValidationFails",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1584,
                                                            "char": 50
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1584,
                                                        "char": 50
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1584,
                                                "char": 51
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1585,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1586,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "bool",
                                        "value": "false",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1586,
                                        "char": 25
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1587,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1589,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "disableEvents",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1589,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1589,
                                "char": 27
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "variable",
                                            "value": "exists",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1594,
                                            "char": 24
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1594,
                                        "char": 24
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "eventName",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "afterValidationOnCreate",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1595,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1595,
                                                    "char": 56
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1596,
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
                                                    "variable": "eventName",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "afterValidationOnUpdate",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1597,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1597,
                                                    "char": 56
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1598,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1600,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1600,
                                                "char": 21
                                            },
                                            "name": "fireEventCancel",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "eventName",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1600,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1600,
                                                    "char": 47
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1600,
                                            "char": 51
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1600,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1600,
                                        "char": 59
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1601,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1602,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1604,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1604,
                                                "char": 21
                                            },
                                            "name": "fireEventCancel",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "afterValidation",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1604,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1604,
                                                    "char": 53
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1604,
                                            "char": 57
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1604,
                                            "char": 65
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1604,
                                        "char": 65
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1605,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1606,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1611,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1611,
                                                "char": 21
                                            },
                                            "name": "fireEventCancel",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "string",
                                                        "value": "beforeSave",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1611,
                                                        "char": 48
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1611,
                                                    "char": 48
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1611,
                                            "char": 52
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1611,
                                            "char": 60
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1611,
                                        "char": 60
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1612,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1613,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1615,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "variable",
                                        "value": "exists",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1615,
                                        "char": 23
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "eventName",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "beforeUpdate",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1616,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1616,
                                                    "char": 45
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1617,
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
                                                    "variable": "eventName",
                                                    "expr": {
                                                        "type": "string",
                                                        "value": "beforeCreate",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1618,
                                                        "char": 45
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1618,
                                                    "char": 45
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1619,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1621,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1621,
                                                "char": 21
                                            },
                                            "name": "fireEventCancel",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "eventName",
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1621,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1621,
                                                    "char": 47
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1621,
                                            "char": 51
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1621,
                                            "char": 59
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1621,
                                        "char": 59
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1622,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1623,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1625,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1627,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1627,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1628,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Executes internal hooks before save a document\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1555,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 1555,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 1554,
                    "last-line": 1632,
                    "char": 28
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "postSave",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "disableEvents",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1633,
                            "char": 57
                        },
                        {
                            "type": "parameter",
                            "name": "success",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1633,
                            "char": 71
                        },
                        {
                            "type": "parameter",
                            "name": "exists",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1633,
                            "char": 84
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "eventName",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1635,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1637,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "success",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1637,
                                "char": 20
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "variable",
                                            "value": "disableEvents",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1638,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1638,
                                        "char": 31
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "variable",
                                                "value": "exists",
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1639,
                                                "char": 27
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "eventName",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "afterUpdate",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 1640,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1640,
                                                            "char": 48
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1641,
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
                                                            "variable": "eventName",
                                                            "expr": {
                                                                "type": "string",
                                                                "value": "afterCreate",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 1642,
                                                                "char": 48
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1642,
                                                            "char": 48
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1643,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1645,
                                            "char": 20
                                        },
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1645,
                                                    "char": 22
                                                },
                                                "name": "fireEvent",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "eventName",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1645,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1645,
                                                        "char": 42
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1645,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1647,
                                            "char": 20
                                        },
                                        {
                                            "type": "mcall",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1647,
                                                    "char": 22
                                                },
                                                "name": "fireEvent",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "string",
                                                            "value": "afterSave",
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1647,
                                                            "char": 42
                                                        },
                                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                        "line": 1647,
                                                        "char": 42
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1647,
                                                "char": 43
                                            },
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1648,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1650,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "success",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1650,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1651,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1653,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "not",
                                "left": {
                                    "type": "variable",
                                    "value": "disableEvents",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1653,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1653,
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
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1654,
                                            "char": 18
                                        },
                                        "name": "fireEvent",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "notSaved",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1654,
                                                    "char": 37
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1654,
                                                "char": 37
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1654,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1655,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1657,
                            "char": 12
                        },
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1657,
                                    "char": 14
                                },
                                "name": "cancelOperation",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "disableEvents",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1657,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1657,
                                        "char": 44
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1657,
                                "char": 45
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1658,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1658,
                                "char": 21
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1659,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Executes internal events after save a document\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1634,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 1634,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 1633,
                    "last-line": 1664,
                    "char": 28
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "method",
                    "name": "prepareCU",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1667,
                                    "char": 22
                                },
                                {
                                    "variable": "connection",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1667,
                                    "char": 34
                                },
                                {
                                    "variable": "source",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1667,
                                    "char": 42
                                },
                                {
                                    "variable": "collection",
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1667,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1669,
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
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1669,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "container",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1669,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1669,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1669,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1670,
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
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1670,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1670,
                                        "char": 39
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "object",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1670,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1670,
                                    "char": 48
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1670,
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
                                                                "value": "the services related to the ODM",
                                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                                "line": 1674,
                                                                "char": 17
                                                            },
                                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                            "line": 1674,
                                                            "char": 17
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1675,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1675,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1675,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1676,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1678,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "source",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1678,
                                            "char": 27
                                        },
                                        "name": "getSource",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1678,
                                        "char": 39
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1678,
                                    "char": 39
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1679,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "unlikely",
                                "left": {
                                    "type": "empty",
                                    "left": {
                                        "type": "variable",
                                        "value": "source",
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1679,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1679,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1679,
                                "char": 34
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
                                                    "value": "Method getSource() returns empty string",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1680,
                                                    "char": 72
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1680,
                                                "char": 72
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1680,
                                        "char": 73
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1681,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1683,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "connection",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1683,
                                            "char": 31
                                        },
                                        "name": "getConnection",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1683,
                                        "char": 47
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1683,
                                    "char": 47
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1688,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "collection",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "connection",
                                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                            "line": 1688,
                                            "char": 37
                                        },
                                        "name": "selectCollection",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "source",
                                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                    "line": 1688,
                                                    "char": 61
                                                },
                                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                                "line": 1688,
                                                "char": 61
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                        "line": 1688,
                                        "char": 62
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                    "line": 1688,
                                    "char": 62
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1690,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "collection",
                                "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                                "line": 1690,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                            "line": 1691,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Shared Code for CU Operations\n     * Prepares Collection\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 1665,
                    "last-line": 1692,
                    "char": 22
                }
            ],
            "constants": [
                {
                    "type": "const",
                    "name": "DIRTY_STATE_DETACHED",
                    "default": {
                        "type": "int",
                        "value": "2",
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 37,
                        "char": 35
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 38,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "DIRTY_STATE_PERSISTENT",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 38,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 39,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "DIRTY_STATE_TRANSIENT",
                    "default": {
                        "type": "int",
                        "value": "1",
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 39,
                        "char": 36
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 40,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "OP_CREATE",
                    "default": {
                        "type": "int",
                        "value": "1",
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 40,
                        "char": 24
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 41,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "OP_DELETE",
                    "default": {
                        "type": "int",
                        "value": "3",
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 41,
                        "char": 24
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 42,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "OP_NONE",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 42,
                        "char": 22
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 43,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "OP_UPDATE",
                    "default": {
                        "type": "int",
                        "value": "2",
                        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                        "line": 43,
                        "char": 24
                    },
                    "file": "\/app\/phalcon\/Mvc\/Collection.zep",
                    "line": 45,
                    "char": 10
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Collection.zep",
            "line": 35,
            "char": 14
        },
        "file": "\/app\/phalcon\/Mvc\/Collection.zep",
        "line": 35,
        "char": 14
    }
]