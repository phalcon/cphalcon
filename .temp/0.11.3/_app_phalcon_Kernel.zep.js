[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Kernel.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon",
        "file": "\/app\/phalcon\/Kernel.zep",
        "line": 15,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * This class allows to change the internal behavior of the framework in runtime\n *",
        "file": "\/app\/phalcon\/Kernel.zep",
        "line": 16,
        "char": 5
    },
    {
        "type": "class",
        "name": "Kernel",
        "abstract": 0,
        "final": 0,
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public",
                        "static"
                    ],
                    "type": "method",
                    "name": "preComputeHashKey",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "key",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Kernel.zep",
                            "line": 24,
                            "char": 57
                        }
                    ],
                    "statements": [
                        {
                            "type": "cblock",
                            "value": "\n\n        {\n\n        RETURN_MM_NULL();\n\n        }\n\n        ",
                            "file": "\/app\/phalcon\/Kernel.zep",
                            "line": 35,
                            "char": 5
                        }
                    ],
                    "docblock": "**\n     * Produces a pre-computed hash key based on a string. This function\n     * produces different numbers in 32bit\/64bit processors\n     *\n     * @return string\n     *",
                    "file": "\/app\/phalcon\/Kernel.zep",
                    "line": 24,
                    "last-line": 36,
                    "char": 26
                }
            ],
            "file": "\/app\/phalcon\/Kernel.zep",
            "line": 16,
            "char": 5
        },
        "file": "\/app\/phalcon\/Kernel.zep",
        "line": 16,
        "char": 5
    }
]