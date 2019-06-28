[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/BehaviorInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model",
        "file": "\/app\/phalcon\/Mvc\/Model\/BehaviorInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ModelInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/BehaviorInterface.zep",
                "line": 13,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/BehaviorInterface.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\BehaviorInterface\n *\n * Interface for Phalcon\\Mvc\\Model\\Behavior\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/BehaviorInterface.zep",
        "line": 20,
        "char": 9
    },
    {
        "type": "interface",
        "name": "BehaviorInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "missingMethod",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/BehaviorInterface.zep",
                                "line": 25,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/BehaviorInterface.zep",
                            "line": 25,
                            "char": 57
                        },
                        {
                            "type": "parameter",
                            "name": "method",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/BehaviorInterface.zep",
                            "line": 25,
                            "char": 73
                        },
                        {
                            "type": "parameter",
                            "name": "arguments",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 0,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Mvc\/Model\/BehaviorInterface.zep",
                                "line": 25,
                                "char": 95
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/BehaviorInterface.zep",
                            "line": 25,
                            "char": 95
                        }
                    ],
                    "docblock": "**\n     * Calls a method when it's missing in the model\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/BehaviorInterface.zep",
                    "line": 25,
                    "last-line": 29,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "notify",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "type",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/BehaviorInterface.zep",
                            "line": 30,
                            "char": 40
                        },
                        {
                            "type": "parameter",
                            "name": "model",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "ModelInterface",
                                "file": "\/app\/phalcon\/Mvc\/Model\/BehaviorInterface.zep",
                                "line": 30,
                                "char": 63
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/Model\/BehaviorInterface.zep",
                            "line": 30,
                            "char": 64
                        }
                    ],
                    "docblock": "**\n     * This method receives the notifications from the EventsManager\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Model\/BehaviorInterface.zep",
                    "line": 30,
                    "last-line": 31,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/BehaviorInterface.zep",
            "line": 31,
            "char": 1
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/BehaviorInterface.zep",
        "line": 0,
        "char": 0
    }
]