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
    'file' => '/app/phalcon/Http/Request.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Http',
    'file' => '/app/phalcon/Http/Request.zep',
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
        'name' => 'Phalcon\\DiInterface',
        'file' => '/app/phalcon/Http/Request.zep',
        'line' => 13,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Http/Request.zep',
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
        'name' => 'Phalcon\\Filter\\FilterInterface',
        'file' => '/app/phalcon/Http/Request.zep',
        'line' => 14,
        'char' => 35,
      ),
    ),
    'file' => '/app/phalcon/Http/Request.zep',
    'line' => 15,
    'char' => 3,
  ),
  4 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Http\\Request\\File',
        'file' => '/app/phalcon/Http/Request.zep',
        'line' => 15,
        'char' => 30,
      ),
    ),
    'file' => '/app/phalcon/Http/Request.zep',
    'line' => 16,
    'char' => 3,
  ),
  5 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Http\\Request\\FileInterface',
        'file' => '/app/phalcon/Http/Request.zep',
        'line' => 16,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Http/Request.zep',
    'line' => 17,
    'char' => 3,
  ),
  6 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Http\\Request\\Exception',
        'file' => '/app/phalcon/Http/Request.zep',
        'line' => 17,
        'char' => 35,
      ),
    ),
    'file' => '/app/phalcon/Http/Request.zep',
    'line' => 18,
    'char' => 3,
  ),
  7 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Events\\ManagerInterface',
        'file' => '/app/phalcon/Http/Request.zep',
        'line' => 18,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Http/Request.zep',
    'line' => 19,
    'char' => 3,
  ),
  8 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Di\\InjectionAwareInterface',
        'file' => '/app/phalcon/Http/Request.zep',
        'line' => 19,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Http/Request.zep',
    'line' => 20,
    'char' => 3,
  ),
  9 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'UnexpectedValueException',
        'file' => '/app/phalcon/Http/Request.zep',
        'line' => 20,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Http/Request.zep',
    'line' => 21,
    'char' => 3,
  ),
  10 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'stdClass',
        'file' => '/app/phalcon/Http/Request.zep',
        'line' => 21,
        'char' => 13,
      ),
    ),
    'file' => '/app/phalcon/Http/Request.zep',
    'line' => 48,
    'char' => 2,
  ),
  11 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Encapsulates request information for easy and secure access from application
 * controllers.
 *
 * The request object is a simple value object that is passed between the
 * dispatcher and controller classes. It packages the HTTP request environment.
 *
 *```php
 * use Phalcon\\Http\\Request;
 *
 * $request = new Request();
 *
 * if ($request->isPost() && $request->isAjax()) {
 *     echo "Request was made using POST and AJAX";
 * }
 *
 * // Retrieve SERVER variables
 * $request->getServer("HTTP_HOST");
 *
 * // GET, POST, PUT, DELETE, HEAD, OPTIONS, PATCH, PURGE, TRACE, CONNECT
 * $request->getMethod();
 *
 * // An array of languages the client accepts
 * $request->getLanguages();
 *```
 *',
    'file' => '/app/phalcon/Http/Request.zep',
    'line' => 49,
    'char' => 5,
  ),
  12 => 
  array (
    'type' => 'class',
    'name' => 'Request',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'RequestInterface',
        'file' => '/app/phalcon/Http/Request.zep',
        'line' => 49,
        'char' => 42,
      ),
      1 => 
      array (
        'type' => 'variable',
        'value' => 'InjectionAwareInterface',
        'file' => '/app/phalcon/Http/Request.zep',
        'line' => 50,
        'char' => 1,
      ),
    ),
    'definition' => 
    array (
      'properties' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'container',
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 53,
          'char' => 11,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'filterService',
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 57,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'httpMethodParameterOverride',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 58,
            'char' => 49,
          ),
          'docblock' => '**
     * @var bool
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 58,
              'char' => 54,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 58,
              'char' => 60,
            ),
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 62,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'queryFilters',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 63,
            'char' => 30,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 65,
          'char' => 11,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'putCache',
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 67,
          'char' => 11,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'rawBody',
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 71,
          'char' => 6,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'strictHostCheck',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 72,
            'char' => 36,
          ),
          'docblock' => '**
     * @var bool
     *',
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 85,
          'char' => 6,
        ),
      ),
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 86,
                'char' => 44,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 86,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 86,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 86,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 86,
                'char' => 89,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 86,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 86,
                'char' => 117,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 86,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 86,
                'char' => 143,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 86,
              'char' => 143,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 88,
                  'char' => 21,
                ),
                'name' => 'getHelper',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => '_REQUEST',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 89,
                      'char' => 21,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 89,
                    'char' => 21,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 90,
                      'char' => 17,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 90,
                    'char' => 17,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'filters',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 91,
                      'char' => 20,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 91,
                    'char' => 20,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'defaultValue',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 92,
                      'char' => 25,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 92,
                    'char' => 25,
                  ),
                  4 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'notAllowEmpty',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 93,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 93,
                    'char' => 26,
                  ),
                  5 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'noRecursive',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 95,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 95,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 95,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 96,
              'char' => 5,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 87,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 87,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 86,
          'last-line' => 101,
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
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 104,
                  'char' => 21,
                ),
                'name' => 'getQualityHeader',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'HTTP_ACCEPT',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 104,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 104,
                    'char' => 50,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'accept',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 104,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 104,
                    'char' => 58,
                  ),
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 104,
                'char' => 59,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 105,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 103,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 103,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 102,
          'last-line' => 110,
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
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'or',
                'left' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'isset',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => '_SERVER',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 113,
                        'char' => 26,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'PHP_AUTH_USER',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 113,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 113,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 113,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 113,
                  'char' => 43,
                ),
                'right' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'isset',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => '_SERVER',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 113,
                        'char' => 59,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'PHP_AUTH_PW',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 113,
                        'char' => 71,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 113,
                      'char' => 73,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 113,
                    'char' => 73,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 113,
                  'char' => 73,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 113,
                'char' => 73,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 114,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 115,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 117,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'array',
                'left' => 
                array (
                  0 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'username',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 118,
                      'char' => 21,
                    ),
                    'value' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => '_SERVER',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 118,
                        'char' => 30,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'PHP_AUTH_USER',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 118,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 118,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 118,
                    'char' => 45,
                  ),
                  1 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'password',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 119,
                      'char' => 21,
                    ),
                    'value' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => '_SERVER',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 119,
                        'char' => 30,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'PHP_AUTH_PW',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 119,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 120,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 120,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 120,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 121,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 111,
                'char' => 45,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 112,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 112,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 111,
          'last-line' => 126,
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
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 129,
                  'char' => 21,
                ),
                'name' => 'getBestQuality',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 129,
                        'char' => 42,
                      ),
                      'name' => 'getAcceptableContent',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 129,
                      'char' => 65,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 129,
                    'char' => 65,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'accept',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 129,
                      'char' => 73,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 129,
                    'char' => 73,
                  ),
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 129,
                'char' => 74,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 130,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 128,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 128,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 127,
          'last-line' => 135,
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
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 138,
                  'char' => 21,
                ),
                'name' => 'getBestQuality',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 138,
                        'char' => 42,
                      ),
                      'name' => 'getClientCharsets',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 138,
                      'char' => 62,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 138,
                    'char' => 62,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'charset',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 138,
                      'char' => 71,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 138,
                    'char' => 71,
                  ),
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 138,
                'char' => 72,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 139,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 137,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 137,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 136,
          'last-line' => 144,
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
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 147,
                  'char' => 21,
                ),
                'name' => 'getBestQuality',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 147,
                        'char' => 42,
                      ),
                      'name' => 'getLanguages',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 147,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 147,
                    'char' => 57,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'language',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 147,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 147,
                    'char' => 67,
                  ),
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 147,
                'char' => 68,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 148,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 146,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 146,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 145,
          'last-line' => 154,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 155,
                'char' => 71,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 155,
              'char' => 71,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'address',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 157,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 157,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 162,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'trustForwardedHeader',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 162,
                'char' => 33,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'fetch',
                  'expr' => 
                  array (
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'address',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 163,
                      'char' => 57,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => '_SERVER',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 163,
                        'char' => 35,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'HTTP_X_FORWARDED_FOR',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 163,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 163,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 163,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 165,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'address',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 165,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 165,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 165,
                    'char' => 33,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'fetch',
                      'expr' => 
                      array (
                        'type' => 'fetch',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'address',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 166,
                          'char' => 55,
                        ),
                        'right' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => '_SERVER',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 166,
                            'char' => 39,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'HTTP_CLIENT_IP',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 166,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 166,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 166,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 167,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 168,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 170,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'address',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 170,
                  'char' => 22,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 170,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 170,
                'char' => 29,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'fetch',
                  'expr' => 
                  array (
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'address',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 171,
                      'char' => 48,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => '_SERVER',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 171,
                        'char' => 35,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'REMOTE_ADDR',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 171,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 171,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 171,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 172,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 174,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'address',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 174,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 174,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'string',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 174,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 174,
                'char' => 37,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 175,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 176,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 178,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'memstr',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'address',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 178,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 178,
                    'char' => 26,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => ',',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 178,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 178,
                    'char' => 29,
                  ),
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 178,
                'char' => 31,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'explode',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => ',',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 183,
                            'char' => 29,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 183,
                          'char' => 29,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'address',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 183,
                            'char' => 38,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 183,
                          'char' => 38,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 183,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 183,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 183,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 184,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 186,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'address',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 186,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 187,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets most possible client IPv4 Address. This method searches in
     * `$_SERVER["REMOTE_ADDR"]` and optionally in
     * `$_SERVER["HTTP_X_FORWARDED_FOR"]`
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 155,
                'char' => 83,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 156,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 156,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 155,
          'last-line' => 192,
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
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 195,
                  'char' => 21,
                ),
                'name' => 'getQualityHeader',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'HTTP_ACCEPT_CHARSET',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 195,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 195,
                    'char' => 58,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'charset',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 195,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 195,
                    'char' => 67,
                  ),
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 195,
                'char' => 68,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 196,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 194,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 194,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 193,
          'last-line' => 200,
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
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'contentType',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 203,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 205,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'contentType',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 205,
                    'char' => 54,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => '_SERVER',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 205,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'CONTENT_TYPE',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 205,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 205,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 205,
                  'char' => 54,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 205,
                'char' => 54,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 206,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 207,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 209,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'contentType',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 209,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 210,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 201,
                'char' => 48,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 202,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 202,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 201,
          'last-line' => 215,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDI',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 218,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'container',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 218,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 218,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 219,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the internal dependency injector
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
                  'value' => 'DiInterface',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 217,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 217,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 217,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 216,
          'last-line' => 224,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDigestAuth',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'digest',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 227,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'matches',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 227,
                  'char' => 28,
                ),
                2 => 
                array (
                  'variable' => 'match',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 227,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 228,
              'char' => 13,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'array',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'auth',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 228,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 230,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'auth',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 230,
                    'char' => 22,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 230,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 232,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'digest',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 232,
                  'char' => 51,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => '_SERVER',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 232,
                    'char' => 33,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'PHP_AUTH_DIGEST',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 232,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 232,
                  'char' => 51,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 232,
                'char' => 51,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'matches',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 233,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 233,
                      'char' => 29,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 235,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'preg_match_all',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => '#(\\\\w+)=([\'\\"]?)([^\'\\" ,]+)\\\\2#',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 235,
                            'char' => 63,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 235,
                          'char' => 63,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'digest',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 235,
                            'char' => 71,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 235,
                          'char' => 71,
                        ),
                        2 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'matches',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 235,
                            'char' => 80,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 235,
                          'char' => 80,
                        ),
                        3 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'int',
                            'value' => '2',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 235,
                            'char' => 83,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 235,
                          'char' => 83,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 235,
                      'char' => 85,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 235,
                    'char' => 85,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'auth',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 236,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 237,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 239,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'matches',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 239,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 239,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 239,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 239,
                    'char' => 40,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'for',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'matches',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 240,
                        'char' => 38,
                      ),
                      'value' => 'match',
                      'reverse' => 0,
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'auth',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'match',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 241,
                                    'char' => 35,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '1',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 241,
                                    'char' => 37,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 241,
                                  'char' => 38,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'array-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'match',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 241,
                                  'char' => 47,
                                ),
                                'right' => 
                                array (
                                  'type' => 'int',
                                  'value' => '3',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 241,
                                  'char' => 49,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 241,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 241,
                              'char' => 50,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 242,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 243,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 244,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 246,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'auth',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 246,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 247,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 226,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 226,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 225,
          'last-line' => 251,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getFilteredQuery',
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 252,
                'char' => 57,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 252,
              'char' => 57,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultValue',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 252,
                'char' => 82,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 252,
              'char' => 82,
            ),
            2 => 
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 252,
                'char' => 110,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 252,
              'char' => 110,
            ),
            3 => 
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 252,
                'char' => 136,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 252,
              'char' => 136,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'filters',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 254,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 256,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'filters',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 256,
                    'char' => 58,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 256,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'queryFilters',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 256,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 256,
                        'char' => 46,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'get',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 256,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 256,
                      'char' => 51,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 256,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 256,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 256,
                  'char' => 58,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 256,
                'char' => 58,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'filters',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 257,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 257,
                      'char' => 29,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 258,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 260,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 260,
                  'char' => 21,
                ),
                'name' => 'getQuery',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 261,
                      'char' => 17,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 261,
                    'char' => 17,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'filters',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 262,
                      'char' => 20,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 262,
                    'char' => 20,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'defaultValue',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 263,
                      'char' => 25,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 263,
                    'char' => 25,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'notAllowEmpty',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 264,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 264,
                    'char' => 26,
                  ),
                  4 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'noRecursive',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 266,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 266,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 266,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 267,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Retrieves a query/get value always sanitized with the preset filters
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 253,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 253,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 252,
          'last-line' => 271,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getFilteredPost',
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 272,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 272,
              'char' => 56,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultValue',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 272,
                'char' => 81,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 272,
              'char' => 81,
            ),
            2 => 
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 272,
                'char' => 109,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 272,
              'char' => 109,
            ),
            3 => 
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 272,
                'char' => 135,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 272,
              'char' => 135,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'filters',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 274,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 276,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'filters',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 276,
                    'char' => 59,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 276,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'queryFilters',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 276,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 276,
                        'char' => 46,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'post',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 276,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 276,
                      'char' => 52,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 276,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 276,
                    'char' => 59,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 276,
                  'char' => 59,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 276,
                'char' => 59,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'filters',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 277,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 277,
                      'char' => 29,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 278,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 280,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 280,
                  'char' => 21,
                ),
                'name' => 'getPost',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 281,
                      'char' => 17,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 281,
                    'char' => 17,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'filters',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 282,
                      'char' => 20,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 282,
                    'char' => 20,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'defaultValue',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 283,
                      'char' => 25,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 283,
                    'char' => 25,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'notAllowEmpty',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 284,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 284,
                    'char' => 26,
                  ),
                  4 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'noRecursive',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 286,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 286,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 286,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 287,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Retrieves a post value always sanitized with the preset filters
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 273,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 273,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 272,
          'last-line' => 291,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getFilteredPut',
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 292,
                'char' => 55,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 292,
              'char' => 55,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultValue',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 292,
                'char' => 80,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 292,
              'char' => 80,
            ),
            2 => 
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 292,
                'char' => 108,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 292,
              'char' => 108,
            ),
            3 => 
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 292,
                'char' => 134,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 292,
              'char' => 134,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'filters',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 294,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 296,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'filters',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 296,
                    'char' => 58,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 296,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'queryFilters',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 296,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 296,
                        'char' => 46,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'put',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 296,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 296,
                      'char' => 51,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 296,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 296,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 296,
                  'char' => 58,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 296,
                'char' => 58,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'filters',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 297,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 297,
                      'char' => 29,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 298,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 300,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 300,
                  'char' => 21,
                ),
                'name' => 'getPut',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 301,
                      'char' => 17,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 301,
                    'char' => 17,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'filters',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 302,
                      'char' => 20,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 302,
                    'char' => 20,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'defaultValue',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 303,
                      'char' => 25,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 303,
                    'char' => 25,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'notAllowEmpty',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 304,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 304,
                    'char' => 26,
                  ),
                  4 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'noRecursive',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 306,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 306,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 306,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 307,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Retrieves a put value always sanitized with the preset filters
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 293,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 293,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 292,
          'last-line' => 311,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
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
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 312,
              'char' => 51,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 314,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'name',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 314,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 316,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'name',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'strtoupper',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'strtr',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'header',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 317,
                                'char' => 25,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 317,
                              'char' => 25,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => '-',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 317,
                                'char' => 28,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 317,
                              'char' => 28,
                            ),
                            2 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => '_',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 317,
                                'char' => 31,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 317,
                              'char' => 31,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 318,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 318,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 318,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 318,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 320,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'value',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 320,
                  'char' => 39,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => '_SERVER',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 320,
                    'char' => 32,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'name',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 320,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 320,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 320,
                'char' => 39,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'value',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 321,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 322,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 324,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'value',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 324,
                  'char' => 47,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => '_SERVER',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 324,
                    'char' => 32,
                  ),
                  'right' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'string',
                      'value' => 'HTTP_',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 324,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 324,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 324,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 324,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 324,
                'char' => 47,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'value',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 325,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 326,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 328,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'string',
                'value' => '',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 328,
                'char' => 16,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 329,
              'char' => 5,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 313,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 313,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 312,
          'last-line' => 344,
          'char' => 25,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getHeaders',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'name',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 347,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 347,
                  'char' => 24,
                ),
                2 => 
                array (
                  'variable' => 'authHeaders',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 347,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 349,
              'char' => 13,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'array',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'headers',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 349,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 349,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 351,
              'char' => 13,
            ),
            2 => 
            array (
              'type' => 'declare',
              'data-type' => 'array',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'contentHeaders',
                  'expr' => 
                  array (
                    'type' => 'array',
                    'left' => 
                    array (
                      0 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'CONTENT_TYPE',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 352,
                          'char' => 25,
                        ),
                        'value' => 
                        array (
                          'type' => 'bool',
                          'value' => 'true',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 352,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 352,
                        'char' => 33,
                      ),
                      1 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'CONTENT_LENGTH',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 353,
                          'char' => 27,
                        ),
                        'value' => 
                        array (
                          'type' => 'bool',
                          'value' => 'true',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 353,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 353,
                        'char' => 33,
                      ),
                      2 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'CONTENT_MD5',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 354,
                          'char' => 24,
                        ),
                        'value' => 
                        array (
                          'type' => 'bool',
                          'value' => 'true',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 355,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 355,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 355,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 355,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 357,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => '_SERVER',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 357,
                'char' => 36,
              ),
              'key' => 'name',
              'value' => 'value',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'starts_with',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 359,
                          'char' => 32,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 359,
                        'char' => 32,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'HTTP_',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 359,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 359,
                        'char' => 39,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 359,
                    'char' => 41,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'name',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'ucwords',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'fcall',
                                  'name' => 'strtolower',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'fcall',
                                        'name' => 'str_replace',
                                        'call-type' => 1,
                                        'parameters' => 
                                        array (
                                          0 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'string',
                                              'value' => '_',
                                              'file' => '/app/phalcon/Http/Request.zep',
                                              'line' => 363,
                                              'char' => 30,
                                            ),
                                            'file' => '/app/phalcon/Http/Request.zep',
                                            'line' => 363,
                                            'char' => 30,
                                          ),
                                          1 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'string',
                                              'value' => ' ',
                                              'file' => '/app/phalcon/Http/Request.zep',
                                              'line' => 364,
                                              'char' => 30,
                                            ),
                                            'file' => '/app/phalcon/Http/Request.zep',
                                            'line' => 364,
                                            'char' => 30,
                                          ),
                                          2 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'fcall',
                                              'name' => 'substr',
                                              'call-type' => 1,
                                              'parameters' => 
                                              array (
                                                0 => 
                                                array (
                                                  'parameter' => 
                                                  array (
                                                    'type' => 'variable',
                                                    'value' => 'name',
                                                    'file' => '/app/phalcon/Http/Request.zep',
                                                    'line' => 365,
                                                    'char' => 40,
                                                  ),
                                                  'file' => '/app/phalcon/Http/Request.zep',
                                                  'line' => 365,
                                                  'char' => 40,
                                                ),
                                                1 => 
                                                array (
                                                  'parameter' => 
                                                  array (
                                                    'type' => 'int',
                                                    'value' => '5',
                                                    'file' => '/app/phalcon/Http/Request.zep',
                                                    'line' => 365,
                                                    'char' => 43,
                                                  ),
                                                  'file' => '/app/phalcon/Http/Request.zep',
                                                  'line' => 365,
                                                  'char' => 43,
                                                ),
                                              ),
                                              'file' => '/app/phalcon/Http/Request.zep',
                                              'line' => 366,
                                              'char' => 25,
                                            ),
                                            'file' => '/app/phalcon/Http/Request.zep',
                                            'line' => 366,
                                            'char' => 25,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Http/Request.zep',
                                        'line' => 367,
                                        'char' => 21,
                                      ),
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 367,
                                      'char' => 21,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 368,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 368,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 368,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 368,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 370,
                      'char' => 19,
                    ),
                    1 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'name',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'str_replace',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => ' ',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 370,
                                  'char' => 41,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 370,
                                'char' => 41,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => '-',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 370,
                                  'char' => 44,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 370,
                                'char' => 44,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'name',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 370,
                                  'char' => 50,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 370,
                                'char' => 50,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 370,
                            'char' => 51,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 370,
                          'char' => 51,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 372,
                      'char' => 19,
                    ),
                    2 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'headers',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'name',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 372,
                              'char' => 33,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'value',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 372,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 372,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 374,
                      'char' => 24,
                    ),
                    3 => 
                    array (
                      'type' => 'continue',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 375,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 378,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'name',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'strtoupper',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'name',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 378,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 378,
                            'char' => 39,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 378,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 378,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 380,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'isset',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'contentHeaders',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 380,
                        'char' => 36,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'name',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 380,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 380,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 380,
                    'char' => 43,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'name',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'ucwords',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'fcall',
                                  'name' => 'strtolower',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'fcall',
                                        'name' => 'str_replace',
                                        'call-type' => 1,
                                        'parameters' => 
                                        array (
                                          0 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'string',
                                              'value' => '_',
                                              'file' => '/app/phalcon/Http/Request.zep',
                                              'line' => 383,
                                              'char' => 38,
                                            ),
                                            'file' => '/app/phalcon/Http/Request.zep',
                                            'line' => 383,
                                            'char' => 38,
                                          ),
                                          1 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'string',
                                              'value' => ' ',
                                              'file' => '/app/phalcon/Http/Request.zep',
                                              'line' => 383,
                                              'char' => 41,
                                            ),
                                            'file' => '/app/phalcon/Http/Request.zep',
                                            'line' => 383,
                                            'char' => 41,
                                          ),
                                          2 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'name',
                                              'file' => '/app/phalcon/Http/Request.zep',
                                              'line' => 383,
                                              'char' => 47,
                                            ),
                                            'file' => '/app/phalcon/Http/Request.zep',
                                            'line' => 383,
                                            'char' => 47,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Http/Request.zep',
                                        'line' => 384,
                                        'char' => 21,
                                      ),
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 384,
                                      'char' => 21,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 385,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 385,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 385,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 385,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 387,
                      'char' => 19,
                    ),
                    1 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'name',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'str_replace',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => ' ',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 387,
                                  'char' => 41,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 387,
                                'char' => 41,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => '-',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 387,
                                  'char' => 44,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 387,
                                'char' => 44,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'name',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 387,
                                  'char' => 50,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 387,
                                'char' => 50,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 387,
                            'char' => 51,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 387,
                          'char' => 51,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 389,
                      'char' => 19,
                    ),
                    2 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'headers',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'name',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 389,
                              'char' => 33,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'value',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 389,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 389,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 390,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 391,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 393,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'authHeaders',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 393,
                      'char' => 32,
                    ),
                    'name' => 'resolveAuthorizationHeaders',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 393,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 393,
                  'char' => 62,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 396,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'headers',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'array_merge',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'headers',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 396,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 396,
                        'char' => 42,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'authHeaders',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 396,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 396,
                        'char' => 55,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 396,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 396,
                  'char' => 56,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 398,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'headers',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 398,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 399,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 346,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 346,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 345,
          'last-line' => 434,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getHttpHost',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'host',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 437,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'strict',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 437,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 439,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'strict',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 439,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'strictHostCheck',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 439,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 439,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 439,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 444,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'host',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 444,
                      'char' => 25,
                    ),
                    'name' => 'getServer',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'HTTP_HOST',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 444,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 444,
                        'char' => 45,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 444,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 444,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 446,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'host',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 446,
                  'char' => 18,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 446,
                'char' => 18,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'host',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 450,
                          'char' => 29,
                        ),
                        'name' => 'getServer',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'SERVER_NAME',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 450,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 450,
                            'char' => 51,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 450,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 450,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 451,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'host',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 451,
                      'char' => 22,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 451,
                    'char' => 22,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'host',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 455,
                              'char' => 33,
                            ),
                            'name' => 'getServer',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'SERVER_ADDR',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 455,
                                  'char' => 55,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 455,
                                'char' => 55,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 455,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 455,
                          'char' => 56,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 456,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 457,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 459,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'and',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'host',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 459,
                  'char' => 18,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'strict',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 459,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 459,
                'char' => 27,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'host',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'strtolower',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'trim',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'host',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 464,
                                    'char' => 26,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 464,
                                  'char' => 26,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 465,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 465,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 465,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 465,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 467,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'memstr',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'host',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 467,
                          'char' => 27,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 467,
                        'char' => 27,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => ':',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 467,
                          'char' => 30,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 467,
                        'char' => 30,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 467,
                    'char' => 32,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'host',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'preg_replace',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => '/:[[:digit:]]+$/',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 468,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 468,
                                'char' => 57,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => '',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 468,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 468,
                                'char' => 59,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'host',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 468,
                                  'char' => 65,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 468,
                                'char' => 65,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 468,
                            'char' => 66,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 468,
                          'char' => 66,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 469,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 476,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'unlikely',
                    'left' => 
                    array (
                      'type' => 'list',
                      'left' => 
                      array (
                        'type' => 'not-identical',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => '',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 476,
                          'char' => 29,
                        ),
                        'right' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'preg_replace',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => '/[a-z0-9-]+\\.?/',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 476,
                                'char' => 59,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 476,
                              'char' => 59,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => '',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 476,
                                'char' => 61,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 476,
                              'char' => 61,
                            ),
                            2 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'host',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 476,
                                'char' => 67,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 476,
                              'char' => 67,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 476,
                          'char' => 68,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 476,
                        'char' => 68,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 476,
                      'char' => 70,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 476,
                    'char' => 70,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'throw',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'UnexpectedValueException',
                        'dynamic' => 0,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'string',
                                'value' => 'Invalid host ',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 477,
                                'char' => 66,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'host',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 477,
                                'char' => 72,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 477,
                              'char' => 72,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 477,
                            'char' => 72,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 477,
                        'char' => 73,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 478,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 479,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 481,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'cast',
                'left' => 'string',
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'host',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 481,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 481,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 482,
              'char' => 5,
            ),
          ),
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
     * The `Request::$strictHostCheck` can be used to validate host name.
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 436,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 436,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 435,
          'last-line' => 486,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getHTTPReferer',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'httpReferer',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 489,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 491,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'httpReferer',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 491,
                    'char' => 54,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => '_SERVER',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 491,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'HTTP_REFERER',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 491,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 491,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 491,
                  'char' => 54,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 491,
                'char' => 54,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 492,
                    'char' => 20,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 493,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 495,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'httpReferer',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 495,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 496,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 488,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 488,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 487,
          'last-line' => 500,
          'char' => 19,
        ),
        18 => 
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 501,
                'char' => 60,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 501,
              'char' => 60,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'rawBody',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 503,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 505,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'rawBody',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 505,
                      'char' => 28,
                    ),
                    'name' => 'getRawBody',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 505,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 505,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 507,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'rawBody',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 507,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 507,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'string',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 507,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 507,
                'char' => 37,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 508,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 509,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 511,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'json_decode',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'rawBody',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 511,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 511,
                    'char' => 35,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'associative',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 511,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 511,
                    'char' => 48,
                  ),
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 511,
                'char' => 49,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 512,
              'char' => 5,
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
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 501,
                  'char' => 76,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 501,
                'char' => 76,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 501,
                'char' => 84,
              ),
              2 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 502,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 502,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 501,
          'last-line' => 517,
          'char' => 19,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getLanguages',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 520,
                  'char' => 21,
                ),
                'name' => 'getQualityHeader',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'HTTP_ACCEPT_LANGUAGE',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 520,
                      'char' => 59,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 520,
                    'char' => 59,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'language',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 520,
                      'char' => 69,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 520,
                    'char' => 69,
                  ),
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 520,
                'char' => 70,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 521,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 519,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 519,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 518,
          'last-line' => 533,
          'char' => 19,
        ),
        20 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
          ),
          'type' => 'method',
          'name' => 'getMethod',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'overridedMethod',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 536,
                  'char' => 28,
                ),
                1 => 
                array (
                  'variable' => 'spoofedMethod',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 536,
                  'char' => 43,
                ),
                2 => 
                array (
                  'variable' => 'requestMethod',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 536,
                  'char' => 58,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 537,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'returnMethod',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 537,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 537,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 539,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'likely',
                'left' => 
                array (
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'requestMethod',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 539,
                    'char' => 64,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => '_SERVER',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 539,
                      'char' => 47,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'REQUEST_METHOD',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 539,
                      'char' => 62,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 539,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 539,
                  'char' => 64,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 539,
                'char' => 64,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'returnMethod',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'strtoupper',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'requestMethod',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 540,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 540,
                            'char' => 56,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 540,
                        'char' => 57,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 540,
                      'char' => 57,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 541,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'GET',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 542,
                    'char' => 23,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 543,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 545,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'string',
                  'value' => 'POST',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 545,
                  'char' => 19,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'returnMethod',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 545,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 545,
                'char' => 34,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'overridedMethod',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 546,
                          'char' => 40,
                        ),
                        'name' => 'getHeader',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'X-HTTP-METHOD-OVERRIDE',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 546,
                              'char' => 73,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 546,
                            'char' => 73,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 546,
                        'char' => 74,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 546,
                      'char' => 74,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 548,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'empty',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'overridedMethod',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 548,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 548,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 548,
                    'char' => 39,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'returnMethod',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'strtoupper',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'overridedMethod',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 549,
                                  'char' => 62,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 549,
                                'char' => 62,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 549,
                            'char' => 63,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 549,
                          'char' => 63,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 550,
                      'char' => 13,
                    ),
                  ),
                  'elseif_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 550,
                          'char' => 27,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'httpMethodParameterOverride',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 550,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 550,
                        'char' => 56,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'fetch',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'spoofedMethod',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 551,
                              'char' => 59,
                            ),
                            'right' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => '_REQUEST',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 551,
                                'char' => 49,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => '_method',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 551,
                                'char' => 57,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 551,
                              'char' => 59,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 551,
                            'char' => 59,
                          ),
                          'statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'let',
                              'assignments' => 
                              array (
                                0 => 
                                array (
                                  'assign-type' => 'variable',
                                  'operator' => 'assign',
                                  'variable' => 'returnMethod',
                                  'expr' => 
                                  array (
                                    'type' => 'fcall',
                                    'name' => 'strtoupper',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'spoofedMethod',
                                          'file' => '/app/phalcon/Http/Request.zep',
                                          'line' => 552,
                                          'char' => 64,
                                        ),
                                        'file' => '/app/phalcon/Http/Request.zep',
                                        'line' => 552,
                                        'char' => 64,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 552,
                                    'char' => 65,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 552,
                                  'char' => 65,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 553,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 554,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 555,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 555,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 557,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 557,
                    'char' => 18,
                  ),
                  'name' => 'isValidHttpMethod',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'returnMethod',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 557,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 557,
                      'char' => 49,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 557,
                  'char' => 51,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 557,
                'char' => 51,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'GET',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 558,
                    'char' => 23,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 559,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 561,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'returnMethod',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 561,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 562,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 535,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 535,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 534,
          'last-line' => 566,
          'char' => 25,
        ),
        21 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getPort',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'host',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 569,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'pos',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 569,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 574,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'host',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 574,
                      'char' => 25,
                    ),
                    'name' => 'getServer',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'HTTP_HOST',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 574,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 574,
                        'char' => 45,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 574,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 574,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 576,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'host',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 576,
                  'char' => 18,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 576,
                'char' => 18,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'int',
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 577,
                        'char' => 31,
                      ),
                      'name' => 'getServer',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'SERVER_PORT',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 577,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 577,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 577,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 577,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 578,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 580,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'memstr',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'host',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 580,
                      'char' => 23,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 580,
                    'char' => 23,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => ':',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 580,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 580,
                    'char' => 26,
                  ),
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 580,
                'char' => 28,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'pos',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'strrpos',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'host',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 581,
                              'char' => 35,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 581,
                            'char' => 35,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => ':',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 581,
                              'char' => 38,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 581,
                            'char' => 38,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 581,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 581,
                      'char' => 39,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 583,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not-identical',
                    'left' => 
                    array (
                      'type' => 'bool',
                      'value' => 'false',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 583,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pos',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 583,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 583,
                    'char' => 30,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'int',
                        'right' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'substr',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'host',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 584,
                                'char' => 41,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 584,
                              'char' => 41,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'add',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'pos',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 584,
                                  'char' => 47,
                                ),
                                'right' => 
                                array (
                                  'type' => 'int',
                                  'value' => '1',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 584,
                                  'char' => 50,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 584,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 584,
                              'char' => 50,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 584,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 584,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 585,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 586,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 588,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'ternary',
                'left' => 
                array (
                  'type' => 'identical',
                  'left' => 
                  array (
                    'type' => 'string',
                    'value' => 'https',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 588,
                    'char' => 24,
                  ),
                  'right' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 588,
                      'char' => 31,
                    ),
                    'name' => 'getScheme',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 588,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 588,
                  'char' => 44,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '443',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 588,
                  'char' => 50,
                ),
                'extra' => 
                array (
                  'type' => 'int',
                  'value' => '80',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 588,
                  'char' => 54,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 588,
                'char' => 54,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 589,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets information about the port on which the request is made.
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 568,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 568,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 567,
          'last-line' => 602,
          'char' => 19,
        ),
        22 => 
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 603,
                'char' => 48,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 603,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 603,
                'char' => 68,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 603,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 603,
                'char' => 93,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 603,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 603,
                'char' => 121,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 603,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 603,
                'char' => 147,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 603,
              'char' => 147,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 605,
                  'char' => 21,
                ),
                'name' => 'getHelper',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => '_POST',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 606,
                      'char' => 18,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 606,
                    'char' => 18,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 607,
                      'char' => 17,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 607,
                    'char' => 17,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'filters',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 608,
                      'char' => 20,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 608,
                    'char' => 20,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'defaultValue',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 609,
                      'char' => 25,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 609,
                    'char' => 25,
                  ),
                  4 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'notAllowEmpty',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 610,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 610,
                    'char' => 26,
                  ),
                  5 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'noRecursive',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 612,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 612,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 612,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 613,
              'char' => 5,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 604,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 604,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 603,
          'last-line' => 625,
          'char' => 19,
        ),
        23 => 
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 626,
                'char' => 47,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 626,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 626,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 626,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 626,
                'char' => 92,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 626,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 626,
                'char' => 120,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 626,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 626,
                'char' => 146,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 626,
              'char' => 146,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'put',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 628,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'contentType',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 628,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 630,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'put',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 630,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'putCache',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 630,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 630,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 630,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 632,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'put',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 632,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 632,
                  'char' => 24,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 632,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 632,
                'char' => 32,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'contentType',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 633,
                          'char' => 36,
                        ),
                        'name' => 'getContentType',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 633,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 633,
                      'char' => 53,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 635,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'equals',
                      'left' => 
                      array (
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'contentType',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 635,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 635,
                        'char' => 36,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'string',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 635,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 635,
                      'char' => 46,
                    ),
                    'right' => 
                    array (
                      'type' => 'not-equals',
                      'left' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'stripos',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'contentType',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 635,
                              'char' => 67,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 635,
                            'char' => 67,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'json',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 635,
                              'char' => 73,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 635,
                            'char' => 73,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 635,
                        'char' => 76,
                      ),
                      'right' => 
                      array (
                        'type' => 'bool',
                        'value' => 'false',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 635,
                        'char' => 84,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 635,
                      'char' => 84,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 635,
                    'char' => 84,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'put',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 636,
                              'char' => 32,
                            ),
                            'name' => 'getJsonRawBody',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'bool',
                                  'value' => 'true',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 636,
                                  'char' => 52,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 636,
                                'char' => 52,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 636,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 636,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 638,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'not-equals',
                        'left' => 
                        array (
                          'type' => 'typeof',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'put',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 638,
                            'char' => 32,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 638,
                          'char' => 32,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'array',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 638,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 638,
                        'char' => 40,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'put',
                              'expr' => 
                              array (
                                'type' => 'empty-array',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 639,
                                'char' => 33,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 639,
                              'char' => 33,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 640,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 641,
                      'char' => 13,
                    ),
                  ),
                  'else_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'put',
                          'expr' => 
                          array (
                            'type' => 'empty-array',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 642,
                            'char' => 29,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 642,
                          'char' => 29,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 644,
                      'char' => 25,
                    ),
                    1 => 
                    array (
                      'type' => 'fcall',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'parse_str',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 644,
                                'char' => 32,
                              ),
                              'name' => 'getRawBody',
                              'call-type' => 1,
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 644,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 644,
                            'char' => 45,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'put',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 644,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 644,
                            'char' => 50,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 644,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 645,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 647,
                  'char' => 15,
                ),
                2 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'putCache',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'put',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 647,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 647,
                      'char' => 37,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 648,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 650,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 650,
                  'char' => 21,
                ),
                'name' => 'getHelper',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'put',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 651,
                      'char' => 16,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 651,
                    'char' => 16,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 652,
                      'char' => 17,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 652,
                    'char' => 17,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'filters',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 653,
                      'char' => 20,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 653,
                    'char' => 20,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'defaultValue',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 654,
                      'char' => 25,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 654,
                    'char' => 25,
                  ),
                  4 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'notAllowEmpty',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 655,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 655,
                    'char' => 26,
                  ),
                  5 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'noRecursive',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 657,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 657,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 657,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 658,
              'char' => 5,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 627,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 627,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 626,
          'last-line' => 674,
          'char' => 19,
        ),
        24 => 
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 675,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 675,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 675,
                'char' => 69,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 675,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 675,
                'char' => 94,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 675,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 675,
                'char' => 122,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 675,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 675,
                'char' => 148,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 675,
              'char' => 148,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 677,
                  'char' => 21,
                ),
                'name' => 'getHelper',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => '_GET',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 678,
                      'char' => 17,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 678,
                    'char' => 17,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 679,
                      'char' => 17,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 679,
                    'char' => 17,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'filters',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 680,
                      'char' => 20,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 680,
                    'char' => 20,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'defaultValue',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 681,
                      'char' => 25,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 681,
                    'char' => 25,
                  ),
                  4 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'notAllowEmpty',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 682,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 682,
                    'char' => 26,
                  ),
                  5 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'noRecursive',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 684,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 684,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 684,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 685,
              'char' => 5,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 676,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 676,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 675,
          'last-line' => 689,
          'char' => 19,
        ),
        25 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRawBody',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'rawBody',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 692,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'contents',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 692,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 694,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'rawBody',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 694,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'rawBody',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 694,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 694,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 694,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 696,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'empty',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'rawBody',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 696,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 696,
                'char' => 26,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'contents',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'file_get_contents',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'php://input',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 697,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 697,
                            'char' => 57,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 697,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 697,
                      'char' => 58,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 702,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'rawBody',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'contents',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 702,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 702,
                      'char' => 41,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 704,
                  'char' => 18,
                ),
                2 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'contents',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 704,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 705,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 707,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'rawBody',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 707,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 708,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 691,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 691,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 690,
          'last-line' => 712,
          'char' => 19,
        ),
        26 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getScheme',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'https',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 715,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 717,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'https',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 717,
                      'char' => 26,
                    ),
                    'name' => 'getServer',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'HTTPS',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 717,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 717,
                        'char' => 42,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 717,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 717,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 719,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'and',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'https',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 719,
                  'char' => 19,
                ),
                'right' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'https',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 719,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'off',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 719,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 719,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 719,
                'char' => 34,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'https',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 720,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 721,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 723,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'string',
                'value' => 'http',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 723,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 724,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 714,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 714,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 713,
          'last-line' => 728,
          'char' => 19,
        ),
        27 => 
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
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 729,
              'char' => 43,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'serverValue',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 731,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 733,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'serverValue',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 733,
                    'char' => 46,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => '_SERVER',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 733,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 733,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 733,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 733,
                  'char' => 46,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 733,
                'char' => 46,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 734,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 735,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 737,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'serverValue',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 737,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 738,
              'char' => 5,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 729,
                'char' => 55,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 730,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 730,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 729,
          'last-line' => 742,
          'char' => 19,
        ),
        28 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getServerAddress',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'serverAddr',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 745,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 747,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'serverAddr',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 747,
                    'char' => 52,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => '_SERVER',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 747,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'SERVER_ADDR',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 747,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 747,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 747,
                  'char' => 52,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 747,
                'char' => 52,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'gethostbyname',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'localhost',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 748,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 748,
                        'char' => 43,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 748,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 749,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 751,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'serverAddr',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 751,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 752,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 744,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 744,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 743,
          'last-line' => 756,
          'char' => 19,
        ),
        29 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getServerName',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'serverName',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 759,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 761,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'serverName',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 761,
                    'char' => 52,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => '_SERVER',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 761,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'SERVER_NAME',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 761,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 761,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 761,
                  'char' => 52,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 761,
                'char' => 52,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'localhost',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 762,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 763,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 765,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'serverName',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 765,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 766,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 758,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 758,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 757,
          'last-line' => 770,
          'char' => 19,
        ),
        30 => 
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 771,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 771,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 771,
                'char' => 89,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 771,
              'char' => 89,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'superFiles',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 773,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'prefix',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 773,
                  'char' => 31,
                ),
                2 => 
                array (
                  'variable' => 'input',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 773,
                  'char' => 38,
                ),
                3 => 
                array (
                  'variable' => 'smoothInput',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 773,
                  'char' => 51,
                ),
                4 => 
                array (
                  'variable' => 'file',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 773,
                  'char' => 57,
                ),
                5 => 
                array (
                  'variable' => 'dataFile',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 773,
                  'char' => 67,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 774,
              'char' => 13,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'array',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'files',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 774,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 774,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 776,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'superFiles',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => '_FILES',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 776,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 776,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 778,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'greater',
                'left' => 
                array (
                  'type' => 'fcall',
                  'name' => 'count',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'superFiles',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 778,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 778,
                      'char' => 28,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 778,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '0',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 778,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 778,
                'char' => 34,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'superFiles',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 779,
                    'char' => 45,
                  ),
                  'key' => 'prefix',
                  'value' => 'input',
                  'reverse' => 0,
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'equals',
                        'left' => 
                        array (
                          'type' => 'typeof',
                          'left' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'input',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 780,
                              'char' => 32,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'name',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 780,
                              'char' => 37,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 780,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 780,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'array',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 780,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 780,
                        'char' => 48,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'smoothInput',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 781,
                                  'char' => 44,
                                ),
                                'name' => 'smoothFiles',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'array-access',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'input',
                                        'file' => '/app/phalcon/Http/Request.zep',
                                        'line' => 782,
                                        'char' => 30,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => 'name',
                                        'file' => '/app/phalcon/Http/Request.zep',
                                        'line' => 782,
                                        'char' => 35,
                                      ),
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 782,
                                      'char' => 36,
                                    ),
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 782,
                                    'char' => 36,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'array-access',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'input',
                                        'file' => '/app/phalcon/Http/Request.zep',
                                        'line' => 783,
                                        'char' => 30,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => 'type',
                                        'file' => '/app/phalcon/Http/Request.zep',
                                        'line' => 783,
                                        'char' => 35,
                                      ),
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 783,
                                      'char' => 36,
                                    ),
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 783,
                                    'char' => 36,
                                  ),
                                  2 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'array-access',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'input',
                                        'file' => '/app/phalcon/Http/Request.zep',
                                        'line' => 784,
                                        'char' => 30,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => 'tmp_name',
                                        'file' => '/app/phalcon/Http/Request.zep',
                                        'line' => 784,
                                        'char' => 39,
                                      ),
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 784,
                                      'char' => 40,
                                    ),
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 784,
                                    'char' => 40,
                                  ),
                                  3 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'array-access',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'input',
                                        'file' => '/app/phalcon/Http/Request.zep',
                                        'line' => 785,
                                        'char' => 30,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => 'size',
                                        'file' => '/app/phalcon/Http/Request.zep',
                                        'line' => 785,
                                        'char' => 35,
                                      ),
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 785,
                                      'char' => 36,
                                    ),
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 785,
                                    'char' => 36,
                                  ),
                                  4 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'array-access',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'input',
                                        'file' => '/app/phalcon/Http/Request.zep',
                                        'line' => 786,
                                        'char' => 30,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => 'error',
                                        'file' => '/app/phalcon/Http/Request.zep',
                                        'line' => 786,
                                        'char' => 36,
                                      ),
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 786,
                                      'char' => 37,
                                    ),
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 786,
                                    'char' => 37,
                                  ),
                                  5 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'prefix',
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 788,
                                      'char' => 21,
                                    ),
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 788,
                                    'char' => 21,
                                  ),
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 788,
                                'char' => 22,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 788,
                              'char' => 22,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 790,
                          'char' => 23,
                        ),
                        1 => 
                        array (
                          'type' => 'for',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'smoothInput',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 790,
                            'char' => 45,
                          ),
                          'value' => 'file',
                          'reverse' => 0,
                          'statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'if',
                              'expr' => 
                              array (
                                'type' => 'or',
                                'left' => 
                                array (
                                  'type' => 'equals',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'onlySuccessful',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 791,
                                    'char' => 44,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'bool',
                                    'value' => 'false',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 791,
                                    'char' => 53,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 791,
                                  'char' => 53,
                                ),
                                'right' => 
                                array (
                                  'type' => 'equals',
                                  'left' => 
                                  array (
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'file',
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 791,
                                      'char' => 59,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'error',
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 791,
                                      'char' => 65,
                                    ),
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 791,
                                    'char' => 68,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'constant',
                                    'value' => 'UPLOAD_ERR_OK',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 791,
                                    'char' => 84,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 791,
                                  'char' => 84,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 791,
                                'char' => 84,
                              ),
                              'statements' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'let',
                                  'assignments' => 
                                  array (
                                    0 => 
                                    array (
                                      'assign-type' => 'variable',
                                      'operator' => 'assign',
                                      'variable' => 'dataFile',
                                      'expr' => 
                                      array (
                                        'type' => 'array',
                                        'left' => 
                                        array (
                                          0 => 
                                          array (
                                            'key' => 
                                            array (
                                              'type' => 'string',
                                              'value' => 'name',
                                              'file' => '/app/phalcon/Http/Request.zep',
                                              'line' => 793,
                                              'char' => 37,
                                            ),
                                            'value' => 
                                            array (
                                              'type' => 'array-access',
                                              'left' => 
                                              array (
                                                'type' => 'variable',
                                                'value' => 'file',
                                                'file' => '/app/phalcon/Http/Request.zep',
                                                'line' => 793,
                                                'char' => 47,
                                              ),
                                              'right' => 
                                              array (
                                                'type' => 'string',
                                                'value' => 'name',
                                                'file' => '/app/phalcon/Http/Request.zep',
                                                'line' => 793,
                                                'char' => 52,
                                              ),
                                              'file' => '/app/phalcon/Http/Request.zep',
                                              'line' => 793,
                                              'char' => 53,
                                            ),
                                            'file' => '/app/phalcon/Http/Request.zep',
                                            'line' => 793,
                                            'char' => 53,
                                          ),
                                          1 => 
                                          array (
                                            'key' => 
                                            array (
                                              'type' => 'string',
                                              'value' => 'type',
                                              'file' => '/app/phalcon/Http/Request.zep',
                                              'line' => 794,
                                              'char' => 37,
                                            ),
                                            'value' => 
                                            array (
                                              'type' => 'array-access',
                                              'left' => 
                                              array (
                                                'type' => 'variable',
                                                'value' => 'file',
                                                'file' => '/app/phalcon/Http/Request.zep',
                                                'line' => 794,
                                                'char' => 47,
                                              ),
                                              'right' => 
                                              array (
                                                'type' => 'string',
                                                'value' => 'type',
                                                'file' => '/app/phalcon/Http/Request.zep',
                                                'line' => 794,
                                                'char' => 52,
                                              ),
                                              'file' => '/app/phalcon/Http/Request.zep',
                                              'line' => 794,
                                              'char' => 53,
                                            ),
                                            'file' => '/app/phalcon/Http/Request.zep',
                                            'line' => 794,
                                            'char' => 53,
                                          ),
                                          2 => 
                                          array (
                                            'key' => 
                                            array (
                                              'type' => 'string',
                                              'value' => 'tmp_name',
                                              'file' => '/app/phalcon/Http/Request.zep',
                                              'line' => 795,
                                              'char' => 41,
                                            ),
                                            'value' => 
                                            array (
                                              'type' => 'array-access',
                                              'left' => 
                                              array (
                                                'type' => 'variable',
                                                'value' => 'file',
                                                'file' => '/app/phalcon/Http/Request.zep',
                                                'line' => 795,
                                                'char' => 47,
                                              ),
                                              'right' => 
                                              array (
                                                'type' => 'string',
                                                'value' => 'tmp_name',
                                                'file' => '/app/phalcon/Http/Request.zep',
                                                'line' => 795,
                                                'char' => 56,
                                              ),
                                              'file' => '/app/phalcon/Http/Request.zep',
                                              'line' => 795,
                                              'char' => 57,
                                            ),
                                            'file' => '/app/phalcon/Http/Request.zep',
                                            'line' => 795,
                                            'char' => 57,
                                          ),
                                          3 => 
                                          array (
                                            'key' => 
                                            array (
                                              'type' => 'string',
                                              'value' => 'size',
                                              'file' => '/app/phalcon/Http/Request.zep',
                                              'line' => 796,
                                              'char' => 37,
                                            ),
                                            'value' => 
                                            array (
                                              'type' => 'array-access',
                                              'left' => 
                                              array (
                                                'type' => 'variable',
                                                'value' => 'file',
                                                'file' => '/app/phalcon/Http/Request.zep',
                                                'line' => 796,
                                                'char' => 47,
                                              ),
                                              'right' => 
                                              array (
                                                'type' => 'string',
                                                'value' => 'size',
                                                'file' => '/app/phalcon/Http/Request.zep',
                                                'line' => 796,
                                                'char' => 52,
                                              ),
                                              'file' => '/app/phalcon/Http/Request.zep',
                                              'line' => 796,
                                              'char' => 53,
                                            ),
                                            'file' => '/app/phalcon/Http/Request.zep',
                                            'line' => 796,
                                            'char' => 53,
                                          ),
                                          4 => 
                                          array (
                                            'key' => 
                                            array (
                                              'type' => 'string',
                                              'value' => 'error',
                                              'file' => '/app/phalcon/Http/Request.zep',
                                              'line' => 797,
                                              'char' => 38,
                                            ),
                                            'value' => 
                                            array (
                                              'type' => 'array-access',
                                              'left' => 
                                              array (
                                                'type' => 'variable',
                                                'value' => 'file',
                                                'file' => '/app/phalcon/Http/Request.zep',
                                                'line' => 797,
                                                'char' => 47,
                                              ),
                                              'right' => 
                                              array (
                                                'type' => 'string',
                                                'value' => 'error',
                                                'file' => '/app/phalcon/Http/Request.zep',
                                                'line' => 797,
                                                'char' => 53,
                                              ),
                                              'file' => '/app/phalcon/Http/Request.zep',
                                              'line' => 798,
                                              'char' => 29,
                                            ),
                                            'file' => '/app/phalcon/Http/Request.zep',
                                            'line' => 798,
                                            'char' => 29,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Http/Request.zep',
                                        'line' => 798,
                                        'char' => 30,
                                      ),
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 798,
                                      'char' => 30,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 800,
                                  'char' => 30,
                                ),
                                1 => 
                                array (
                                  'type' => 'if',
                                  'expr' => 
                                  array (
                                    'type' => 'equals',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'namedKeys',
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 800,
                                      'char' => 43,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'bool',
                                      'value' => 'true',
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 800,
                                      'char' => 50,
                                    ),
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 800,
                                    'char' => 50,
                                  ),
                                  'statements' => 
                                  array (
                                    0 => 
                                    array (
                                      'type' => 'let',
                                      'assignments' => 
                                      array (
                                        0 => 
                                        array (
                                          'assign-type' => 'array-index',
                                          'operator' => 'assign',
                                          'variable' => 'files',
                                          'index-expr' => 
                                          array (
                                            0 => 
                                            array (
                                              'type' => 'array-access',
                                              'left' => 
                                              array (
                                                'type' => 'variable',
                                                'value' => 'file',
                                                'file' => '/app/phalcon/Http/Request.zep',
                                                'line' => 801,
                                                'char' => 47,
                                              ),
                                              'right' => 
                                              array (
                                                'type' => 'string',
                                                'value' => 'key',
                                                'file' => '/app/phalcon/Http/Request.zep',
                                                'line' => 801,
                                                'char' => 51,
                                              ),
                                              'file' => '/app/phalcon/Http/Request.zep',
                                              'line' => 801,
                                              'char' => 52,
                                            ),
                                          ),
                                          'expr' => 
                                          array (
                                            'type' => 'new',
                                            'class' => 'File',
                                            'dynamic' => 0,
                                            'parameters' => 
                                            array (
                                              0 => 
                                              array (
                                                'parameter' => 
                                                array (
                                                  'type' => 'variable',
                                                  'value' => 'dataFile',
                                                  'file' => '/app/phalcon/Http/Request.zep',
                                                  'line' => 802,
                                                  'char' => 45,
                                                ),
                                                'file' => '/app/phalcon/Http/Request.zep',
                                                'line' => 802,
                                                'char' => 45,
                                              ),
                                              1 => 
                                              array (
                                                'parameter' => 
                                                array (
                                                  'type' => 'array-access',
                                                  'left' => 
                                                  array (
                                                    'type' => 'variable',
                                                    'value' => 'file',
                                                    'file' => '/app/phalcon/Http/Request.zep',
                                                    'line' => 803,
                                                    'char' => 41,
                                                  ),
                                                  'right' => 
                                                  array (
                                                    'type' => 'string',
                                                    'value' => 'key',
                                                    'file' => '/app/phalcon/Http/Request.zep',
                                                    'line' => 803,
                                                    'char' => 45,
                                                  ),
                                                  'file' => '/app/phalcon/Http/Request.zep',
                                                  'line' => 804,
                                                  'char' => 33,
                                                ),
                                                'file' => '/app/phalcon/Http/Request.zep',
                                                'line' => 804,
                                                'char' => 33,
                                              ),
                                            ),
                                            'file' => '/app/phalcon/Http/Request.zep',
                                            'line' => 804,
                                            'char' => 34,
                                          ),
                                          'file' => '/app/phalcon/Http/Request.zep',
                                          'line' => 804,
                                          'char' => 34,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 805,
                                      'char' => 29,
                                    ),
                                  ),
                                  'else_statements' => 
                                  array (
                                    0 => 
                                    array (
                                      'type' => 'let',
                                      'assignments' => 
                                      array (
                                        0 => 
                                        array (
                                          'assign-type' => 'variable-append',
                                          'operator' => 'assign',
                                          'variable' => 'files',
                                          'expr' => 
                                          array (
                                            'type' => 'new',
                                            'class' => 'File',
                                            'dynamic' => 0,
                                            'parameters' => 
                                            array (
                                              0 => 
                                              array (
                                                'parameter' => 
                                                array (
                                                  'type' => 'variable',
                                                  'value' => 'dataFile',
                                                  'file' => '/app/phalcon/Http/Request.zep',
                                                  'line' => 807,
                                                  'char' => 45,
                                                ),
                                                'file' => '/app/phalcon/Http/Request.zep',
                                                'line' => 807,
                                                'char' => 45,
                                              ),
                                              1 => 
                                              array (
                                                'parameter' => 
                                                array (
                                                  'type' => 'array-access',
                                                  'left' => 
                                                  array (
                                                    'type' => 'variable',
                                                    'value' => 'file',
                                                    'file' => '/app/phalcon/Http/Request.zep',
                                                    'line' => 808,
                                                    'char' => 41,
                                                  ),
                                                  'right' => 
                                                  array (
                                                    'type' => 'string',
                                                    'value' => 'key',
                                                    'file' => '/app/phalcon/Http/Request.zep',
                                                    'line' => 808,
                                                    'char' => 45,
                                                  ),
                                                  'file' => '/app/phalcon/Http/Request.zep',
                                                  'line' => 809,
                                                  'char' => 33,
                                                ),
                                                'file' => '/app/phalcon/Http/Request.zep',
                                                'line' => 809,
                                                'char' => 33,
                                              ),
                                            ),
                                            'file' => '/app/phalcon/Http/Request.zep',
                                            'line' => 809,
                                            'char' => 34,
                                          ),
                                          'file' => '/app/phalcon/Http/Request.zep',
                                          'line' => 809,
                                          'char' => 34,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 810,
                                      'char' => 29,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 811,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 812,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 813,
                          'char' => 17,
                        ),
                      ),
                      'else_statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'or',
                            'left' => 
                            array (
                              'type' => 'equals',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'onlySuccessful',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 814,
                                'char' => 40,
                              ),
                              'right' => 
                              array (
                                'type' => 'bool',
                                'value' => 'false',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 814,
                                'char' => 49,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 814,
                              'char' => 49,
                            ),
                            'right' => 
                            array (
                              'type' => 'equals',
                              'left' => 
                              array (
                                'type' => 'array-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'input',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 814,
                                  'char' => 56,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'error',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 814,
                                  'char' => 62,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 814,
                                'char' => 65,
                              ),
                              'right' => 
                              array (
                                'type' => 'constant',
                                'value' => 'UPLOAD_ERR_OK',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 814,
                                'char' => 81,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 814,
                              'char' => 81,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 814,
                            'char' => 81,
                          ),
                          'statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'if',
                              'expr' => 
                              array (
                                'type' => 'equals',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'namedKeys',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 815,
                                  'char' => 39,
                                ),
                                'right' => 
                                array (
                                  'type' => 'bool',
                                  'value' => 'true',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 815,
                                  'char' => 46,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 815,
                                'char' => 46,
                              ),
                              'statements' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'let',
                                  'assignments' => 
                                  array (
                                    0 => 
                                    array (
                                      'assign-type' => 'array-index',
                                      'operator' => 'assign',
                                      'variable' => 'files',
                                      'index-expr' => 
                                      array (
                                        0 => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'prefix',
                                          'file' => '/app/phalcon/Http/Request.zep',
                                          'line' => 816,
                                          'char' => 45,
                                        ),
                                      ),
                                      'expr' => 
                                      array (
                                        'type' => 'new',
                                        'class' => 'File',
                                        'dynamic' => 0,
                                        'parameters' => 
                                        array (
                                          0 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'input',
                                              'file' => '/app/phalcon/Http/Request.zep',
                                              'line' => 816,
                                              'char' => 63,
                                            ),
                                            'file' => '/app/phalcon/Http/Request.zep',
                                            'line' => 816,
                                            'char' => 63,
                                          ),
                                          1 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'prefix',
                                              'file' => '/app/phalcon/Http/Request.zep',
                                              'line' => 816,
                                              'char' => 71,
                                            ),
                                            'file' => '/app/phalcon/Http/Request.zep',
                                            'line' => 816,
                                            'char' => 71,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Http/Request.zep',
                                        'line' => 816,
                                        'char' => 72,
                                      ),
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 816,
                                      'char' => 72,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 817,
                                  'char' => 25,
                                ),
                              ),
                              'else_statements' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'let',
                                  'assignments' => 
                                  array (
                                    0 => 
                                    array (
                                      'assign-type' => 'variable-append',
                                      'operator' => 'assign',
                                      'variable' => 'files',
                                      'expr' => 
                                      array (
                                        'type' => 'new',
                                        'class' => 'File',
                                        'dynamic' => 0,
                                        'parameters' => 
                                        array (
                                          0 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'input',
                                              'file' => '/app/phalcon/Http/Request.zep',
                                              'line' => 818,
                                              'char' => 57,
                                            ),
                                            'file' => '/app/phalcon/Http/Request.zep',
                                            'line' => 818,
                                            'char' => 57,
                                          ),
                                          1 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'prefix',
                                              'file' => '/app/phalcon/Http/Request.zep',
                                              'line' => 818,
                                              'char' => 65,
                                            ),
                                            'file' => '/app/phalcon/Http/Request.zep',
                                            'line' => 818,
                                            'char' => 65,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Http/Request.zep',
                                        'line' => 818,
                                        'char' => 66,
                                      ),
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 818,
                                      'char' => 66,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 819,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 820,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 821,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 822,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 823,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 825,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'files',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 825,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 826,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets attached files as Phalcon\\Http\\Request\\File instances
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
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 772,
                  'char' => 5,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 772,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 772,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 771,
          'last-line' => 830,
          'char' => 19,
        ),
        31 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
          ),
          'type' => 'method',
          'name' => 'getURI',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'requestURI',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 833,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 835,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'requestURI',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 835,
                    'char' => 52,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => '_SERVER',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 835,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'REQUEST_URI',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 835,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 835,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 835,
                  'char' => 52,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 835,
                'char' => 52,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 836,
                    'char' => 20,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 837,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 839,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'requestURI',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 839,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 840,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 832,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 832,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 831,
          'last-line' => 844,
          'char' => 25,
        ),
        32 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getUserAgent',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'userAgent',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 847,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 849,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'userAgent',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 849,
                    'char' => 55,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => '_SERVER',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 849,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'HTTP_USER_AGENT',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 849,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 849,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 849,
                  'char' => 55,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 849,
                'char' => 55,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 850,
                    'char' => 20,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 851,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 853,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'userAgent',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 853,
                'char' => 25,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 854,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 846,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 846,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 845,
          'last-line' => 858,
          'char' => 19,
        ),
        33 => 
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
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 859,
              'char' => 37,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'isset',
                'left' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => '_REQUEST',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 861,
                    'char' => 30,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'name',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 861,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 861,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 861,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 862,
              'char' => 5,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 860,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 860,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 859,
          'last-line' => 868,
          'char' => 19,
        ),
        34 => 
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 869,
                'char' => 57,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 869,
              'char' => 57,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'files',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 871,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'file',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 871,
                  'char' => 24,
                ),
                2 => 
                array (
                  'variable' => 'error',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 871,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 872,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'int',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'numberFiles',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 872,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 872,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 874,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'files',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => '_FILES',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 874,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 874,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 876,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'files',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 876,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 876,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 876,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 876,
                'char' => 34,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 877,
                    'char' => 21,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 878,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 880,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'files',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 880,
                'char' => 27,
              ),
              'value' => 'file',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'error',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 881,
                      'char' => 41,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'file',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 881,
                        'char' => 33,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'error',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 881,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 881,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 881,
                    'char' => 41,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'not-equals',
                        'left' => 
                        array (
                          'type' => 'typeof',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'error',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 882,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 882,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'array',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 882,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 882,
                        'char' => 42,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'or',
                            'left' => 
                            array (
                              'type' => 'not',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'error',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 883,
                                'char' => 32,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 883,
                              'char' => 32,
                            ),
                            'right' => 
                            array (
                              'type' => 'not',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'onlySuccessful',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 883,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 883,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 883,
                            'char' => 50,
                          ),
                          'statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'let',
                              'assignments' => 
                              array (
                                0 => 
                                array (
                                  'assign-type' => 'incr',
                                  'variable' => 'numberFiles',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 884,
                                  'char' => 42,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 885,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 886,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 888,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'equals',
                        'left' => 
                        array (
                          'type' => 'typeof',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'error',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 888,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 888,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'array',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 888,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 888,
                        'char' => 42,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'add-assign',
                              'variable' => 'numberFiles',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 889,
                                  'char' => 44,
                                ),
                                'name' => 'hasFileHelper',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'error',
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 890,
                                      'char' => 30,
                                    ),
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 890,
                                    'char' => 30,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'onlySuccessful',
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 892,
                                      'char' => 21,
                                    ),
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 892,
                                    'char' => 21,
                                  ),
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 892,
                                'char' => 22,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 892,
                              'char' => 22,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 893,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 894,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 895,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 897,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'numberFiles',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 897,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 898,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the number of files available
     *
     * TODO: Check this
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 870,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 870,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 869,
          'last-line' => 902,
          'char' => 19,
        ),
        35 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
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
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 903,
              'char' => 51,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'name',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 905,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 907,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'name',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'strtoupper',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'strtr',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'header',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 907,
                                'char' => 43,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 907,
                              'char' => 43,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => '-',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 907,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 907,
                              'char' => 46,
                            ),
                            2 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => '_',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 907,
                                'char' => 49,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 907,
                              'char' => 49,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 907,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 907,
                        'char' => 50,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 907,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 907,
                  'char' => 51,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 909,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'or',
                'left' => 
                array (
                  'type' => 'isset',
                  'left' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => '_SERVER',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 909,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 909,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 909,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 909,
                  'char' => 37,
                ),
                'right' => 
                array (
                  'type' => 'isset',
                  'left' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => '_SERVER',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 909,
                      'char' => 52,
                    ),
                    'right' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => 'HTTP_',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 909,
                        'char' => 59,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'name',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 909,
                        'char' => 65,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 909,
                      'char' => 65,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 909,
                    'char' => 66,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 909,
                  'char' => 66,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 909,
                'char' => 66,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 910,
              'char' => 5,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 904,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 904,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 903,
          'last-line' => 914,
          'char' => 25,
        ),
        36 => 
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
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 915,
              'char' => 41,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'isset',
                'left' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => '_POST',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 917,
                    'char' => 27,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'name',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 917,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 917,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 917,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 918,
              'char' => 5,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 916,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 916,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 915,
          'last-line' => 922,
          'char' => 19,
        ),
        37 => 
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
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 923,
              'char' => 40,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'put',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 925,
                  'char' => 16,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 927,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'put',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 927,
                      'char' => 24,
                    ),
                    'name' => 'getPut',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 927,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 927,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 929,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'isset',
                'left' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'put',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 929,
                    'char' => 25,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'name',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 929,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 929,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 929,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 930,
              'char' => 5,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 924,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 924,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 923,
          'last-line' => 934,
          'char' => 19,
        ),
        38 => 
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
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 935,
              'char' => 42,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'isset',
                'left' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => '_GET',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 937,
                    'char' => 26,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'name',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 937,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 937,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 937,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 938,
              'char' => 5,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 936,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 936,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 935,
          'last-line' => 942,
          'char' => 19,
        ),
        39 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
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
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 943,
              'char' => 49,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'isset',
                'left' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => '_SERVER',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 945,
                    'char' => 29,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'name',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 945,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 945,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 945,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 946,
              'char' => 5,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 944,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 944,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 943,
          'last-line' => 950,
          'char' => 25,
        ),
        40 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isAjax',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'and',
                'left' => 
                array (
                  'type' => 'isset',
                  'left' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => '_SERVER',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 953,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'HTTP_X_REQUESTED_WITH',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 953,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 953,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 953,
                  'char' => 54,
                ),
                'right' => 
                array (
                  'type' => 'identical',
                  'left' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => '_SERVER',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 953,
                      'char' => 63,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'HTTP_X_REQUESTED_WITH',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 953,
                      'char' => 85,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 953,
                    'char' => 89,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'XMLHttpRequest',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 953,
                    'char' => 105,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 953,
                  'char' => 105,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 953,
                'char' => 105,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 954,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks whether request has been made using ajax
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 952,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 952,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 951,
          'last-line' => 959,
          'char' => 19,
        ),
        41 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isConnect',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 962,
                    'char' => 21,
                  ),
                  'name' => 'getMethod',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 962,
                  'char' => 36,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'CONNECT',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 962,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 962,
                'char' => 45,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 963,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks whether HTTP method is CONNECT.
     * if _SERVER["REQUEST_METHOD"]==="CONNECT"
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 961,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 961,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 960,
          'last-line' => 968,
          'char' => 19,
        ),
        42 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isDelete',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 971,
                    'char' => 21,
                  ),
                  'name' => 'getMethod',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 971,
                  'char' => 36,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'DELETE',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 971,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 971,
                'char' => 44,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 972,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks whether HTTP method is DELETE.
     * if _SERVER["REQUEST_METHOD"]==="DELETE"
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 970,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 970,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 969,
          'last-line' => 977,
          'char' => 19,
        ),
        43 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isGet',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 980,
                    'char' => 21,
                  ),
                  'name' => 'getMethod',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 980,
                  'char' => 36,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'GET',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 980,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 980,
                'char' => 41,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 981,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks whether HTTP method is GET.
     * if _SERVER["REQUEST_METHOD"]==="GET"
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 979,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 979,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 978,
          'last-line' => 986,
          'char' => 19,
        ),
        44 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isHead',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 989,
                    'char' => 21,
                  ),
                  'name' => 'getMethod',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 989,
                  'char' => 36,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'HEAD',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 989,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 989,
                'char' => 42,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 990,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks whether HTTP method is HEAD.
     * if _SERVER["REQUEST_METHOD"]==="HEAD"
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 988,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 988,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 987,
          'last-line' => 995,
          'char' => 19,
        ),
        45 => 
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
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 996,
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 996,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 996,
              'char' => 62,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'httpMethod',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 998,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'method',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 998,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1000,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'httpMethod',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1000,
                      'char' => 31,
                    ),
                    'name' => 'getMethod',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1000,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1000,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1002,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'methods',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1002,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1002,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'string',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1002,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1002,
                'char' => 37,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'unlikely',
                    'left' => 
                    array (
                      'type' => 'list',
                      'left' => 
                      array (
                        'type' => 'and',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'strict',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1003,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'not',
                          'left' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1003,
                              'char' => 42,
                            ),
                            'name' => 'isValidHttpMethod',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'methods',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1003,
                                  'char' => 68,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1003,
                                'char' => 68,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1003,
                            'char' => 69,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1003,
                          'char' => 69,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1003,
                        'char' => 69,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1003,
                      'char' => 71,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1003,
                    'char' => 71,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'throw',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'Exception',
                        'dynamic' => 0,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'string',
                                'value' => 'Invalid HTTP method: ',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1004,
                                'char' => 59,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'methods',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1004,
                                'char' => 68,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1004,
                              'char' => 68,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1004,
                            'char' => 68,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1004,
                        'char' => 69,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1005,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1007,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'methods',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1007,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'httpMethod',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1007,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1007,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1008,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1010,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'methods',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1010,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1010,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1010,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1010,
                'char' => 36,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'methods',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1011,
                    'char' => 35,
                  ),
                  'value' => 'method',
                  'reverse' => 0,
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1012,
                          'char' => 25,
                        ),
                        'name' => 'isMethod',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'method',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1012,
                              'char' => 41,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1012,
                            'char' => 41,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'strict',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1012,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1012,
                            'char' => 49,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1012,
                        'char' => 51,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'return',
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1013,
                            'char' => 32,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1014,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1015,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1017,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1017,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1018,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1020,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'strict',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1020,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1020,
                'char' => 28,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Exception',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'Invalid HTTP method: non-string',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1021,
                          'char' => 64,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1021,
                        'char' => 64,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1021,
                    'char' => 65,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1022,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1024,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1024,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1025,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check if HTTP method match any of the passed methods
     * When strict is true it checks if validated methods are real HTTP methods
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 997,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 997,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 996,
          'last-line' => 1030,
          'char' => 19,
        ),
        46 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isOptions',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1033,
                    'char' => 21,
                  ),
                  'name' => 'getMethod',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1033,
                  'char' => 36,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'OPTIONS',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1033,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1033,
                'char' => 45,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1034,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks whether HTTP method is OPTIONS.
     * if _SERVER["REQUEST_METHOD"]==="OPTIONS"
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1032,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 1032,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 1031,
          'last-line' => 1039,
          'char' => 19,
        ),
        47 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isPatch',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1042,
                    'char' => 21,
                  ),
                  'name' => 'getMethod',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1042,
                  'char' => 36,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'PATCH',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1042,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1042,
                'char' => 43,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1043,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks whether HTTP method is PATCH.
     * if _SERVER["REQUEST_METHOD"]==="PATCH"
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1041,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 1041,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 1040,
          'last-line' => 1048,
          'char' => 19,
        ),
        48 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isPost',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1051,
                    'char' => 21,
                  ),
                  'name' => 'getMethod',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1051,
                  'char' => 36,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'POST',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1051,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1051,
                'char' => 42,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1052,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks whether HTTP method is POST.
     * if _SERVER["REQUEST_METHOD"]==="POST"
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1050,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 1050,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 1049,
          'last-line' => 1057,
          'char' => 19,
        ),
        49 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isPut',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1060,
                    'char' => 21,
                  ),
                  'name' => 'getMethod',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1060,
                  'char' => 36,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'PUT',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1060,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1060,
                'char' => 41,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1061,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks whether HTTP method is PUT.
     * if _SERVER["REQUEST_METHOD"]==="PUT"
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1059,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 1059,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 1058,
          'last-line' => 1066,
          'char' => 19,
        ),
        50 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isPurge',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1069,
                    'char' => 21,
                  ),
                  'name' => 'getMethod',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1069,
                  'char' => 36,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'PURGE',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1069,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1069,
                'char' => 43,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1070,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks whether HTTP method is PURGE (Squid and Varnish support).
     * if _SERVER["REQUEST_METHOD"]==="PURGE"
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1068,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 1068,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 1067,
          'last-line' => 1074,
          'char' => 19,
        ),
        51 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isSecure',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1077,
                    'char' => 21,
                  ),
                  'name' => 'getScheme',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1077,
                  'char' => 36,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'https',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1077,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1077,
                'char' => 43,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1078,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1076,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 1076,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 1075,
          'last-line' => 1083,
          'char' => 19,
        ),
        52 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isStrictHostCheck',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1086,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'strictHostCheck',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1086,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1086,
                'char' => 37,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1087,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks if the `Request::getHttpHost` method will be use strict validation
     * of host name or not
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1085,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 1085,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 1084,
          'last-line' => 1091,
          'char' => 19,
        ),
        53 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isSoap',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'contentType',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1094,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1096,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'isset',
                'left' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => '_SERVER',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1096,
                    'char' => 25,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'HTTP_SOAPACTION',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1096,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1096,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1096,
                'char' => 43,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'true',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1097,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1098,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1100,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'contentType',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1100,
                      'char' => 32,
                    ),
                    'name' => 'getContentType',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1100,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1100,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1102,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'empty',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'contentType',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1102,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1102,
                'char' => 30,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1103,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1104,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1106,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'memstr',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'contentType',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1106,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1106,
                    'char' => 34,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'application/soap+xml',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1106,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1106,
                    'char' => 56,
                  ),
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1106,
                'char' => 57,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1107,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1093,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 1093,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 1092,
          'last-line' => 1112,
          'char' => 19,
        ),
        54 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isTrace',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1115,
                    'char' => 21,
                  ),
                  'name' => 'getMethod',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1115,
                  'char' => 36,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'TRACE',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1115,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1115,
                'char' => 43,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1116,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks whether HTTP method is TRACE.
     * if _SERVER["REQUEST_METHOD"]==="TRACE"
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1114,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 1114,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 1113,
          'last-line' => 1120,
          'char' => 19,
        ),
        55 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isValidHttpMethod',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'method',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1121,
              'char' => 52,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'switch',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'strtoupper',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'method',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1123,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1123,
                    'char' => 33,
                  ),
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1123,
                'char' => 35,
              ),
              'clauses' => 
              array (
                0 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'GET',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1124,
                    'char' => 21,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1125,
                  'char' => 16,
                ),
                1 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'POST',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1125,
                    'char' => 22,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1126,
                  'char' => 16,
                ),
                2 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'PUT',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1126,
                    'char' => 21,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1127,
                  'char' => 16,
                ),
                3 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'DELETE',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1127,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1128,
                  'char' => 16,
                ),
                4 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'HEAD',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1128,
                    'char' => 22,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1129,
                  'char' => 16,
                ),
                5 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'OPTIONS',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1129,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1130,
                  'char' => 16,
                ),
                6 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'PATCH',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1130,
                    'char' => 23,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1131,
                  'char' => 16,
                ),
                7 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'PURGE',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1131,
                    'char' => 23,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1132,
                  'char' => 16,
                ),
                8 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'TRACE',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1132,
                    'char' => 23,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1133,
                  'char' => 16,
                ),
                9 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'CONNECT',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1133,
                    'char' => 25,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'bool',
                        'value' => 'true',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1134,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1135,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1135,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1137,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1137,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1138,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks if a method is a valid HTTP method
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1122,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 1122,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 1121,
          'last-line' => 1142,
          'char' => 19,
        ),
        56 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDI',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'container',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'DiInterface',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1143,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1143,
              'char' => 50,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'container',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'container',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1145,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1145,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1146,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the dependency injector
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 1144,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 1143,
          'last-line' => 1151,
          'char' => 19,
        ),
        57 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setParameterFilters',
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
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1152,
              'char' => 53,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'filters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1152,
                'char' => 73,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1152,
              'char' => 73,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'scope',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1152,
                'char' => 91,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1152,
              'char' => 91,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'filterService',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1154,
                  'char' => 26,
                ),
                1 => 
                array (
                  'variable' => 'sanitizer',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1154,
                  'char' => 37,
                ),
                2 => 
                array (
                  'variable' => 'localScope',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1154,
                  'char' => 49,
                ),
                3 => 
                array (
                  'variable' => 'scopeMethod',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1154,
                  'char' => 62,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1156,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'less',
                  'left' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'count',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'filters',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1156,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1156,
                        'char' => 34,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1156,
                    'char' => 36,
                  ),
                  'right' => 
                  array (
                    'type' => 'int',
                    'value' => '1',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1156,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1156,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1156,
                'char' => 40,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Exception',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'string',
                              'value' => 'Filters have not been defined for \'',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1158,
                              'char' => 53,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'name',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1158,
                              'char' => 60,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1158,
                            'char' => 60,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '\'',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1159,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1159,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1159,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1159,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1160,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1162,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'filterService',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1162,
                      'char' => 34,
                    ),
                    'name' => 'getFilterService',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1162,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1162,
                  'char' => 53,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1164,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'filters',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1164,
                'char' => 34,
              ),
              'value' => 'sanitizer',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'unlikely',
                    'left' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'bool',
                        'value' => 'true',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1165,
                        'char' => 32,
                      ),
                      'right' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'filterService',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1165,
                          'char' => 48,
                        ),
                        'name' => 'has',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'sanitizer',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1165,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1165,
                            'char' => 62,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1165,
                        'char' => 64,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1165,
                      'char' => 64,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1165,
                    'char' => 64,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'throw',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'Exception',
                        'dynamic' => 0,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'Sanitizer \'',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1167,
                                  'char' => 33,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'sanitizer',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1167,
                                  'char' => 45,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1167,
                                'char' => 45,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => '\' does not exist in the filter locator',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1168,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1168,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1168,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1168,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1169,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1170,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1172,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'less',
                'left' => 
                array (
                  'type' => 'fcall',
                  'name' => 'count',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'scope',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1172,
                        'char' => 23,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1172,
                      'char' => 23,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1172,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '1',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1172,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1172,
                'char' => 29,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'localScope',
                      'expr' => 
                      array (
                        'type' => 'array',
                        'left' => 
                        array (
                          0 => 
                          array (
                            'value' => 
                            array (
                              'type' => 'string',
                              'value' => 'get',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1173,
                              'char' => 34,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1173,
                            'char' => 34,
                          ),
                          1 => 
                          array (
                            'value' => 
                            array (
                              'type' => 'string',
                              'value' => 'post',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1173,
                              'char' => 40,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1173,
                            'char' => 40,
                          ),
                          2 => 
                          array (
                            'value' => 
                            array (
                              'type' => 'string',
                              'value' => 'put',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1173,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1173,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1173,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1173,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1174,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'localScope',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'scope',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1175,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1175,
                      'char' => 35,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1176,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1178,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'localScope',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1178,
                'char' => 39,
              ),
              'value' => 'scopeMethod',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property-array-index',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'queryFilters',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'scopeMethod',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1179,
                          'char' => 47,
                        ),
                        1 => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1179,
                          'char' => 53,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'filters',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1179,
                        'char' => 64,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1179,
                      'char' => 64,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1180,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1182,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1182,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1183,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets automatic sanitizers/filters for a particular field and for
     * particular methods
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
                  'value' => 'RequestInterface',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1153,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1153,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 1153,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 1152,
          'last-line' => 1188,
          'char' => 19,
        ),
        58 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setStrictHostCheck',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'flag',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1189,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1189,
              'char' => 56,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'strictHostCheck',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'flag',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1191,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1191,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1193,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1193,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1194,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets if the `Request::getHttpHost` method must be use strict validation
     * of host name or not
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
                  'value' => 'RequestInterface',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1190,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1190,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 1190,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 1189,
          'last-line' => 1198,
          'char' => 19,
        ),
        59 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getBestQuality',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'qualityParts',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1199,
              'char' => 63,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1199,
              'char' => 77,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'int',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'i',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1201,
                  'char' => 14,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1202,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'double',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'quality',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1202,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'acceptQuality',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1202,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1203,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'selectedName',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1203,
                  'char' => 25,
                ),
                1 => 
                array (
                  'variable' => 'accept',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1203,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1205,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'i',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1205,
                    'char' => 18,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1205,
                  'char' => 18,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'quality',
                  'expr' => 
                  array (
                    'type' => 'double',
                    'value' => '0.0',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1206,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1206,
                  'char' => 26,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'selectedName',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1207,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1207,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1209,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'qualityParts',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1209,
                'char' => 36,
              ),
              'value' => 'accept',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'i',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1210,
                      'char' => 19,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1210,
                      'char' => 23,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1210,
                    'char' => 23,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'quality',
                          'expr' => 
                          array (
                            'type' => 'cast',
                            'left' => 'double',
                            'right' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'accept',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1211,
                                'char' => 46,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'quality',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1211,
                                'char' => 54,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1211,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1211,
                            'char' => 55,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1211,
                          'char' => 55,
                        ),
                        1 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'selectedName',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'accept',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1212,
                              'char' => 42,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'name',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1212,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1212,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1212,
                          'char' => 48,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1213,
                      'char' => 13,
                    ),
                  ),
                  'else_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'acceptQuality',
                          'expr' => 
                          array (
                            'type' => 'cast',
                            'left' => 'double',
                            'right' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'accept',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1214,
                                'char' => 52,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'quality',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1214,
                                'char' => 60,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1214,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1214,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1214,
                          'char' => 61,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1216,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'greater',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'acceptQuality',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1216,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'quality',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1216,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1216,
                        'char' => 44,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'quality',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'acceptQuality',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1217,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1217,
                              'char' => 48,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'selectedName',
                              'expr' => 
                              array (
                                'type' => 'array-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'accept',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1218,
                                  'char' => 46,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'name',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1218,
                                  'char' => 51,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1218,
                                'char' => 52,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1218,
                              'char' => 52,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1219,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1220,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1222,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'incr',
                      'variable' => 'i',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1222,
                      'char' => 20,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1223,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1225,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'selectedName',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1225,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1226,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Process a request header and return the one with best quality
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1200,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 1200,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 1199,
          'last-line' => 1231,
          'char' => 28,
        ),
        60 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getHelper',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'source',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1232,
              'char' => 52,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1232,
                'char' => 73,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1232,
              'char' => 73,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'filters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1232,
                'char' => 93,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1232,
              'char' => 93,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultValue',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1232,
                'char' => 118,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1232,
              'char' => 118,
            ),
            4 => 
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1232,
                'char' => 146,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1232,
              'char' => 146,
            ),
            5 => 
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1232,
                'char' => 172,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1232,
              'char' => 172,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1234,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'filterService',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1234,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1236,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'name',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1236,
                  'char' => 19,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1236,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1236,
                'char' => 26,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'source',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1237,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1238,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1240,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'value',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1240,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'source',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1240,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1240,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1240,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1240,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1240,
                'char' => 39,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'defaultValue',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1241,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1242,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1244,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'filters',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1244,
                  'char' => 22,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1244,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1244,
                'char' => 29,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'filterService',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1245,
                          'char' => 38,
                        ),
                        'name' => 'getFilterService',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1245,
                        'char' => 57,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1245,
                      'char' => 57,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'value',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'filterService',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1246,
                          'char' => 47,
                        ),
                        'name' => 'sanitize',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1246,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1246,
                            'char' => 62,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'filters',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1246,
                              'char' => 71,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1246,
                            'char' => 71,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'noRecursive',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1246,
                              'char' => 84,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1246,
                            'char' => 84,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1246,
                        'char' => 85,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1246,
                      'char' => 85,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1247,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1249,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'and',
                'left' => 
                array (
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'value',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1249,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1249,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'notAllowEmpty',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1249,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1249,
                'char' => 41,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'defaultValue',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1250,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1251,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1253,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'value',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1253,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1254,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Helper to get data from superglobals, applying filters if needed.
     * If no parameters are given the superglobal is returned.
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1233,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 1233,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 1232,
          'last-line' => 1258,
          'char' => 28,
        ),
        61 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'protected',
          ),
          'type' => 'method',
          'name' => 'hasFileHelper',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1259,
              'char' => 52,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'onlySuccessful',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1259,
              'char' => 73,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1261,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1262,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'int',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'numberFiles',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1262,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1262,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1264,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1264,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1264,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1264,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1264,
                'char' => 33,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '1',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1265,
                    'char' => 21,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1266,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1268,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'data',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1268,
                'char' => 27,
              ),
              'value' => 'value',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not-equals',
                    'left' => 
                    array (
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1269,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1269,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1269,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1269,
                    'char' => 38,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'or',
                        'left' => 
                        array (
                          'type' => 'not',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'value',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1270,
                            'char' => 28,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1270,
                          'char' => 28,
                        ),
                        'right' => 
                        array (
                          'type' => 'not',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'onlySuccessful',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1270,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1270,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1270,
                        'char' => 46,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'incr',
                              'variable' => 'numberFiles',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1271,
                              'char' => 38,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1272,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1273,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1275,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1275,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1275,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1275,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1275,
                    'char' => 38,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'add-assign',
                          'variable' => 'numberFiles',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1276,
                              'char' => 40,
                            ),
                            'name' => 'hasFileHelper',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'value',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1276,
                                  'char' => 60,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1276,
                                'char' => 60,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'onlySuccessful',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1276,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1276,
                                'char' => 76,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1276,
                            'char' => 77,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1276,
                          'char' => 77,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1277,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1278,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1280,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'numberFiles',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1280,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1281,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Recursively counts file in an array of files
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1260,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 1260,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 1259,
          'last-line' => 1285,
          'char' => 28,
        ),
        62 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getQualityHeader',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'serverIndex',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1286,
              'char' => 66,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1286,
              'char' => 80,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'returnedParts',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1288,
                  'char' => 26,
                ),
                1 => 
                array (
                  'variable' => 'parts',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1288,
                  'char' => 33,
                ),
                2 => 
                array (
                  'variable' => 'part',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1288,
                  'char' => 39,
                ),
                3 => 
                array (
                  'variable' => 'headerParts',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1288,
                  'char' => 52,
                ),
                4 => 
                array (
                  'variable' => 'headerPart',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1288,
                  'char' => 64,
                ),
                5 => 
                array (
                  'variable' => 'split',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1288,
                  'char' => 71,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1290,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'returnedParts',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1290,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1290,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1292,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'parts',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'preg_split',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '/,\\\\s*/',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1293,
                          'char' => 20,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1293,
                        'char' => 20,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1294,
                            'char' => 18,
                          ),
                          'name' => 'getServer',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'serverIndex',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1294,
                                'char' => 40,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1294,
                              'char' => 40,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1294,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1294,
                        'char' => 41,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'int',
                          'value' => '-1',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1295,
                          'char' => 15,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1295,
                        'char' => 15,
                      ),
                      3 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'constant',
                          'value' => 'PREG_SPLIT_NO_EMPTY',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1297,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1297,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1297,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1297,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1299,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'parts',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1299,
                'char' => 27,
              ),
              'value' => 'part',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'headerParts',
                      'expr' => 
                      array (
                        'type' => 'empty-array',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1300,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1300,
                      'char' => 33,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1302,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'preg_split',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '/\\s*;\\s*/',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1302,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1302,
                        'char' => 51,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'trim',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'part',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1302,
                                'char' => 62,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1302,
                              'char' => 62,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1302,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1302,
                        'char' => 63,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'int',
                          'value' => '-1',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1302,
                          'char' => 67,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1302,
                        'char' => 67,
                      ),
                      3 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'constant',
                          'value' => 'PREG_SPLIT_NO_EMPTY',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1302,
                          'char' => 88,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1302,
                        'char' => 88,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1302,
                    'char' => 90,
                  ),
                  'value' => 'headerPart',
                  'reverse' => 0,
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'not-identical',
                        'left' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'strpos',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'headerPart',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1303,
                                'char' => 37,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1303,
                              'char' => 37,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => '=',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1303,
                                'char' => 40,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1303,
                              'char' => 40,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1303,
                          'char' => 44,
                        ),
                        'right' => 
                        array (
                          'type' => 'bool',
                          'value' => 'false',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1303,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1303,
                        'char' => 52,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'split',
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'explode',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '=',
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 1304,
                                      'char' => 42,
                                    ),
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1304,
                                    'char' => 42,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'headerPart',
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 1304,
                                      'char' => 54,
                                    ),
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1304,
                                    'char' => 54,
                                  ),
                                  2 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'int',
                                      'value' => '2',
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 1304,
                                      'char' => 57,
                                    ),
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1304,
                                    'char' => 57,
                                  ),
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1304,
                                'char' => 58,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1304,
                              'char' => 58,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1306,
                          'char' => 22,
                        ),
                        1 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'identical',
                            'left' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'split',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1306,
                                'char' => 29,
                              ),
                              'right' => 
                              array (
                                'type' => 'int',
                                'value' => '0',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1306,
                                'char' => 31,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1306,
                              'char' => 35,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'q',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1306,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1306,
                            'char' => 39,
                          ),
                          'statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'let',
                              'assignments' => 
                              array (
                                0 => 
                                array (
                                  'assign-type' => 'array-index',
                                  'operator' => 'assign',
                                  'variable' => 'headerParts',
                                  'index-expr' => 
                                  array (
                                    0 => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'quality',
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 1307,
                                      'char' => 48,
                                    ),
                                  ),
                                  'expr' => 
                                  array (
                                    'type' => 'cast',
                                    'left' => 'double',
                                    'right' => 
                                    array (
                                      'type' => 'array-access',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'split',
                                        'file' => '/app/phalcon/Http/Request.zep',
                                        'line' => 1307,
                                        'char' => 66,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'int',
                                        'value' => '1',
                                        'file' => '/app/phalcon/Http/Request.zep',
                                        'line' => 1307,
                                        'char' => 68,
                                      ),
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 1307,
                                      'char' => 69,
                                    ),
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1307,
                                    'char' => 69,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1307,
                                  'char' => 69,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1308,
                              'char' => 21,
                            ),
                          ),
                          'else_statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'let',
                              'assignments' => 
                              array (
                                0 => 
                                array (
                                  'assign-type' => 'array-index',
                                  'operator' => 'assign',
                                  'variable' => 'headerParts',
                                  'index-expr' => 
                                  array (
                                    0 => 
                                    array (
                                      'type' => 'array-access',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'split',
                                        'file' => '/app/phalcon/Http/Request.zep',
                                        'line' => 1309,
                                        'char' => 46,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'int',
                                        'value' => '0',
                                        'file' => '/app/phalcon/Http/Request.zep',
                                        'line' => 1309,
                                        'char' => 48,
                                      ),
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 1309,
                                      'char' => 49,
                                    ),
                                  ),
                                  'expr' => 
                                  array (
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'split',
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 1309,
                                      'char' => 58,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'int',
                                      'value' => '1',
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 1309,
                                      'char' => 60,
                                    ),
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1309,
                                    'char' => 61,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1309,
                                  'char' => 61,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1310,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1311,
                          'char' => 17,
                        ),
                      ),
                      'else_statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'headerParts',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'name',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1312,
                                  'char' => 41,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'headerPart',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1312,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1312,
                              'char' => 55,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1313,
                          'char' => 23,
                        ),
                        1 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'headerParts',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'string',
                                  'value' => 'quality',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1313,
                                  'char' => 44,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'double',
                                'value' => '1.0',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1313,
                                'char' => 51,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1313,
                              'char' => 51,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1314,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1315,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1317,
                  'char' => 15,
                ),
                2 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'returnedParts',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'headerParts',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1317,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1317,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1318,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1320,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'returnedParts',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1320,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1321,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Process a request header and return an array of values with their qualities
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1287,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 1287,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 1286,
          'last-line' => 1325,
          'char' => 28,
        ),
        63 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'resolveAuthorizationHeaders',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'resolved',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1328,
                  'char' => 21,
                ),
                1 => 
                array (
                  'variable' => 'eventsManager',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1328,
                  'char' => 36,
                ),
                2 => 
                array (
                  'variable' => 'hasEventsManager',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1328,
                  'char' => 54,
                ),
                3 => 
                array (
                  'variable' => 'container',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1328,
                  'char' => 65,
                ),
                4 => 
                array (
                  'variable' => 'exploded',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1328,
                  'char' => 75,
                ),
                5 => 
                array (
                  'variable' => 'digest',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1329,
                  'char' => 19,
                ),
                6 => 
                array (
                  'variable' => 'authHeader',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1329,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1329,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1330,
              'char' => 13,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'array',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'headers',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1330,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1330,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1332,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'container',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'DiInterface',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1332,
                      'char' => 52,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1332,
                        'char' => 44,
                      ),
                      'name' => 'getDI',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1332,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1332,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1332,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1335,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'container',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1335,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1335,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1335,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1335,
                'char' => 40,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'hasEventsManager',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'bool',
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'container',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1336,
                            'char' => 53,
                          ),
                          'name' => 'has',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'eventsManager',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1336,
                                'char' => 71,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1336,
                              'char' => 71,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1336,
                          'char' => 72,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1336,
                        'char' => 72,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1336,
                      'char' => 72,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1338,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'hasEventsManager',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1338,
                    'char' => 33,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'eventsManager',
                          'expr' => 
                          array (
                            'type' => 'type-hint',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'ManagerInterface',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1339,
                              'char' => 91,
                            ),
                            'right' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'container',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1339,
                                'char' => 66,
                              ),
                              'name' => 'getShared',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'eventsManager',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1339,
                                    'char' => 90,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1339,
                                  'char' => 90,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1339,
                              'char' => 91,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1339,
                            'char' => 91,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1339,
                          'char' => 91,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1340,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1341,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1343,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'and',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'hasEventsManager',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1343,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'identical',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'eventsManager',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1343,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1343,
                    'char' => 55,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1343,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1343,
                  'char' => 64,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1343,
                'char' => 64,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'resolved',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'eventsManager',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1344,
                          'char' => 42,
                        ),
                        'name' => 'fire',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'request:beforeAuthorizationResolve',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1345,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1345,
                            'char' => 51,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1346,
                              'char' => 21,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1346,
                            'char' => 21,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'array',
                              'left' => 
                              array (
                                0 => 
                                array (
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'server',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1348,
                                    'char' => 27,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => '_SERVER',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1349,
                                    'char' => 17,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1349,
                                  'char' => 17,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1350,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1350,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1350,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1350,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1352,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'resolved',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1352,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1352,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1352,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1352,
                    'char' => 42,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'headers',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'array_merge',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'headers',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1353,
                                  'char' => 50,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1353,
                                'char' => 50,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'resolved',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1353,
                                  'char' => 60,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1353,
                                'char' => 60,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1353,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1353,
                          'char' => 61,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1354,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1355,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1357,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'and',
                'left' => 
                array (
                  'type' => 'isset',
                  'left' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => '_SERVER',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1357,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'PHP_AUTH_USER',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1357,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1357,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1357,
                  'char' => 42,
                ),
                'right' => 
                array (
                  'type' => 'isset',
                  'left' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => '_SERVER',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1357,
                      'char' => 57,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'PHP_AUTH_PW',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1357,
                      'char' => 69,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1357,
                    'char' => 71,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1357,
                  'char' => 71,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1357,
                'char' => 71,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'headers',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'Php-Auth-User',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1358,
                          'char' => 38,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => '_SERVER',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1358,
                          'char' => 49,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'PHP_AUTH_USER',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1358,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1358,
                        'char' => 64,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1358,
                      'char' => 64,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'headers',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'Php-Auth-Pw',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1359,
                          'char' => 36,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => '_SERVER',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1359,
                          'char' => 47,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'PHP_AUTH_PW',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1359,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1359,
                        'char' => 60,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1359,
                      'char' => 60,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1360,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'isset',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => '_SERVER',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1361,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'HTTP_AUTHORIZATION',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1361,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1361,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1361,
                    'char' => 50,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'authHeader',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => '_SERVER',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1362,
                              'char' => 41,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'HTTP_AUTHORIZATION',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1362,
                              'char' => 60,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1362,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1362,
                          'char' => 61,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1363,
                      'char' => 13,
                    ),
                  ),
                  'elseif_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'isset',
                        'left' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => '_SERVER',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1363,
                            'char' => 35,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'REDIRECT_HTTP_AUTHORIZATION',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1363,
                            'char' => 63,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1363,
                          'char' => 65,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1363,
                        'char' => 65,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'authHeader',
                              'expr' => 
                              array (
                                'type' => 'array-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => '_SERVER',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1364,
                                  'char' => 41,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'REDIRECT_HTTP_AUTHORIZATION',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1364,
                                  'char' => 69,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1364,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1364,
                              'char' => 70,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1365,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1367,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1367,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'authHeader',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1367,
                    'char' => 27,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'identical',
                        'left' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'stripos',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'authHeader',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1368,
                                'char' => 38,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1368,
                              'char' => 38,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'basic ',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1368,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1368,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1368,
                          'char' => 50,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1368,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1368,
                        'char' => 54,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'exploded',
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'explode',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'string',
                                      'value' => ':',
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 1370,
                                      'char' => 26,
                                    ),
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1370,
                                    'char' => 26,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'fcall',
                                      'name' => 'base64_decode',
                                      'call-type' => 1,
                                      'parameters' => 
                                      array (
                                        0 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'fcall',
                                            'name' => 'substr',
                                            'call-type' => 1,
                                            'parameters' => 
                                            array (
                                              0 => 
                                              array (
                                                'parameter' => 
                                                array (
                                                  'type' => 'variable',
                                                  'value' => 'authHeader',
                                                  'file' => '/app/phalcon/Http/Request.zep',
                                                  'line' => 1372,
                                                  'char' => 46,
                                                ),
                                                'file' => '/app/phalcon/Http/Request.zep',
                                                'line' => 1372,
                                                'char' => 46,
                                              ),
                                              1 => 
                                              array (
                                                'parameter' => 
                                                array (
                                                  'type' => 'int',
                                                  'value' => '6',
                                                  'file' => '/app/phalcon/Http/Request.zep',
                                                  'line' => 1372,
                                                  'char' => 49,
                                                ),
                                                'file' => '/app/phalcon/Http/Request.zep',
                                                'line' => 1372,
                                                'char' => 49,
                                              ),
                                            ),
                                            'file' => '/app/phalcon/Http/Request.zep',
                                            'line' => 1373,
                                            'char' => 25,
                                          ),
                                          'file' => '/app/phalcon/Http/Request.zep',
                                          'line' => 1373,
                                          'char' => 25,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 1373,
                                      'char' => 26,
                                    ),
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1373,
                                    'char' => 26,
                                  ),
                                  2 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'int',
                                      'value' => '2',
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 1375,
                                      'char' => 21,
                                    ),
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1375,
                                    'char' => 21,
                                  ),
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1375,
                                'char' => 22,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1375,
                              'char' => 22,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1377,
                          'char' => 22,
                        ),
                        1 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'equals',
                            'left' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'count',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'exploded',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1377,
                                    'char' => 38,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1377,
                                  'char' => 38,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1377,
                              'char' => 41,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '2',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1377,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1377,
                            'char' => 45,
                          ),
                          'statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'let',
                              'assignments' => 
                              array (
                                0 => 
                                array (
                                  'assign-type' => 'array-index',
                                  'operator' => 'assign',
                                  'variable' => 'headers',
                                  'index-expr' => 
                                  array (
                                    0 => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'Php-Auth-User',
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 1378,
                                      'char' => 50,
                                    ),
                                  ),
                                  'expr' => 
                                  array (
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'exploded',
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 1378,
                                      'char' => 62,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'int',
                                      'value' => '0',
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 1378,
                                      'char' => 64,
                                    ),
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1378,
                                    'char' => 65,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1378,
                                  'char' => 65,
                                ),
                                1 => 
                                array (
                                  'assign-type' => 'array-index',
                                  'operator' => 'assign',
                                  'variable' => 'headers',
                                  'index-expr' => 
                                  array (
                                    0 => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'Php-Auth-Pw',
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 1379,
                                      'char' => 48,
                                    ),
                                  ),
                                  'expr' => 
                                  array (
                                    'type' => 'array-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'exploded',
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 1379,
                                      'char' => 62,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'int',
                                      'value' => '1',
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 1379,
                                      'char' => 64,
                                    ),
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1379,
                                    'char' => 65,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1379,
                                  'char' => 65,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1380,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1381,
                          'char' => 17,
                        ),
                      ),
                      'elseif_statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'and',
                            'left' => 
                            array (
                              'type' => 'identical',
                              'left' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'stripos',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'authHeader',
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 1381,
                                      'char' => 44,
                                    ),
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1381,
                                    'char' => 44,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'digest ',
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 1381,
                                      'char' => 53,
                                    ),
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1381,
                                    'char' => 53,
                                  ),
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1381,
                                'char' => 57,
                              ),
                              'right' => 
                              array (
                                'type' => 'int',
                                'value' => '0',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1381,
                                'char' => 62,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1381,
                              'char' => 62,
                            ),
                            'right' => 
                            array (
                              'type' => 'not',
                              'left' => 
                              array (
                                'type' => 'fetch',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'digest',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1381,
                                  'char' => 104,
                                ),
                                'right' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => '_SERVER',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1381,
                                    'char' => 86,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'PHP_AUTH_DIGEST',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1381,
                                    'char' => 102,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1381,
                                  'char' => 104,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1381,
                                'char' => 104,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1381,
                              'char' => 104,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1381,
                            'char' => 104,
                          ),
                          'statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'let',
                              'assignments' => 
                              array (
                                0 => 
                                array (
                                  'assign-type' => 'array-index',
                                  'operator' => 'assign',
                                  'variable' => 'headers',
                                  'index-expr' => 
                                  array (
                                    0 => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'Php-Auth-Digest',
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 1382,
                                      'char' => 48,
                                    ),
                                  ),
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'authHeader',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1382,
                                    'char' => 62,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1382,
                                  'char' => 62,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1383,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1383,
                          'char' => 24,
                        ),
                        1 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'identical',
                            'left' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'stripos',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'authHeader',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1383,
                                    'char' => 44,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1383,
                                  'char' => 44,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'bearer ',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1383,
                                    'char' => 53,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1383,
                                  'char' => 53,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1383,
                              'char' => 57,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '0',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1383,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1383,
                            'char' => 61,
                          ),
                          'statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'let',
                              'assignments' => 
                              array (
                                0 => 
                                array (
                                  'assign-type' => 'array-index',
                                  'operator' => 'assign',
                                  'variable' => 'headers',
                                  'index-expr' => 
                                  array (
                                    0 => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'Authorization',
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 1384,
                                      'char' => 46,
                                    ),
                                  ),
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'authHeader',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1384,
                                    'char' => 60,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1384,
                                  'char' => 60,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1385,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1386,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1386,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1387,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1389,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'isset',
                  'left' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'headers',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1389,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'Authorization',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1389,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1389,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1389,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1389,
                'char' => 42,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'isset',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'headers',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1390,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'Php-Auth-User',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1390,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1390,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1390,
                    'char' => 45,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'headers',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'Authorization',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1391,
                              'char' => 42,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'string',
                              'value' => 'Basic ',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1391,
                              'char' => 53,
                            ),
                            'right' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'base64_encode',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'concat',
                                    'left' => 
                                    array (
                                      'type' => 'concat',
                                      'left' => 
                                      array (
                                        'type' => 'array-access',
                                        'left' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'headers',
                                          'file' => '/app/phalcon/Http/Request.zep',
                                          'line' => 1391,
                                          'char' => 76,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => 'Php-Auth-User',
                                          'file' => '/app/phalcon/Http/Request.zep',
                                          'line' => 1391,
                                          'char' => 90,
                                        ),
                                        'file' => '/app/phalcon/Http/Request.zep',
                                        'line' => 1391,
                                        'char' => 92,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => ':',
                                        'file' => '/app/phalcon/Http/Request.zep',
                                        'line' => 1391,
                                        'char' => 96,
                                      ),
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 1391,
                                      'char' => 96,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'array-access',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'headers',
                                        'file' => '/app/phalcon/Http/Request.zep',
                                        'line' => 1391,
                                        'char' => 105,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => 'Php-Auth-Pw',
                                        'file' => '/app/phalcon/Http/Request.zep',
                                        'line' => 1391,
                                        'char' => 117,
                                      ),
                                      'file' => '/app/phalcon/Http/Request.zep',
                                      'line' => 1391,
                                      'char' => 118,
                                    ),
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1391,
                                    'char' => 118,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1391,
                                  'char' => 118,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1391,
                              'char' => 119,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1391,
                            'char' => 119,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1391,
                          'char' => 119,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1392,
                      'char' => 13,
                    ),
                  ),
                  'elseif_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'fetch',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'digest',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1392,
                          'char' => 61,
                        ),
                        'right' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'headers',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1392,
                            'char' => 43,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'Php-Auth-Digest',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1392,
                            'char' => 59,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1392,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1392,
                        'char' => 61,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'headers',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'string',
                                  'value' => 'Authorization',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1393,
                                  'char' => 42,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'digest',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1393,
                                'char' => 52,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1393,
                              'char' => 52,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1394,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1395,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1395,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1397,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'and',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'hasEventsManager',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1397,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'identical',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'eventsManager',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1397,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1397,
                    'char' => 55,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1397,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1397,
                  'char' => 64,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1397,
                'char' => 64,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'resolved',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'eventsManager',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1398,
                          'char' => 42,
                        ),
                        'name' => 'fire',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'request:afterAuthorizationResolve',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1399,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1399,
                            'char' => 50,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1400,
                              'char' => 21,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1400,
                            'char' => 21,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'array',
                              'left' => 
                              array (
                                0 => 
                                array (
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'headers',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1402,
                                    'char' => 28,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'headers',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1402,
                                    'char' => 37,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1402,
                                  'char' => 37,
                                ),
                                1 => 
                                array (
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'server',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1403,
                                    'char' => 27,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => '_SERVER',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1404,
                                    'char' => 17,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1404,
                                  'char' => 17,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1405,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1405,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1405,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1405,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1407,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'resolved',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1407,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1407,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1407,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1407,
                    'char' => 42,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'headers',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'array_merge',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'headers',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1408,
                                  'char' => 50,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1408,
                                'char' => 50,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'resolved',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1408,
                                  'char' => 60,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1408,
                                'char' => 60,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1408,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1408,
                          'char' => 61,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1409,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1411,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1413,
              'char' => 14,
            ),
            8 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'headers',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1413,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1414,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Resolve authorization headers.
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1327,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 1327,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 1326,
          'last-line' => 1418,
          'char' => 22,
        ),
        64 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'protected',
          ),
          'type' => 'method',
          'name' => 'smoothFiles',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'names',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1419,
              'char' => 54,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'types',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1419,
              'char' => 68,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'tmp_names',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1419,
              'char' => 86,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'sizes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1419,
              'char' => 100,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'errors',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1419,
              'char' => 115,
            ),
            5 => 
            array (
              'type' => 'parameter',
              'name' => 'prefix',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1419,
              'char' => 130,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'idx',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1421,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'name',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1421,
                  'char' => 22,
                ),
                2 => 
                array (
                  'variable' => 'file',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1421,
                  'char' => 28,
                ),
                3 => 
                array (
                  'variable' => 'files',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1421,
                  'char' => 35,
                ),
                4 => 
                array (
                  'variable' => 'parentFiles',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1421,
                  'char' => 48,
                ),
                5 => 
                array (
                  'variable' => 'p',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1421,
                  'char' => 51,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1423,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'files',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1423,
                    'char' => 23,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1423,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1425,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'names',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1425,
                'char' => 32,
              ),
              'key' => 'idx',
              'value' => 'name',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'p',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'prefix',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1426,
                            'char' => 28,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '.',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1426,
                            'char' => 32,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1426,
                          'char' => 32,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'idx',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1426,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1426,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1426,
                      'char' => 37,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1428,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'name',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1428,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1428,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'string',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1428,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1428,
                    'char' => 38,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable-append',
                          'operator' => 'assign',
                          'variable' => 'files',
                          'expr' => 
                          array (
                            'type' => 'array',
                            'left' => 
                            array (
                              0 => 
                              array (
                                'key' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'name',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1430,
                                  'char' => 25,
                                ),
                                'value' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'name',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1430,
                                  'char' => 35,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1430,
                                'char' => 35,
                              ),
                              1 => 
                              array (
                                'key' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1431,
                                  'char' => 25,
                                ),
                                'value' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'types',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1431,
                                    'char' => 36,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'idx',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1431,
                                    'char' => 40,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1431,
                                  'char' => 41,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1431,
                                'char' => 41,
                              ),
                              2 => 
                              array (
                                'key' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'tmp_name',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1432,
                                  'char' => 29,
                                ),
                                'value' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'tmp_names',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1432,
                                    'char' => 40,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'idx',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1432,
                                    'char' => 44,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1432,
                                  'char' => 45,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1432,
                                'char' => 45,
                              ),
                              3 => 
                              array (
                                'key' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'size',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1433,
                                  'char' => 25,
                                ),
                                'value' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'sizes',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1433,
                                    'char' => 36,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'idx',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1433,
                                    'char' => 40,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1433,
                                  'char' => 41,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1433,
                                'char' => 41,
                              ),
                              4 => 
                              array (
                                'key' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'error',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1434,
                                  'char' => 26,
                                ),
                                'value' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'errors',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1434,
                                    'char' => 37,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'idx',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1434,
                                    'char' => 41,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1434,
                                  'char' => 42,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1434,
                                'char' => 42,
                              ),
                              5 => 
                              array (
                                'key' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'key',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1435,
                                  'char' => 24,
                                ),
                                'value' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'p',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1436,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1436,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1436,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1436,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1437,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1439,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'name',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1439,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1439,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1439,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1439,
                    'char' => 37,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'parentFiles',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1440,
                              'char' => 40,
                            ),
                            'name' => 'smoothFiles',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'names',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1441,
                                    'char' => 26,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'idx',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1441,
                                    'char' => 30,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1441,
                                  'char' => 31,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1441,
                                'char' => 31,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'types',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1442,
                                    'char' => 26,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'idx',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1442,
                                    'char' => 30,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1442,
                                  'char' => 31,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1442,
                                'char' => 31,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'tmp_names',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1443,
                                    'char' => 30,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'idx',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1443,
                                    'char' => 34,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1443,
                                  'char' => 35,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1443,
                                'char' => 35,
                              ),
                              3 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'sizes',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1444,
                                    'char' => 26,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'idx',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1444,
                                    'char' => 30,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1444,
                                  'char' => 31,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1444,
                                'char' => 31,
                              ),
                              4 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'errors',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1445,
                                    'char' => 27,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'idx',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1445,
                                    'char' => 31,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1445,
                                  'char' => 32,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1445,
                                'char' => 32,
                              ),
                              5 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'p',
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1447,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1447,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1447,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1447,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1449,
                      'char' => 19,
                    ),
                    1 => 
                    array (
                      'type' => 'for',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'parentFiles',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1449,
                        'char' => 41,
                      ),
                      'value' => 'file',
                      'reverse' => 0,
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'variable-append',
                              'operator' => 'assign',
                              'variable' => 'files',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'file',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1450,
                                'char' => 39,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1450,
                              'char' => 39,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1451,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1452,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1453,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1455,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'files',
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1455,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1456,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Smooth out $_FILES to have plain array with all files uploaded
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
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1420,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 1420,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 1419,
          'last-line' => 1460,
          'char' => 28,
        ),
        65 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'getFilterService',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'container',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1463,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'filterService',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1463,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1465,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'filterService',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1465,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'filterService',
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1465,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1465,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1465,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1467,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'filterService',
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1467,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1467,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1467,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1467,
                'char' => 43,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'container',
                      'expr' => 
                      array (
                        'type' => 'type-hint',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'DiInterface',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1468,
                          'char' => 58,
                        ),
                        'right' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1468,
                            'char' => 48,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'container',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1468,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1468,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1468,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1468,
                      'char' => 58,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1470,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'unlikely',
                    'left' => 
                    array (
                      'type' => 'not-equals',
                      'left' => 
                      array (
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'container',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1470,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1470,
                        'char' => 43,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'object',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1470,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1470,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Http/Request.zep',
                    'line' => 1470,
                    'char' => 52,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'throw',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'Exception',
                        'dynamic' => 0,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'scall',
                              'dynamic-class' => 0,
                              'class' => 'Exception',
                              'dynamic' => 0,
                              'name' => 'containerServiceNotFound',
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'the \'filter\' service',
                                    'file' => '/app/phalcon/Http/Request.zep',
                                    'line' => 1472,
                                    'char' => 77,
                                  ),
                                  'file' => '/app/phalcon/Http/Request.zep',
                                  'line' => 1472,
                                  'char' => 77,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1473,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1473,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1473,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1474,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1476,
                  'char' => 15,
                ),
                2 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'filterService',
                      'expr' => 
                      array (
                        'type' => 'type-hint',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'FilterInterface',
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1476,
                          'char' => 85,
                        ),
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'container',
                            'file' => '/app/phalcon/Http/Request.zep',
                            'line' => 1476,
                            'char' => 67,
                          ),
                          'name' => 'getShared',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'filter',
                                'file' => '/app/phalcon/Http/Request.zep',
                                'line' => 1476,
                                'char' => 84,
                              ),
                              'file' => '/app/phalcon/Http/Request.zep',
                              'line' => 1476,
                              'char' => 84,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Request.zep',
                          'line' => 1476,
                          'char' => 85,
                        ),
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1476,
                        'char' => 85,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1476,
                      'char' => 85,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'filterService',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'filterService',
                        'file' => '/app/phalcon/Http/Request.zep',
                        'line' => 1477,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Http/Request.zep',
                      'line' => 1477,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1478,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1480,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1480,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'filterService',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1480,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1480,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Http/Request.zep',
              'line' => 1481,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks the filter service and assigns it to the class parameter
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
                  'value' => 'FilterInterface',
                  'file' => '/app/phalcon/Http/Request.zep',
                  'line' => 1462,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Request.zep',
                'line' => 1462,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request.zep',
            'line' => 1462,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request.zep',
          'line' => 1461,
          'last-line' => 1482,
          'char' => 20,
        ),
      ),
      'file' => '/app/phalcon/Http/Request.zep',
      'line' => 49,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Http/Request.zep',
    'line' => 49,
    'char' => 5,
  ),
);