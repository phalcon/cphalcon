[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Cache\/Adapter\/Redis.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Cache\\Adapter",
        "file": "\/app\/phalcon\/Cache\/Adapter\/Redis.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Cache\\Adapter\\AdapterInterface",
                "alias": "CacheAdapterInterface",
                "file": "\/app\/phalcon\/Cache\/Adapter\/Redis.zep",
                "line": 13,
                "char": 68
            }
        ],
        "file": "\/app\/phalcon\/Cache\/Adapter\/Redis.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Storage\\Adapter\\Redis",
                "alias": "StorageRedis",
                "file": "\/app\/phalcon\/Cache\/Adapter\/Redis.zep",
                "line": 14,
                "char": 50
            }
        ],
        "file": "\/app\/phalcon\/Cache\/Adapter\/Redis.zep",
        "line": 18,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Redis adapter\n *",
        "file": "\/app\/phalcon\/Cache\/Adapter\/Redis.zep",
        "line": 19,
        "char": 5
    },
    {
        "type": "class",
        "name": "Redis",
        "abstract": 0,
        "final": 0,
        "extends": "StorageRedis",
        "implements": [
            {
                "type": "variable",
                "value": "CacheAdapterInterface",
                "file": "\/app\/phalcon\/Cache\/Adapter\/Redis.zep",
                "line": 20,
                "char": 1
            }
        ],
        "file": "\/app\/phalcon\/Cache\/Adapter\/Redis.zep",
        "line": 19,
        "char": 5
    }
]