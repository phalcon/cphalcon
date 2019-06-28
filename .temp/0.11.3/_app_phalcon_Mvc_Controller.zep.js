[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Mvc\/Controller.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Mvc",
        "file": "\/app\/phalcon\/Mvc\/Controller.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\Injectable",
                "file": "\/app\/phalcon\/Mvc\/Controller.zep",
                "line": 13,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Mvc\/Controller.zep",
        "line": 54,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Mvc\\Controller\n *\n * Every application controller should extend this class that encapsulates all\n * the controller functionality\n *\n * The controllers provide the \u201cflow\u201d between models and views. Controllers are\n * responsible for processing the incoming requests from the web browser,\n * interrogating the models for data, and passing that data on to the views for\n * presentation.\n *\n *```php\n * <?php\n *\n * class PeopleController extends \\Phalcon\\Mvc\\Controller\n * {\n *     \/\/ This action will be executed by default\n *     public function indexAction()\n *     {\n *\n *     }\n *\n *     public function findAction()\n *     {\n *\n *     }\n *\n *     public function saveAction()\n *     {\n *         \/\/ Forwards flow to the index action\n *         return $this->dispatcher->forward(\n *             [\n *                 \"controller\" => \"people\",\n *                 \"action\"     => \"index\",\n *             ]\n *         );\n *     }\n * }\n *```\n *",
        "file": "\/app\/phalcon\/Mvc\/Controller.zep",
        "line": 55,
        "char": 8
    },
    {
        "type": "class",
        "name": "Controller",
        "abstract": 1,
        "final": 0,
        "extends": "Injectable",
        "implements": [
            {
                "type": "variable",
                "value": "ControllerInterface",
                "file": "\/app\/phalcon\/Mvc\/Controller.zep",
                "line": 56,
                "char": 1
            }
        ],
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "__construct",
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
                                            "file": "\/app\/phalcon\/Mvc\/Controller.zep",
                                            "line": 62,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Controller.zep",
                                        "line": 62,
                                        "char": 30
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "onConstruct",
                                            "file": "\/app\/phalcon\/Mvc\/Controller.zep",
                                            "line": 62,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Mvc\/Controller.zep",
                                        "line": 62,
                                        "char": 43
                                    }
                                ],
                                "file": "\/app\/phalcon\/Mvc\/Controller.zep",
                                "line": 62,
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
                                            "file": "\/app\/phalcon\/Mvc\/Controller.zep",
                                            "line": 63,
                                            "char": 18
                                        },
                                        "name": "onConstruct",
                                        "call-type": 3,
                                        "file": "\/app\/phalcon\/Mvc\/Controller.zep",
                                        "line": 63,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Mvc\/Controller.zep",
                                    "line": 64,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Mvc\/Controller.zep",
                            "line": 65,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Mvc\\Controller constructor\n     *",
                    "file": "\/app\/phalcon\/Mvc\/Controller.zep",
                    "line": 60,
                    "last-line": 66,
                    "char": 25
                }
            ],
            "file": "\/app\/phalcon\/Mvc\/Controller.zep",
            "line": 55,
            "char": 14
        },
        "file": "\/app\/phalcon\/Mvc\/Controller.zep",
        "line": 55,
        "char": 14
    }
]