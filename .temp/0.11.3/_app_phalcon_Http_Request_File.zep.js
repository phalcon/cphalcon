[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Http\\Request",
        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Request\\FileInterface",
                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                "line": 13,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
        "line": 37,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Phalcon\\Http\\Request\\File\n *\n * Provides OO wrappers to the $_FILES superglobal\n *\n *```php\n * use Phalcon\\Mvc\\Controller;\n *\n * class PostsController extends Controller\n * {\n *     public function uploadAction()\n *     {\n *         \/\/ Check if the user has uploaded files\n *         if ($this->request->hasFiles() == true) {\n *             \/\/ Print the real file names and their sizes\n *             foreach ($this->request->getUploadedFiles() as $file) {\n *                 echo $file->getName(), \" \", $file->getSize(), \"\\n\";\n *             }\n *         }\n *     }\n * }\n *```\n *",
        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
        "line": 38,
        "char": 5
    },
    {
        "type": "class",
        "name": "File",
        "abstract": 0,
        "final": 0,
        "implements": [
            {
                "type": "variable",
                "value": "FileInterface",
                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                "line": 39,
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
                    "name": "error",
                    "docblock": "**\n     * @var string|null\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                            "line": 43,
                            "char": 27
                        }
                    ],
                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                    "line": 47,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "extension",
                    "docblock": "**\n     * @var string\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                            "line": 48,
                            "char": 31
                        }
                    ],
                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                    "line": 52,
                    "char": 6
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "key",
                    "docblock": "**\n     * @var string|null\n     *",
                    "shortcuts": [
                        {
                            "type": "shortcut",
                            "name": "get",
                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                            "line": 53,
                            "char": 25
                        }
                    ],
                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                    "line": 55,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "name",
                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                    "line": 57,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "realType",
                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                    "line": 59,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "size",
                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                    "line": 61,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "tmp",
                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                    "line": 63,
                    "char": 13
                },
                {
                    "visibility": [
                        "protected"
                    ],
                    "type": "property",
                    "name": "type",
                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                    "line": 67,
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
                            "name": "file",
                            "const": 0,
                            "data-type": "array",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                            "line": 68,
                            "char": 44
                        },
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                "line": 68,
                                "char": 56
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                            "line": 68,
                            "char": 56
                        }
                    ],
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "name",
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 70,
                                    "char": 17
                                },
                                {
                                    "variable": "tempName",
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 70,
                                    "char": 27
                                },
                                {
                                    "variable": "size",
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 70,
                                    "char": 33
                                },
                                {
                                    "variable": "type",
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 70,
                                    "char": 39
                                },
                                {
                                    "variable": "error",
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 70,
                                    "char": 46
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                            "line": 72,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 72,
                                    "char": 35
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "file",
                                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                        "line": 72,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "name",
                                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                        "line": 72,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 72,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                "line": 72,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "name",
                                            "expr": {
                                                "type": "variable",
                                                "value": "name",
                                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                                "line": 73,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                            "line": 73,
                                            "char": 34
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 75,
                                    "char": 14
                                },
                                {
                                    "type": "if",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "defined",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "string",
                                                    "value": "PATHINFO_EXTENSION",
                                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                                    "line": 75,
                                                    "char": 42
                                                },
                                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                                "line": 75,
                                                "char": 42
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                        "line": 75,
                                        "char": 44
                                    },
                                    "statements": [
                                        {
                                            "type": "let",
                                            "assignments": [
                                                {
                                                    "assign-type": "object-property",
                                                    "operator": "assign",
                                                    "variable": "this",
                                                    "property": "extension",
                                                    "expr": {
                                                        "type": "fcall",
                                                        "name": "pathinfo",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "name",
                                                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                                                    "line": 76,
                                                                    "char": 52
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                                                "line": 76,
                                                                "char": 52
                                                            },
                                                            {
                                                                "parameter": {
                                                                    "type": "constant",
                                                                    "value": "PATHINFO_EXTENSION",
                                                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                                                    "line": 76,
                                                                    "char": 72
                                                                },
                                                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                                                "line": 76,
                                                                "char": 72
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                                        "line": 76,
                                                        "char": 73
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                                    "line": 76,
                                                    "char": 73
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                            "line": 77,
                                            "char": 13
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 78,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                            "line": 80,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "tempName",
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 80,
                                    "char": 43
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "file",
                                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                        "line": 80,
                                        "char": 32
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "tmp_name",
                                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                        "line": 80,
                                        "char": 41
                                    },
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 80,
                                    "char": 43
                                },
                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                "line": 80,
                                "char": 43
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "tmp",
                                            "expr": {
                                                "type": "variable",
                                                "value": "tempName",
                                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                                "line": 81,
                                                "char": 37
                                            },
                                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                            "line": 81,
                                            "char": 37
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 82,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                            "line": 84,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "size",
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 84,
                                    "char": 35
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "file",
                                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                        "line": 84,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "size",
                                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                        "line": 84,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 84,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                "line": 84,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "size",
                                            "expr": {
                                                "type": "variable",
                                                "value": "size",
                                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                                "line": 85,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                            "line": 85,
                                            "char": 34
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 86,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                            "line": 88,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "type",
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 88,
                                    "char": 35
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "file",
                                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                        "line": 88,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "type",
                                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                        "line": 88,
                                        "char": 33
                                    },
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 88,
                                    "char": 35
                                },
                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                "line": 88,
                                "char": 35
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "type",
                                            "expr": {
                                                "type": "variable",
                                                "value": "type",
                                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                                "line": 89,
                                                "char": 34
                                            },
                                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                            "line": 89,
                                            "char": 34
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 90,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                            "line": 92,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "fetch",
                                "left": {
                                    "type": "variable",
                                    "value": "error",
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 92,
                                    "char": 37
                                },
                                "right": {
                                    "type": "array-access",
                                    "left": {
                                        "type": "variable",
                                        "value": "file",
                                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                        "line": 92,
                                        "char": 29
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "error",
                                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                        "line": 92,
                                        "char": 35
                                    },
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 92,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                "line": 92,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "error",
                                            "expr": {
                                                "type": "variable",
                                                "value": "error",
                                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                                "line": 93,
                                                "char": 36
                                            },
                                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                            "line": 93,
                                            "char": 36
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 94,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                            "line": 96,
                            "char": 10
                        },
                        {
                            "type": "if",
                            "expr": {
                                "type": "variable",
                                "value": "key",
                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                "line": 96,
                                "char": 16
                            },
                            "statements": [
                                {
                                    "type": "let",
                                    "assignments": [
                                        {
                                            "assign-type": "object-property",
                                            "operator": "assign",
                                            "variable": "this",
                                            "property": "key",
                                            "expr": {
                                                "type": "variable",
                                                "value": "key",
                                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                                "line": 97,
                                                "char": 32
                                            },
                                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                            "line": 97,
                                            "char": 32
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 98,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                            "line": 99,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Http\\Request\\File constructor\n     *",
                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                    "line": 68,
                    "last-line": 103,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getName",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 106,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "name",
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 106,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                "line": 106,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                            "line": 107,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the real name of the uploaded file\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                "line": 105,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                        "line": 105,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                    "line": 104,
                    "last-line": 111,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRealType",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "finfo",
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 114,
                                    "char": 18
                                },
                                {
                                    "variable": "mime",
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 114,
                                    "char": 24
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                            "line": 116,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "finfo",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "finfo_open",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "constant",
                                                    "value": "FILEINFO_MIME_TYPE",
                                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                                    "line": 116,
                                                    "char": 50
                                                },
                                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                                "line": 116,
                                                "char": 50
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                        "line": 116,
                                        "char": 51
                                    },
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 116,
                                    "char": 51
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                            "line": 118,
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
                                        "value": "finfo",
                                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                        "line": 118,
                                        "char": 26
                                    },
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 118,
                                    "char": 26
                                },
                                "right": {
                                    "type": "string",
                                    "value": "resource",
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 118,
                                    "char": 37
                                },
                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                "line": 118,
                                "char": 37
                            },
                            "statements": [
                                {
                                    "type": "return",
                                    "expr": {
                                        "type": "string",
                                        "value": "",
                                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                        "line": 119,
                                        "char": 20
                                    },
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 120,
                                    "char": 9
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                            "line": 122,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "mime",
                                    "expr": {
                                        "type": "fcall",
                                        "name": "finfo_file",
                                        "call-type": 1,
                                        "parameters": [
                                            {
                                                "parameter": {
                                                    "type": "variable",
                                                    "value": "finfo",
                                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                                    "line": 122,
                                                    "char": 36
                                                },
                                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                                "line": 122,
                                                "char": 36
                                            },
                                            {
                                                "parameter": {
                                                    "type": "property-access",
                                                    "left": {
                                                        "type": "variable",
                                                        "value": "this",
                                                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                                        "line": 122,
                                                        "char": 43
                                                    },
                                                    "right": {
                                                        "type": "variable",
                                                        "value": "tmp",
                                                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                                        "line": 122,
                                                        "char": 47
                                                    },
                                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                                    "line": 122,
                                                    "char": 47
                                                },
                                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                                "line": 122,
                                                "char": 47
                                            }
                                        ],
                                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                        "line": 122,
                                        "char": 48
                                    },
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 122,
                                    "char": 48
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                            "line": 124,
                            "char": 19
                        },
                        {
                            "type": "fcall",
                            "expr": {
                                "type": "fcall",
                                "name": "finfo_close",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "finfo",
                                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                            "line": 124,
                                            "char": 26
                                        },
                                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                        "line": 124,
                                        "char": 26
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                "line": 124,
                                "char": 27
                            },
                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                            "line": 126,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "variable",
                                "value": "mime",
                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                "line": 126,
                                "char": 20
                            },
                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                            "line": 127,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Gets the real mime type of the upload file using finfo\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                "line": 113,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                        "line": 113,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                    "line": 112,
                    "last-line": 131,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getSize",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 134,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "size",
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 134,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                "line": 134,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                            "line": 135,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the file size of the uploaded file\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                "line": 133,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                        "line": 133,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                    "line": 132,
                    "last-line": 139,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getTempName",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 142,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "tmp",
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 142,
                                    "char": 25
                                },
                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                "line": 142,
                                "char": 25
                            },
                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                            "line": 143,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the temporary name of the uploaded file\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                "line": 141,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                        "line": 141,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                    "line": 140,
                    "last-line": 148,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getType",
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "property-access",
                                "left": {
                                    "type": "variable",
                                    "value": "this",
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 151,
                                    "char": 21
                                },
                                "right": {
                                    "type": "variable",
                                    "value": "type",
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 151,
                                    "char": 26
                                },
                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                "line": 151,
                                "char": 26
                            },
                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                            "line": 152,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Returns the mime type reported by the browser\n     * This mime type is not completely secure, use getRealType() instead\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                "line": 150,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                        "line": 150,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                    "line": 149,
                    "last-line": 156,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isUploadedFile",
                    "statements": [
                        {
                            "type": "declare",
                            "data-type": "variable",
                            "variables": [
                                {
                                    "variable": "tmp",
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 159,
                                    "char": 16
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                            "line": 161,
                            "char": 11
                        },
                        {
                            "type": "let",
                            "assignments": [
                                {
                                    "assign-type": "variable",
                                    "operator": "assign",
                                    "variable": "tmp",
                                    "expr": {
                                        "type": "mcall",
                                        "variable": {
                                            "type": "variable",
                                            "value": "this",
                                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                            "line": 161,
                                            "char": 24
                                        },
                                        "name": "getTempName",
                                        "call-type": 1,
                                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                        "line": 161,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 161,
                                    "char": 38
                                }
                            ],
                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                            "line": 163,
                            "char": 14
                        },
                        {
                            "type": "return",
                            "expr": {
                                "type": "and",
                                "left": {
                                    "type": "equals",
                                    "left": {
                                        "type": "typeof",
                                        "left": {
                                            "type": "variable",
                                            "value": "tmp",
                                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                            "line": 163,
                                            "char": 28
                                        },
                                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                        "line": 163,
                                        "char": 28
                                    },
                                    "right": {
                                        "type": "string",
                                        "value": "string",
                                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                        "line": 163,
                                        "char": 38
                                    },
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 163,
                                    "char": 38
                                },
                                "right": {
                                    "type": "fcall",
                                    "name": "is_uploaded_file",
                                    "call-type": 1,
                                    "parameters": [
                                        {
                                            "parameter": {
                                                "type": "variable",
                                                "value": "tmp",
                                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                                "line": 163,
                                                "char": 60
                                            },
                                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                            "line": 163,
                                            "char": 60
                                        }
                                    ],
                                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                    "line": 163,
                                    "char": 61
                                },
                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                "line": 163,
                                "char": 61
                            },
                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                            "line": 164,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Checks whether the file has been uploaded via Post.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                "line": 158,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                        "line": 158,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                    "line": 157,
                    "last-line": 168,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "moveTo",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "destination",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                            "line": 169,
                            "char": 47
                        }
                    ],
                    "statements": [
                        {
                            "type": "return",
                            "expr": {
                                "type": "fcall",
                                "name": "move_uploaded_file",
                                "call-type": 1,
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "property-access",
                                            "left": {
                                                "type": "variable",
                                                "value": "this",
                                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                                "line": 171,
                                                "char": 40
                                            },
                                            "right": {
                                                "type": "variable",
                                                "value": "tmp",
                                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                                "line": 171,
                                                "char": 44
                                            },
                                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                            "line": 171,
                                            "char": 44
                                        },
                                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                        "line": 171,
                                        "char": 44
                                    },
                                    {
                                        "parameter": {
                                            "type": "variable",
                                            "value": "destination",
                                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                            "line": 171,
                                            "char": 57
                                        },
                                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                        "line": 171,
                                        "char": 57
                                    }
                                ],
                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                "line": 171,
                                "char": 58
                            },
                            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                            "line": 172,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Moves the temporary file to a destination within the application\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                                "line": 170,
                                "char": 5
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                        "line": 170,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Http\/Request\/File.zep",
                    "line": 169,
                    "last-line": 173,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Http\/Request\/File.zep",
            "line": 38,
            "char": 5
        },
        "file": "\/app\/phalcon\/Http\/Request\/File.zep",
        "line": 38,
        "char": 5
    }
]