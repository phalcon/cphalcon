[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Di\/ServiceProviderInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Di",
        "file": "\/app\/phalcon\/Di\/ServiceProviderInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\DiInterface",
                "file": "\/app\/phalcon\/Di\/ServiceProviderInterface.zep",
                "line": 13,
                "char": 24
            }
        ],
        "file": "\/app\/phalcon\/Di\/ServiceProviderInterface.zep",
        "line": 38,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Should be implemented by service providers, or such components, which\n * register a service in the service container.\n *\n * ```php\n * namespace Acme;\n *\n * use Phalcon\\DiInterface;\n * use Phalcon\\Di\\ServiceProviderInterface;\n *\n * class SomeServiceProvider implements ServiceProviderInterface\n * {\n *     public function register(DiInterface $di)\n *     {\n *         $di->setShared(\n *             'service',\n *             function () {\n *                 \/\/ ...\n *             }\n *         );\n *     }\n * }\n * ```\n *",
        "file": "\/app\/phalcon\/Di\/ServiceProviderInterface.zep",
        "line": 39,
        "char": 9
    },
    {
        "type": "interface",
        "name": "ServiceProviderInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "register",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "di",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "cast": {
                                "type": "variable",
                                "value": "DiInterface",
                                "file": "\/app\/phalcon\/Di\/ServiceProviderInterface.zep",
                                "line": 44,
                                "char": 45
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Di\/ServiceProviderInterface.zep",
                            "line": 44,
                            "char": 46
                        }
                    ],
                    "docblock": "**\n     * Registers a service provider.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "void": 1,
                        "file": "\/app\/phalcon\/Di\/ServiceProviderInterface.zep",
                        "line": 44,
                        "char": 55
                    },
                    "file": "\/app\/phalcon\/Di\/ServiceProviderInterface.zep",
                    "line": 44,
                    "last-line": 45,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Di\/ServiceProviderInterface.zep",
            "line": 45,
            "char": 1
        },
        "file": "\/app\/phalcon\/Di\/ServiceProviderInterface.zep",
        "line": 0,
        "char": 0
    }
]