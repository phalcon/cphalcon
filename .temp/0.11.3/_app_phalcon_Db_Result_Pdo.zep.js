[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Db\\Result",
        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db",
                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                "line": 13,
                "char": 15
            }
        ],
        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Db\\ResultInterface",
                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                "line": 14,
                "char": 31
            }
        ],
        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
        "line": 17,
        "char": 36
    },
    {
        "type": "cblock",
        "value": "\n#include <ext\/pdo\/php_pdo_driver.h>\n",
        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
        "line": 33,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Encapsulates the resultset internals\n *\n * ```php\n * $result = $connection->query(\"SELECT * FROM robots ORDER BY name\");\n *\n * $result->setFetchMode(\n *     \\Phalcon\\Db::FETCH_NUM\n * );\n *\n * while ($robot = $result->fetchArray()) {\n *     print_r($robot);\n * }\n * ```\n *",
        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
        "line": 34,
        "char": 5
    },
    {
        "type": "class",
        "name": "Pdo",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "ResultInterface",
                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                "line": 35,
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
                    "name": "bindParams",
                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                    "line": 38,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "bindTypes",
                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                    "line": 40,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "connection",
                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                    "line": 44,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "fetchMode",
                    "default": {
                        "type": "static-constant-access",
                        "left": {
                            "type": "variable",
                            "value": "Db",
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 45,
                            "char": 40
                        },
                        "right": {
                            "type": "variable",
                            "value": "FETCH_OBJ",
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 45,
                            "char": 40
                        },
                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                        "line": 45,
                        "char": 40
                    },
                    "docblock": "**\n     * Active fetch mode\n     *",
                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                    "line": 51,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "pdoStatement",
                    "docblock": "**\n     * Internal resultset\n     *\n     * @var \\PDOStatement\n     *",
                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                    "line": 54,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "result",
                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                    "line": 56,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "rowCount",
                    "default": {
                        "type": "bool",
                        "value": "false",
                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                        "line": 56,
                        "char": 31
                    },
                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                    "line": 58,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "sqlStatement",
                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                    "line": 62,
                    "char": 6
                }
            ],
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "__construct",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "connection",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "Db\\AdapterInterface",
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 63,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 63,
                            "char": 65
                        },
                        {
                            "type": "parameter",
                            "name": "result",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "\\PDOStatement",
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 63,
                                "char": 88
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 63,
                            "char": 89
                        },
                        {
                            "type": "parameter",
                            "name": "sqlStatement",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 64,
                                "char": 28
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 64,
                            "char": 28
                        },
                        {
                            "type": "parameter",
                            "name": "bindParams",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 64,
                                "char": 47
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 64,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "bindTypes",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 64,
                                "char": 65
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 64,
                            "char": 65
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
                                    "property": "connection",
                                    "expr": {
                                        "type": "variable",
                                        "value": "connection",
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 66,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 66,
                                    "char": 42
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "pdoStatement",
                                    "expr": {
                                        "type": "variable",
                                        "value": "result",
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 67,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 67,
                                    "char": 40
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "sqlStatement",
                                    "expr": {
                                        "type": "variable",
                                        "value": "sqlStatement",
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 68,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 68,
                                    "char": 46
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "bindParams",
                                    "expr": {
                                        "type": "variable",
                                        "value": "bindParams",
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 69,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 69,
                                    "char": 42
                                },
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "bindTypes",
                                    "expr": {
                                        "type": "variable",
                                        "value": "bindTypes",
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 70,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 70,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 71,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Db\\Result\\Pdo constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                        "line": 65,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                    "line": 63,
                    "last-line": 88,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "dataSeek",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "number",
                            "const": 0,
                            "data-type": "long",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 89,
                            "char": 41
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "connection",
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 91,
                                    "char": 23
                                },
                                {
                                    "variable": "pdo",
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 91,
                                    "char": 28
                                },
                                {
                                    "variable": "sqlStatement",
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 91,
                                    "char": 42
                                },
                                {
                                    "variable": "bindParams",
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 91,
                                    "char": 54
                                },
                                {
                                    "variable": "statement",
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 91,
                                    "char": 65
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 92,
                            "char": 12
                        },
                        {
                            "type": "declare",
                            "data-type": "long",
                            "variables": [
                                {
                                    "variable": "n",
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 92,
                                    "char": 15
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 94,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "connection",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 94,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "connection",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 94,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 94,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 94,
                                    "char": 42
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "pdo",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "connection",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 95,
                                            "char": 30
                                        },
                                        "name": "getInternalHandler",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 95,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 95,
                                    "char": 51
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "sqlStatement",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 96,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "sqlStatement",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 96,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 96,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 96,
                                    "char": 46
                                },
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "bindParams",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 97,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "bindParams",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 97,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 97,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 97,
                                    "char": 42
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 103,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "typeof",
                                    "left": {
                                        "type": "variable",
                                        "value": "bindParams",
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 103,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 103,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "array",
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 103,
                                    "char": 39
                                },
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 103,
                                "char": 39
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "statement",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "pdo",
                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                    "line": 104,
                                                    "char": 33
                                                },
                                                "name": "prepare",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "sqlStatement",
                                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                            "line": 104,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                        "line": 104,
                                                        "char": 54
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                "line": 104,
                                                "char": 55
                                            },
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 104,
                                            "char": 55
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 106,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "typeof",
                                            "left": {
                                                "type": "variable",
                                                "value": "statement",
                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                "line": 106,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 106,
                                            "char": 34
                                        },
                                        "right": {
                                            "type": "string",
                                            "value": "object",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 106,
                                            "char": 43
                                        },
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 106,
                                        "char": 43
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "statement",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "connection",
                                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                            "line": 107,
                                                            "char": 44
                                                        },
                                                        "name": "executePrepared",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "statement",
                                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                    "line": 108,
                                                                    "char": 30
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                "line": 108,
                                                                "char": 30
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "bindParams",
                                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                    "line": 109,
                                                                    "char": 31
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                "line": 109,
                                                                "char": 31
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "property-access",
                                                                    "left": {
                                                                        "type": "variable",
                                                                        "value": "this",
                                                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                        "line": 110,
                                                                        "char": 26
                                                                    },
                                                                    "right": {
                                                                        "type": "variable",
                                                                        "value": "bindTypes",
                                                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                        "line": 111,
                                                                        "char": 17
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                    "line": 111,
                                                                    "char": 17
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                "line": 111,
                                                                "char": 17
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                        "line": 111,
                                                        "char": 18
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                    "line": 111,
                                                    "char": 18
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 112,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 113,
                                    "char": 9
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "statement",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "pdo",
                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                    "line": 114,
                                                    "char": 33
                                                },
                                                "name": "query",
                                                "call-type": 1,
                                                "parameters": [
                                                    {
                                                        "parameter": {
                                                            "type": "variable",
                                                            "value": "sqlStatement",
                                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                            "line": 114,
                                                            "char": 52
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                        "line": 114,
                                                        "char": 52
                                                    }
                                                ],
                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                "line": 114,
                                                "char": 53
                                            },
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 114,
                                            "char": 53
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 115,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 117,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "pdoStatement",
                                    "expr": {
                                        "type": "variable",
                                        "value": "statement",
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 117,
                                        "char": 43
                                    },
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 117,
                                    "char": 43
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 119,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "n",
                                    "expr": {
                                        "type": "int",
                                        "value": "-1",
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 119,
                                        "char": 19
                                    },
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 119,
                                    "char": 19
                                },
                                {
                                    "assign-type": "decr",
                                    "variable": "number",
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 120,
                                    "char": 21
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 122,
                            "char": 13
                        },
                        {
                            "type": "while",
                            "expr": {
                                "type": "not-equals",
                                "left": {
                                    "type": "variable",
                                    "value": "n",
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 122,
                                    "char": 18
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "number",
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 122,
                                    "char": 27
                                },
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 122,
                                "char": 27
                            },
                            "statements": [
                                {
                                    "type": "mcall",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "statement",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 123,
                                            "char": 23
                                        },
                                        "name": "fetch",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 123,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 125,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "incr",
                                            "variable": "n",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 125,
                                            "char": 20
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 126,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 127,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Moves internal resultset cursor to another position letting us to fetch a\n     * certain row\n     *\n     *```php\n     * $result = $connection->query(\n     *     \"SELECT * FROM robots ORDER BY name\"\n     * );\n     *\n     * \/\/ Move to third row on result\n     * $result->dataSeek(2);\n     *\n     * \/\/ Fetch third row\n     * $row = $result->fetch();\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                        "line": 90,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                    "line": 89,
                    "last-line": 133,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "execute",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 136,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "pdoStatement",
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 136,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 136,
                                    "char": 35
                                },
                                "name": "execute",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 136,
                                "char": 45
                            },
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 137,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Allows to execute the statement again. Some database systems don't\n     * support scrollable cursors. So, as cursors are forward only, we need to\n     * execute the cursor again to fetch rows from the begining\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 135,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                        "line": 135,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                    "line": 134,
                    "last-line": 155,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "fetch",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "fetchStyle",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 156,
                                "char": 48
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 156,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "cursorOrientation",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 156,
                                "char": 78
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 156,
                            "char": 78
                        },
                        {
                            "type": "parameter",
                            "name": "cursorOffset",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 156,
                                "char": 103
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 156,
                            "char": 103
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 158,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "pdoStatement",
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 158,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 158,
                                    "char": 35
                                },
                                "name": "fetch",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "fetchStyle",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 159,
                                            "char": 23
                                        },
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 159,
                                        "char": 23
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "cursorOrientation",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 160,
                                            "char": 30
                                        },
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 160,
                                        "char": 30
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "cursorOffset",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 162,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 162,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 162,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 163,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Fetches an array\/object of strings that corresponds to the fetched row,\n     * or FALSE if there are no more rows. This method is affected by the active\n     * fetch flag set using `Phalcon\\Db\\Result\\Pdo::setFetchMode()`\n     *\n     *```php\n     * $result = $connection->query(\"SELECT * FROM robots ORDER BY name\");\n     *\n     * $result->setFetchMode(\n     *     \\Phalcon\\Db::FETCH_OBJ\n     * );\n     *\n     * while ($robot = $result->fetch()) {\n     *     echo $robot->name;\n     * }\n     *```\n     *",
                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                    "line": 156,
                    "last-line": 177,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "fetchAll",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "fetchStyle",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 178,
                                "char": 51
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 178,
                            "char": 51
                        },
                        {
                            "type": "parameter",
                            "name": "fetchArgument",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 178,
                                "char": 77
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 178,
                            "char": 77
                        },
                        {
                            "type": "parameter",
                            "name": "ctorArgs",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 178,
                                "char": 98
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 178,
                            "char": 98
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "pdoStatement",
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 180,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 182,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "pdoStatement",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 182,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "pdoStatement",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 182,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 182,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 182,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 184,
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
                                        "value": "fetchStyle",
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 184,
                                        "char": 31
                                    },
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 184,
                                    "char": 31
                                },
                                "right": {
                                    "type": "string",
                                    "value": "integer",
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 184,
                                    "char": 41
                                },
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 184,
                                "char": 41
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "pdoStatement",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 185,
                                            "char": 33
                                        },
                                        "name": "fetchAll",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 185,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 186,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 188,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "equals",
                                "left": {
                                    "type": "variable",
                                    "value": "fetchStyle",
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 188,
                                    "char": 24
                                },
                                "right": {
                                    "type": "static-constant-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "Db",
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 188,
                                        "char": 42
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "FETCH_CLASS",
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 188,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 188,
                                    "char": 42
                                },
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 188,
                                "char": 42
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "pdoStatement",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 189,
                                            "char": 33
                                        },
                                        "name": "fetchAll",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "fetchStyle",
                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                    "line": 190,
                                                    "char": 27
                                                },
                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                "line": 190,
                                                "char": 27
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "fetchArgument",
                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                    "line": 191,
                                                    "char": 30
                                                },
                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                "line": 191,
                                                "char": 30
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "ctorArgs",
                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                    "line": 193,
                                                    "char": 13
                                                },
                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                "line": 193,
                                                "char": 13
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 193,
                                        "char": 14
                                    },
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 194,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 196,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "equals",
                                    "left": {
                                        "type": "variable",
                                        "value": "fetchStyle",
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 196,
                                        "char": 24
                                    },
                                    "right": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Db",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 196,
                                            "char": 44
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "FETCH_COLUMN",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 196,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 196,
                                        "char": 44
                                    },
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 196,
                                    "char": 44
                                },
                                "right": {
                                    "type": "equals",
                                    "left": {
                                        "type": "variable",
                                        "value": "fetchStyle",
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 196,
                                        "char": 58
                                    },
                                    "right": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Db",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 196,
                                            "char": 75
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "FETCH_FUNC",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 196,
                                            "char": 75
                                        },
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 196,
                                        "char": 75
                                    },
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 196,
                                    "char": 75
                                },
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 196,
                                "char": 75
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "pdoStatement",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 197,
                                            "char": 33
                                        },
                                        "name": "fetchAll",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "fetchStyle",
                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                    "line": 197,
                                                    "char": 53
                                                },
                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                "line": 197,
                                                "char": 53
                                            },
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "fetchArgument",
                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                    "line": 197,
                                                    "char": 68
                                                },
                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                "line": 197,
                                                "char": 68
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 197,
                                        "char": 69
                                    },
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 198,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 200,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "variable",
                                    "value": "pdoStatement",
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 200,
                                    "char": 29
                                },
                                "name": "fetchAll",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "fetchStyle",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 200,
                                            "char": 49
                                        },
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 200,
                                        "char": 49
                                    }
                                ],
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 200,
                                "char": 50
                            },
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 201,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns an array of arrays containing all the records in the result\n     * This method is affected by the active fetch flag set using\n     * `Phalcon\\Db\\Result\\Pdo::setFetchMode()`\n     *\n     *```php\n     * $result = $connection->query(\n     *     \"SELECT * FROM robots ORDER BY name\"\n     * );\n     *\n     * $robots = $result->fetchAll();\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 179,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                        "line": 179,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                    "line": 178,
                    "last-line": 219,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "fetchArray",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "mcall",
                                "variable": {
                                    "type": "property-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "this",
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 222,
                                        "char": 21
                                    },
                                    "right": {
                                        "type": "variable",
                                        "value": "pdoStatement",
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 222,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 222,
                                    "char": 35
                                },
                                "name": "fetch",
                                "call-type": 1,
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 222,
                                "char": 43
                            },
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 223,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns an array of strings that corresponds to the fetched row, or FALSE\n     * if there are no more rows. This method is affected by the active fetch\n     * flag set using `Phalcon\\Db\\Result\\Pdo::setFetchMode()`\n     *\n     *```php\n     * $result = $connection->query(\"SELECT * FROM robots ORDER BY name\");\n     *\n     * $result->setFetchMode(\n     *     \\Phalcon\\Db::FETCH_NUM\n     * );\n     *\n     * while ($robot = result->fetchArray()) {\n     *     print_r($robot);\n     * }\n     *```\n     *",
                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                    "line": 220,
                    "last-line": 227,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getInternalResult",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 230,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "pdoStatement",
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 230,
                                    "char": 34
                                },
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 230,
                                "char": 34
                            },
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 231,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets the internal PDO result object\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "\\PDOStatement",
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 229,
                                    "char": 5
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 229,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                        "line": 229,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                    "line": 228,
                    "last-line": 243,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "numRows",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "sqlStatement",
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 246,
                                    "char": 25
                                },
                                {
                                    "variable": "rowCount",
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 246,
                                    "char": 35
                                },
                                {
                                    "variable": "connection",
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 246,
                                    "char": 47
                                },
                                {
                                    "variable": "type",
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 246,
                                    "char": 53
                                },
                                {
                                    "variable": "pdoStatement",
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 246,
                                    "char": 67
                                },
                                {
                                    "variable": "matches",
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 246,
                                    "char": 76
                                },
                                {
                                    "variable": "result",
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 247,
                                    "char": 19
                                },
                                {
                                    "variable": "row",
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 247,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 249,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "rowCount",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 249,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "rowCount",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 249,
                                            "char": 38
                                        },
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 249,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 249,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 251,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "identical",
                                "left": {
                                    "type": "variable",
                                    "value": "rowCount",
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 251,
                                    "char": 23
                                },
                                "right": {
                                    "type": "bool",
                                    "value": "false",
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 251,
                                    "char": 31
                                },
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 251,
                                "char": 31
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "connection",
                                            "expr": {
                                                "type": "property-access",
                                                "left": {
                                                    "type": "variable",
                                                    "value": "this",
                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                    "line": 252,
                                                    "char": 35
                                                },
                                                "right": {
                                                    "type": "variable",
                                                    "value": "connection",
                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                    "line": 252,
                                                    "char": 46
                                                },
                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                "line": 252,
                                                "char": 46
                                            },
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 252,
                                            "char": 46
                                        },
                                        {
                                            "assign-type": "variable",
                                            "operator": "assign",
                                            "variable": "type",
                                            "expr": {
                                                "type": "mcall",
                                                "variable": {
                                                    "type": "variable",
                                                    "value": "connection",
                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                    "line": 253,
                                                    "char": 35
                                                },
                                                "name": "getType",
                                                "call-type": 1,
                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                "line": 253,
                                                "char": 45
                                            },
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 253,
                                            "char": 45
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 258,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "or",
                                        "left": {
                                            "type": "equals",
                                            "left": {
                                                "type": "variable",
                                                "value": "type",
                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                "line": 258,
                                                "char": 22
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "mysql",
                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                "line": 258,
                                                "char": 31
                                            },
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 258,
                                            "char": 31
                                        },
                                        "right": {
                                            "type": "equals",
                                            "left": {
                                                "type": "variable",
                                                "value": "type",
                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                "line": 258,
                                                "char": 39
                                            },
                                            "right": {
                                                "type": "string",
                                                "value": "pgsql",
                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                "line": 258,
                                                "char": 47
                                            },
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 258,
                                            "char": 47
                                        },
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 258,
                                        "char": 47
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "pdoStatement",
                                                    "expr": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                            "line": 259,
                                                            "char": 41
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "pdoStatement",
                                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                            "line": 259,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                        "line": 259,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                    "line": 259,
                                                    "char": 54
                                                },
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "rowCount",
                                                    "expr": {
                                                        "type": "mcall",
                                                        "variable": {
                                                            "type": "variable",
                                                            "value": "pdoStatement",
                                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                            "line": 260,
                                                            "char": 45
                                                        },
                                                        "name": "rowCount",
                                                        "call-type": 1,
                                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                        "line": 260,
                                                        "char": 56
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                    "line": 260,
                                                    "char": 56
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 261,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 266,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "identical",
                                        "left": {
                                            "type": "variable",
                                            "value": "rowCount",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 266,
                                            "char": 27
                                        },
                                        "right": {
                                            "type": "bool",
                                            "value": "false",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 266,
                                            "char": 35
                                        },
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 266,
                                        "char": 35
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "variable",
                                                    "operator": "assign",
                                                    "variable": "sqlStatement",
                                                    "expr": {
                                                        "type": "property-access",
                                                        "left": {
                                                            "type": "variable",
                                                            "value": "this",
                                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                            "line": 272,
                                                            "char": 41
                                                        },
                                                        "right": {
                                                            "type": "variable",
                                                            "value": "sqlStatement",
                                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                            "line": 272,
                                                            "char": 54
                                                        },
                                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                        "line": 272,
                                                        "char": 54
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                    "line": 272,
                                                    "char": 54
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 278,
                                            "char": 18
                                        },
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not",
                                                "left": {
                                                    "type": "fcall",
                                                    "name": "starts_with",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "sqlStatement",
                                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                "line": 278,
                                                                "char": 45
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                            "line": 278,
                                                            "char": 45
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "string",
                                                                "value": "SELECT COUNT(*) ",
                                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                "line": 278,
                                                                "char": 63
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                            "line": 278,
                                                            "char": 63
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                    "line": 278,
                                                    "char": 65
                                                },
                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                "line": 278,
                                                "char": 65
                                            },
                                            "statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "matches",
                                                            "expr": {
                                                                "type": "null",
                                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                "line": 279,
                                                                "char": 39
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                            "line": 279,
                                                            "char": 39
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                    "line": 281,
                                                    "char": 22
                                                },
                                                {
                                                    "type": "if",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "preg_match",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "string",
                                                                    "value": "\/^SELECT\\\\s+(.*)\/i",
                                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                    "line": 281,
                                                                    "char": 53
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                "line": 281,
                                                                "char": 53
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "sqlStatement",
                                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                    "line": 281,
                                                                    "char": 67
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                "line": 281,
                                                                "char": 67
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "matches",
                                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                    "line": 281,
                                                                    "char": 76
                                                                },
                                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                "line": 281,
                                                                "char": 76
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                        "line": 281,
                                                        "char": 78
                                                    },
                                                    "statements": [
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "result",
                                                                    "expr": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "connection",
                                                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                            "line": 282,
                                                                            "char": 49
                                                                        },
                                                                        "name": "query",
                                                                        "call-type": 1,
                                                                        "parameters": [
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "concat",
                                                                                    "left": {
                                                                                        "type": "concat",
                                                                                        "left": {
                                                                                            "type": "string",
                                                                                            "value": "SELECT COUNT(*) \\\"numrows\\\" FROM (SELECT ",
                                                                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                                            "line": 283,
                                                                                            "char": 71
                                                                                        },
                                                                                        "right": {
                                                                                            "type": "array-access",
                                                                                            "left": {
                                                                                                "type": "variable",
                                                                                                "value": "matches",
                                                                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                                                "line": 283,
                                                                                                "char": 80
                                                                                            },
                                                                                            "right": {
                                                                                                "type": "int",
                                                                                                "value": "1",
                                                                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                                                "line": 283,
                                                                                                "char": 82
                                                                                            },
                                                                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                                            "line": 283,
                                                                                            "char": 84
                                                                                        },
                                                                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                                        "line": 283,
                                                                                        "char": 84
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "string",
                                                                                        "value": ")",
                                                                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                                        "line": 283,
                                                                                        "char": 87
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                                    "line": 283,
                                                                                    "char": 87
                                                                                },
                                                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                                "line": 283,
                                                                                "char": 87
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "property-access",
                                                                                    "left": {
                                                                                        "type": "variable",
                                                                                        "value": "this",
                                                                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                                        "line": 284,
                                                                                        "char": 34
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "variable",
                                                                                        "value": "bindParams",
                                                                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                                        "line": 284,
                                                                                        "char": 45
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                                    "line": 284,
                                                                                    "char": 45
                                                                                },
                                                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                                "line": 284,
                                                                                "char": 45
                                                                            },
                                                                            {
                                                                                "parameter": {
                                                                                    "type": "property-access",
                                                                                    "left": {
                                                                                        "type": "variable",
                                                                                        "value": "this",
                                                                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                                        "line": 285,
                                                                                        "char": 34
                                                                                    },
                                                                                    "right": {
                                                                                        "type": "variable",
                                                                                        "value": "bindTypes",
                                                                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                                        "line": 286,
                                                                                        "char": 25
                                                                                    },
                                                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                                    "line": 286,
                                                                                    "char": 25
                                                                                },
                                                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                                "line": 286,
                                                                                "char": 25
                                                                            }
                                                                        ],
                                                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                        "line": 286,
                                                                        "char": 26
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                    "line": 286,
                                                                    "char": 26
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                            "line": 288,
                                                            "char": 27
                                                        },
                                                        {
                                                            "type": "let",
                                                            "assignments": [
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "row",
                                                                    "expr": {
                                                                        "type": "mcall",
                                                                        "variable": {
                                                                            "type": "variable",
                                                                            "value": "result",
                                                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                            "line": 288,
                                                                            "char": 42
                                                                        },
                                                                        "name": "fetch",
                                                                        "call-type": 1,
                                                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                        "line": 288,
                                                                        "char": 50
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                    "line": 288,
                                                                    "char": 50
                                                                },
                                                                {
                                                                    "assign-type": "variable",
                                                                    "operator": "assign",
                                                                    "variable": "rowCount",
                                                                    "expr": {
                                                                        "type": "array-access",
                                                                        "left": {
                                                                            "type": "variable",
                                                                            "value": "row",
                                                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                            "line": 289,
                                                                            "char": 43
                                                                        },
                                                                        "right": {
                                                                            "type": "string",
                                                                            "value": "numrows",
                                                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                            "line": 289,
                                                                            "char": 51
                                                                        },
                                                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                        "line": 289,
                                                                        "char": 52
                                                                    },
                                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                    "line": 289,
                                                                    "char": 52
                                                                }
                                                            ],
                                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                            "line": 290,
                                                            "char": 21
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                    "line": 291,
                                                    "char": 17
                                                }
                                            ],
                                            "else_statements": [
                                                {
                                                    "type": "let",
                                                    "assignments": [
                                                        {
                                                            "assign-type": "variable",
                                                            "operator": "assign",
                                                            "variable": "rowCount",
                                                            "expr": {
                                                                "type": "int",
                                                                "value": "1",
                                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                "line": 292,
                                                                "char": 37
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                            "line": 292,
                                                            "char": 37
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                    "line": 293,
                                                    "char": 17
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 294,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 299,
                                    "char": 15
                                },
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "rowCount",
                                            "expr": {
                                                "type": "variable",
                                                "value": "rowCount",
                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                "line": 299,
                                                "char": 42
                                            },
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 299,
                                            "char": 42
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 300,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 302,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "rowCount",
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 302,
                                "char": 24
                            },
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 303,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets number of rows returned by a resultset\n     *\n     *```php\n     * $result = $connection->query(\n     *     \"SELECT * FROM robots ORDER BY name\"\n     * );\n     *\n     * echo \"There are \", $result->numRows(), \" rows in the resultset\";\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 245,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                        "line": 245,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                    "line": 244,
                    "last-line": 329,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "setFetchMode",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "fetchMode",
                            "const": 0,
                            "data-type": "int",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 330,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "colNoOrClassNameOrObject",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 330,
                                "char": 84
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 330,
                            "char": 84
                        },
                        {
                            "type": "parameter",
                            "name": "ctorargs",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 330,
                                "char": 105
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 330,
                            "char": 105
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "pdoStatement",
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 332,
                                    "char": 25
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 334,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "pdoStatement",
                                    "expr": {
                                        "type": "property-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 334,
                                            "char": 33
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "pdoStatement",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 334,
                                            "char": 46
                                        },
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 334,
                                        "char": 46
                                    },
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 334,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 336,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "or",
                                "left": {
                                    "type": "equals",
                                    "left": {
                                        "type": "variable",
                                        "value": "fetchMode",
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 336,
                                        "char": 23
                                    },
                                    "right": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Db",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 336,
                                            "char": 42
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "FETCH_CLASS",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 336,
                                            "char": 42
                                        },
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 336,
                                        "char": 42
                                    },
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 336,
                                    "char": 42
                                },
                                "right": {
                                    "type": "equals",
                                    "left": {
                                        "type": "variable",
                                        "value": "fetchMode",
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 336,
                                        "char": 55
                                    },
                                    "right": {
                                        "type": "static-constant-access",
                                        "left": {
                                            "type": "variable",
                                            "value": "Db",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 336,
                                            "char": 72
                                        },
                                        "right": {
                                            "type": "variable",
                                            "value": "FETCH_INTO",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 336,
                                            "char": 72
                                        },
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 336,
                                        "char": 72
                                    },
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 336,
                                    "char": 72
                                },
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 336,
                                "char": 72
                            },
                            "statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "pdoStatement",
                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                "line": 337,
                                                "char": 30
                                            },
                                            "name": "setFetchMode",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "fetchMode",
                                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                        "line": 337,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                    "line": 337,
                                                    "char": 53
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "colNoOrClassNameOrObject",
                                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                        "line": 337,
                                                        "char": 79
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                    "line": 337,
                                                    "char": 79
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "ctorargs",
                                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                        "line": 337,
                                                        "char": 89
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                    "line": 337,
                                                    "char": 89
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 337,
                                            "char": 91
                                        },
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 337,
                                        "char": 91
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                "line": 338,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 339,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 340,
                                    "char": 9
                                }
                            ],
                            "elseif_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "equals",
                                        "left": {
                                            "type": "variable",
                                            "value": "fetchMode",
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 340,
                                            "char": 29
                                        },
                                        "right": {
                                            "type": "static-constant-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "Db",
                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                "line": 340,
                                                "char": 48
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "FETCH_COLUMN",
                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                "line": 340,
                                                "char": 48
                                            },
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 340,
                                            "char": 48
                                        },
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 340,
                                        "char": 48
                                    },
                                    "statements": [
                                        {
                                            "type": "if",
                                            "expr": {
                                                "type": "not",
                                                "left": {
                                                    "type": "mcall",
                                                    "variable": {
                                                        "type": "variable",
                                                        "value": "pdoStatement",
                                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                        "line": 341,
                                                        "char": 30
                                                    },
                                                    "name": "setFetchMode",
                                                    "call-type": 1,
                                                    "parameters": [
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "fetchMode",
                                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                "line": 341,
                                                                "char": 53
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                            "line": 341,
                                                            "char": 53
                                                        },
                                                        {
                                                            "parameter": {
                                                                "type": "variable",
                                                                "value": "colNoOrClassNameOrObject",
                                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                                "line": 341,
                                                                "char": 79
                                                            },
                                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                            "line": 341,
                                                            "char": 79
                                                        }
                                                    ],
                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                    "line": 341,
                                                    "char": 81
                                                },
                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                "line": 341,
                                                "char": 81
                                            },
                                            "statements": [
                                                {
                                                    "type": "return",
                                                    "expr": {
                                                        "type": "bool",
                                                        "value": "false",
                                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                        "line": 342,
                                                        "char": 29
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                    "line": 343,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 344,
                                            "char": 9
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 344,
                                    "char": 14
                                }
                            ],
                            "else_statements": [
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "not",
                                        "left": {
                                            "type": "mcall",
                                            "variable": {
                                                "type": "variable",
                                                "value": "pdoStatement",
                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                "line": 345,
                                                "char": 30
                                            },
                                            "name": "setFetchMode",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "variable",
                                                        "value": "fetchMode",
                                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                        "line": 345,
                                                        "char": 53
                                                    },
                                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                    "line": 345,
                                                    "char": 53
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 345,
                                            "char": 55
                                        },
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 345,
                                        "char": 55
                                    },
                                    "statements": [
                                        {
                                            "type": "return",
                                            "expr": {
                                                "type": "bool",
                                                "value": "false",
                                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                                "line": 346,
                                                "char": 29
                                            },
                                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                            "line": 347,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 348,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 350,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "object-property",
                                    "operator": "assign",
                                    "variable": "this",
                                    "property": "fetchMode",
                                    "expr": {
                                        "type": "variable",
                                        "value": "fetchMode",
                                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                        "line": 350,
                                        "char": 40
                                    },
                                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                    "line": 350,
                                    "char": 40
                                }
                            ],
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 352,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "bool",
                                "value": "true",
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 352,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                            "line": 353,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Changes the fetching mode affecting Phalcon\\Db\\Result\\Pdo::fetch()\n     *\n     *```php\n     * \/\/ Return array with integer indexes\n     * $result->setFetchMode(\n     *     \\Phalcon\\Db::FETCH_NUM\n     * );\n     *\n     * \/\/ Return associative array without integer indexes\n     * $result->setFetchMode(\n     *     \\Phalcon\\Db::FETCH_ASSOC\n     * );\n     *\n     * \/\/ Return associative array together with integer indexes\n     * $result->setFetchMode(\n     *     \\Phalcon\\Db::FETCH_BOTH\n     * );\n     *\n     * \/\/ Return an object\n     * $result->setFetchMode(\n     *     \\Phalcon\\Db::FETCH_OBJ\n     * );\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                                "line": 331,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                        "line": 331,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
                    "line": 330,
                    "last-line": 354,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
            "line": 34,
            "char": 5
        },
        "file": "\/app\/phalcon\/Db\/Result\/Pdo.zep",
        "line": 34,
        "char": 5
    }
]