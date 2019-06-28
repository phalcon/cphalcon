[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon\\Http",
        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
        "line": 13,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "Phalcon\\Http\\Request\\FileInterface",
                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                "line": 13,
                "char": 39
            }
        ],
        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
        "line": 14,
        "char": 3
    },
    {
        "type": "use",
        "aliases": [
            {
                "name": "stdClass",
                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                "line": 14,
                "char": 13
            }
        ],
        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
        "line": 18,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * Interface for Phalcon\\Http\\Request\n *",
        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
        "line": 19,
        "char": 9
    },
    {
        "type": "interface",
        "name": "RequestInterface",
        "definition": {
            "methods": [
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "get",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 33,
                                "char": 44
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 33,
                            "char": 44
                        },
                        {
                            "type": "parameter",
                            "name": "filters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 33,
                                "char": 64
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 33,
                            "char": 64
                        },
                        {
                            "type": "parameter",
                            "name": "defaultValue",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 33,
                                "char": 89
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 33,
                            "char": 89
                        },
                        {
                            "type": "parameter",
                            "name": "notAllowEmpty",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 33,
                                "char": 117
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 33,
                            "char": 117
                        },
                        {
                            "type": "parameter",
                            "name": "noRecursive",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 33,
                                "char": 143
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 33,
                            "char": 143
                        }
                    ],
                    "docblock": "**\n     * Gets a variable from the $_REQUEST superglobal applying filters if\n     * needed. If no parameters are given the $_REQUEST superglobal is returned\n     *\n     *```php\n     * \/\/ Returns value from $_REQUEST[\"user_email\"] without sanitizing\n     * $userEmail = $request->get(\"user_email\");\n     *\n     * \/\/ Returns value from $_REQUEST[\"user_email\"] with sanitizing\n     * $userEmail = $request->get(\"user_email\", \"email\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 33,
                                "char": 151
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 33,
                        "char": 151
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 33,
                    "last-line": 38,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getAcceptableContent",
                    "docblock": "**\n     * Gets an array with mime\/types and their quality accepted by the\n     * browser\/client from _SERVER[\"HTTP_ACCEPT\"]\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 39,
                                "char": 52
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 39,
                        "char": 52
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 39,
                    "last-line": 44,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getBasicAuth",
                    "docblock": "**\n     * Gets auth info accepted by the browser\/client from\n     * $_SERVER[\"PHP_AUTH_USER\"]\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 45,
                                "char": 45
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 45,
                                "char": 51
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 45,
                        "char": 51
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 45,
                    "last-line": 50,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getBestAccept",
                    "docblock": "**\n     * Gets best mime\/type accepted by the browser\/client from\n     * _SERVER[\"HTTP_ACCEPT\"]\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 51,
                                "char": 46
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 51,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 51,
                    "last-line": 56,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getBestCharset",
                    "docblock": "**\n     * Gets best charset accepted by the browser\/client from\n     * _SERVER[\"HTTP_ACCEPT_CHARSET\"]\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 57,
                                "char": 47
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 57,
                        "char": 47
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 57,
                    "last-line": 62,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getBestLanguage",
                    "docblock": "**\n     * Gets best language accepted by the browser\/client from\n     * _SERVER[\"HTTP_ACCEPT_LANGUAGE\"]\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 63,
                                "char": 48
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 63,
                        "char": 48
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 63,
                    "last-line": 69,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getClientAddress",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "trustForwardedHeader",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 70,
                                "char": 71
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 70,
                            "char": 71
                        }
                    ],
                    "docblock": "**\n     * Gets most possible client IPv4 Address. This method searches in\n     * $_SERVER[\"REMOTE_ADDR\"] and optionally in\n     * $_SERVER[\"HTTP_X_FORWARDED_FOR\"]\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 70,
                                "char": 83
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 70,
                                "char": 89
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 70,
                        "char": 89
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 70,
                    "last-line": 75,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getClientCharsets",
                    "docblock": "**\n     * Gets a charsets array and their quality accepted by the browser\/client\n     * from _SERVER[\"HTTP_ACCEPT_CHARSET\"]\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 76,
                                "char": 49
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 76,
                        "char": 49
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 76,
                    "last-line": 80,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getContentType",
                    "docblock": "**\n     * Gets content type which request has been made\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 81,
                                "char": 48
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 81,
                                "char": 54
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 81,
                        "char": 54
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 81,
                    "last-line": 86,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getDigestAuth",
                    "docblock": "**\n     * Gets auth info accepted by the browser\/client from\n     * $_SERVER[\"PHP_AUTH_DIGEST\"]\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 87,
                                "char": 45
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 87,
                        "char": 45
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 87,
                    "last-line": 91,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHeader",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "header",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 92,
                            "char": 45
                        }
                    ],
                    "docblock": "**\n     * Gets HTTP header from request data\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 92,
                                "char": 56
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 92,
                        "char": 56
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 92,
                    "last-line": 107,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHeaders",
                    "docblock": "**\n     * Returns the available headers in the request\n     *\n     * ```php\n     * $_SERVER = [\n     *     \"PHP_AUTH_USER\" => \"phalcon\",\n     *     \"PHP_AUTH_PW\"   => \"secret\",\n     * ];\n     *\n     * $headers = $request->getHeaders();\n     *\n     * echo $headers[\"Authorization\"]; \/\/ Basic cGhhbGNvbjpzZWNyZXQ=\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 108,
                                "char": 42
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 108,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 108,
                    "last-line": 143,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHttpHost",
                    "docblock": "**\n     * Gets host name used by the request.\n     *\n     * `Request::getHttpHost` trying to find host name in following order:\n     *\n     * - `$_SERVER[\"HTTP_HOST\"]`\n     * - `$_SERVER[\"SERVER_NAME\"]`\n     * - `$_SERVER[\"SERVER_ADDR\"]`\n     *\n     * Optionally `Request::getHttpHost` validates and clean host name.\n     * The `Request::$_strictHostCheck` can be used to validate host name.\n     *\n     * Note: validation and cleaning have a negative performance impact because\n     * they use regular expressions.\n     *\n     * ```php\n     * use Phalcon\\Http\\Request;\n     *\n     * $request = new Request;\n     *\n     * $_SERVER[\"HTTP_HOST\"] = \"example.com\";\n     * $request->getHttpHost(); \/\/ example.com\n     *\n     * $_SERVER[\"HTTP_HOST\"] = \"example.com:8080\";\n     * $request->getHttpHost(); \/\/ example.com:8080\n     *\n     * $request->setStrictHostCheck(true);\n     * $_SERVER[\"HTTP_HOST\"] = \"ex=am~ple.com\";\n     * $request->getHttpHost(); \/\/ UnexpectedValueException\n     *\n     * $_SERVER[\"HTTP_HOST\"] = \"ExAmPlE.com\";\n     * $request->getHttpHost(); \/\/ example.com\n     * ```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 144,
                                "char": 44
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 144,
                        "char": 44
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 144,
                    "last-line": 148,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getHTTPReferer",
                    "docblock": "**\n     * Gets web page that refers active request. ie: http:\/\/www.google.com\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 149,
                                "char": 47
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 149,
                        "char": 47
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 149,
                    "last-line": 153,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getJsonRawBody",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "associative",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 154,
                                "char": 60
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 154,
                            "char": 60
                        }
                    ],
                    "docblock": "**\n     * Gets decoded JSON HTTP raw request body\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "stdClass",
                                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                    "line": 154,
                                    "char": 76
                                },
                                "collection": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 154,
                                "char": 76
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 154,
                                "char": 84
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 154,
                                "char": 90
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 154,
                        "char": 90
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 154,
                    "last-line": 159,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getLanguages",
                    "docblock": "**\n     * Gets languages array and their quality accepted by the browser\/client\n     * from _SERVER[\"HTTP_ACCEPT_LANGUAGE\"]\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "array",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 160,
                                "char": 44
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 160,
                        "char": 44
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 160,
                    "last-line": 172,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getMethod",
                    "docblock": "**\n     * Gets HTTP method which request has been made\n     *\n     * If the X-HTTP-Method-Override header is set, and if the method is a POST,\n     * then it is used to determine the \"real\" intended HTTP method.\n     *\n     * The _method request parameter can also be used to determine the HTTP\n     * method, but only if setHttpMethodParameterOverride(true) has been called.\n     *\n     * The method is always an uppercased string.\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 173,
                                "char": 42
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 173,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 173,
                    "last-line": 177,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getPort",
                    "docblock": "**\n     * Gets information about the port on which the request is made\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "int",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 178,
                                "char": 37
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 178,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 178,
                    "last-line": 182,
                    "char": 19
                },
                {
                    "visibility": [
                        "final",
                        "public"
                    ],
                    "type": "method",
                    "name": "getURI",
                    "docblock": "**\n     * Gets HTTP URI which request has been made\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 183,
                                "char": 45
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 183,
                        "char": 45
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 183,
                    "last-line": 196,
                    "char": 25
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getPost",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 197,
                                "char": 48
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 197,
                            "char": 48
                        },
                        {
                            "type": "parameter",
                            "name": "filters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 197,
                                "char": 68
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 197,
                            "char": 68
                        },
                        {
                            "type": "parameter",
                            "name": "defaultValue",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 197,
                                "char": 93
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 197,
                            "char": 93
                        },
                        {
                            "type": "parameter",
                            "name": "notAllowEmpty",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 197,
                                "char": 121
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 197,
                            "char": 121
                        },
                        {
                            "type": "parameter",
                            "name": "noRecursive",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 197,
                                "char": 147
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 197,
                            "char": 147
                        }
                    ],
                    "docblock": "**\n     * Gets a variable from the $_POST superglobal applying filters if needed\n     * If no parameters are given the $_POST superglobal is returned\n     *\n     *```php\n     * \/\/ Returns value from $_POST[\"user_email\"] without sanitizing\n     * $userEmail = $request->getPost(\"user_email\");\n     *\n     * \/\/ Returns value from $_POST[\"user_email\"] with sanitizing\n     * $userEmail = $request->getPost(\"user_email\", \"email\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 197,
                                "char": 155
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 197,
                        "char": 155
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 197,
                    "last-line": 209,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getPut",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 210,
                                "char": 47
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 210,
                            "char": 47
                        },
                        {
                            "type": "parameter",
                            "name": "filters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 210,
                                "char": 67
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 210,
                            "char": 67
                        },
                        {
                            "type": "parameter",
                            "name": "defaultValue",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 210,
                                "char": 92
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 210,
                            "char": 92
                        },
                        {
                            "type": "parameter",
                            "name": "notAllowEmpty",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 210,
                                "char": 120
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 210,
                            "char": 120
                        },
                        {
                            "type": "parameter",
                            "name": "noRecursive",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 210,
                                "char": 146
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 210,
                            "char": 146
                        }
                    ],
                    "docblock": "**\n     * Gets a variable from put request\n     *\n     *```php\n     * \/\/ Returns value from $_PUT[\"user_email\"] without sanitizing\n     * $userEmail = $request->getPut(\"user_email\");\n     *\n     * \/\/ Returns value from $_PUT[\"user_email\"] with sanitizing\n     * $userEmail = $request->getPut(\"user_email\", \"email\");\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 210,
                                "char": 154
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 210,
                        "char": 154
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 210,
                    "last-line": 226,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getQuery",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 227,
                                "char": 49
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 227,
                            "char": 49
                        },
                        {
                            "type": "parameter",
                            "name": "filters",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 227,
                                "char": 69
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 227,
                            "char": 69
                        },
                        {
                            "type": "parameter",
                            "name": "defaultValue",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "default": {
                                "type": "null",
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 227,
                                "char": 94
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 227,
                            "char": 94
                        },
                        {
                            "type": "parameter",
                            "name": "notAllowEmpty",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 227,
                                "char": 122
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 227,
                            "char": 122
                        },
                        {
                            "type": "parameter",
                            "name": "noRecursive",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 227,
                                "char": 148
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 227,
                            "char": 148
                        }
                    ],
                    "docblock": "**\n     * Gets variable from $_GET superglobal applying filters if needed\n     * If no parameters are given the $_GET superglobal is returned\n     *\n     *```php\n     * \/\/ Returns value from $_GET[\"id\"] without sanitizing\n     * $id = $request->getQuery(\"id\");\n     *\n     * \/\/ Returns value from $_GET[\"id\"] with sanitizing\n     * $id = $request->getQuery(\"id\", \"int\");\n     *\n     * \/\/ Returns value from $_GET[\"id\"] with a default value\n     * $id = $request->getQuery(\"id\", null, 150);\n     *```\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "variable",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 227,
                                "char": 156
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 227,
                        "char": 156
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 227,
                    "last-line": 231,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getRawBody",
                    "docblock": "**\n     * Gets HTTP raw request body\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 232,
                                "char": 43
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 232,
                        "char": 43
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 232,
                    "last-line": 236,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getScheme",
                    "docblock": "**\n     * Gets HTTP schema (http\/https)\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 237,
                                "char": 42
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 237,
                        "char": 42
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 237,
                    "last-line": 242,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getServer",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 243,
                            "char": 43
                        }
                    ],
                    "docblock": "**\n     * Gets variable from $_SERVER superglobal\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 243,
                                "char": 55
                            },
                            {
                                "type": "return-type-parameter",
                                "data-type": "null",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 243,
                                "char": 61
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 243,
                        "char": 61
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 243,
                    "last-line": 247,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getServerAddress",
                    "docblock": "**\n     * Gets active server address IP\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 248,
                                "char": 49
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 248,
                        "char": 49
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 248,
                    "last-line": 252,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getServerName",
                    "docblock": "**\n     * Gets active server name\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 253,
                                "char": 46
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 253,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 253,
                    "last-line": 258,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getUploadedFiles",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "onlySuccessful",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 259,
                                "char": 65
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 259,
                            "char": 65
                        },
                        {
                            "type": "parameter",
                            "name": "namedKeys",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 259,
                                "char": 89
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 259,
                            "char": 89
                        }
                    ],
                    "docblock": "**\n     * Gets attached files as Phalcon\\Http\\Request\\FileInterface compatible\n     * instances\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "cast": {
                                    "type": "variable",
                                    "value": "FileInterface",
                                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                    "line": 259,
                                    "char": 111
                                },
                                "collection": 1,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 259,
                                "char": 111
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 259,
                        "char": 111
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 259,
                    "last-line": 263,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "getUserAgent",
                    "docblock": "**\n     * Gets HTTP user agent used to made the request\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "string",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 264,
                                "char": 45
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 264,
                        "char": 45
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 264,
                    "last-line": 268,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "has",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 269,
                            "char": 37
                        }
                    ],
                    "docblock": "**\n     * Checks whether $_REQUEST superglobal has certain index\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 269,
                                "char": 46
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 269,
                        "char": 46
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 269,
                    "last-line": 274,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "hasFiles",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "onlySuccessful",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 275,
                                "char": 57
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 275,
                            "char": 57
                        }
                    ],
                    "docblock": "**\n     * Checks whether request include attached files\n     * TODO: We need to check the name. Not very intuitive\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "long",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 275,
                                "char": 66
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 275,
                        "char": 66
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 275,
                    "last-line": 279,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "hasHeader",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "header",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 280,
                            "char": 45
                        }
                    ],
                    "docblock": "**\n     * Checks whether headers has certain index\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 280,
                                "char": 54
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 280,
                        "char": 54
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 280,
                    "last-line": 284,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "hasQuery",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 285,
                            "char": 42
                        }
                    ],
                    "docblock": "**\n     * Checks whether $_GET superglobal has certain index\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 285,
                                "char": 51
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 285,
                        "char": 51
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 285,
                    "last-line": 289,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "hasPost",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 290,
                            "char": 41
                        }
                    ],
                    "docblock": "**\n     * Checks whether $_POST superglobal has certain index\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 290,
                                "char": 50
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 290,
                        "char": 50
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 290,
                    "last-line": 294,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "hasPut",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 295,
                            "char": 40
                        }
                    ],
                    "docblock": "**\n     * Checks whether the PUT data has certain index\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 295,
                                "char": 49
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 295,
                        "char": 49
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 295,
                    "last-line": 299,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "hasServer",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "name",
                            "const": 0,
                            "data-type": "string",
                            "mandatory": 1,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 300,
                            "char": 43
                        }
                    ],
                    "docblock": "**\n     * Checks whether $_SERVER superglobal has certain index\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 300,
                                "char": 52
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 300,
                        "char": 52
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 300,
                    "last-line": 304,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isAjax",
                    "docblock": "**\n     * Checks whether request has been made using ajax. Checks if $_SERVER[\"HTTP_X_REQUESTED_WITH\"] === \"XMLHttpRequest\"\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 305,
                                "char": 37
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 305,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 305,
                    "last-line": 309,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isConnect",
                    "docblock": "**\n     * Checks whether HTTP method is CONNECT. if $_SERVER[\"REQUEST_METHOD\"] === \"CONNECT\"\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 310,
                                "char": 40
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 310,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 310,
                    "last-line": 314,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isDelete",
                    "docblock": "**\n     * Checks whether HTTP method is DELETE. if $_SERVER[\"REQUEST_METHOD\"] === \"DELETE\"\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 315,
                                "char": 39
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 315,
                        "char": 39
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 315,
                    "last-line": 319,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isGet",
                    "docblock": "**\n     * Checks whether HTTP method is GET. if $_SERVER[\"REQUEST_METHOD\"] === \"GET\"\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 320,
                                "char": 36
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 320,
                        "char": 36
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 320,
                    "last-line": 324,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isHead",
                    "docblock": "**\n     * Checks whether HTTP method is HEAD. if $_SERVER[\"REQUEST_METHOD\"] === \"HEAD\"\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 325,
                                "char": 37
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 325,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 325,
                    "last-line": 331,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isMethod",
                    "parameters": [
                        {
                            "type": "parameter",
                            "name": "methods",
                            "const": 0,
                            "data-type": "variable",
                            "mandatory": 0,
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 332,
                            "char": 41
                        },
                        {
                            "type": "parameter",
                            "name": "strict",
                            "const": 0,
                            "data-type": "bool",
                            "mandatory": 0,
                            "default": {
                                "type": "bool",
                                "value": "false",
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 332,
                                "char": 62
                            },
                            "reference": 0,
                            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                            "line": 332,
                            "char": 62
                        }
                    ],
                    "docblock": "**\n     * Check if HTTP method match any of the passed methods\n     *\n     * @param string|array methods\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 332,
                                "char": 71
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 332,
                        "char": 71
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 332,
                    "last-line": 336,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isOptions",
                    "docblock": "**\n     * Checks whether HTTP method is OPTIONS. if $_SERVER[\"REQUEST_METHOD\"] === \"OPTIONS\"\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 337,
                                "char": 40
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 337,
                        "char": 40
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 337,
                    "last-line": 341,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isPost",
                    "docblock": "**\n     * Checks whether HTTP method is POST. if $_SERVER[\"REQUEST_METHOD\"] === \"POST\"\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 342,
                                "char": 37
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 342,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 342,
                    "last-line": 346,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isPurge",
                    "docblock": "**\n     * Checks whether HTTP method is PURGE (Squid and Varnish support). if $_SERVER[\"REQUEST_METHOD\"] === \"PURGE\"\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 347,
                                "char": 38
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 347,
                        "char": 38
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 347,
                    "last-line": 351,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isPut",
                    "docblock": "**\n     * Checks whether HTTP method is PUT. if $_SERVER[\"REQUEST_METHOD\"] === \"PUT\"\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 352,
                                "char": 36
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 352,
                        "char": 36
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 352,
                    "last-line": 356,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isSecure",
                    "docblock": "**\n     * Checks whether request has been made using any secure layer\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 357,
                                "char": 39
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 357,
                        "char": 39
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 357,
                    "last-line": 361,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isSoap",
                    "docblock": "**\n     * Checks whether request has been made using SOAP\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 362,
                                "char": 37
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 362,
                        "char": 37
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 362,
                    "last-line": 367,
                    "char": 19
                },
                {
                    "visibility": [
                        "public"
                    ],
                    "type": "method",
                    "name": "isTrace",
                    "docblock": "**\n     * Checks whether HTTP method is TRACE.\n     * if $_SERVER[\"REQUEST_METHOD\"] === \"TRACE\"\n     *",
                    "return-type": {
                        "type": "return-type",
                        "list": [
                            {
                                "type": "return-type-parameter",
                                "data-type": "bool",
                                "mandatory": 0,
                                "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                                "line": 368,
                                "char": 38
                            }
                        ],
                        "void": 0,
                        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                        "line": 368,
                        "char": 38
                    },
                    "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
                    "line": 368,
                    "last-line": 369,
                    "char": 19
                }
            ],
            "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
            "line": 369,
            "char": 1
        },
        "file": "\/app\/phalcon\/Http\/RequestInterface.zep",
        "line": 0,
        "char": 0
    }
]