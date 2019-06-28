[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Registry.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon",
        "file": "\/app\/phalcon\/Registry.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Collection\\Collection",
                "file": "\/app\/phalcon\/Registry.zep",
                "line": 13,
                "char": 34
            }
        ],
        "file": "\/app\/phalcon\/Registry.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Traversable",
                "file": "\/app\/phalcon\/Registry.zep",
                "line": 14,
                "char": 16
            }
        ],
        "file": "\/app\/phalcon\/Registry.zep",
        "line": 65,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Registry\n *\n * A registry is a container for storing objects and values in the application\n * space. By storing the value in a registry, the same object is always\n * available throughout your application.\n *\n *```php\n * $registry = new \\Phalcon\\Registry();\n *\n * \/\/ Set value\n * $registry->something = \"something\";\n * \/\/ or\n * $registry[\"something\"] = \"something\";\n *\n * \/\/ Get value\n * $value = $registry->something;\n * \/\/ or\n * $value = $registry[\"something\"];\n *\n * \/\/ Check if the key exists\n * $exists = isset($registry->something);\n * \/\/ or\n * $exists = isset($registry[\"something\"]);\n *\n * \/\/ Unset\n * unset($registry->something);\n * \/\/ or\n * unset($registry[\"something\"]);\n *```\n *\n * In addition to ArrayAccess, Phalcon\\Registry also implements Countable\n * (count($registry) will return the number of elements in the registry),\n * Serializable and Iterator (you can iterate over the registry using a foreach\n * loop) interfaces. For PHP 5.4 and higher, JsonSerializable interface is\n * implemented.\n *\n * Phalcon\\Registry is very fast (it is typically faster than any userspace\n * implementation of the registry); however, this comes at a price:\n * Phalcon\\Registry is a final class and cannot be inherited from.\n *\n * Though Phalcon\\Registry exposes methods like __get(), offsetGet(), count() etc,\n * it is not recommended to invoke them manually (these methods exist mainly to\n * match the interfaces the registry implements): $registry->__get(\"property\")\n * is several times slower than $registry->property.\n *\n * Internally all the magic methods (and interfaces except JsonSerializable)\n * are implemented using object handlers or similar techniques: this allows to\n * bypass relatively slow method calls.\n *",
        "file": "\/app\/phalcon\/Registry.zep",
        "line": 66,
        "char": 5
    },
    {
        "type": "class",
        "name": "Registry",
        "abstract": 0,
        "final": 1,
        "extends": "Collection",
        "definition": {
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
                            "name": "data",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 71,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 71,
                            "char": 57
                        }
                    ],
                    "statements": [
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "__construct",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Registry.zep",
                                            "line": 73,
                                            "char": 33
                                        },
                                        "file": "\/app\/phalcon\/Registry.zep",
                                        "line": 73,
                                        "char": 33
                                    }
                                ],
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 73,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 74,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Registry.zep",
                        "line": 72,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Registry.zep",
                    "line": 71,
                    "last-line": 78,
                    "char": 25
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "__get",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "element",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 79,
                            "char": 48
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "get",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "element",
                                            "file": "\/app\/phalcon\/Registry.zep",
                                            "line": 81,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Registry.zep",
                                        "line": 81,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 81,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 82,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Magic getter to get an element from the collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 80,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Registry.zep",
                        "line": 80,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Registry.zep",
                    "line": 79,
                    "last-line": 86,
                    "char": 25
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "__isset",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "element",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 87,
                            "char": 50
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "has",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "element",
                                            "file": "\/app\/phalcon\/Registry.zep",
                                            "line": 89,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Registry.zep",
                                        "line": 89,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 89,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 90,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Magic isset to check whether an element exists or not\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 88,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Registry.zep",
                        "line": 88,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Registry.zep",
                    "line": 87,
                    "last-line": 94,
                    "char": 25
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "__set",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "element",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 95,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 95,
                            "char": 59
                        }
                    ],
                    "statements": [
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "set",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "element",
                                            "file": "\/app\/phalcon\/Registry.zep",
                                            "line": 97,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Registry.zep",
                                        "line": 97,
                                        "char": 28
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Registry.zep",
                                            "line": 97,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Registry.zep",
                                        "line": 97,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 97,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 98,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Magic setter to assign values to an element\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Registry.zep",
                        "line": 96,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Registry.zep",
                    "line": 95,
                    "last-line": 102,
                    "char": 25
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "__unset",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "element",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 103,
                            "char": 50
                        }
                    ],
                    "statements": [
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "remove",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "element",
                                            "file": "\/app\/phalcon\/Registry.zep",
                                            "line": 105,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Registry.zep",
                                        "line": 105,
                                        "char": 31
                                    }
                                ],
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 105,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 106,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Magic unset to remove an element from the collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Registry.zep",
                        "line": 104,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Registry.zep",
                    "line": 103,
                    "last-line": 110,
                    "char": 25
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "clear",
                    "statements": [
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "clear",
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 113,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 114,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Clears the internal collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Registry.zep",
                        "line": 112,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Registry.zep",
                    "line": 111,
                    "last-line": 120,
                    "char": 25
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "count",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "count",
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 123,
                                "char": 31
                            },
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 124,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Count elements of an object\n     *\n     * @link https:\/\/php.net\/manual\/en\/countable.count.php\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 122,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Registry.zep",
                        "line": 122,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Registry.zep",
                    "line": 121,
                    "last-line": 128,
                    "char": 25
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "get",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "element",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 129,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "defaultValue",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 129,
                                "char": 71
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 129,
                            "char": 71
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "get",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "element",
                                            "file": "\/app\/phalcon\/Registry.zep",
                                            "line": 131,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Registry.zep",
                                        "line": 131,
                                        "char": 35
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "defaultValue",
                                            "file": "\/app\/phalcon\/Registry.zep",
                                            "line": 131,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Registry.zep",
                                        "line": 131,
                                        "char": 49
                                    }
                                ],
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 131,
                                "char": 50
                            },
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 132,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Get the element from the collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 130,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Registry.zep",
                        "line": 130,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Registry.zep",
                    "line": 129,
                    "last-line": 136,
                    "char": 25
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "getIterator",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "getIterator",
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 139,
                                "char": 37
                            },
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 140,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the iterator of the class\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "Traversable",
                                    "file": "\/app\/phalcon\/Registry.zep",
                                    "line": 138,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 138,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Registry.zep",
                        "line": 138,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Registry.zep",
                    "line": 137,
                    "last-line": 144,
                    "char": 25
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "has",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "element",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 145,
                            "char": 46
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "has",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "element",
                                            "file": "\/app\/phalcon\/Registry.zep",
                                            "line": 147,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Registry.zep",
                                        "line": 147,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 147,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 148,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Get the element from the collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 146,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Registry.zep",
                        "line": 146,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Registry.zep",
                    "line": 145,
                    "last-line": 152,
                    "char": 25
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "init",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "data",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "default": {
                                "type": "empty-array",
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 153,
                                "char": 48
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 153,
                            "char": 48
                        }
                    ],
                    "statements": [
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "init",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "data",
                                            "file": "\/app\/phalcon\/Registry.zep",
                                            "line": 155,
                                            "char": 26
                                        },
                                        "file": "\/app\/phalcon\/Registry.zep",
                                        "line": 155,
                                        "char": 26
                                    }
                                ],
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 155,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 156,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Initialize internal array\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Registry.zep",
                        "line": 154,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Registry.zep",
                    "line": 153,
                    "last-line": 162,
                    "char": 25
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "jsonSerialize",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "jsonSerialize",
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 165,
                                "char": 39
                            },
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 166,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Specify data which should be serialized to JSON\n     *\n     * @link https:\/\/php.net\/manual\/en\/jsonserializable.jsonserialize.php\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 164,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Registry.zep",
                        "line": 164,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Registry.zep",
                    "line": 163,
                    "last-line": 172,
                    "char": 25
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "offsetExists",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "element",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 173,
                            "char": 51
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "has",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "element",
                                            "file": "\/app\/phalcon\/Registry.zep",
                                            "line": 175,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Registry.zep",
                                        "line": 175,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 175,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 176,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Whether a offset exists\n     *\n     * @link https:\/\/php.net\/manual\/en\/arrayaccess.offsetexists.php\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 174,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Registry.zep",
                        "line": 174,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Registry.zep",
                    "line": 173,
                    "last-line": 182,
                    "char": 25
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "offsetGet",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "element",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 183,
                            "char": 48
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "get",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "element",
                                            "file": "\/app\/phalcon\/Registry.zep",
                                            "line": 185,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Registry.zep",
                                        "line": 185,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 185,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 186,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Offset to retrieve\n     *\n     * @link https:\/\/php.net\/manual\/en\/arrayaccess.offsetget.php\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 184,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Registry.zep",
                        "line": 184,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Registry.zep",
                    "line": 183,
                    "last-line": 192,
                    "char": 25
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "offsetSet",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "element",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 193,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 193,
                            "char": 59
                        }
                    ],
                    "statements": [
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "set",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "element",
                                            "file": "\/app\/phalcon\/Registry.zep",
                                            "line": 195,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Registry.zep",
                                        "line": 195,
                                        "char": 28
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Registry.zep",
                                            "line": 195,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Registry.zep",
                                        "line": 195,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 195,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 196,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Offset to set\n     *\n     * @link https:\/\/php.net\/manual\/en\/arrayaccess.offsetset.php\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Registry.zep",
                        "line": 194,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Registry.zep",
                    "line": 193,
                    "last-line": 202,
                    "char": 25
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "offsetUnset",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "element",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 203,
                            "char": 50
                        }
                    ],
                    "statements": [
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "remove",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "element",
                                            "file": "\/app\/phalcon\/Registry.zep",
                                            "line": 205,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Registry.zep",
                                        "line": 205,
                                        "char": 31
                                    }
                                ],
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 205,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 206,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Offset to unset\n     *\n     * @link https:\/\/php.net\/manual\/en\/arrayaccess.offsetunset.php\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Registry.zep",
                        "line": 204,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Registry.zep",
                    "line": 203,
                    "last-line": 210,
                    "char": 25
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "remove",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "element",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 211,
                            "char": 49
                        }
                    ],
                    "statements": [
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "remove",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "element",
                                            "file": "\/app\/phalcon\/Registry.zep",
                                            "line": 213,
                                            "char": 31
                                        },
                                        "file": "\/app\/phalcon\/Registry.zep",
                                        "line": 213,
                                        "char": 31
                                    }
                                ],
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 213,
                                "char": 32
                            },
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 214,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Delete the element from the collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Registry.zep",
                        "line": 212,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Registry.zep",
                    "line": 211,
                    "last-line": 220,
                    "char": 25
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "serialize",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "serialize",
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 223,
                                "char": 35
                            },
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 224,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * String representation of object\n     *\n     * @link https:\/\/php.net\/manual\/en\/serializable.serialize.php\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 222,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Registry.zep",
                        "line": 222,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Registry.zep",
                    "line": 221,
                    "last-line": 228,
                    "char": 25
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "set",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "element",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 229,
                            "char": 46
                        },
                        {
                            "type": "parameter",
                            "name": "value",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 229,
                            "char": 57
                        }
                    ],
                    "statements": [
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "set",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "element",
                                            "file": "\/app\/phalcon\/Registry.zep",
                                            "line": 231,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Registry.zep",
                                        "line": 231,
                                        "char": 28
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "value",
                                            "file": "\/app\/phalcon\/Registry.zep",
                                            "line": 231,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Registry.zep",
                                        "line": 231,
                                        "char": 35
                                    }
                                ],
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 231,
                                "char": 36
                            },
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 232,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Set an element in the collection\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Registry.zep",
                        "line": 230,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Registry.zep",
                    "line": 229,
                    "last-line": 236,
                    "char": 25
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "toArray",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "toArray",
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 239,
                                "char": 33
                            },
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 240,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the object in an array format\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 238,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Registry.zep",
                        "line": 238,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Registry.zep",
                    "line": 237,
                    "last-line": 250,
                    "char": 25
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "toJson",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "options",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "default": {
                                "type": "int",
                                "value": "79",
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 251,
                                "char": 50
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 251,
                            "char": 50
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "toJson",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "options",
                                            "file": "\/app\/phalcon\/Registry.zep",
                                            "line": 253,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Registry.zep",
                                        "line": 253,
                                        "char": 38
                                    }
                                ],
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 253,
                                "char": 39
                            },
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 254,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the object in a JSON format\n     *\n     * The default string uses the following options for json_encode\n     *\n     * JSON_HEX_TAG, JSON_HEX_APOS, JSON_HEX_AMP, JSON_HEX_QUOT, JSON_UNESCAPED_SLASHES\n     *\n     * @see https:\/\/www.ietf.org\/rfc\/rfc4627.txt\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 252,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Registry.zep",
                        "line": 252,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Registry.zep",
                    "line": 251,
                    "last-line": 260,
                    "char": 25
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "unserialize",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "serialized",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 261,
                            "char": 53
                        }
                    ],
                    "statements": [
                        {
                            "type": "scall",
                            "expr": {
                                "type": "scall",
                                "dynamic-class": 0,
                                "class": "parent",
                                "dynamic": 0,
                                "name": "unserialize",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "serialized",
                                            "file": "\/app\/phalcon\/Registry.zep",
                                            "line": 263,
                                            "char": 39
                                        },
                                        "file": "\/app\/phalcon\/Registry.zep",
                                        "line": 263,
                                        "char": 39
                                    }
                                ],
                                "file": "\/app\/phalcon\/Registry.zep",
                                "line": 263,
                                "char": 40
                            },
                            "file": "\/app\/phalcon\/Registry.zep",
                            "line": 264,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Constructs the object\n     *\n     * @link https:\/\/php.net\/manual\/en\/serializable.unserialize.php\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Registry.zep",
                        "line": 262,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Registry.zep",
                    "line": 261,
                    "last-line": 265,
                    "char": 25
                }
            ],
            "file": "\/app\/phalcon\/Registry.zep",
            "line": 66,
            "char": 11
        },
        "file": "\/app\/phalcon\/Registry.zep",
        "line": 66,
        "char": 11
    }
]