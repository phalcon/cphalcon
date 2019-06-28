[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *\n * Implementation of this file has been influenced by phalcon-api and AuraPHP\n * @link    https:\/\/github.com\/phalcon\/phalcon-api\n * @license https:\/\/github.com\/phalcon\/phalcon-api\/blob\/master\/LICENSE\n * @link    https:\/\/github.com\/auraphp\/Aura.Payload\n * @license https:\/\/github.com\/auraphp\/Aura.Payload\/blob\/3.x\/LICENSE\n *\n * @see Original inspiration for the https:\/\/github.com\/phalcon\/phalcon-api\n *",
        "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
        "line": 19,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Domain\\Payload",
        "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
        "line": 23,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Holds the status codes for the payload\n *",
        "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
        "line": 24,
        "char": 5
    },
    {
        "type": "class",
        "name": "Status",
        "abstract": 0,
        "final": 0,
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "final",
                        "private"
                    ],
                    "type": "method",
                    "name": "__construct",
                    "docblock": "**\n     * Instantiation not allowed.\n     *",
                    "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                    "line": 50,
                    "last-line": 53,
                    "char": 26
                }
            ],
            "constants": [
                {
                    "type": "const",
                    "name": "ACCEPTED",
                    "default": {
                        "type": "string",
                        "value": "ACCEPTED",
                        "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                        "line": 26,
                        "char": 39
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                    "line": 27,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "AUTHENTICATED",
                    "default": {
                        "type": "string",
                        "value": "AUTHENTICATED",
                        "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                        "line": 27,
                        "char": 44
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                    "line": 28,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "AUTHORIZED",
                    "default": {
                        "type": "string",
                        "value": "AUTHORIZED",
                        "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                        "line": 28,
                        "char": 41
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                    "line": 29,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "CREATED",
                    "default": {
                        "type": "string",
                        "value": "CREATED",
                        "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                        "line": 29,
                        "char": 38
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                    "line": 30,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "DELETED",
                    "default": {
                        "type": "string",
                        "value": "DELETED",
                        "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                        "line": 30,
                        "char": 38
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                    "line": 31,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "ERROR",
                    "default": {
                        "type": "string",
                        "value": "ERROR",
                        "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                        "line": 31,
                        "char": 36
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                    "line": 32,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FAILURE",
                    "default": {
                        "type": "string",
                        "value": "FAILURE",
                        "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                        "line": 32,
                        "char": 38
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                    "line": 33,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "FOUND",
                    "default": {
                        "type": "string",
                        "value": "FOUND",
                        "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                        "line": 33,
                        "char": 36
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                    "line": 34,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "NOT_ACCEPTED",
                    "default": {
                        "type": "string",
                        "value": "NOT_ACCEPTED",
                        "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                        "line": 34,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                    "line": 35,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "NOT_AUTHENTICATED",
                    "default": {
                        "type": "string",
                        "value": "NOT_AUTHENTICATED",
                        "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                        "line": 35,
                        "char": 48
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                    "line": 36,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "NOT_AUTHORIZED",
                    "default": {
                        "type": "string",
                        "value": "NOT_AUTHORIZED",
                        "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                        "line": 36,
                        "char": 45
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                    "line": 37,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "NOT_CREATED",
                    "default": {
                        "type": "string",
                        "value": "NOT_CREATED",
                        "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                        "line": 37,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                    "line": 38,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "NOT_DELETED",
                    "default": {
                        "type": "string",
                        "value": "NOT_DELETED",
                        "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                        "line": 38,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                    "line": 39,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "NOT_FOUND",
                    "default": {
                        "type": "string",
                        "value": "NOT_FOUND",
                        "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                        "line": 39,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                    "line": 40,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "NOT_UPDATED",
                    "default": {
                        "type": "string",
                        "value": "NOT_UPDATED",
                        "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                        "line": 40,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                    "line": 41,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "NOT_VALID",
                    "default": {
                        "type": "string",
                        "value": "NOT_VALID",
                        "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                        "line": 41,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                    "line": 42,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "PROCESSING",
                    "default": {
                        "type": "string",
                        "value": "PROCESSING",
                        "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                        "line": 42,
                        "char": 41
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                    "line": 43,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "SUCCESS",
                    "default": {
                        "type": "string",
                        "value": "SUCCESS",
                        "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                        "line": 43,
                        "char": 38
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                    "line": 44,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "UPDATED",
                    "default": {
                        "type": "string",
                        "value": "UPDATED",
                        "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                        "line": 44,
                        "char": 38
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                    "line": 45,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "VALID",
                    "default": {
                        "type": "string",
                        "value": "VALID",
                        "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                        "line": 45,
                        "char": 36
                    },
                    "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
                    "line": 49,
                    "char": 6
                }
            ],
            "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
            "line": 24,
            "char": 5
        },
        "file": "\/app\/phalcon\/Domain\/Payload\/Status.zep",
        "line": 24,
        "char": 5
    }
]