[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Config\/Adapter\/Json.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Config\\Adapter",
        "file": "\/app\/phalcon\/Config\/Adapter\/Json.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Config\\Config",
                "file": "\/app\/phalcon\/Config\/Adapter\/Json.zep",
                "line": 13,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Config\/Adapter\/Json.zep",
        "line": 34,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Reads JSON files and converts them to Phalcon\\Config objects.\n *\n * Given the following configuration file:\n *\n *```json\n * {\"phalcon\":{\"baseuri\":\"\\\/phalcon\\\/\"},\"models\":{\"metadata\":\"memory\"}}\n *```\n *\n * You can read it as follows:\n *\n *```php\n * use Phalcon\\Config\\Adapter\\Json;\n *\n * $config = new Json(\"path\/config.json\");\n *\n * echo $config->phalcon->baseuri;\n * echo $config->models->metadata;\n *```\n *",
        "file": "\/app\/phalcon\/Config\/Adapter\/Json.zep",
        "line": 35,
        "char": 5
    },
    {
        "type": "class",
        "name": "Json",
        "abstract": 0,
        "final": 0,
        "extends": "Config",
        "definition": {
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
                            "name": "filePath",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Config\/Adapter\/Json.zep",
                            "line": 40,
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
                                "name": "__construct",
                                "parameters": [
                                    {
                                        "parameter": {
                                            "type": "fcall",
                                            "name": "json_decode",
                                            "call-type": 1,
                                            "parameters": [
                                                {
                                                    "parameter": {
                                                        "type": "fcall",
                                                        "name": "file_get_contents",
                                                        "call-type": 1,
                                                        "parameters": [
                                                            {
                                                                "parameter": {
                                                                    "type": "variable",
                                                                    "value": "filePath",
                                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Json.zep",
                                                                    "line": 44,
                                                                    "char": 43
                                                                },
                                                                "file": "\/app\/phalcon\/Config\/Adapter\/Json.zep",
                                                                "line": 44,
                                                                "char": 43
                                                            }
                                                        ],
                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Json.zep",
                                                        "line": 44,
                                                        "char": 44
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Json.zep",
                                                    "line": 44,
                                                    "char": 44
                                                },
                                                {
                                                    "parameter": {
                                                        "type": "bool",
                                                        "value": "true",
                                                        "file": "\/app\/phalcon\/Config\/Adapter\/Json.zep",
                                                        "line": 46,
                                                        "char": 13
                                                    },
                                                    "file": "\/app\/phalcon\/Config\/Adapter\/Json.zep",
                                                    "line": 46,
                                                    "char": 13
                                                }
                                            ],
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Json.zep",
                                            "line": 47,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Json.zep",
                                        "line": 47,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Config\/Adapter\/Json.zep",
                                "line": 47,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Config\/Adapter\/Json.zep",
                            "line": 48,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Config\\Adapter\\Json constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Config\/Adapter\/Json.zep",
                        "line": 41,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Config\/Adapter\/Json.zep",
                    "line": 40,
                    "last-line": 49,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Config\/Adapter\/Json.zep",
            "line": 35,
            "char": 5
        },
        "file": "\/app\/phalcon\/Config\/Adapter\/Json.zep",
        "line": 35,
        "char": 5
    }
]