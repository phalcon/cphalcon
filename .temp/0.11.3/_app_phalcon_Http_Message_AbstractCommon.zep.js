[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *\n * Implementation of this file has been influenced by Zend Diactoros\n * @link    https:\/\/github.com\/zendframework\/zend-diactoros\n * @license https:\/\/github.com\/zendframework\/zend-diactoros\/blob\/master\/LICENSE.md\n *",
        "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
        "line": 15,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Http\\Message",
        "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
        "line": 17,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Message\\Exception\\InvalidArgumentException",
                "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                "line": 17,
                "char": 60
            }
        ],
        "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
        "line": 21,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Common methods\n *",
        "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
        "line": 22,
        "char": 8
    },
    {
        "type": "class",
        "name": "AbstractCommon",
        "abstract": 1,
        "final": 0,
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "cloneInstance",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "element",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                            "line": 32,
                            "char": 55
                        },
                        {
                            "type": "parameter",
                            "name": "property",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                            "line": 32,
                            "char": 72
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "newInstance",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                                    "line": 34,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                            "line": 36,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "newInstance",
                                    "expr": {
                                        "type": "clone",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                                            "line": 36,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                                        "line": 36,
                                        "char": 49
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                                    "line": 36,
                                    "char": 49
                                },
                                {
                                    "assign-type": "variable-dynamic-object-property",
                                    "operator": "assign",
                                    "variable": "newInstance",
                                    "property": "property",
                                    "expr": {
                                        "type": "variable",
                                        "value": "element",
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                                        "line": 37,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                                    "line": 37,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                            "line": 39,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "newInstance",
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                                "line": 39,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                            "line": 40,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns a new instance having set the parameter\n     *\n     * @param mixed  $element\n     * @param string $property\n     *\n     * @return mixed\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "object",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                                "line": 33,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                        "line": 33,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                    "line": 32,
                    "last-line": 46,
                    "char": 28
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "checkStringParameter",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "element",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                            "line": 47,
                            "char": 58
                        }
                    ],
                    "statements": [
                        {
                            "type": "if",
                            "expr": {
                                "type": "not-identical",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "element",
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                                        "line": 49,
                                        "char": 29
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                                    "line": 49,
                                    "char": 29
                                },
                                "right": {
                                    "type": "string",
                                    "value": "string",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                                    "line": 49,
                                    "char": 38
                                },
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                                "line": 49,
                                "char": 38
                            },
                            "statements": [
                                {
                                    "type": "throw",
                                    "expr": {
                                        "type": "new",
                                        "class": "InvalidArgumentException",
                                        "dynamic": 0,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "Method requires a string argument",
                                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                                                    "line": 52,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                                                "line": 52,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                                        "line": 52,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                                    "line": 53,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                            "line": 54,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks the element passed if it is a string\n     *\n     * @param mixed $element\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                        "line": 48,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                    "line": 47,
                    "last-line": 64,
                    "char": 28
                },
                {
                    "visibility": [
                        "final",
                        "protected"
                    ],
                    "type": "method",
                    "name": "processWith",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "element",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                            "line": 65,
                            "char": 53
                        },
                        {
                            "type": "parameter",
                            "name": "property",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                            "line": 65,
                            "char": 70
                        }
                    ],
                    "statements": [
                        {
                            "type": "mcall",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                                    "line": 67,
                                    "char": 14
                                },
                                "name": "checkStringParameter",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "element",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                                            "line": 67,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                                        "line": 67,
                                        "char": 43
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                                "line": 67,
                                "char": 44
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                            "line": 69,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                                    "line": 69,
                                    "char": 21
                                },
                                "name": "cloneInstance",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "element",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                                            "line": 69,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                                        "line": 69,
                                        "char": 43
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "property",
                                            "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                                            "line": 69,
                                            "char": 53
                                        },
                                        "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                                        "line": 69,
                                        "char": 53
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                                "line": 69,
                                "char": 54
                            },
                            "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                            "line": 70,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks the element passed; assigns it to the property and returns a\n     * clone of the object back\n     *\n     * @param mixed  $element\n     * @param string $property\n     *\n     * @return mixed\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "object",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                                "line": 66,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                        "line": 66,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
                    "line": 65,
                    "last-line": 71,
                    "char": 28
                }
            ],
            "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
            "line": 22,
            "char": 14
        },
        "file": "\/app\/phalcon\/Http\/Message\/AbstractCommon.zep",
        "line": 22,
        "char": 14
    }
]