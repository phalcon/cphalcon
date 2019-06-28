<?php return array (
  0 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *',
    'file' => '/app/phalcon/Http/RequestInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Http',
    'file' => '/app/phalcon/Http/RequestInterface.zep',
    'line' => 13,
    'char' => 3,
  ),
  2 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Http\\Request\\FileInterface',
        'file' => '/app/phalcon/Http/RequestInterface.zep',
        'line' => 13,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Http/RequestInterface.zep',
    'line' => 14,
    'char' => 3,
  ),
  3 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'stdClass',
        'file' => '/app/phalcon/Http/RequestInterface.zep',
        'line' => 14,
        'char' => 13,
      ),
    ),
    'file' => '/app/phalcon/Http/RequestInterface.zep',
    'line' => 18,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Interface for Phalcon\\Http\\Request
 *',
    'file' => '/app/phalcon/Http/RequestInterface.zep',
    'line' => 19,
    'char' => 9,
  ),
  5 => 
  array (
    'type' => 'interface',
    'name' => 'RequestInterface',
    'definition' => 
    array (
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'get',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 33,
                'char' => 44,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 33,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'filters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 33,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 33,
              'char' => 64,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultValue',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 33,
                'char' => 89,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 33,
              'char' => 89,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'notAllowEmpty',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 33,
                'char' => 117,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 33,
              'char' => 117,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'noRecursive',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 33,
                'char' => 143,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 33,
              'char' => 143,
            ),
          ),
          'docblock' => '**
     * Gets a variable from the $_REQUEST superglobal applying filters if
     * needed. If no parameters are given the $_REQUEST superglobal is returned
     *
     *```php
     * // Returns value from $_REQUEST["user_email"] without sanitizing
     * $userEmail = $request->get("user_email");
     *
     * // Returns value from $_REQUEST["user_email"] with sanitizing
     * $userEmail = $request->get("user_email", "email");
     *```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 33,
                'char' => 151,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 33,
            'char' => 151,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 33,
          'last-line' => 38,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getAcceptableContent',
          'docblock' => '**
     * Gets an array with mime/types and their quality accepted by the
     * browser/client from _SERVER["HTTP_ACCEPT"]
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 39,
                'char' => 52,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 39,
            'char' => 52,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 39,
          'last-line' => 44,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getBasicAuth',
          'docblock' => '**
     * Gets auth info accepted by the browser/client from
     * $_SERVER["PHP_AUTH_USER"]
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 45,
                'char' => 45,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 45,
                'char' => 51,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 45,
            'char' => 51,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 45,
          'last-line' => 50,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getBestAccept',
          'docblock' => '**
     * Gets best mime/type accepted by the browser/client from
     * _SERVER["HTTP_ACCEPT"]
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 51,
                'char' => 46,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 51,
            'char' => 46,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 51,
          'last-line' => 56,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getBestCharset',
          'docblock' => '**
     * Gets best charset accepted by the browser/client from
     * _SERVER["HTTP_ACCEPT_CHARSET"]
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 57,
                'char' => 47,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 57,
            'char' => 47,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 57,
          'last-line' => 62,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getBestLanguage',
          'docblock' => '**
     * Gets best language accepted by the browser/client from
     * _SERVER["HTTP_ACCEPT_LANGUAGE"]
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 63,
                'char' => 48,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 63,
            'char' => 48,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 63,
          'last-line' => 69,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getClientAddress',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'trustForwardedHeader',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 70,
                'char' => 71,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 70,
              'char' => 71,
            ),
          ),
          'docblock' => '**
     * Gets most possible client IPv4 Address. This method searches in
     * $_SERVER["REMOTE_ADDR"] and optionally in
     * $_SERVER["HTTP_X_FORWARDED_FOR"]
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 70,
                'char' => 83,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 70,
                'char' => 89,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 70,
            'char' => 89,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 70,
          'last-line' => 75,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getClientCharsets',
          'docblock' => '**
     * Gets a charsets array and their quality accepted by the browser/client
     * from _SERVER["HTTP_ACCEPT_CHARSET"]
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 76,
                'char' => 49,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 76,
            'char' => 49,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 76,
          'last-line' => 80,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getContentType',
          'docblock' => '**
     * Gets content type which request has been made
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 81,
                'char' => 48,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 81,
                'char' => 54,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 81,
            'char' => 54,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 81,
          'last-line' => 86,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDigestAuth',
          'docblock' => '**
     * Gets auth info accepted by the browser/client from
     * $_SERVER["PHP_AUTH_DIGEST"]
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 87,
                'char' => 45,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 87,
            'char' => 45,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 87,
          'last-line' => 91,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getHeader',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'header',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 92,
              'char' => 45,
            ),
          ),
          'docblock' => '**
     * Gets HTTP header from request data
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 92,
                'char' => 56,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 92,
            'char' => 56,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 92,
          'last-line' => 107,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getHeaders',
          'docblock' => '**
     * Returns the available headers in the request
     *
     * ```php
     * $_SERVER = [
     *     "PHP_AUTH_USER" => "phalcon",
     *     "PHP_AUTH_PW"   => "secret",
     * ];
     *
     * $headers = $request->getHeaders();
     *
     * echo $headers["Authorization"]; // Basic cGhhbGNvbjpzZWNyZXQ=
     * ```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 108,
                'char' => 42,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 108,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 108,
          'last-line' => 143,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getHttpHost',
          'docblock' => '**
     * Gets host name used by the request.
     *
     * `Request::getHttpHost` trying to find host name in following order:
     *
     * - `$_SERVER["HTTP_HOST"]`
     * - `$_SERVER["SERVER_NAME"]`
     * - `$_SERVER["SERVER_ADDR"]`
     *
     * Optionally `Request::getHttpHost` validates and clean host name.
     * The `Request::$_strictHostCheck` can be used to validate host name.
     *
     * Note: validation and cleaning have a negative performance impact because
     * they use regular expressions.
     *
     * ```php
     * use Phalcon\\Http\\Request;
     *
     * $request = new Request;
     *
     * $_SERVER["HTTP_HOST"] = "example.com";
     * $request->getHttpHost(); // example.com
     *
     * $_SERVER["HTTP_HOST"] = "example.com:8080";
     * $request->getHttpHost(); // example.com:8080
     *
     * $request->setStrictHostCheck(true);
     * $_SERVER["HTTP_HOST"] = "ex=am~ple.com";
     * $request->getHttpHost(); // UnexpectedValueException
     *
     * $_SERVER["HTTP_HOST"] = "ExAmPlE.com";
     * $request->getHttpHost(); // example.com
     * ```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 144,
                'char' => 44,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 144,
            'char' => 44,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 144,
          'last-line' => 148,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getHTTPReferer',
          'docblock' => '**
     * Gets web page that refers active request. ie: http://www.google.com
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 149,
                'char' => 47,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 149,
            'char' => 47,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 149,
          'last-line' => 153,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getJsonRawBody',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'associative',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 154,
                'char' => 60,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 154,
              'char' => 60,
            ),
          ),
          'docblock' => '**
     * Gets decoded JSON HTTP raw request body
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'stdClass',
                  'file' => '/app/phalcon/Http/RequestInterface.zep',
                  'line' => 154,
                  'char' => 76,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 154,
                'char' => 76,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 154,
                'char' => 84,
              ),
              2 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 154,
                'char' => 90,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 154,
            'char' => 90,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 154,
          'last-line' => 159,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getLanguages',
          'docblock' => '**
     * Gets languages array and their quality accepted by the browser/client
     * from _SERVER["HTTP_ACCEPT_LANGUAGE"]
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 160,
                'char' => 44,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 160,
            'char' => 44,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 160,
          'last-line' => 172,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getMethod',
          'docblock' => '**
     * Gets HTTP method which request has been made
     *
     * If the X-HTTP-Method-Override header is set, and if the method is a POST,
     * then it is used to determine the "real" intended HTTP method.
     *
     * The _method request parameter can also be used to determine the HTTP
     * method, but only if setHttpMethodParameterOverride(true) has been called.
     *
     * The method is always an uppercased string.
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 173,
                'char' => 42,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 173,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 173,
          'last-line' => 177,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getPort',
          'docblock' => '**
     * Gets information about the port on which the request is made
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 178,
                'char' => 37,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 178,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 178,
          'last-line' => 182,
          'char' => 19,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
          ),
          'type' => 'method',
          'name' => 'getURI',
          'docblock' => '**
     * Gets HTTP URI which request has been made
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 183,
                'char' => 45,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 183,
            'char' => 45,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 183,
          'last-line' => 196,
          'char' => 25,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getPost',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 197,
                'char' => 48,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 197,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'filters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 197,
                'char' => 68,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 197,
              'char' => 68,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultValue',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 197,
                'char' => 93,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 197,
              'char' => 93,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'notAllowEmpty',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 197,
                'char' => 121,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 197,
              'char' => 121,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'noRecursive',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 197,
                'char' => 147,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 197,
              'char' => 147,
            ),
          ),
          'docblock' => '**
     * Gets a variable from the $_POST superglobal applying filters if needed
     * If no parameters are given the $_POST superglobal is returned
     *
     *```php
     * // Returns value from $_POST["user_email"] without sanitizing
     * $userEmail = $request->getPost("user_email");
     *
     * // Returns value from $_POST["user_email"] with sanitizing
     * $userEmail = $request->getPost("user_email", "email");
     *```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 197,
                'char' => 155,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 197,
            'char' => 155,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 197,
          'last-line' => 209,
          'char' => 19,
        ),
        20 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getPut',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 210,
                'char' => 47,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 210,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'filters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 210,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 210,
              'char' => 67,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultValue',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 210,
                'char' => 92,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 210,
              'char' => 92,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'notAllowEmpty',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 210,
                'char' => 120,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 210,
              'char' => 120,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'noRecursive',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 210,
                'char' => 146,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 210,
              'char' => 146,
            ),
          ),
          'docblock' => '**
     * Gets a variable from put request
     *
     *```php
     * // Returns value from $_PUT["user_email"] without sanitizing
     * $userEmail = $request->getPut("user_email");
     *
     * // Returns value from $_PUT["user_email"] with sanitizing
     * $userEmail = $request->getPut("user_email", "email");
     *```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 210,
                'char' => 154,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 210,
            'char' => 154,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 210,
          'last-line' => 226,
          'char' => 19,
        ),
        21 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getQuery',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 227,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 227,
              'char' => 49,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'filters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 227,
                'char' => 69,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 227,
              'char' => 69,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultValue',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 227,
                'char' => 94,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 227,
              'char' => 94,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'notAllowEmpty',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 227,
                'char' => 122,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 227,
              'char' => 122,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'noRecursive',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 227,
                'char' => 148,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 227,
              'char' => 148,
            ),
          ),
          'docblock' => '**
     * Gets variable from $_GET superglobal applying filters if needed
     * If no parameters are given the $_GET superglobal is returned
     *
     *```php
     * // Returns value from $_GET["id"] without sanitizing
     * $id = $request->getQuery("id");
     *
     * // Returns value from $_GET["id"] with sanitizing
     * $id = $request->getQuery("id", "int");
     *
     * // Returns value from $_GET["id"] with a default value
     * $id = $request->getQuery("id", null, 150);
     *```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 227,
                'char' => 156,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 227,
            'char' => 156,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 227,
          'last-line' => 231,
          'char' => 19,
        ),
        22 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRawBody',
          'docblock' => '**
     * Gets HTTP raw request body
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 232,
                'char' => 43,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 232,
            'char' => 43,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 232,
          'last-line' => 236,
          'char' => 19,
        ),
        23 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getScheme',
          'docblock' => '**
     * Gets HTTP schema (http/https)
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 237,
                'char' => 42,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 237,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 237,
          'last-line' => 242,
          'char' => 19,
        ),
        24 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getServer',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 243,
              'char' => 43,
            ),
          ),
          'docblock' => '**
     * Gets variable from $_SERVER superglobal
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 243,
                'char' => 55,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 243,
                'char' => 61,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 243,
            'char' => 61,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 243,
          'last-line' => 247,
          'char' => 19,
        ),
        25 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getServerAddress',
          'docblock' => '**
     * Gets active server address IP
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 248,
                'char' => 49,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 248,
            'char' => 49,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 248,
          'last-line' => 252,
          'char' => 19,
        ),
        26 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getServerName',
          'docblock' => '**
     * Gets active server name
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 253,
                'char' => 46,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 253,
            'char' => 46,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 253,
          'last-line' => 258,
          'char' => 19,
        ),
        27 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getUploadedFiles',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'onlySuccessful',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 259,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 259,
              'char' => 65,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'namedKeys',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 259,
                'char' => 89,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 259,
              'char' => 89,
            ),
          ),
          'docblock' => '**
     * Gets attached files as Phalcon\\Http\\Request\\FileInterface compatible
     * instances
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'FileInterface',
                  'file' => '/app/phalcon/Http/RequestInterface.zep',
                  'line' => 259,
                  'char' => 111,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 259,
                'char' => 111,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 259,
            'char' => 111,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 259,
          'last-line' => 263,
          'char' => 19,
        ),
        28 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getUserAgent',
          'docblock' => '**
     * Gets HTTP user agent used to made the request
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 264,
                'char' => 45,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 264,
            'char' => 45,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 264,
          'last-line' => 268,
          'char' => 19,
        ),
        29 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'has',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 269,
              'char' => 37,
            ),
          ),
          'docblock' => '**
     * Checks whether $_REQUEST superglobal has certain index
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 269,
                'char' => 46,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 269,
            'char' => 46,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 269,
          'last-line' => 274,
          'char' => 19,
        ),
        30 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'hasFiles',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'onlySuccessful',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 275,
                'char' => 57,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 275,
              'char' => 57,
            ),
          ),
          'docblock' => '**
     * Checks whether request include attached files
     * TODO: We need to check the name. Not very intuitive
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'long',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 275,
                'char' => 66,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 275,
            'char' => 66,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 275,
          'last-line' => 279,
          'char' => 19,
        ),
        31 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'hasHeader',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'header',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 280,
              'char' => 45,
            ),
          ),
          'docblock' => '**
     * Checks whether headers has certain index
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 280,
                'char' => 54,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 280,
            'char' => 54,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 280,
          'last-line' => 284,
          'char' => 19,
        ),
        32 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'hasQuery',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 285,
              'char' => 42,
            ),
          ),
          'docblock' => '**
     * Checks whether $_GET superglobal has certain index
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 285,
                'char' => 51,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 285,
            'char' => 51,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 285,
          'last-line' => 289,
          'char' => 19,
        ),
        33 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'hasPost',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 290,
              'char' => 41,
            ),
          ),
          'docblock' => '**
     * Checks whether $_POST superglobal has certain index
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 290,
                'char' => 50,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 290,
            'char' => 50,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 290,
          'last-line' => 294,
          'char' => 19,
        ),
        34 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'hasPut',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 295,
              'char' => 40,
            ),
          ),
          'docblock' => '**
     * Checks whether the PUT data has certain index
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 295,
                'char' => 49,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 295,
            'char' => 49,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 295,
          'last-line' => 299,
          'char' => 19,
        ),
        35 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'hasServer',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 300,
              'char' => 43,
            ),
          ),
          'docblock' => '**
     * Checks whether $_SERVER superglobal has certain index
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 300,
                'char' => 52,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 300,
            'char' => 52,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 300,
          'last-line' => 304,
          'char' => 19,
        ),
        36 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isAjax',
          'docblock' => '**
     * Checks whether request has been made using ajax. Checks if $_SERVER["HTTP_X_REQUESTED_WITH"] === "XMLHttpRequest"
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 305,
                'char' => 37,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 305,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 305,
          'last-line' => 309,
          'char' => 19,
        ),
        37 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isConnect',
          'docblock' => '**
     * Checks whether HTTP method is CONNECT. if $_SERVER["REQUEST_METHOD"] === "CONNECT"
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 310,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 310,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 310,
          'last-line' => 314,
          'char' => 19,
        ),
        38 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isDelete',
          'docblock' => '**
     * Checks whether HTTP method is DELETE. if $_SERVER["REQUEST_METHOD"] === "DELETE"
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 315,
                'char' => 39,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 315,
            'char' => 39,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 315,
          'last-line' => 319,
          'char' => 19,
        ),
        39 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isGet',
          'docblock' => '**
     * Checks whether HTTP method is GET. if $_SERVER["REQUEST_METHOD"] === "GET"
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 320,
                'char' => 36,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 320,
            'char' => 36,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 320,
          'last-line' => 324,
          'char' => 19,
        ),
        40 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isHead',
          'docblock' => '**
     * Checks whether HTTP method is HEAD. if $_SERVER["REQUEST_METHOD"] === "HEAD"
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 325,
                'char' => 37,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 325,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 325,
          'last-line' => 331,
          'char' => 19,
        ),
        41 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isMethod',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'methods',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 332,
              'char' => 41,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'strict',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 332,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/RequestInterface.zep',
              'line' => 332,
              'char' => 62,
            ),
          ),
          'docblock' => '**
     * Check if HTTP method match any of the passed methods
     *
     * @param string|array methods
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 332,
                'char' => 71,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 332,
            'char' => 71,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 332,
          'last-line' => 336,
          'char' => 19,
        ),
        42 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isOptions',
          'docblock' => '**
     * Checks whether HTTP method is OPTIONS. if $_SERVER["REQUEST_METHOD"] === "OPTIONS"
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 337,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 337,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 337,
          'last-line' => 341,
          'char' => 19,
        ),
        43 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isPost',
          'docblock' => '**
     * Checks whether HTTP method is POST. if $_SERVER["REQUEST_METHOD"] === "POST"
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 342,
                'char' => 37,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 342,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 342,
          'last-line' => 346,
          'char' => 19,
        ),
        44 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isPurge',
          'docblock' => '**
     * Checks whether HTTP method is PURGE (Squid and Varnish support). if $_SERVER["REQUEST_METHOD"] === "PURGE"
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 347,
                'char' => 38,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 347,
            'char' => 38,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 347,
          'last-line' => 351,
          'char' => 19,
        ),
        45 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isPut',
          'docblock' => '**
     * Checks whether HTTP method is PUT. if $_SERVER["REQUEST_METHOD"] === "PUT"
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 352,
                'char' => 36,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 352,
            'char' => 36,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 352,
          'last-line' => 356,
          'char' => 19,
        ),
        46 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isSecure',
          'docblock' => '**
     * Checks whether request has been made using any secure layer
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 357,
                'char' => 39,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 357,
            'char' => 39,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 357,
          'last-line' => 361,
          'char' => 19,
        ),
        47 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isSoap',
          'docblock' => '**
     * Checks whether request has been made using SOAP
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 362,
                'char' => 37,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 362,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 362,
          'last-line' => 367,
          'char' => 19,
        ),
        48 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isTrace',
          'docblock' => '**
     * Checks whether HTTP method is TRACE.
     * if $_SERVER["REQUEST_METHOD"] === "TRACE"
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/RequestInterface.zep',
                'line' => 368,
                'char' => 38,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/RequestInterface.zep',
            'line' => 368,
            'char' => 38,
          ),
          'file' => '/app/phalcon/Http/RequestInterface.zep',
          'line' => 368,
          'last-line' => 369,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Http/RequestInterface.zep',
      'line' => 369,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Http/RequestInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);