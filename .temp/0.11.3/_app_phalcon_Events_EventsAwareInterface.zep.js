[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Events\/EventsAwareInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Events",
        "file": "\/app\/phalcon\/Events\/EventsAwareInterface.zep",
        "line": 18,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Events\\EventsAwareInterface\n *\n * This interface must for those classes that accept an EventsManager and\n * dispatch events\n *",
        "file": "\/app\/phalcon\/Events\/EventsAwareInterface.zep",
        "line": 19,
        "char": 9
    },
    {
        "type": "interface",
        "name": "EventsAwareInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getEventsManager",
                    "docblock": "**\n     * Returns the internal event manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ManagerInterface",
                                    "file": "\/app\/phalcon\/Events\/EventsAwareInterface.zep",
                                    "line": 24,
                                    "char": 61
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Events\/EventsAwareInterface.zep",
                                "line": 24,
                                "char": 61
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Events\/EventsAwareInterface.zep",
                        "line": 24,
                        "char": 61
                    },
                    "file": "\/app\/phalcon\/Events\/EventsAwareInterface.zep",
                    "line": 24,
                    "last-line": 28,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
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
                                "file": "\/app\/phalcon\/Events\/EventsAwareInterface.zep",
                                "line": 29,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Events\/EventsAwareInterface.zep",
                            "line": 29,
                            "char": 70
                        }
                    ],
                    "docblock": "**\n     * Sets the events manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Events\/EventsAwareInterface.zep",
                        "line": 29,
                        "char": 79
                    },
                    "file": "\/app\/phalcon\/Events\/EventsAwareInterface.zep",
                    "line": 29,
                    "last-line": 30,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Events\/EventsAwareInterface.zep",
            "line": 30,
            "char": 1
        },
        "file": "\/app\/phalcon\/Events\/EventsAwareInterface.zep",
        "line": 0,
        "char": 0
    }
]