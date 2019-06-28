[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/ResultInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc\\Model",
        "file": "\/app\/phalcon\/Mvc\/Model\/ResultInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Mvc\\ModelInterface",
                "file": "\/app\/phalcon\/Mvc\/Model\/ResultInterface.zep",
                "line": 13,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Model\/ResultInterface.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Model\\ResultInterface\n *\n * All single objects passed as base objects to Resultsets must implement this interface\n *",
        "file": "\/app\/phalcon\/Mvc\/Model\/ResultInterface.zep",
        "line": 20,
        "char": 9
    },
    {
        "type": "interface",
        "name": "ResultInterface",
        "definition": {
            "methods": [
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
                            "file": "\/app\/phalcon\/Mvc\/Model\/ResultInterface.zep",
                            "line": 25,
                            "char": 49
                        }
                    ],
                    "docblock": "**\n     * Sets the object's state\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ModelInterface",
                                    "file": "\/app\/phalcon\/Mvc\/Model\/ResultInterface.zep",
                                    "line": 25,
                                    "char": 71
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ResultInterface.zep",
                                "line": 25,
                                "char": 71
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Mvc\/Model\/ResultInterface.zep",
                                "line": 25,
                                "char": 77
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Mvc\/Model\/ResultInterface.zep",
                        "line": 25,
                        "char": 77
                    },
                    "file": "\/app\/phalcon\/Mvc\/Model\/ResultInterface.zep",
                    "line": 25,
                    "last-line": 26,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Model\/ResultInterface.zep",
            "line": 26,
            "char": 1
        },
        "file": "\/app\/phalcon\/Mvc\/Model\/ResultInterface.zep",
        "line": 0,
        "char": 0
    }
]