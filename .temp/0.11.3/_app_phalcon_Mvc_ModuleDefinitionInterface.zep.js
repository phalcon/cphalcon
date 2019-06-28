[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/ModuleDefinitionInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc",
        "file": "\/app\/phalcon\/Mvc\/ModuleDefinitionInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Mvc\/ModuleDefinitionInterface.zep",
                "line": 13,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/ModuleDefinitionInterface.zep",
        "line": 19,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\ModuleDefinitionInterface\n *\n * This interface must be implemented by class module definitions\n *",
        "file": "\/app\/phalcon\/Mvc\/ModuleDefinitionInterface.zep",
        "line": 20,
        "char": 9
    },
    {
        "type": "interface",
        "name": "ModuleDefinitionInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "registerAutoloaders",
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
                                "file": "\/app\/phalcon\/Mvc\/ModuleDefinitionInterface.zep",
                                "line": 25,
                                "char": 63
                            },
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Mvc\/ModuleDefinitionInterface.zep",
                                "line": 25,
                                "char": 71
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModuleDefinitionInterface.zep",
                            "line": 25,
                            "char": 71
                        }
                    ],
                    "docblock": "**\n     * Registers an autoloader related to the module\n     *",
                    "file": "\/app\/phalcon\/Mvc\/ModuleDefinitionInterface.zep",
                    "line": 25,
                    "last-line": 29,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "registerServices",
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
                                "file": "\/app\/phalcon\/Mvc\/ModuleDefinitionInterface.zep",
                                "line": 30,
                                "char": 60
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Mvc\/ModuleDefinitionInterface.zep",
                            "line": 30,
                            "char": 61
                        }
                    ],
                    "docblock": "**\n     * Registers services related to the module\n     *",
                    "file": "\/app\/phalcon\/Mvc\/ModuleDefinitionInterface.zep",
                    "line": 30,
                    "last-line": 31,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/ModuleDefinitionInterface.zep",
            "line": 31,
            "char": 1
        },
        "file": "\/app\/phalcon\/Mvc\/ModuleDefinitionInterface.zep",
        "line": 0,
        "char": 0
    }
]