[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc",
        "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Messages\\MessageInterface",
                "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                "line": 13,
                "char": 38
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
        "line": 17,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Interface for Phalcon\\Mvc\\Collection\n *",
        "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
        "line": 18,
        "char": 9
    },
    {
        "type": "interface",
        "name": "CollectionInterface",
        "definition": {
            "methods": [
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
                                "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                                "line": 23,
                                "char": 60
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                            "line": 23,
                            "char": 61
                        }
                    ],
                    "docblock": "**\n     * Appends a customized message on the validation process\n     *",
                    "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                    "line": 23,
                    "last-line": 27,
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
                                "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                                "line": 28,
                                "char": 71
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                            "line": 28,
                            "char": 72
                        },
                        {
                            "type": "parameter",
                            "name": "document",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                            "line": 28,
                            "char": 89
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
                                    "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                                    "line": 28,
                                    "char": 115
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                                "line": 28,
                                "char": 115
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                        "line": 28,
                        "char": 115
                    },
                    "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                    "line": 28,
                    "last-line": 32,
                    "char": 26
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
                                "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                                "line": 33,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                            "line": 33,
                            "char": 57
                        }
                    ],
                    "docblock": "**\n     * Perform a count over a collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                                "line": 33,
                                "char": 65
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                        "line": 33,
                        "char": 65
                    },
                    "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                    "line": 33,
                    "last-line": 37,
                    "char": 26
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "delete",
                    "docblock": "**\n     * Deletes a model instance. Returning true on success or false otherwise\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                                "line": 38,
                                "char": 37
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                        "line": 38,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                    "line": 38,
                    "last-line": 42,
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
                                "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                                "line": 43,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                            "line": 43,
                            "char": 56
                        }
                    ],
                    "docblock": "**\n     * Allows to query a set of records that match the specified conditions\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                                "line": 43,
                                "char": 66
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                        "line": 43,
                        "char": 66
                    },
                    "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                    "line": 43,
                    "last-line": 49,
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
                            "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                            "line": 50,
                            "char": 43
                        }
                    ],
                    "docblock": "**\n     * Find a document by its id\n     *\n     * @param string id\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "CollectionInterface",
                                    "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                                    "line": 50,
                                    "char": 70
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                                "line": 50,
                                "char": 70
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                                "line": 50,
                                "char": 76
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                        "line": 50,
                        "char": 76
                    },
                    "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                    "line": 50,
                    "last-line": 54,
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
                                "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                                "line": 55,
                                "char": 61
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                            "line": 55,
                            "char": 61
                        }
                    ],
                    "docblock": "**\n     * Allows to query the first record that match the specified conditions\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                                "line": 55,
                                "char": 71
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                        "line": 55,
                        "char": 71
                    },
                    "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                    "line": 55,
                    "last-line": 60,
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
                            "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                            "line": 61,
                            "char": 48
                        }
                    ],
                    "docblock": "**\n     * Fires an event, implicitly calls behaviors and listeners in the events\n     * manager are notified\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                                "line": 61,
                                "char": 57
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                        "line": 61,
                        "char": 57
                    },
                    "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                    "line": 61,
                    "last-line": 66,
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
                            "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                            "line": 67,
                            "char": 54
                        }
                    ],
                    "docblock": "**\n     * Fires an event, implicitly listeners in the events manager are notified\n     * This method stops if one of the callbacks\/listeners returns bool false\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                                "line": 67,
                                "char": 63
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                        "line": 67,
                        "char": 63
                    },
                    "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                    "line": 67,
                    "last-line": 73,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getConnection",
                    "docblock": "**\n     * Retrieves a database connection\n     *\n     * @return MongoDb\n     *",
                    "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                    "line": 74,
                    "last-line": 79,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDirtyState",
                    "docblock": "**\n     * Returns one of the DIRTY_STATE_* constants telling if the record exists\n     * in the database or not\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                                "line": 80,
                                "char": 43
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                        "line": 80,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                    "line": 80,
                    "last-line": 86,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getId",
                    "docblock": "**\n     * Returns the value of the _id property\n     *\n     * @return MongoId\n     *",
                    "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                    "line": 87,
                    "last-line": 91,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMessages",
                    "docblock": "**\n     * Returns all the validation messages\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "MessageInterface",
                                    "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                                    "line": 92,
                                    "char": 58
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                                "line": 92,
                                "char": 58
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                        "line": 92,
                        "char": 58
                    },
                    "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                    "line": 92,
                    "last-line": 97,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getReservedAttributes",
                    "docblock": "**\n     * Returns an array with reserved properties that cannot be part of the\n     * insert\/update\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                                "line": 98,
                                "char": 53
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                        "line": 98,
                        "char": 53
                    },
                    "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                    "line": 98,
                    "last-line": 102,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getSource",
                    "docblock": "**\n     * Returns collection name mapped in the model\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                                "line": 103,
                                "char": 42
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                        "line": 103,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                    "line": 103,
                    "last-line": 107,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "save",
                    "docblock": "**\n     * Creates\/Updates a collection based on the values in the attributes\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                                "line": 108,
                                "char": 35
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                        "line": 108,
                        "char": 35
                    },
                    "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                    "line": 108,
                    "last-line": 112,
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
                            "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                            "line": 113,
                            "char": 67
                        }
                    ],
                    "docblock": "**\n     * Sets a service in the services container that returns the Mongo database\n     *",
                    "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                    "line": 113,
                    "last-line": 118,
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
                            "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                            "line": 119,
                            "char": 49
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
                                    "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                                    "line": 119,
                                    "char": 75
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                                "line": 119,
                                "char": 75
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                        "line": 119,
                        "char": 75
                    },
                    "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                    "line": 119,
                    "last-line": 125,
                    "char": 19
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
                            "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                            "line": 126,
                            "char": 29
                        }
                    ],
                    "docblock": "**\n     * Sets a value for the _id property, creates a MongoId object if needed\n     *\n     * @param mixed id\n     *",
                    "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                    "line": 126,
                    "last-line": 130,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "validationHasFailed",
                    "docblock": "**\n     * Check whether validation process has generated any messages\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                                "line": 131,
                                "char": 50
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                        "line": 131,
                        "char": 50
                    },
                    "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
                    "line": 131,
                    "last-line": 132,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
            "line": 132,
            "char": 1
        },
        "file": "\/app\/phalcon\/Mvc\/CollectionInterface.zep",
        "line": 0,
        "char": 0
    }
]