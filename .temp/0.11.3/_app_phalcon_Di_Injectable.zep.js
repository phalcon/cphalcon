[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Di\/Injectable.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Di",
        "file": "\/app\/phalcon\/Di\/Injectable.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di",
                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                "line": 13,
                "char": 15
            }
        ],
        "file": "\/app\/phalcon\/Di\/Injectable.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                "line": 14,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Di\/Injectable.zep",
        "line": 15,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\ManagerInterface",
                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                "line": 15,
                "char": 36
            }
        ],
        "file": "\/app\/phalcon\/Di\/Injectable.zep",
        "line": 16,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\InjectionAwareInterface",
                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                "line": 16,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Di\/Injectable.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Events\\EventsAwareInterface",
                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                "line": 17,
                "char": 40
            }
        ],
        "file": "\/app\/phalcon\/Di\/Injectable.zep",
        "line": 18,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Di\\Exception",
                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                "line": 18,
                "char": 25
            }
        ],
        "file": "\/app\/phalcon\/Di\/Injectable.zep",
        "line": 19,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Session\\BagInterface",
                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                "line": 19,
                "char": 33
            }
        ],
        "file": "\/app\/phalcon\/Di\/Injectable.zep",
        "line": 49,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * This class allows to access services in the services container by just only\n * accessing a public property with the same name of a registered service\n *\n * @property \\Phalcon\\Mvc\\Dispatcher|\\Phalcon\\Mvc\\DispatcherInterface $dispatcher\n * @property \\Phalcon\\Mvc\\Router|\\Phalcon\\Mvc\\RouterInterface $router\n * @property \\Phalcon\\Url|\\Phalcon\\UrlInterface $url\n * @property \\Phalcon\\Http\\Request|\\Phalcon\\Http\\RequestInterface $request\n * @property \\Phalcon\\Http\\Response|\\Phalcon\\Http\\ResponseInterface $response\n * @property \\Phalcon\\Http\\Response\\Cookies|\\Phalcon\\Http\\Response\\CookiesInterface $cookies\n * @property \\Phalcon\\Filter\\FilterLocator $filter\n * @property \\Phalcon\\Flash\\Direct $flash\n * @property \\Phalcon\\Flash\\Session $flashSession\n * @property \\Phalcon\\Session\\ManagerInterface $session\n * @property \\Phalcon\\Events\\Manager|\\Phalcon\\Events\\ManagerInterface $eventsManager\n * @property \\Phalcon\\Db\\AdapterInterface $db\n * @property \\Phalcon\\Security $security\n * @property \\Phalcon\\Crypt|\\Phalcon\\CryptInterface $crypt\n * @property \\Phalcon\\Tag $tag\n * @property \\Phalcon\\Escaper|\\Phalcon\\EscaperInterface $escaper\n * @property \\Phalcon\\Annotations\\Adapter\\Memory|\\Phalcon\\Annotations\\Adapter $annotations\n * @property \\Phalcon\\Mvc\\Model\\Manager|\\Phalcon\\Mvc\\Model\\ManagerInterface $modelsManager\n * @property \\Phalcon\\Mvc\\Model\\MetaData\\Memory|\\Phalcon\\Mvc\\Model\\MetadataInterface $modelsMetadata\n * @property \\Phalcon\\Mvc\\Model\\Transaction\\Manager|\\Phalcon\\Mvc\\Model\\Transaction\\ManagerInterface $transactionManager\n * @property \\Phalcon\\Assets\\Manager $assets\n * @property \\Phalcon\\Di|\\Phalcon\\DiInterface $di\n * @property \\Phalcon\\Session\\Bag|\\Phalcon\\Session\\BagInterface $persistent\n * @property \\Phalcon\\Mvc\\View|\\Phalcon\\Mvc\\ViewInterface $view\n *",
        "file": "\/app\/phalcon\/Di\/Injectable.zep",
        "line": 50,
        "char": 8
    },
    {
        "type": "class",
        "name": "Injectable",
        "abstract": 1,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "InjectionAwareInterface",
                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                "line": 50,
                "char": 61
            },
            {
                "type": "variable",
                "value": "EventsAwareInterface",
                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                "line": 51,
                "char": 1
            }
        ],
        "definition": {
            "properties": [
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "container",
                    "docblock": "**\n     * Dependency Injector\n     *\n     * @var DiInterface\n     *",
                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                    "line": 63,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "eventsManager",
                    "docblock": "**\n     * Events Manager\n     *\n     * @var \\Phalcon\\Events\\ManagerInterface\n     *",
                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                    "line": 68,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__get",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "propertyName",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                            "line": 69,
                            "char": 47
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 71,
                                    "char": 22
                                },
                                {
                                    "variable": "service",
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 71,
                                    "char": 31
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                            "line": 73,
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
                                        "type": "type-hint",
                                        "left": {
                                            "type": "variable",
                                            "value": "DiInterface",
                                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                            "line": 73,
                                            "char": 54
                                        },
                                        "right": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                "line": 73,
                                                "char": 44
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "container",
                                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                "line": 73,
                                                "char": 54
                                            },
                                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                            "line": 73,
                                            "char": 54
                                        },
                                        "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                        "line": 73,
                                        "char": 54
                                    },
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 73,
                                    "char": 54
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                            "line": 75,
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
                                        "value": "container",
                                        "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                        "line": 75,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 75,
                                    "char": 30
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 75,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
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
                                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                "line": 76,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                            "line": 76,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 78,
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
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                    "line": 78,
                                                    "char": 43
                                                },
                                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                "line": 78,
                                                "char": 43
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "object",
                                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                "line": 78,
                                                "char": 52
                                            },
                                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                            "line": 78,
                                            "char": 52
                                        },
                                        "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                        "line": 78,
                                        "char": 52
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
                                                                        "value": "internal services",
                                                                        "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                                        "line": 80,
                                                                        "char": 74
                                                                    },
                                                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                                    "line": 80,
                                                                    "char": 74
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                            "line": 81,
                                                            "char": 17
                                                        },
                                                        "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                        "line": 81,
                                                        "char": 17
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                "line": 81,
                                                "char": 18
                                            },
                                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                            "line": 82,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 83,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                            "line": 88,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "container",
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 88,
                                    "char": 22
                                },
                                "name": "has",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "propertyName",
                                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                            "line": 88,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                        "line": 88,
                                        "char": 39
                                    }
                                ],
                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                "line": 88,
                                "char": 41
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "service",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "container",
                                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                    "line": 89,
                                                    "char": 37
                                                },
                                                "name": "getShared",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "propertyName",
                                                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                            "line": 89,
                                                            "char": 60
                                                        },
                                                        "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                        "line": 89,
                                                        "char": 60
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                "line": 89,
                                                "char": 61
                                            },
                                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                            "line": 89,
                                            "char": 61
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 90,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable-dynamic-object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "propertyName",
                                            "expr": {
                                                "type": "variable",
                                                "value": "service",
                                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                "line": 90,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                            "line": 90,
                                            "char": 47
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 92,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "service",
                                        "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                        "line": 92,
                                        "char": 27
                                    },
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 93,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                            "line": 95,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "variable",
                                    "value": "propertyName",
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 95,
                                    "char": 26
                                },
                                "right": {
                                    "type": "string",
                                    "value": "di",
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 95,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                "line": 95,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "string-dynamic-object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "di",
                                            "expr": {
                                                "type": "variable",
                                                "value": "container",
                                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                "line": 96,
                                                "char": 39
                                            },
                                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                            "line": 96,
                                            "char": 39
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 98,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "variable",
                                        "value": "container",
                                        "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                        "line": 98,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 99,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                            "line": 104,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "variable",
                                    "value": "propertyName",
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 104,
                                    "char": 26
                                },
                                "right": {
                                    "type": "string",
                                    "value": "persistent",
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 104,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                "line": 104,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "string-dynamic-object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "persistent",
                                            "expr": {
                                                "type": "type-hint",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "BagInterface",
                                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                    "line": 110,
                                                    "char": 14
                                                },
                                                "right": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "container",
                                                        "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                        "line": 105,
                                                        "char": 63
                                                    },
                                                    "name": "get",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "sessionBag",
                                                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                                "line": 106,
                                                                "char": 27
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                            "line": 106,
                                                            "char": 27
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "array",
                                                                "left": [
                                                                    {
                                                                        "value": {
                                                                            "type": "fcall",
                                                                            "name": "get_class",
                                                                            "call-type": 1,
                                                                            "parameters": [
                                                                                {
                                                                                    "parameter": {
                                                                                        "type": "variable",
                                                                                        "value": "this",
                                                                                        "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                                                        "line": 108,
                                                                                        "char": 35
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                                                    "line": 108,
                                                                                    "char": 35
                                                                                }
                                                                            ],
                                                                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                                            "line": 109,
                                                                            "char": 17
                                                                        },
                                                                        "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                                        "line": 109,
                                                                        "char": 17
                                                                    }
                                                                ],
                                                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                                "line": 110,
                                                                "char": 13
                                                            },
                                                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                            "line": 110,
                                                            "char": 13
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                    "line": 110,
                                                    "char": 14
                                                },
                                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                "line": 110,
                                                "char": 14
                                            },
                                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                            "line": 110,
                                            "char": 14
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 112,
                                    "char": 18
                                },
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "property-string-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                            "line": 112,
                                            "char": 25
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "persistent",
                                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                            "line": 112,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                        "line": 112,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 113,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                            "line": 118,
                            "char": 21
                        },
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
                                                "type": "string",
                                                "value": "Access to undefined property ",
                                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                "line": 118,
                                                "char": 53
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "propertyName",
                                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                "line": 118,
                                                "char": 67
                                            },
                                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                            "line": 118,
                                            "char": 67
                                        },
                                        "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                        "line": 118,
                                        "char": 67
                                    }
                                ],
                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                "line": 118,
                                "char": 68
                            },
                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                            "line": 120,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                "line": 120,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                            "line": 121,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Magic method __get\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                "line": 69,
                                "char": 56
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                "line": 70,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di\/Injectable.zep",
                        "line": 70,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                    "line": 69,
                    "last-line": 125,
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
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "container",
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 128,
                                    "char": 22
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                            "line": 130,
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
                                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                            "line": 130,
                                            "char": 30
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "container",
                                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                            "line": 130,
                                            "char": 40
                                        },
                                        "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                        "line": 130,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 130,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                            "line": 132,
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
                                        "value": "container",
                                        "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                        "line": 132,
                                        "char": 30
                                    },
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 132,
                                    "char": 30
                                },
                                "right": {
                                    "type": "string",
                                    "value": "object",
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 132,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                "line": 132,
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
                                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                                "line": 133,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                            "line": 133,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 134,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                            "line": 136,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "container",
                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                "line": 136,
                                "char": 25
                            },
                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                            "line": 137,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the internal dependency injector\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "DiInterface",
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 127,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                "line": 127,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di\/Injectable.zep",
                        "line": 127,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                    "line": 126,
                    "last-line": 141,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getEventsManager",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 144,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "eventsManager",
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 144,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                "line": 144,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                            "line": 145,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the internal event manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "ManagerInterface",
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 143,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                "line": 143,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Di\/Injectable.zep",
                        "line": 143,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                    "line": 142,
                    "last-line": 149,
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
                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                "line": 150,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                            "line": 150,
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
                                        "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                        "line": 152,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 152,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                            "line": 153,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the dependency injector\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Di\/Injectable.zep",
                        "line": 151,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                    "line": 150,
                    "last-line": 157,
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
                                "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                "line": 158,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                            "line": 158,
                            "char": 70
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
                                    "property": "eventsManager",
                                    "expr": {
                                        "type": "variable",
                                        "value": "eventsManager",
                                        "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                        "line": 160,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                                    "line": 160,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Di\/Injectable.zep",
                            "line": 161,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Sets the event manager\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Di\/Injectable.zep",
                        "line": 159,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Di\/Injectable.zep",
                    "line": 158,
                    "last-line": 162,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Di\/Injectable.zep",
            "line": 50,
            "char": 14
        },
        "file": "\/app\/phalcon\/Di\/Injectable.zep",
        "line": 50,
        "char": 14
    }
]