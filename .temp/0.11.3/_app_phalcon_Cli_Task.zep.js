[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Cli\/Task.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Cli",
        "file": "\/app\/phalcon\/Cli\/Task.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\Injectable",
                "file": "\/app\/phalcon\/Cli\/Task.zep",
                "line": 13,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Cli\/Task.zep",
        "line": 38,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Every command-line task should extend this class that encapsulates all the\n * task functionality\n *\n * A task can be used to run \"tasks\" such as migrations, cronjobs, unit-tests,\n * or anything that you want. The Task class should at least have a \"mainAction\"\n * method.\n *\n *```php\n * class HelloTask extends \\Phalcon\\Cli\\Task\n * {\n *     \/\/ This action will be executed by default\n *     public function mainAction()\n *     {\n *\n *     }\n *\n *     public function findAction()\n *     {\n *\n *     }\n * }\n *```\n *",
        "file": "\/app\/phalcon\/Cli\/Task.zep",
        "line": 39,
        "char": 5
    },
    {
        "type": "class",
        "name": "Task",
        "abstract": 0,
        "final": 0,
        "extends": "Injectable",
        "implements": [
            {
                "type": "variable",
                "value": "TaskInterface",
                "file": "\/app\/phalcon\/Cli\/Task.zep",
                "line": 40,
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
                                            "file": "\/app\/phalcon\/Cli\/Task.zep",
                                            "line": 46,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Task.zep",
                                        "line": 46,
                                        "char": 30
                                    },
                                    {
                                        "parameter": {
                                            "type": "string",
                                            "value": "onConstruct",
                                            "file": "\/app\/phalcon\/Cli\/Task.zep",
                                            "line": 46,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Cli\/Task.zep",
                                        "line": 46,
                                        "char": 43
                                    }
                                ],
                                "file": "\/app\/phalcon\/Cli\/Task.zep",
                                "line": 46,
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
                                            "file": "\/app\/phalcon\/Cli\/Task.zep",
                                            "line": 47,
                                            "char": 18
                                        },
                                        "name": "onConstruct",
                                        "call-type": 3,
                                        "file": "\/app\/phalcon\/Cli\/Task.zep",
                                        "line": 47,
                                        "char": 34
                                    },
                                    "file": "\/app\/phalcon\/Cli\/Task.zep",
                                    "line": 48,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Cli\/Task.zep",
                            "line": 49,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Cli\\Task constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Cli\/Task.zep",
                        "line": 45,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Cli\/Task.zep",
                    "line": 44,
                    "last-line": 50,
                    "char": 25
                }
            ],
            "file": "\/app\/phalcon\/Cli\/Task.zep",
            "line": 39,
            "char": 5
        },
        "file": "\/app\/phalcon\/Cli\/Task.zep",
        "line": 39,
        "char": 5
    }
]