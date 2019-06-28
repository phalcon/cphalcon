[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Config\/Adapter\/Php.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Config\\Adapter",
        "file": "\/app\/phalcon\/Config\/Adapter\/Php.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Config\\Config",
                "file": "\/app\/phalcon\/Config\/Adapter\/Php.zep",
                "line": 13,
                "char": 26
            }
        ],
        "file": "\/app\/phalcon\/Config\/Adapter\/Php.zep",
        "line": 49,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Reads php files and converts them to Phalcon\\Config objects.\n *\n * Given the next configuration file:\n *\n *```php\n * <?php\n *\n * return [\n *     \"database\" => [\n *         \"adapter\"  => \"Mysql\",\n *         \"host\"     => \"localhost\",\n *         \"username\" => \"scott\",\n *         \"password\" => \"cheetah\",\n *         \"dbname\"   => \"test_db\",\n *     ],\n *     \"phalcon\" => [\n *         \"controllersDir\" => \"..\/app\/controllers\/\",\n *         \"modelsDir\"      => \"..\/app\/models\/\",\n *         \"viewsDir\"       => \"..\/app\/views\/\",\n *     ],\n * ];\n *```\n *\n * You can read it as follows:\n *\n *```php\n * use Phalcon\\Config\\Adapter\\Php;\n *\n * $config = new Php(\"path\/config.php\");\n *\n * echo $config->phalcon->controllersDir;\n * echo $config->database->username;\n *```\n *",
        "file": "\/app\/phalcon\/Config\/Adapter\/Php.zep",
        "line": 50,
        "char": 5
    },
    {
        "type": "class",
        "name": "Php",
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
                            "file": "\/app\/phalcon\/Config\/Adapter\/Php.zep",
                            "line": 55,
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
                                            "type": "require",
                                            "left": {
                                                "type": "variable",
                                                "value": "filePath",
                                                "file": "\/app\/phalcon\/Config\/Adapter\/Php.zep",
                                                "line": 59,
                                                "char": 9
                                            },
                                            "file": "\/app\/phalcon\/Config\/Adapter\/Php.zep",
                                            "line": 59,
                                            "char": 9
                                        },
                                        "file": "\/app\/phalcon\/Config\/Adapter\/Php.zep",
                                        "line": 59,
                                        "char": 9
                                    }
                                ],
                                "file": "\/app\/phalcon\/Config\/Adapter\/Php.zep",
                                "line": 59,
                                "char": 10
                            },
                            "file": "\/app\/phalcon\/Config\/Adapter\/Php.zep",
                            "line": 60,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Phalcon\\Config\\Adapter\\Php constructor\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Config\/Adapter\/Php.zep",
                        "line": 56,
                        "char": 5
                    },
                    "file": "\/app\/phalcon\/Config\/Adapter\/Php.zep",
                    "line": 55,
                    "last-line": 61,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Config\/Adapter\/Php.zep",
            "line": 50,
            "char": 5
        },
        "file": "\/app\/phalcon\/Config\/Adapter\/Php.zep",
        "line": 50,
        "char": 5
    }
]